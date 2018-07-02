


///g++ -O3 bam_prase.cpp -lhts -o bam_prase

#include"bam_prase.h"
#include <pthread.h>

bam_operations bitmapperBS_bam;
pthread_mutex_t queueMutex_bam;


void init_bam_header(char* tmp_sam_file_name, char* bam_file_name)
{

	samFile* in;
	in = sam_open(tmp_sam_file_name, "r");
	bitmapperBS_bam.bam_file = sam_open(bam_file_name, "wb");
	bitmapperBS_bam.bam_header = NULL;

	


	///����sam���ײ�
	if ((bitmapperBS_bam.bam_header = sam_hdr_read(in)) == 0) {
		fprintf(stderr, "fail to read %s\n", tmp_sam_file_name);
		return;
	}

	///д��sam���ײ�
	if (sam_hdr_write(bitmapperBS_bam.bam_file, bitmapperBS_bam.bam_header) != 0) {
		fprintf(stderr, "fail to write %s\n", bam_file_name);
		return;
	}

	///һ��Ҫ�رգ����صĻ�д�����ļ���ȥ
	sam_close(in);

}



void close_bam_file()
{
	if (bitmapperBS_bam.bam_header) 
		bam_hdr_destroy(bitmapperBS_bam.bam_header);

	///һ��Ҫ�رգ����صĻ�д�����ļ���ȥ
	sam_close(bitmapperBS_bam.bam_file);
}



void write_alignment(const char* alignment)
{


	kstring_t line;
	int r;

	line.l = strlen(alignment);
	if (line.l == 0)
	{
		return;

	}

	line.m = line.l;
	line.s = (char*)malloc(line.l + 1);
	memcpy(line.s, alignment, line.l + 1);

	bam1_t *b = bam_init1();  ///��ʼ����,�����ڴ�
	int ret = sam_parse1(&line, bitmapperBS_bam.bam_header, b);
	line.l = 0;
	sam_write1(bitmapperBS_bam.bam_file, bitmapperBS_bam.bam_header, b);
	free(line.s);

	bam_destroy1(b);   ///�ͷ��ڴ�
}


void write_alignment_muti_thread(const char* alignment)
{


	kstring_t line;
	int r;

	line.l = strlen(alignment);
	if (line.l == 0)
	{
		return;

	}

	line.m = line.l;
	line.s = (char*)malloc(line.l + 1);
	memcpy(line.s, alignment, line.l + 1);

	bam1_t *b = bam_init1();  ///��ʼ����,�����ڴ�
	int ret = sam_parse1(&line, bitmapperBS_bam.bam_header, b);
	line.l = 0;


	pthread_mutex_lock(&queueMutex_bam);
	sam_write1(bitmapperBS_bam.bam_file, bitmapperBS_bam.bam_header, b);
	pthread_mutex_unlock(&queueMutex_bam);


	
	free(line.s);

	bam_destroy1(b);   ///�ͷ��ڴ�
}


/**
void write_alignment(const char* alignment)
{
	

	kstring_t line;
	int r;

	///bitmapperBS_bam.bam_file->line.l = strlen(alignment);
	line.l = strlen(alignment);
	if (bitmapperBS_bam.bam_file->line.l == 0)
	{
		return;

	}

	bitmapperBS_bam.bam_file->line.m = bitmapperBS_bam.bam_file->line.l;
	bitmapperBS_bam.bam_file->line.s = (char*)malloc(bitmapperBS_bam.bam_file->line.l + 1);
	memcpy(bitmapperBS_bam.bam_file->line.s, alignment, bitmapperBS_bam.bam_file->line.l + 1);

	bam1_t *b = bam_init1();  ///��ʼ����,�����ڴ�
	int ret = sam_parse1(&bitmapperBS_bam.bam_file->line, bitmapperBS_bam.bam_header, b);
	bitmapperBS_bam.bam_file->line.l = 0;
	sam_write1(bitmapperBS_bam.bam_file, bitmapperBS_bam.bam_header, b);
	free(bitmapperBS_bam.bam_file->line.s);

	bam_destroy1(b);   ///�ͷ��ڴ�
}
**/


/**
int main(int argc, char **argv)
{

	///min_example_string_to_bam();

	init_bam_header("output.sam", "output.bam");
	write_alignment("SRR1532535.52049\t16\t4\t61322565\t255\t90M\t*\t0\t0\tAACAATCCCCCCACTTTAACTTCCCATAATACTAAAATAACAAACATAAATCACCACTCCTAATCCCCAATATTTCTTTTATATTAATTA\tCDCC><DDFHHGHEHIHIHHGFGJJIIJGGFIJJJJJIJJJJJIIJIJJJJIGIGEJJJJJJJIJJJJJJJJJJJJIHHHHHFFFFFCCC\tNM:i:0\tZS:Z:-+\0");
	close_bam_file();
}
**/