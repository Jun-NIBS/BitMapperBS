/*
  Authors:
  Haoyu Cheng
	  chhy@mail.ustc.edu.cn
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Auxiliary.h"
#include "Process_sam_out.h"
#include <pthread.h>

pthread_mutex_t o_readinputMutex;
pthread_mutex_t o_queueMutex;
pthread_mutex_t o_terminateMutex;
pthread_cond_t o_flushCond;
pthread_cond_t o_readinputflushCond;
pthread_cond_t o_stallCond;
pthread_cond_t o_readinputstallCond;
pthread_mutex_t o_doneMutex;



FILE *_out_fp;

int sub_block_init_length = 10000;


Output_buffer buffer_out;
Output_buffer_sub_block tmp_buffer_sub_block;

///void finalizeTXOutput()
void finalizeOutput()
{
  fclose(_out_fp);
}

void init_buffer_sub_block(Output_buffer_sub_block* sub_block)
{
	sub_block->length = 0;
	sub_block->size = sub_block_init_length;
	sub_block->buffer = (char*)malloc(sub_block->size);
}




///初始化缓冲区
void init_output_buffer(int thread_number)
{


	///ouput_buffer_size
	///size是空间大小
	buffer_out.sub_block_size = ouput_buffer_size * thread_number;
	buffer_out.sub_block_number = 0;

	buffer_out.sub_buffer = (Output_buffer_sub_block*)malloc(sizeof(Output_buffer_sub_block)*buffer_out.sub_block_size);



	for (int i = 0; i < buffer_out.sub_block_size; i++)
	{
		init_buffer_sub_block(&(buffer_out.sub_buffer[i]));
	}

	buffer_out.all_buffer_end = 0;
}

inline int if_empty_buffer()
{

	if (buffer_out.sub_block_number == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

inline int if_full_buffer()
{

	if (buffer_out.sub_block_number >= buffer_out.sub_block_size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


///这个是要取一个结果取到curr_sub_block中
inline void pop_single_buffer(Output_buffer_sub_block* curr_sub_block)
{
	buffer_out.sub_block_number--;
	///只交换指针
	///记得要交换，直接赋值会内存泄露，造成野指针
	char *k;
	k = buffer_out.sub_buffer[buffer_out.sub_block_number].buffer;
	buffer_out.sub_buffer[buffer_out.sub_block_number].buffer = curr_sub_block->buffer;
	curr_sub_block->buffer = k;

	
	long long tmp_size;
	tmp_size = curr_sub_block->size;
	curr_sub_block->size = buffer_out.sub_buffer[buffer_out.sub_block_number].size;
	buffer_out.sub_buffer[buffer_out.sub_block_number].size = tmp_size;


	curr_sub_block->length = buffer_out.sub_buffer[buffer_out.sub_block_number].length;
	buffer_out.sub_buffer[buffer_out.sub_block_number].length = 0;




}

///这个是要把curr_sub_block的结果放到队列中
inline void push_single_buffer(Output_buffer_sub_block* curr_sub_block)
{


	///只交换指针
	///记得要交换，直接赋值会内存泄露，造成野指针
	char *k;
	k = buffer_out.sub_buffer[buffer_out.sub_block_number].buffer;
	buffer_out.sub_buffer[buffer_out.sub_block_number].buffer = curr_sub_block->buffer;
	curr_sub_block->buffer = k;


	long long tmp_size;
	tmp_size = curr_sub_block->size;
	curr_sub_block->size = buffer_out.sub_buffer[buffer_out.sub_block_number].size;
	buffer_out.sub_buffer[buffer_out.sub_block_number].size = tmp_size;




	buffer_out.sub_buffer[buffer_out.sub_block_number].length = curr_sub_block->length;
	curr_sub_block->length = 0;



	buffer_out.sub_block_number++;
}


void finish_output_buffer()
{
	///这个也要加互斥锁
	pthread_mutex_lock(&o_doneMutex);
	buffer_out.all_buffer_end++;


	if (buffer_out.all_buffer_end == THREAD_COUNT)
		pthread_cond_signal(&o_flushCond);
	pthread_mutex_unlock(&o_doneMutex);
}


void push_results_to_buffer(Output_buffer_sub_block* sub_block)
{
	
	pthread_mutex_lock(&o_queueMutex);

	///if_full_buffer
	while (if_full_buffer())
	{
		///按道理这个信号量似乎不用发
		///因为队列不可能一边满一边空
		pthread_cond_signal(&o_flushCond);


		pthread_cond_wait(&o_stallCond, &o_queueMutex);
	}


	push_single_buffer(sub_block);



	pthread_cond_signal(&o_flushCond);
	pthread_mutex_unlock(&o_queueMutex);
	
}

void* pop_buffer(void*)
{
	
	FILE* output_file = get_Ouput_Dec();

	init_buffer_sub_block(&tmp_buffer_sub_block);

	

	while (buffer_out.all_buffer_end<THREAD_COUNT)
	{

		pthread_mutex_lock(&o_queueMutex);


		while (if_empty_buffer() && (buffer_out.all_buffer_end<THREAD_COUNT))
		{
			///按道理这个信号量似乎不用发
			///因为队列不可能一边满一边空
			pthread_cond_signal(&o_stallCond);


			pthread_cond_wait(&o_flushCond, &o_queueMutex);
		}


		if (!if_empty_buffer())
		{
			pop_single_buffer(&tmp_buffer_sub_block);
		}

		pthread_cond_signal(&o_stallCond);
		pthread_mutex_unlock(&o_queueMutex);

		if (tmp_buffer_sub_block.length != 0)
		{
			fprintf(output_file, "%s", tmp_buffer_sub_block.buffer);
		}

	}


	while (buffer_out.sub_block_number>0)
	{
		buffer_out.sub_block_number--;
		fprintf(output_file, "%s", buffer_out.sub_buffer[buffer_out.sub_block_number].buffer);

	}

}


void OutPutSAM_Nounheader(_rg_name_l  *_ih_refGenName, int refChromeCont, int argc, char *argv[])
{
	fprintf(_out_fp, "@HD\tVN:1.4\tSO:unsorted\n");
	int i = 0;
	for (i = 0; i<refChromeCont; i++)
	{
		fprintf(_out_fp, "@SQ\tSN:%s\tLN:%u\n", _ih_refGenName[i]._rg_chrome_name, _ih_refGenName[i]._rg_chrome_length);
	}

	fprintf(_out_fp, "@PG\tID:BitMapperBS\tVN:%s\tCL:", versionN);
	for (size_t i = 0; i < argc; i++)
	{
		fprintf(_out_fp, "%s ", argv[i]);
	}

	fprintf(_out_fp, "\n");
}

FILE* get_Ouput_Dec()
{
    return _out_fp;
}


void multi_outputQ(SAM map, int thread_id)
{
    if(map.FLAG<=16)
    {
        fprintf(_out_fp, "%s\t%d\t%s\t%u\t%d\t%s\t%s\t%d\t%d\t%s\t%s",
	  map.QNAME,
	  map.FLAG,
	  map.RNAME,
	  map.POS,
	  map.MAPQ,
	  map.CIGAR,
	  map.MRNAME,
	  map.MPOS,
	  map.ISIZE,
	  map.SEQ,
	  map.QUAL);
    }
    else
    {
        fprintf(_out_fp, "%s\t%d\t%s\t%u\t%d\t%s\t%s\t%d\t%d\t%c\t%c",
	  map.QNAME,
	  map.FLAG,
	  map.RNAME,
	  map.POS,
	  map.MAPQ,
	  map.CIGAR,
	  map.MRNAME,
	  map.MPOS,
	  map.ISIZE,
	  '*',
	  '*');
    }
  int i;

  for ( i = 0; i < map.optSize; i++)
    {
      switch (map.optFields[i].type)
	{
	case 'A':
	  fprintf(_out_fp, "\t%s:%c:%c", map.optFields[i].tag, map.optFields[i].type, map.optFields[i].cVal);
	  break;
	case 'i':
	  fprintf(_out_fp, "\t%s:%c:%d", map.optFields[i].tag, map.optFields[i].type, map.optFields[i].iVal);
	  break;
	case 'f':
	  fprintf(_out_fp, "\t%s:%c:%f", map.optFields[i].tag, map.optFields[i].type, map.optFields[i].fVal);
	  break;
	case 'Z':
	case 'H':
	  fprintf(_out_fp, "\t%s:%c:%s", map.optFields[i].tag, map.optFields[i].type, map.optFields[i].sVal);
	  break;
	}
    }

  fprintf(_out_fp, "\n");
}






int Output_gene ( char *fileName)
{


    _out_fp = fopen (fileName, "w");
    char tmpFileName[NAME_LENGTH];

    if (_out_fp == NULL)
	{
	  return 0;
	}
    ///finalizeOutput = &finalizeTXOutput;

  return 1;
}

