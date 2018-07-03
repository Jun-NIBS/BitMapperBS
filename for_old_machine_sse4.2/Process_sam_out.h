/*
  Authors:
  Haoyu Cheng
	  chhy@mail.ustc.edu.cn
*/



#ifndef __OUTPUT__
#define __OUTPUT__

#define	FORWARD 0
#define REVERSE 1

#include "Schema.h"


typedef struct
{
  char		*tag;
  char		type;
  char		cVal;
  int		iVal;
  float		fVal;
  char		*sVal;
} OPT_FIELDS;

typedef struct
{
  char			*QNAME;
  short			FLAG;
  char			*RNAME;
  unsigned int			POS;
  unsigned char  	MAPQ;
  char			*CIGAR;
  char          *CIGAR_CHAR;
  int           *CIGAR_SIZE;
  char			*MRNAME;
  int			MPOS;
  int			ISIZE;
  char			*SEQ;
  char			*QUAL;
  int			optSize;
  OPT_FIELDS	        *optFields;
} SAM;

int Output_gene(char *fileName);
///void (*finalizeOutput)();
void finalizeOutput();
void multi_outputQ(SAM map, int thread_id);
FILE* get_Ouput_Dec();
void OutPutSAM_Nounheader(_rg_name_l  *_ih_refGenName, int refChromeCont, int argc, char *argv[]);

///��˫�˵�read
#define IS_PAIRED 1
///˫��read����Ҫ��ıȶ���(����һ������)
#define MATE_MAPPED 2
///read����û�бȶ���
#define SINGLE_UNMAPPED 4
///˫��readû�з���Ҫ��ıȶ���(����һ������)
#define MATE_UNMAPPED 8
///read����ȶԵ����򻥲���
#define RC_MAPPED 16
///˫��read����һ���ȶԵ����򻥲�����Ҳ���Ǹ�read����ȶԵ���������
#define RC_MATE_MAPPED 32
///˫��read�е�read1
#define READ1 64
///˫��read�е�read2
#define READ2 128
///��mutiple mapping
#define MUTIREAD 128


typedef struct
{
	char* buffer;
	long long size;
	long long length;

} Output_buffer_sub_block;


typedef struct
{
	Output_buffer_sub_block* sub_buffer;

	///��������λ��subblock
	long long sub_block_size;
	long long sub_block_number;
	int all_buffer_end = 0;

} Output_buffer;


void init_buffer_sub_block(Output_buffer_sub_block* sub_block);
void init_output_buffer(int thread_number);
void* pop_buffer(void*);
void push_results_to_buffer(Output_buffer_sub_block* sub_block);
void finish_output_buffer();


#define OFFSET 32
#define INT_LENGTH 20 //2^64 -1 = 18446744073709551615, ռ��20λ

///����ռ����Ķ�����������������һ��\t֮��Ĳ���Ҫ�ټ����
///������������char*,�ҳ��Ȳ�֪
inline void output_to_buffer_char_no_length(Output_buffer_sub_block* sub_block, char* input)
{
	


	int input_length = strlen(input);

	/**
	fprintf(stderr, "****inner_no_length****\nsub_block->length: %llu\n", sub_block->length);
	fflush(stderr);
	fprintf(stderr, "sub_block->size: %llu\n", sub_block->size);
	fflush(stderr);
	fprintf(stderr, "input_length: %llu\n", input_length);
	fflush(stderr);
	**/

	///������length
	sub_block->length = sub_block->length + input_length;

	///����ռ��㹻��,��size���ø���
	if (sub_block->length + OFFSET< sub_block->size)
	{
		memcpy(sub_block->buffer + sub_block->length - input_length, input, input_length);
		///sub_block->buffer[sub_block->length] = '\0';
	}
	else
	{
		///�ռ䲻����size��Ҫ����
		sub_block->size = (sub_block->length + OFFSET)* 2 + 1;
		char* tmp = (char*)malloc(sub_block->size);
		memcpy(tmp, sub_block->buffer, sub_block->length - input_length);
		free(sub_block->buffer);
		sub_block->buffer = tmp;
		memcpy(sub_block->buffer + sub_block->length - input_length, input, input_length);
		///sub_block->buffer[sub_block->length] = '\0';

	}

	/**
	fprintf(stderr, "hahahah\n");
	fflush(stderr);
	**/
}



///����ռ����Ķ�����������������һ��\t֮��Ĳ���Ҫ�ټ����
///������������char*,�ҳ�����֪
inline void output_to_buffer_char_length(Output_buffer_sub_block* sub_block, char* input, int input_length)
{
	/**
	fprintf(stderr, "****inner_length****\nsub_block->length: %llu\n", sub_block->length);
	fflush(stderr);
	fprintf(stderr, "sub_block->size: %llu\n", sub_block->size);
	fflush(stderr);
	fprintf(stderr, "input_length: %llu\n", input_length);
	fflush(stderr);
	**/

	///������length
	sub_block->length = sub_block->length + input_length;

	/**
	fprintf(stderr, "sub_block->length: %llu\n", sub_block->length);
	fflush(stderr);
	**/

	///����ռ��㹻��,��size���ø���
	if (sub_block->length + OFFSET< sub_block->size)
	{
		memcpy(sub_block->buffer + sub_block->length - input_length, input, input_length);
		///sub_block->buffer[sub_block->length] = '\0';
		/**
		fprintf(stderr, "xxxxxxxxxxx\n");
		fflush(stderr);
		**/
	}
	else
	{
		///�ռ䲻����size��Ҫ����
		sub_block->size = (sub_block->length + OFFSET) * 2 + 1;
		char* tmp = (char*)malloc(sub_block->size);
		memcpy(tmp, sub_block->buffer, sub_block->length - input_length);
		free(sub_block->buffer);
		sub_block->buffer = tmp;
		memcpy(sub_block->buffer + sub_block->length - input_length, input, input_length);
		///sub_block->buffer[sub_block->length] = '\0';

	}

	/**
	fprintf(stderr, "hahahah\n");
	fflush(stderr);
	**/
}






///����ռ����Ķ�����������������һ��\t֮��Ĳ���Ҫ�ټ����
///ע���������
inline void output_to_buffer_int(Output_buffer_sub_block* sub_block, bitmapper_bs_iter input)
{
	/**
	fprintf(stderr, "****inner_int****\nsub_block->length: %llu\n", sub_block->length);
	fflush(stderr);
	fprintf(stderr, "sub_block->size: %llu\n", sub_block->size);
	fflush(stderr);
	**/

	int input_int_length;
	//2^64 -1 = 18446744073709551615, ռ��20λ
	///����ռ��㹻��,��size���ø���
	if (sub_block->length + INT_LENGTH + OFFSET< sub_block->size)
	{
		sprintf(sub_block->buffer + sub_block->length, "%llu", input);
		input_int_length = strlen(sub_block->buffer + sub_block->length);
		sub_block->length = sub_block->length + input_int_length;
	}
	else
	{
		///�ռ䲻����size��Ҫ����
		sub_block->size = (sub_block->length + INT_LENGTH + OFFSET) * 2 + 1;
		char* tmp = (char*)malloc(sub_block->size);
		memcpy(tmp, sub_block->buffer, sub_block->length);
		free(sub_block->buffer);
		sub_block->buffer = tmp;

		sprintf(sub_block->buffer + sub_block->length, "%llu", input);
		input_int_length = strlen(sub_block->buffer + sub_block->length);
		sub_block->length = sub_block->length + input_int_length;

	}

	/**
	fprintf(stderr, "hahahah\n");
	fflush(stderr);
	**/
	
}



#endif
