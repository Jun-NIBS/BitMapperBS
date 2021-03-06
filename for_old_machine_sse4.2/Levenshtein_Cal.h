/*
  Authors:
  Haoyu Cheng
	  chhy@mail.ustc.edu.cn
*/

#ifndef __LEVENSHTEIN_
#define __LEVENSHTEIN_

#include "Auxiliary.h"
#include <iostream>
#include "emmintrin.h"
#include "nmmintrin.h"
#include "smmintrin.h"
#include <immintrin.h>



///int each_length;
typedef uint64_t Word;
typedef uint16_t Small_Word;
typedef uint32_t Word_32;

///Word D0_arry_64[2000];
///Word HP_arry_64[2000];

///int Route_Size_Whole[2000];
///char Route_Char_Whole[2000];

///char err_match[2000];



inline void dec_bit(Word input)
{
	unsigned int bit_2[64];
	int i = 0;
	for (i = 0; i < 64; i++)
	{

		Word tmp = (Word)((Word)input&(Word)1);

		input = input >> 1;

		if (tmp == (Word)0)
		{
			bit_2[i] = 0;
		}
		else
		{
			bit_2[i] = 1;
		}
	}

	for (i = 63; i >= 0; i--)
	{

		fprintf(stderr, "%u", bit_2[i]);
	}

	fprintf(stderr, "\n");

}

int Calcu_Cigar_MD(int Peq_i, char *pattern, int p_length, char *text, int t_length,
	unsigned short errthold, unsigned short band_down, unsigned short band_below, unsigned short band_length, int err, int match_site, char* cigar, char* MD_Z, int thread_id);

int Brief_2_Banded_BPM_Non_SSE(char *pattern1,char *pattern2,int p_length,char *text,int t_length,
                              int* return_sites,int* return_sites_error,unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length, int thread_id);



int Brief_Reserve_Banded_BPM_4_high_SSE(char *pattern1,char *pattern2,char *pattern3,char *pattern4,int p_length,char *text,int t_length,
                int* return_sites,int* return_sites_error,unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length, int thread_id);
int Brief_Reserve_Banded_BPM_3_high_SSE(char *pattern1,char *pattern2,char *pattern3,int p_length,char *text,int t_length,
                int* return_sites,int* return_sites_error,unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length, int thread_id);

int Start_location_Brief_Reserve_Banded_BPM_4_high_SSE(char *pattern1,char *pattern2,char *pattern3,char *pattern4,int p_length,char *text,int t_length,
                int* return_sites,int* return_sites_error,unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length, int thread_id);
int Start_location_Brief_Reserve_Banded_BPM_3_high_SSE(char *pattern1,char *pattern2,char *pattern3,int p_length,char *text,int t_length,
                int* return_sites,int* return_sites_error,unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length, int thread_id);
int Start_location_Reserve_Banded_BPM_high(char *pattern,int p_length,char *text,int t_length,
                unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length,int* return_err, int thread_id);



int Start_location_Calcu_Cigar_MD(char *pattern,int p_length,char *text,int t_length,
                unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length,int pre_err, char* cigar,char* MD_Z,int thread_id,int return_site);


int Start_location_Brief_Reserve_Banded_BPM_8_SSE(char *pattern1,char *pattern2,char *pattern3,char *pattern4,char *pattern5,char *pattern6,char *pattern7,char *pattern8,int p_length,char *text,int t_length,
                int* return_sites,int* return_sites_error,unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length, int thread_id);

int Brief_Reserve_Banded_BPM_8_SSE(char *pattern1,char *pattern2,char *pattern3,char *pattern4,char *pattern5,char *pattern6,char *pattern7,char *pattern8,int p_length,char *text,int t_length,
                int* return_sites,int* return_sites_error,unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length, int thread_id);

int Brief_Reserve_Banded_BPM_7_SSE(char *pattern1,char *pattern2,char *pattern3,char *pattern4,char *pattern5,char *pattern6,char *pattern7,int p_length,char *text,int t_length,
                int* return_sites,int* return_sites_error,unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length, int thread_id);

int Start_location_Brief_Reserve_Banded_BPM_7_SSE(char *pattern1,char *pattern2,char *pattern3,char *pattern4,char *pattern5,char *pattern6,char *pattern7,int p_length,char *text,int t_length,
                int* return_sites,int* return_sites_error,unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length, int thread_id);

int Brief_Reserve_Banded_BPM_6_SSE(char *pattern1,char *pattern2,char *pattern3,char *pattern4,char *pattern5,char *pattern6,int p_length,char *text,int t_length,
                int* return_sites,int* return_sites_error,unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length, int thread_id);

int Start_location_Brief_Reserve_Banded_BPM_6_SSE(char *pattern1,char *pattern2,char *pattern3,char *pattern4,char *pattern5,char *pattern6,int p_length,char *text,int t_length,
                int* return_sites,int* return_sites_error,unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length, int thread_id);


int Brief_Reserve_Banded_BPM_5_SSE(char *pattern1,char *pattern2,char *pattern3,char *pattern4,char *pattern5,int p_length,char *text,int t_length,
                int* return_sites,int* return_sites_error,unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length, int thread_id);

int Start_location_Brief_Reserve_Banded_BPM_5_SSE(char *pattern1,char *pattern2,char *pattern3,char *pattern4,char *pattern5,int p_length,char *text,int t_length,
                int* return_sites,int* return_sites_error,unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length, int thread_id);


int Reserve_Banded_BPM(char *pattern,int p_length,char *text,int t_length,
                unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length,int* return_err, int thread_id);

int Start_location_Reserve_Banded_BPM(char *pattern,int p_length,char *text,int t_length,
                unsigned short errthold,unsigned short band_down,unsigned short band_below,unsigned short band_length,int* return_err, int thread_id);




/**************************************************单条比对***************************************************************************************************/

///这个程序实际就假设pattern里面有可能有N
inline int BS_Reserve_Banded_BPM_back
(char *pattern, int p_length, char *text, int t_length, unsigned short errthold, unsigned int* return_err)
{
	(*return_err) = (unsigned int)-1;

	///这个是那个需要预处理的向量
	Word Peq[256];

	int band_length = (errthold << 1) + 1;
	int i = 0;
	Word tmp_Peq_1 = (Word)1;

	Peq['A'] = (Word)0;
	Peq['T'] = (Word)0;
	Peq['G'] = (Word)0;
	Peq['C'] = (Word)0;


	Word Peq_A;
	Word Peq_T;
	Word Peq_C;
	Word Peq_G;

	///band_length = 2k + 1
	///这是把pattern的前2k + 1个字符预处理
	///pattern[0]对应Peq[0]
	///pattern[2k]对应Peq[2k]
	for (i = 0; i<band_length; i++)
	{
		Peq[pattern[i]] = Peq[pattern[i]] | tmp_Peq_1;
		tmp_Peq_1 = tmp_Peq_1 << 1;
	}

	Peq['T'] = Peq['T'] | Peq['C'];

	Peq_A = Peq['A'];
	Peq_C = Peq['C'];
	Peq_T = Peq['T'];
	Peq_G = Peq['G'];


	memset(Peq, 0, sizeof(Word)* 256);


	Peq['A'] = Peq_A;
	Peq['C'] = Peq_C;
	Peq['T'] = Peq_T;
	Peq['G'] = Peq_G;


	Word Mask = ((Word)1 << (errthold << 1));

	Word VP = 0;
	Word VN = 0;
	Word X = 0;
	Word D0 = 0;
	Word HN = 0;
	Word HP = 0;


	i = 0;

	int err = 0;

	Word err_mask = (Word)1;


	///band_down = 2k
	///i_bd = 2k
	///int i_bd = i + band_down;
	int i_bd = (errthold << 1);


	int last_high = (errthold << 1);


	/// t_length_1 = SEQ_LENGTH - 1
	int t_length_1 = t_length - 1;
	//while(i<t_length)

	while (i<t_length_1)
	{

		///pattern[0]在Peq[2k], 而pattern[2k]在Peq[0]
		X = Peq[text[i]] | VN;

		D0 = ((VP + (X&VP)) ^ VP) | X;

		HN = VP&D0;
		HP = VN | ~(VP | D0);

		X = D0 >> 1;
		VN = X&HP;
		VP = HN | ~(X | HP);
		///如果斜对角线方向匹配则D0是1
		///如果不匹配则D0是0
		///这个意思是如果最上面那条对角线上的斜对角线方向发生误配,则执行内部程序
		///
		if (!(D0&err_mask))
		{
			++err;

			///即使全部递减，也就减2k
			if ((err - last_high)>errthold)
				return -1;
		}

		///pattern[0]在Peq[2k], 而pattern[2k]在Peq[0]
		//右移实际上是把pattern[0]移掉了
		Peq['A'] = Peq['A'] >> 1;
		Peq['C'] = Peq['C'] >> 1;
		Peq['G'] = Peq['G'] >> 1;
		Peq['T'] = Peq['T'] >> 1;


		++i;
		++i_bd;
		///这是把新的pattern[2k]加进来, 这貌似是加到Peq[2k]上了
		Peq[pattern[i_bd]] = Peq[pattern[i_bd]] | Mask;


		Peq['T'] = Peq['T'] | Peq['C'];
	}


	///fprintf(stderr, "sucess(1)\n");


	///这个循环拿出来是为了防止内存泄露
	///其实也就是循环里的最后一行语句吧
	///完全可以把pattern增大一位
	///不过这样也好，可以减少计算开销
	X = Peq[text[i]] | VN;
	D0 = ((VP + (X&VP)) ^ VP) | X;
	HN = VP&D0;
	HP = VN | ~(VP | D0);
	X = D0 >> 1;
	VN = X&HP;
	VP = HN | ~(X | HP);
	if (!(D0&err_mask))
	{
		++err;
		if ((err - last_high)>errthold)
			return -1;
	}


	////fprintf(stderr, "sucess(2)\n");

	/// last_high = 2k
	/// site = (SEQ_LENGTH + 2k) - 2k -1
	/// site = SEQ_LENGTH - 1
	///此时这个site貌似是最上面那条对角线的位置
	///int site = p_length - last_high - 1;
	int site = t_length - 1;
	int return_site = -1;
	if ((err <= errthold) && (err<=*return_err))
	{
		*return_err = err;
		return_site = site;
	}
	int i_last = i;
	i = 0;

	while (i<errthold)
	{
		err = err + ((VP >> i)&(Word)1);
		err = err - ((VN >> i)&(Word)1);
		++i;

		if ((err <= errthold) && (err <= *return_err))
		{
			*return_err = err;
			return_site = site + i;
		}
	}


	unsigned int ungap_err;
	ungap_err = err;




	while (i<last_high)
	{
		err = err + ((VP >> i)&(Word)1);
		err = err - ((VN >> i)&(Word)1);
		++i;

		if ((err <= errthold) && (err<=*return_err))
		{
			*return_err = err;
			return_site = site + i;
		}


	}


	if ((ungap_err <= errthold) && (ungap_err == *return_err))
	{
		return_site = site + errthold;
	}


	return return_site;

}










/**************************************************单条比对***************************************************************************************************/

///这个程序实际就假设pattern里面有可能有N
inline int BS_Reserve_Banded_BPM
(char *pattern, int p_length, char *text, int t_length, unsigned short errthold, unsigned int* return_err)
{
	(*return_err) = (unsigned int)-1;

	///这个是那个需要预处理的向量
	Word Peq[256];

	int band_length = (errthold << 1) + 1;
	int i = 0;
	Word tmp_Peq_1 = (Word)1;

	Peq['A'] = (Word)0;
	Peq['T'] = (Word)0;
	Peq['G'] = (Word)0;
	Peq['C'] = (Word)0;


	Word Peq_A;
	Word Peq_T;
	Word Peq_C;
	Word Peq_G;

	///band_length = 2k + 1
	///这是把pattern的前2k + 1个字符预处理
	///pattern[0]对应Peq[0]
	///pattern[2k]对应Peq[2k]
	for (i = 0; i<band_length; i++)
	{
		Peq[pattern[i]] = Peq[pattern[i]] | tmp_Peq_1;
		tmp_Peq_1 = tmp_Peq_1 << 1;
	}

	Peq['T'] = Peq['T'] | Peq['C'];

	Peq_A = Peq['A'];
	Peq_C = Peq['C'];
	Peq_T = Peq['T'];
	Peq_G = Peq['G'];


	memset(Peq, 0, sizeof(Word)* 256);


	Peq['A'] = Peq_A;
	Peq['C'] = Peq_C;
	Peq['T'] = Peq_T;
	Peq['G'] = Peq_G;


	

	Word Mask = ((Word)1 << (errthold << 1));

	Word VP = 0;
	Word VN = 0;
	Word X = 0;
	Word D0 = 0;
	Word HN = 0;
	Word HP = 0;


	i = 0;

	int err = 0;

	Word err_mask = (Word)1;


	///band_down = 2k
	///i_bd = 2k
	///int i_bd = i + band_down;
	int i_bd = (errthold << 1);


	int last_high = (errthold << 1);


	/// t_length_1 = SEQ_LENGTH - 1
	int t_length_1 = t_length - 1;
	//while(i<t_length)

	while (i<t_length_1)
	{
		///pattern[0]在Peq[2k], 而pattern[2k]在Peq[0]
		X = Peq[text[i]] | VN;

		D0 = ((VP + (X&VP)) ^ VP) | X;

		HN = VP&D0;
		HP = VN | ~(VP | D0);

		X = D0 >> 1;
		VN = X&HP;
		VP = HN | ~(X | HP);
		///如果斜对角线方向匹配则D0是1
		///如果不匹配则D0是0
		///这个意思是如果最上面那条对角线上的斜对角线方向发生误配,则执行内部程序
		///
		if (!(D0&err_mask))
		{
			++err;

			///即使全部递减，也就减2k
			if ((err - last_high)>errthold)
				return -1;
		}

		///pattern[0]在Peq[2k], 而pattern[2k]在Peq[0]
		//右移实际上是把pattern[0]移掉了
		Peq['A'] = Peq['A'] >> 1;
		Peq['C'] = Peq['C'] >> 1;
		Peq['G'] = Peq['G'] >> 1;
		Peq['T'] = Peq['T'] >> 1;


		++i;
		++i_bd;
		///这是把新的pattern[2k]加进来, 这貌似是加到Peq[2k]上了
		Peq[pattern[i_bd]] = Peq[pattern[i_bd]] | Mask;


		Peq['T'] = Peq['T'] | Peq['C'];
	}




	///fprintf(stderr, "sucess(1)\n");


	///这个循环拿出来是为了防止内存泄露
	///其实也就是循环里的最后一行语句吧
	///完全可以把pattern增大一位
	///不过这样也好，可以减少计算开销
	X = Peq[text[i]] | VN;
	D0 = ((VP + (X&VP)) ^ VP) | X;
	HN = VP&D0;
	HP = VN | ~(VP | D0);
	X = D0 >> 1;
	VN = X&HP;
	VP = HN | ~(X | HP);
	if (!(D0&err_mask))
	{
		++err;
		if ((err - last_high)>errthold)
			return -1;
	}





	////fprintf(stderr, "sucess(2)\n");

	/// last_high = 2k
	/// site = (SEQ_LENGTH + 2k) - 2k -1
	/// site = SEQ_LENGTH - 1
	///此时这个site貌似是最上面那条对角线的位置
	///int site = p_length - last_high - 1;
	int site = t_length - 1;
	int return_site = -1;
	if ((err <= errthold) && (err<=*return_err))
	{
		*return_err = err;
		return_site = site;
	}
	int i_last = i;
	i = 0;




	while (i<errthold)
	{
		err = err + ((VP >> i)&(Word)1);
		err = err - ((VN >> i)&(Word)1);
		++i;

		if ((err <= errthold) && (err <= *return_err))
		{
			*return_err = err;
			return_site = site + i;
		}
	}


	unsigned int ungap_err;
	ungap_err = err;


	while (i<last_high)
	{
		err = err + ((VP >> i)&(Word)1);
		err = err - ((VN >> i)&(Word)1);
		++i;

		if ((err <= errthold) && (err<=*return_err))
		{
			*return_err = err;
			return_site = site + i;
		}




	}


	if ((ungap_err <= errthold) && (ungap_err == *return_err))
	{
		return_site = site + errthold;
	}

	return return_site;

}








/***************************************************2条比对**************************************************/
inline int BS_Reserve_Banded_BPM_2_SSE_back(char *pattern1, char *pattern2, int p_length, char *text, int t_length,
	int* return_sites, unsigned int* return_sites_error, unsigned short errthold)
{
	return_sites_error[0] = (unsigned int)-1;
	return_sites_error[1] = (unsigned int)-1;
    return_sites[0] = -1;
    return_sites[1] = -1;



	Word Peq[256][2];
	int band_length = (errthold << 1) + 1;

	__m128i Peq_SSE[256];

	int i;

	Word tmp_Peq_1 = 1;




	Peq['A'][0] = 0;
	Peq['A'][1] = 0;

	Peq['C'][0] = 0;
	Peq['C'][1] = 0;

	Peq['G'][0] = 0;
	Peq['G'][1] = 0;

	Peq['T'][0] = 0;
	Peq['T'][1] = 0;



	for (i = 0; i<band_length; i++)
	{
		Peq[pattern1[i]][0] = Peq[pattern1[i]][0] | tmp_Peq_1;
		Peq[pattern2[i]][1] = Peq[pattern2[i]][1] | tmp_Peq_1;

		tmp_Peq_1 = tmp_Peq_1 << 1;
	}

	Peq['T'][0] = Peq['T'][0] | Peq['C'][0];
	Peq['T'][1] = Peq['T'][1] | Peq['C'][1];


	for (i = 0; i < 256; i++)
	{
		Peq_SSE[i] = _mm_setzero_si128();
	}

	Peq_SSE['A'] = _mm_set_epi64x(Peq['A'][1], Peq['A'][0]);
	Peq_SSE['C'] = _mm_set_epi64x(Peq['C'][1], Peq['C'][0]);
	Peq_SSE['G'] = _mm_set_epi64x(Peq['G'][1], Peq['G'][0]);
	Peq_SSE['T'] = _mm_set_epi64x(Peq['T'][1], Peq['T'][0]);




	Word Mask = ((Word)1 << (errthold << 1));

	__m128i Mask1 = _mm_set_epi64x(0, Mask);
	__m128i Mask2 = _mm_set_epi64x(Mask, 0);

	__m128i VP = _mm_setzero_si128();
	__m128i VN = _mm_setzero_si128();
	__m128i X = _mm_setzero_si128();
	__m128i D0 = _mm_setzero_si128();
	__m128i HN = _mm_setzero_si128();
	__m128i HP = _mm_setzero_si128();
	__m128i tmp_process;
    __m128i tmp_process1;

	__m128i Err_2 = _mm_set_epi64x(0, 0);
	__m128i err_mask = _mm_set_epi64x(1, 1);
	///for_not li quan shi 1
	__m128i for_not=_mm_set1_epi32(-1);
	__m128i err_arry;
	__m128i cmp_result;




	/**********************************这个是为防止溢出****************************/
    Word a_mask=((Word)-1)>>(64-band_length);
    ///zui gao wei shi 0, fang zhi yi chu
    __m128i add_mask=_mm_set_epi64x(a_mask,a_mask);
    /******************************************************************************************/




	int i_bd = (errthold << 1);
	int last_high = (errthold << 1);
	int t_length_1 = t_length - 1;
	int err1;
    int err2;

	__m128i pre_end=_mm_set_epi64x(last_high+errthold,last_high+errthold);

    i=0;
	while (i<t_length_1)
	{


        ///X = Peq[text[i]] | VN;
		X = _mm_or_si128(Peq_SSE[text[i]], VN);



		/*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/
        ///X&VP
		tmp_process1 = _mm_and_si128(X, VP);
		/*****************************************下面这两步是纯粹防止溢出*************************/
		tmp_process1 = _mm_and_si128(tmp_process1, add_mask);
		VP = _mm_and_si128(VP, add_mask);
		/*************************************************************************************/
		///(VP + (X&VP))
		tmp_process = _mm_add_epi64(tmp_process1, VP);
		///((VP + (X&VP)) ^ VP)
		tmp_process = _mm_xor_si128(tmp_process, VP);
		///((VP + (X&VP)) ^ VP) | X
		D0 = _mm_or_si128(tmp_process, X);
        /*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/

        ///HN = VP&D0;
		HN = _mm_and_si128(D0, VP);

		///HP = VN | ~(VP | D0);
		tmp_process = _mm_or_si128(D0, VP);
		tmp_process = _mm_andnot_si128(tmp_process, for_not);
		HP = _mm_or_si128(tmp_process, VN);


        ///X = D0 >> 1;
		X = _mm_srli_epi64(D0, 1);
        ///VN = X&HP;
		VN = _mm_and_si128(X, HP);
		///VP = HN | ~(X | HP);
		tmp_process = _mm_or_si128(X, HP);
		tmp_process = _mm_andnot_si128(tmp_process, for_not);
		VP = _mm_or_si128(HN, tmp_process);

        ///D0&err_mask
		err_arry = _mm_and_si128(D0, err_mask);
		Err_2 = _mm_add_epi64(Err_2, err_mask);
		Err_2 = _mm_sub_epi64(Err_2, err_arry);

        ///shi ji shang zhe ge zhi hen xiao d
		cmp_result = _mm_cmpgt_epi64(Err_2, pre_end);

        ///jian zhi
		if (_mm_extract_epi64(cmp_result, 0) && _mm_extract_epi64(cmp_result, 1))
			return 1;

		Peq_SSE['A'] = _mm_srli_epi64(Peq_SSE['A'], 1);
		Peq_SSE['T'] = _mm_srli_epi64(Peq_SSE['T'], 1);
		Peq_SSE['G'] = _mm_srli_epi64(Peq_SSE['G'], 1);
		Peq_SSE['C'] = _mm_srli_epi64(Peq_SSE['C'], 1);

		++i;
		++i_bd;

		Peq_SSE[pattern1[i_bd]] = _mm_or_si128(Mask1, Peq_SSE[pattern1[i_bd]]);
		Peq_SSE[pattern2[i_bd]] = _mm_or_si128(Mask2, Peq_SSE[pattern2[i_bd]]);


		Peq_SSE['T'] = _mm_or_si128(Peq_SSE['T'], Peq_SSE['C']);

	}







        ///X = Peq[text[i]] | VN;
    X = _mm_or_si128(Peq_SSE[text[i]], VN);

    /*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/
    ///X&VP
    tmp_process1 = _mm_and_si128(X, VP);
    /*****************************************下面这两步是纯粹防止溢出*************************/
    tmp_process1 = _mm_and_si128(tmp_process1, add_mask);
    VP = _mm_and_si128(VP, add_mask);
    /*************************************************************************************/
    ///(VP + (X&VP))
    tmp_process = _mm_add_epi64(tmp_process1, VP);
    ///((VP + (X&VP)) ^ VP)
    tmp_process = _mm_xor_si128(tmp_process, VP);
    ///((VP + (X&VP)) ^ VP) | X
    D0 = _mm_or_si128(tmp_process, X);
    /*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/

    ///HN = VP&D0;
    HN = _mm_and_si128(D0, VP);

    ///HP = VN | ~(VP | D0);
    tmp_process = _mm_or_si128(D0, VP);
    tmp_process = _mm_andnot_si128(tmp_process, for_not);
    HP = _mm_or_si128(tmp_process, VN);


    ///X = D0 >> 1;
    X = _mm_srli_epi64(D0, 1);
    ///VN = X&HP;
    VN = _mm_and_si128(X, HP);
    ///VP = HN | ~(X | HP);
    tmp_process = _mm_or_si128(X, HP);
    tmp_process = _mm_andnot_si128(tmp_process, for_not);
    VP = _mm_or_si128(HN, tmp_process);

    ///D0&err_mask
    err_arry = _mm_and_si128(D0, err_mask);
    Err_2 = _mm_add_epi64(Err_2, err_mask);
    Err_2 = _mm_sub_epi64(Err_2, err_arry);

    ///shi ji shang zhe ge zhi hen xiao d
    cmp_result = _mm_cmpgt_epi64(Err_2, pre_end);

    ///jian zhi
    if (_mm_extract_epi64(cmp_result, 0) && _mm_extract_epi64(cmp_result, 1))
        return 1;









    int site = t_length - 1;
	err1=_mm_extract_epi64(Err_2,0);
    err2=_mm_extract_epi64(Err_2,1);

    if((err1<=errthold)&&(err1<=return_sites_error[0]))
    {
            return_sites[0]=site;
            return_sites_error[0]=err1;
    }
    if((err2<=errthold)&&(err2<=return_sites_error[1]))
    {
            return_sites[1]=site;
            return_sites_error[1]=err2;
    }

    i=0;



	while (i<errthold)
	{
		///err = err + ((VP >> i)&(Word)1);
		tmp_process = _mm_srli_epi64(VP, i);
		tmp_process = _mm_and_si128(tmp_process, err_mask);
		Err_2 = _mm_add_epi64(Err_2, tmp_process);

		///err = err - ((VN >> i)&(Word)1);
		tmp_process1 = _mm_srli_epi64(VN, i);
		tmp_process1 = _mm_and_si128(tmp_process1, err_mask);
		Err_2 = _mm_sub_epi64(Err_2, tmp_process1);
		++i;

		err1 = _mm_extract_epi64(Err_2, 0);
		err2 = _mm_extract_epi64(Err_2, 1);


		if ((err1 <= errthold) && (err1 <= return_sites_error[0]))
		{
			return_sites[0] = site + i;
			return_sites_error[0] = err1;
		}
		if ((err2 <= errthold) && (err2 <= return_sites_error[1]))
		{
			return_sites[1] = site + i;
			return_sites_error[1] = err2;
		}
	}



	unsigned int ungap_err1;
	unsigned int ungap_err2;

	ungap_err1 = err1;
	ungap_err2 = err2;



    while(i<last_high)
    {
        ///err = err + ((VP >> i)&(Word)1);
        tmp_process=_mm_srli_epi64(VP,i);
        tmp_process=_mm_and_si128(tmp_process,err_mask);
        Err_2=_mm_add_epi64(Err_2,tmp_process);

        ///err = err - ((VN >> i)&(Word)1);
        tmp_process1=_mm_srli_epi64(VN,i);
        tmp_process1=_mm_and_si128(tmp_process1,err_mask);
        Err_2=_mm_sub_epi64(Err_2,tmp_process1);
        ++i;

        err1=_mm_extract_epi64(Err_2,0);
        err2=_mm_extract_epi64(Err_2,1);


        if((err1<=errthold)&&(err1<=return_sites_error[0]))
        {
                return_sites[0]=site+i;
                return_sites_error[0]=err1;
        }
        if((err2<=errthold)&&(err2<=return_sites_error[1]))
        {
                return_sites[1]=site+i;
                return_sites_error[1]=err2;
        }
    }



	if ((ungap_err1 <= errthold) && ungap_err1 == return_sites_error[0])
	{
		return_sites[0] = site + errthold;
	}


	if ((ungap_err2 <= errthold) && ungap_err2 == return_sites_error[1])
	{
		return_sites[1] = site + errthold;
	}


	return 1;

}








/***************************************************2条比对**************************************************/
inline int BS_Reserve_Banded_BPM_2_SSE(char *pattern1, char *pattern2, int p_length, char *text, int t_length,
	int* return_sites, unsigned int* return_sites_error, unsigned short errthold)
{
	return_sites_error[0] = (unsigned int)-1;
    return_sites_error[1] = (unsigned int)-1;
    return_sites[0] = -1;
    return_sites[1] = -1;



	Word Peq[256][2];
	int band_length = (errthold << 1) + 1;

	__m128i Peq_SSE[256];

	int i;

	Word tmp_Peq_1 = 1;




	Peq['A'][0] = 0;
	Peq['A'][1] = 0;

	Peq['C'][0] = 0;
	Peq['C'][1] = 0;

	Peq['G'][0] = 0;
	Peq['G'][1] = 0;

	Peq['T'][0] = 0;
	Peq['T'][1] = 0;



	for (i = 0; i<band_length; i++)
	{
		Peq[pattern1[i]][0] = Peq[pattern1[i]][0] | tmp_Peq_1;
		Peq[pattern2[i]][1] = Peq[pattern2[i]][1] | tmp_Peq_1;

		tmp_Peq_1 = tmp_Peq_1 << 1;
	}

	Peq['T'][0] = Peq['T'][0] | Peq['C'][0];
	Peq['T'][1] = Peq['T'][1] | Peq['C'][1];


	for (i = 0; i < 256; i++)
	{
		Peq_SSE[i] = _mm_setzero_si128();
	}

	Peq_SSE['A'] = _mm_set_epi64x(Peq['A'][1], Peq['A'][0]);
	Peq_SSE['C'] = _mm_set_epi64x(Peq['C'][1], Peq['C'][0]);
	Peq_SSE['G'] = _mm_set_epi64x(Peq['G'][1], Peq['G'][0]);
	Peq_SSE['T'] = _mm_set_epi64x(Peq['T'][1], Peq['T'][0]);




	Word Mask = ((Word)1 << (errthold << 1));

	__m128i Mask1 = _mm_set_epi64x(0, Mask);
	__m128i Mask2 = _mm_set_epi64x(Mask, 0);

	__m128i VP = _mm_setzero_si128();
	__m128i VN = _mm_setzero_si128();
	__m128i X = _mm_setzero_si128();
	__m128i D0 = _mm_setzero_si128();
	__m128i HN = _mm_setzero_si128();
	__m128i HP = _mm_setzero_si128();
	__m128i tmp_process;
    __m128i tmp_process1;

	__m128i Err_2 = _mm_set_epi64x(0, 0);
	__m128i err_mask = _mm_set_epi64x(1, 1);
	///for_not li quan shi 1
	__m128i for_not=_mm_set1_epi32(-1);
	__m128i err_arry;
	__m128i cmp_result;







	int i_bd = (errthold << 1);
	int last_high = (errthold << 1);
	int t_length_1 = t_length - 1;
	int err1;
    int err2;

	__m128i pre_end=_mm_set_epi64x(last_high+errthold,last_high+errthold);

    i=0;
	while (i<t_length_1)
	{


        ///X = Peq[text[i]] | VN;
		X = _mm_or_si128(Peq_SSE[text[i]], VN);



		/*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/
        ///X&VP
		tmp_process1 = _mm_and_si128(X, VP);
		///(VP + (X&VP))
		tmp_process = _mm_add_epi64(tmp_process1, VP);
		///((VP + (X&VP)) ^ VP)
		tmp_process = _mm_xor_si128(tmp_process, VP);
		///((VP + (X&VP)) ^ VP) | X
		D0 = _mm_or_si128(tmp_process, X);
        /*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/

        ///HN = VP&D0;
		HN = _mm_and_si128(D0, VP);

		///HP = VN | ~(VP | D0);
		tmp_process = _mm_or_si128(D0, VP);
		tmp_process = _mm_andnot_si128(tmp_process, for_not);
		HP = _mm_or_si128(tmp_process, VN);


        ///X = D0 >> 1;
		X = _mm_srli_epi64(D0, 1);
        ///VN = X&HP;
		VN = _mm_and_si128(X, HP);
		///VP = HN | ~(X | HP);
		tmp_process = _mm_or_si128(X, HP);
		tmp_process = _mm_andnot_si128(tmp_process, for_not);
		VP = _mm_or_si128(HN, tmp_process);

        ///D0&err_mask
		err_arry = _mm_and_si128(D0, err_mask);
		Err_2 = _mm_add_epi64(Err_2, err_mask);
		Err_2 = _mm_sub_epi64(Err_2, err_arry);

        ///shi ji shang zhe ge zhi hen xiao d
		cmp_result = _mm_cmpgt_epi64(Err_2, pre_end);

        ///jian zhi
		if (_mm_extract_epi64(cmp_result, 0) && _mm_extract_epi64(cmp_result, 1))
			return 1;

		Peq_SSE['A'] = _mm_srli_epi64(Peq_SSE['A'], 1);
		Peq_SSE['T'] = _mm_srli_epi64(Peq_SSE['T'], 1);
		Peq_SSE['G'] = _mm_srli_epi64(Peq_SSE['G'], 1);
		Peq_SSE['C'] = _mm_srli_epi64(Peq_SSE['C'], 1);

		++i;
		++i_bd;

		Peq_SSE[pattern1[i_bd]] = _mm_or_si128(Mask1, Peq_SSE[pattern1[i_bd]]);
		Peq_SSE[pattern2[i_bd]] = _mm_or_si128(Mask2, Peq_SSE[pattern2[i_bd]]);


		Peq_SSE['T'] = _mm_or_si128(Peq_SSE['T'], Peq_SSE['C']);

	}







        ///X = Peq[text[i]] | VN;
    X = _mm_or_si128(Peq_SSE[text[i]], VN);

    /*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/
    ///X&VP
    tmp_process1 = _mm_and_si128(X, VP);
    ///(VP + (X&VP))
    tmp_process = _mm_add_epi64(tmp_process1, VP);
    ///((VP + (X&VP)) ^ VP)
    tmp_process = _mm_xor_si128(tmp_process, VP);
    ///((VP + (X&VP)) ^ VP) | X
    D0 = _mm_or_si128(tmp_process, X);
    /*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/

    ///HN = VP&D0;
    HN = _mm_and_si128(D0, VP);

    ///HP = VN | ~(VP | D0);
    tmp_process = _mm_or_si128(D0, VP);
    tmp_process = _mm_andnot_si128(tmp_process, for_not);
    HP = _mm_or_si128(tmp_process, VN);


    ///X = D0 >> 1;
    X = _mm_srli_epi64(D0, 1);
    ///VN = X&HP;
    VN = _mm_and_si128(X, HP);
    ///VP = HN | ~(X | HP);
    tmp_process = _mm_or_si128(X, HP);
    tmp_process = _mm_andnot_si128(tmp_process, for_not);
    VP = _mm_or_si128(HN, tmp_process);

    ///D0&err_mask
    err_arry = _mm_and_si128(D0, err_mask);
    Err_2 = _mm_add_epi64(Err_2, err_mask);
    Err_2 = _mm_sub_epi64(Err_2, err_arry);

    ///shi ji shang zhe ge zhi hen xiao d
    cmp_result = _mm_cmpgt_epi64(Err_2, pre_end);

    ///jian zhi
    if (_mm_extract_epi64(cmp_result, 0) && _mm_extract_epi64(cmp_result, 1))
        return 1;









    int site = t_length - 1;
	err1=_mm_extract_epi64(Err_2,0);
    err2=_mm_extract_epi64(Err_2,1);

    if((err1<=errthold)&&(err1<=return_sites_error[0]))
    {
            return_sites[0]=site;
            return_sites_error[0]=err1;
    }
    if((err2<=errthold)&&(err2<=return_sites_error[1]))
    {
            return_sites[1]=site;
            return_sites_error[1]=err2;
    }

    i=0;



	while (i<errthold)
	{
		///err = err + ((VP >> i)&(Word)1);
		tmp_process = _mm_srli_epi64(VP, i);
		tmp_process = _mm_and_si128(tmp_process, err_mask);
		Err_2 = _mm_add_epi64(Err_2, tmp_process);

		///err = err - ((VN >> i)&(Word)1);
		tmp_process1 = _mm_srli_epi64(VN, i);
		tmp_process1 = _mm_and_si128(tmp_process1, err_mask);
		Err_2 = _mm_sub_epi64(Err_2, tmp_process1);
		++i;

		err1 = _mm_extract_epi64(Err_2, 0);
		err2 = _mm_extract_epi64(Err_2, 1);


		if ((err1 <= errthold) && (err1 <= return_sites_error[0]))
		{
			return_sites[0] = site + i;
			return_sites_error[0] = err1;
		}
		if ((err2 <= errthold) && (err2 <= return_sites_error[1]))
		{
			return_sites[1] = site + i;
			return_sites_error[1] = err2;
		}
	}


	unsigned int ungap_err1;
	unsigned int ungap_err2;

	ungap_err1 = err1;
	ungap_err2 = err2;




    while(i<last_high)
    {
        ///err = err + ((VP >> i)&(Word)1);
        tmp_process=_mm_srli_epi64(VP,i);
        tmp_process=_mm_and_si128(tmp_process,err_mask);
        Err_2=_mm_add_epi64(Err_2,tmp_process);

        ///err = err - ((VN >> i)&(Word)1);
        tmp_process1=_mm_srli_epi64(VN,i);
        tmp_process1=_mm_and_si128(tmp_process1,err_mask);
        Err_2=_mm_sub_epi64(Err_2,tmp_process1);
        ++i;

        err1=_mm_extract_epi64(Err_2,0);
        err2=_mm_extract_epi64(Err_2,1);


        if((err1<=errthold)&&(err1<=return_sites_error[0]))
        {
                return_sites[0]=site+i;
                return_sites_error[0]=err1;
        }
        if((err2<=errthold)&&(err2<=return_sites_error[1]))
        {
                return_sites[1]=site+i;
                return_sites_error[1]=err2;
        }
    }



	if ((ungap_err1 <= errthold) && ungap_err1 == return_sites_error[0])
	{
		return_sites[0] = site + errthold;
	}


	if ((ungap_err2 <= errthold) && ungap_err2 == return_sites_error[1])
	{
		return_sites[1] = site + errthold;
	}




	return 1;

}



/*************************************************************************************************************************************************************************/








inline int bs_Calculate_Cigar(
	char *pattern, int p_length,
	char *text, int t_length,
	unsigned short errthold,
	int* return_err,
	char* cigar,
	uint16_t* matrix,
	int end_site,
	int* return_start_site,
	char* path
	)
{

	int start_site = end_site - t_length + 1;
	int i = 0;

	if ((*return_err) == 0)
	{
		///其实这里还要置位path, 要把path全部置为0
		(*return_start_site) = start_site;


		/**
		std::cerr << "start_site  : " << start_site << std::endl;
		std::cerr << "end_site    : " << end_site << std::endl;
		std::cerr << "return_err    : " << *return_err << std::endl;
		**/

		return 1;
	}




	if (start_site>=0)
	{

		int tmp_err = 0;

		for (i = 0; i<t_length; i++)
		{
			path[i] = 0;
			if (text[i] != pattern[i + start_site])
			{
				path[i] = 1;
				tmp_err++;
			}
		}

		if (tmp_err == (*return_err))
		{
			/**
			std::cerr << "start_site  : " << start_site << std::endl;
			std::cerr << "end_site    : " << end_site << std::endl;
			std::cerr << "return_err    : " << *return_err << std::endl;
			std::cerr << "Direction: ";


			for (i = 0; i < t_length; i++)
			{
				std::cerr << (int)path[i];

			}





			std::cerr << std::endl;

			**/





			for (i = 0; i < t_length; i++)
			{
				std::cerr << (int)path[i];

			}
			std::cerr << std::endl;











			(*return_start_site) = start_site;

			return 1;
		}



	}























	///这个是那个需要预处理的向量
	Word Peq[256];

	int band_length = (errthold << 1) + 1;
	///int i = 0;
	Word tmp_Peq_1 = (Word)1;

	Peq['A'] = (Word)0;
	Peq['T'] = (Word)0;
	Peq['G'] = (Word)0;
	Peq['C'] = (Word)0;


	Word Peq_A;
	Word Peq_T;
	Word Peq_C;
	Word Peq_G;

	///band_length = 2k + 1
	///这是把pattern的前2k + 1个字符预处理
	///pattern[0]对应Peq[0]
	///pattern[2k]对应Peq[2k]
	for (i = 0; i<band_length; i++)
	{
		Peq[pattern[i]] = Peq[pattern[i]] | tmp_Peq_1;
		tmp_Peq_1 = tmp_Peq_1 << 1;
	}

	Peq['T'] = Peq['T'] | Peq['C'];

	Peq_A = Peq['A'];
	Peq_C = Peq['C'];
	Peq_T = Peq['T'];
	Peq_G = Peq['G'];


	memset(Peq, 0, sizeof(Word)* 256);
	memset(matrix, 0, sizeof(uint16_t)*band_length);


	Peq['A'] = Peq_A;
	Peq['C'] = Peq_C;
	Peq['T'] = Peq_T;
	Peq['G'] = Peq_G;


	Word Mask = ((Word)1 << (errthold << 1));

	Word VP = 0;
	Word VN = 0;
	Word X = 0;
	Word D0 = 0;
	Word HN = 0;
	Word HP = 0;


	i = 0;

	int err = 0;

	Word err_mask = (Word)1;


	///band_down = 2k
	///i_bd = 2k
	///int i_bd = i + band_down;
	int i_bd = (errthold << 1);


	int last_high = (errthold << 1);


	/// t_length_1 = SEQ_LENGTH - 1
	int t_length_1 = t_length - 1;
	//while(i<t_length)

	Word inner_i;
	Word column_start;

	while (i<t_length_1)
	{

		///pattern[0]在Peq[2k], 而pattern[2k]在Peq[0]
		X = Peq[text[i]] | VN;

		D0 = ((VP + (X&VP)) ^ VP) | X;

		HN = VP&D0;
		HP = VN | ~(VP | D0);

		X = D0 >> 1;
		VN = X&HP;
		VP = HN | ~(X | HP);

		///pattern[0]在Peq[2k], 而pattern[2k]在Peq[0]
		//右移实际上是把pattern[0]移掉了
		Peq['A'] = Peq['A'] >> 1;
		Peq['C'] = Peq['C'] >> 1;
		Peq['G'] = Peq['G'] >> 1;
		Peq['T'] = Peq['T'] >> 1;


		++i;
		++i_bd;
		///这是把新的pattern[2k]加进来, 这貌似是加到Peq[2k]上了
		Peq[pattern[i_bd]] = Peq[pattern[i_bd]] | Mask;


		Peq['T'] = Peq['T'] | Peq['C'];


		column_start = i*band_length;

		for (inner_i = 0; inner_i < band_length; inner_i++)
		{
			matrix[column_start + inner_i] = matrix[column_start - band_length + inner_i] + (~(D0 >> inner_i)&err_mask);
		}

		/**
		if (strcmp(text, "AAAAAAAAAAATTAGTTGGGTATGGTGGTGCGTGTAGATCGGAAGAGCGGTTCAGCAGGAATGCCGAGACCGACATCGTATGCCGTCTTCTGCTTGAAAAA") == 0)
		{
			std::cerr << "-i: " << i << std::endl;
			std::cerr << "-D0: " << D0 << std::endl;
			std::cerr << "-VP: " << VP << std::endl;
			std::cerr << "-VN: " << VN << std::endl;
			std::cerr << "-HP: " << HP << std::endl;
			std::cerr << "-HN: " << HN << std::endl;
		}

		**/




	}


	///fprintf(stderr, "sucess(1)\n");


	///这个循环拿出来是为了防止内存泄露
	///其实也就是循环里的最后一行语句吧
	///完全可以把pattern增大一位
	///不过这样也好，可以减少计算开销
	X = Peq[text[i]] | VN;
	D0 = ((VP + (X&VP)) ^ VP) | X;
	HN = VP&D0;
	HP = VN | ~(VP | D0);
	X = D0 >> 1;
	VN = X&HP;
	VP = HN | ~(X | HP);






	///注意这里是(i+1)
	column_start = (i + 1)*band_length;

	for (inner_i = 0; inner_i < band_length; inner_i++)
	{
		matrix[column_start + inner_i] = matrix[column_start - band_length + inner_i] + (~(D0 >> inner_i)&err_mask);
	}

























	int back_track_site = band_length - (p_length - end_site);







	/**
	if (strcmp(text, "AAAAAAAAAAATTAGTTGGGTATGGTGGTGCGTGTAGATCGGAAGAGCGGTTCAGCAGGAATGCCGAGACCGACATCGTATGCCGTCTTCTGCTTGAAAAA") == 0)
	{

		int min_error = 999;
		int min_index = -1;

		for (inner_i = 0; inner_i < band_length; inner_i++)
		{
			if (matrix[column_start + inner_i]< min_error)
			{
				min_error = matrix[column_start + inner_i];
				min_index = inner_i;
			}
		}



		std::cerr << "Matrix: " << std::endl;


		for (i = 0; i < t_length + 1; i++)
		{
			std::cerr << "i: " << i << std::endl;

			column_start = i*band_length;

			for (inner_i = 0; inner_i < band_length; inner_i++)
			{
				std::cerr << matrix[column_start + inner_i] << " ";
			}

			std::cerr << std::endl;
		}


		std::cerr << "min_error  : " << min_error << std::endl;
		std::cerr << "min_index  : " << min_index << std::endl;
		std::cerr << "back_track_site  : " << back_track_site << std::endl;

	}

	**/














	///char cigar[1000];

	Word v_value, h_value, delta_value, min_value;
	Word direction, is_mismatch; ///0 is match, 1 is mismatch, 2 is xiang shang, 3 is shuiping

	i = t_length;
	int path_length = 0;
	start_site = end_site;


	//Word path_site[1000];


    int low_bound = band_length-1;

	while (i>0)
	{

		column_start = i * band_length;

		///h_value = matrix[column_start - band_length + back_track_site + 1];
		delta_value = matrix[column_start - band_length + back_track_site];


        if(back_track_site == 0)
        {
            h_value = matrix[column_start - band_length + back_track_site + 1];

            min_value = delta_value;
			direction = 0;

			if (h_value < min_value)
			{
				min_value = h_value;
				direction = 3;
			}

        }
        else if(back_track_site == low_bound)
        {
            v_value = matrix[column_start + back_track_site - 1];

            min_value = delta_value;
		    direction = 0;

			if (v_value < min_value)
			{
				min_value = v_value;
				direction = 2;
			}

        }
        else
        {
            h_value = matrix[column_start - band_length + back_track_site + 1];
            v_value = matrix[column_start + back_track_site - 1];


            min_value = delta_value;
	        direction = 0;

			if (v_value < min_value)
			{
				min_value = v_value;
				direction = 2;
			}


			if (h_value < min_value)
			{
				min_value = h_value;
				direction = 3;
			}

        }





		/**
		if(strcmp(text, "AAAAAAAAAAATTAGTTGGGTATGGTGGTGCGTGTAGATCGGAAGAGCGGTTCAGCAGGAATGCCGAGACCGACATCGTATGCCGTCTTCTGCTTGAAAAA") == 0)
		{

		std::cerr << "i: " << i << std::endl;

		std::cerr << "start_site : " << start_site << std::endl;
		std::cerr << "back_track_site: " << back_track_site << std::endl;

		std::cerr << "delta_value : " << delta_value << std::endl;
		std::cerr << "h_value : " << h_value << std::endl;
		std::cerr << "v_value : " << v_value << std::endl;
		std::cerr << "c_value : " << matrix[column_start + back_track_site] << std::endl;
		std::cerr << "min_value : " << min_value << std::endl;

		}

		**/




		if (direction == 0)
		{

			if (delta_value != matrix[column_start + back_track_site])
			{
				direction = 1;
			}

			i--;

			start_site--;

		}
		if (direction == 2)///ru guo xiang shang yi dong, bing bu huan lie
		{
			back_track_site--;
			start_site--;
		}
		else if (direction == 3)///ru guo xiang zuo yi dong
		{
			i--;
			back_track_site++;
		}


		path[path_length++] = direction;



		/**
		if(strcmp(text, "AAAAAAAAAAATTAGTTGGGTATGGTGGTGCGTGTAGATCGGAAGAGCGGTTCAGCAGGAATGCCGAGACCGACATCGTATGCCGTCTTCTGCTTGAAAAA") == 0)
		{
		std::cerr << "direction: " << direction << std::endl;
		std::cerr << "*************************************" << std::endl;

		}
		**/


	}

	if (direction != 3)
	{
		start_site++;
	}
	(*return_start_site) = start_site;



        ///if(strcmp(text, "AAAAAAAAATTATATATGATATATATTATAGGTTATGTGTTATGTTTTATATGTAATATATAATTTCATATATTTTATATGTTATATATAATTTTTTTTTA") == 0)

	///if (*return_err>20)
	/**
	if (strcmp(text, "AAAAAAAAAAATTAGTTGGGTATGGTGGTGCGTGTAGATCGGAAGAGCGGTTCAGCAGGAATGCCGAGACCGACATCGTATGCCGTCTTCTGCTTGAAAAA") == 0)
	   {

		std::cerr << "start_site  : " << start_site << std::endl;
		std::cerr << "end_site    : " << end_site << std::endl;
		std::cerr << "return_err    : " << *return_err << std::endl;
		std::cerr << "path_length : " << path_length << std::endl;
		std::cerr << "Direction: ";


		int debug_err = 0;;

		for (i = path_length - 1; i >= 0; i--)
		{
			std::cerr << (int)path[i];

			if ((int)path[i] != 0)
			{
				debug_err++;
			}
		}





		std::cerr << std::endl;


		if (debug_err != *(return_err))
		{
			std::cerr << "ERROR: debug_err = " << debug_err << " return_err = " << *(return_err) << std::endl;
		}
         }


         **/

        /**
        int debug_err = 0;;

		for (i = path_length - 1; i >= 0; i--)
		{
			///std::cerr << (int)path[i];

			if ((int)path[i] != 0)
			{
				debug_err++;
			}
		}





		///std::cerr << std::endl;


		if (debug_err != *(return_err))
		{
			std::cerr << "ERROR: debug_err = " << debug_err << " return_err = " << *(return_err) << std::endl;
		}
         **/







	int debug_err = 0;;

	for (i = path_length - 1; i >= 0; i--)
	{
		std::cerr << (int)path[i];

		if ((int)path[i] != 0)
		{
			debug_err++;
		}
	}





	std::cerr << std::endl;


	if (debug_err != *(return_err))
	{
		std::cerr << "ERROR: debug_err = " << debug_err << " return_err = " << *(return_err) << std::endl;
	}






	return 1;














}







inline int fast_bs_Calculate_Cigar(
	char *pattern, int p_length,
	char *text, int t_length,
	unsigned short errthold,
	unsigned int* return_err,
	char* cigar,
	int end_site,
	int* return_start_site,
	char* path,
	int* return_path_length,
	Word* matrix_bit
	)
{

	int start_site = end_site - t_length + 1;
	int i = 0;
	int tmp_err = 0;

	if ((*return_err) == 0)
	{
		///其实这里还要置位path, 要把path全部置为0
		(*return_start_site) = start_site;



		return 1;
	}




	if (start_site >= 0)
	{



		for (i = 0; i<t_length; i++)
		{
			///path[i] = 0;
			path[t_length - i - 1] = 0;
			if (text[i] != pattern[i + start_site])
			{

				if (!(text[i] == 'T' && pattern[i + start_site] == 'C'))
				{
					path[t_length - i - 1] = 1;
					tmp_err++;
				}



			}
		}






		if (tmp_err == (*return_err))
		{


			(*return_path_length) = t_length;

			(*return_start_site) = start_site;

			return 6;
		}






	}



	///这个是那个需要预处理的向量
	Word Peq[256];

	int band_length = (errthold << 1) + 1;
	///int i = 0;
	Word tmp_Peq_1 = (Word)1;

	Peq['A'] = (Word)0;
	Peq['T'] = (Word)0;
	Peq['G'] = (Word)0;
	Peq['C'] = (Word)0;


	Word Peq_A;
	Word Peq_T;
	Word Peq_C;
	Word Peq_G;

	///band_length = 2k + 1
	///这是把pattern的前2k + 1个字符预处理
	///pattern[0]对应Peq[0]
	///pattern[2k]对应Peq[2k]
	for (i = 0; i<band_length; i++)
	{
		Peq[pattern[i]] = Peq[pattern[i]] | tmp_Peq_1;
		tmp_Peq_1 = tmp_Peq_1 << 1;
	}

	Peq['T'] = Peq['T'] | Peq['C'];

	Peq_A = Peq['A'];
	Peq_C = Peq['C'];
	Peq_T = Peq['T'];
	Peq_G = Peq['G'];


	memset(Peq, 0, sizeof(Word)* 256);


	Peq['A'] = Peq_A;
	Peq['C'] = Peq_C;
	Peq['T'] = Peq_T;
	Peq['G'] = Peq_G;


	Word Mask = ((Word)1 << (errthold << 1));

	Word VP = 0;
	Word VN = 0;
	Word X = 0;
	Word D0 = 0;
	Word HN = 0;
	Word HP = 0;


	i = 0;

	int err = 0;

	Word err_mask = (Word)1;


	///band_down = 2k
	///i_bd = 2k
	///int i_bd = i + band_down;
	int i_bd = (errthold << 1);


	int last_high = (errthold << 1);


	/// t_length_1 = SEQ_LENGTH - 1
	int t_length_1 = t_length - 1;
	//while(i<t_length)

	///Word inner_i;
	Word column_start;

	while (i<t_length_1)
	{


		///pattern[0]在Peq[2k], 而pattern[2k]在Peq[0]
		X = Peq[text[i]] | VN;



		D0 = ((VP + (X&VP)) ^ VP) | X;




		HN = VP&D0;



		HP = VN | ~(VP | D0);


		X = D0 >> 1;


		VN = X&HP;


		VP = HN | ~(X | HP);

		///pattern[0]在Peq[2k], 而pattern[2k]在Peq[0]
		//右移实际上是把pattern[0]移掉了
		Peq['A'] = Peq['A'] >> 1;
		Peq['C'] = Peq['C'] >> 1;
		Peq['G'] = Peq['G'] >> 1;
		Peq['T'] = Peq['T'] >> 1;


		++i;
		++i_bd;
		///这是把新的pattern[2k]加进来, 这貌似是加到Peq[2k]上了
		Peq[pattern[i_bd]] = Peq[pattern[i_bd]] | Mask;


		Peq['T'] = Peq['T'] | Peq['C'];

		///每8个元素一存
		column_start = i << 3;

		matrix_bit[column_start] = D0;
		matrix_bit[column_start + 1] = VP;
		matrix_bit[column_start + 2] = VN;
		matrix_bit[column_start + 3] = HP;
		matrix_bit[column_start + 4] = HN;



	}



	///这个循环拿出来是为了防止内存泄露
	///其实也就是循环里的最后一行语句吧
	///完全可以把pattern增大一位
	///不过这样也好，可以减少计算开销
	X = Peq[text[i]] | VN;
	D0 = ((VP + (X&VP)) ^ VP) | X;
	HN = VP&D0;
	HP = VN | ~(VP | D0);
	X = D0 >> 1;
	VN = X&HP;
	VP = HN | ~(X | HP);


	///每8个元素一存
	column_start = (i + 1) << 3;

	matrix_bit[column_start] = D0;
	matrix_bit[column_start + 1] = VP;
	matrix_bit[column_start + 2] = VN;
	matrix_bit[column_start + 3] = HP;
	matrix_bit[column_start + 4] = HN;





	int back_track_site = band_length - (p_length - end_site);

	Word v_value, h_value, delta_value, min_value, current_value;
	Word direction, is_mismatch; ///0 is match, 1 is mismatch, 2 is xiang shang, 3 is shuiping

	i = t_length;
	int path_length = 0;
	start_site = end_site;

	current_value = *return_err;


	int low_bound = band_length - 1;

	while (i>0)
	{
		if (current_value == 0)
		{
			break;
		}

		///每8个元素一存
		column_start = i << 3;


		///如果斜对角线方向匹配则D0是1
		///所以当D0是1, 减0
		///D0是0, 减1
		delta_value = current_value -
			((~(matrix_bit[column_start] >> back_track_site))&err_mask);


		if (back_track_site == 0)
		{
			///HP
			h_value = current_value - ((matrix_bit[column_start + 3] >> back_track_site)&err_mask);
			//HN
			h_value = h_value + ((matrix_bit[column_start + 4] >> back_track_site)&err_mask);






			min_value = delta_value;
			direction = 0;

			if (h_value < min_value)
			{
				min_value = h_value;
				direction = 3;
			}

		}
		else if (back_track_site == low_bound)
		{
			v_value = current_value - ((matrix_bit[column_start + 1] >> (back_track_site - 1))&err_mask);
			v_value = v_value + ((matrix_bit[column_start + 2] >> (back_track_site - 1))&err_mask);

			min_value = delta_value;
			direction = 0;

			if (v_value < min_value)
			{
				min_value = v_value;
				direction = 2;
			}

		}
		else
		{

			h_value = current_value - ((matrix_bit[column_start + 3] >> back_track_site)&(Word)1);


			h_value = h_value + ((matrix_bit[column_start + 4] >> back_track_site)&(Word)1);


			v_value = current_value - ((matrix_bit[column_start + 1] >> (back_track_site - 1))&err_mask);
			v_value = v_value + ((matrix_bit[column_start + 2] >> (back_track_site - 1))&err_mask);


			min_value = delta_value;
			direction = 0;

			if (v_value < min_value)
			{
				min_value = v_value;
				direction = 2;
			}


			if (h_value < min_value)
			{
				min_value = h_value;
				direction = 3;
			}

		}


		if (direction == 0)
		{

			if (delta_value != current_value)
			{
				direction = 1;
			}

			i--;

			start_site--;

		}
		if (direction == 2)///ru guo xiang shang yi dong, bing bu huan lie
		{
			back_track_site--;
			start_site--;
		}
		else if (direction == 3)///ru guo xiang zuo yi dong
		{
			i--;
			back_track_site++;
		}


		path[path_length++] = direction;


		current_value = min_value;

	}


	if (i > 0)
	{
		memset(path + path_length, 0, i);
		start_site = start_site - i;
		direction = 0;
		path_length = path_length + i;
	}

	/**
	while (i > 0)
	{
	path[path_length++] = 0;
	i--;
	start_site--;
	direction = 0;

	}
	**/

	if (direction != 3)
	{
		start_site++;
	}
	(*return_start_site) = start_site;
	(*return_path_length) = path_length;




	return 1;
}









inline int fast_bs_Calculate_Cigar_back(
	char *pattern, int p_length,
	char *text, int t_length,
	unsigned short errthold,
	unsigned int* return_err,
	char* cigar,
	int end_site,
	int* return_start_site,
	char* path,
        int* return_path_length,
	Word* matrix_bit
	)
{

	int start_site = end_site - t_length + 1;
	int i = 0;
	int tmp_err = 0;

	if ((*return_err) == 0)
	{
		///其实这里还要置位path, 要把path全部置为0
		(*return_start_site) = start_site;



		return 1;
	}




	if (start_site >= 0)
	{



		for (i = 0; i<t_length; i++)
		{
			///path[i] = 0;
			path[t_length - i - 1] = 0;
			if (text[i] != pattern[i + start_site])
			{

				if (!(text[i] == 'T' && pattern[i + start_site] == 'C'))
				{
					path[t_length - i - 1] = 1;
					tmp_err++;
				}



			}
		}






		if (tmp_err == (*return_err))
		{


            (*return_path_length) = t_length;

			(*return_start_site) = start_site;

			return 6;
		}






	}



	///这个是那个需要预处理的向量
	Word Peq[256];

	int band_length = (errthold << 1) + 1;
	///int i = 0;
	Word tmp_Peq_1 = (Word)1;

	Peq['A'] = (Word)0;
	Peq['T'] = (Word)0;
	Peq['G'] = (Word)0;
	Peq['C'] = (Word)0;


	Word Peq_A;
	Word Peq_T;
	Word Peq_C;
	Word Peq_G;

	///band_length = 2k + 1
	///这是把pattern的前2k + 1个字符预处理
	///pattern[0]对应Peq[0]
	///pattern[2k]对应Peq[2k]
	for (i = 0; i<band_length; i++)
	{
		Peq[pattern[i]] = Peq[pattern[i]] | tmp_Peq_1;
		tmp_Peq_1 = tmp_Peq_1 << 1;
	}

	Peq['T'] = Peq['T'] | Peq['C'];

	Peq_A = Peq['A'];
	Peq_C = Peq['C'];
	Peq_T = Peq['T'];
	Peq_G = Peq['G'];


	memset(Peq, 0, sizeof(Word)* 256);


	Peq['A'] = Peq_A;
	Peq['C'] = Peq_C;
	Peq['T'] = Peq_T;
	Peq['G'] = Peq_G;


	Word Mask = ((Word)1 << (errthold << 1));

	Word VP = 0;
	Word VN = 0;
	Word X = 0;
	Word D0 = 0;
	Word HN = 0;
	Word HP = 0;


	i = 0;

	int err = 0;

	Word err_mask = (Word)1;


	///band_down = 2k
	///i_bd = 2k
	///int i_bd = i + band_down;
	int i_bd = (errthold << 1);


	int last_high = (errthold << 1);


	/// t_length_1 = SEQ_LENGTH - 1
	int t_length_1 = t_length - 1;
	//while(i<t_length)

	///Word inner_i;
	Word column_start;

	while (i<t_length_1)
	{


		///pattern[0]在Peq[2k], 而pattern[2k]在Peq[0]
		X = Peq[text[i]] | VN;



		D0 = ((VP + (X&VP)) ^ VP) | X;




		HN = VP&D0;



		HP = VN | ~(VP | D0);


		X = D0 >> 1;


		VN = X&HP;


		VP = HN | ~(X | HP);

		///pattern[0]在Peq[2k], 而pattern[2k]在Peq[0]
		//右移实际上是把pattern[0]移掉了
		Peq['A'] = Peq['A'] >> 1;
		Peq['C'] = Peq['C'] >> 1;
		Peq['G'] = Peq['G'] >> 1;
		Peq['T'] = Peq['T'] >> 1;


		++i;
		++i_bd;
		///这是把新的pattern[2k]加进来, 这貌似是加到Peq[2k]上了
		Peq[pattern[i_bd]] = Peq[pattern[i_bd]] | Mask;


		Peq['T'] = Peq['T'] | Peq['C'];

		///每8个元素一存
		column_start = i << 3;

		matrix_bit[column_start] = D0;
		matrix_bit[column_start + 1] = VP;
		matrix_bit[column_start + 2] = VN;
		matrix_bit[column_start + 3] = HP;
		matrix_bit[column_start + 4] = HN;

		/**
		if (strcmp("NCATGGGATTATAGGCGTGAGTTATTGTGTTTGGTTTTATTTTTTTAATGGGAATTTTAGTTTTATAAGAGTTGTAGTTTGATTTAGAGTTTGTGTTAGTTAGTGGAATAGATGTATTTTATATTTGTAGTATTAGGG", text) == 0)
		{
			fprintf(stderr, "i: %d\n", i);
			dec_bit(matrix_bit[column_start + 3]);
			dec_bit(matrix_bit[column_start + 4]);
			dec_bit(HP);
			dec_bit(HN);

		}
		**/




	}



	///这个循环拿出来是为了防止内存泄露
	///其实也就是循环里的最后一行语句吧
	///完全可以把pattern增大一位
	///不过这样也好，可以减少计算开销
	X = Peq[text[i]] | VN;
	D0 = ((VP + (X&VP)) ^ VP) | X;
	HN = VP&D0;
	HP = VN | ~(VP | D0);
	X = D0 >> 1;
	VN = X&HP;
	VP = HN | ~(X | HP);


	///每8个元素一存
	column_start = (i + 1) << 3;

	matrix_bit[column_start] = D0;
	matrix_bit[column_start + 1] = VP;
	matrix_bit[column_start + 2] = VN;
	matrix_bit[column_start + 3] = HP;
	matrix_bit[column_start + 4] = HN;





	int back_track_site = band_length - (p_length - end_site);

	Word v_value, h_value, delta_value, min_value, current_value;
	Word direction, is_mismatch; ///0 is match, 1 is mismatch, 2 is xiang shang, 3 is shuiping
	Word pre_direction = 0;

	i = t_length;
	int path_length = 0;
	start_site = end_site;
	

	current_value = *return_err;


	int low_bound = band_length - 1;

	pre_direction = 0;
	direction = 0;

	while (i>0)
	{
		if (current_value == 0)
		{
			break;
		}

		///每8个元素一存
		column_start = i << 3;


		///如果斜对角线方向匹配则D0是1
		///所以当D0是1, 减0
		///D0是0, 减1
		delta_value = current_value -
			((~(matrix_bit[column_start] >> back_track_site))&err_mask);


		if (back_track_site == 0)
		{
			///HP
			h_value = current_value - ((matrix_bit[column_start + 3] >> back_track_site)&err_mask);
			//HN
			h_value = h_value + ((matrix_bit[column_start + 4] >> back_track_site)&err_mask);






			min_value = delta_value;
			direction = 0;

			if (h_value < min_value)
			{
				min_value = h_value;
				direction = 3;
			}

		}
		else if (back_track_site == low_bound)
		{
			v_value = current_value - ((matrix_bit[column_start + 1] >> (back_track_site - 1))&err_mask);
			v_value = v_value + ((matrix_bit[column_start + 2] >> (back_track_site - 1))&err_mask);

			min_value = delta_value;
			direction = 0;

			if (v_value < min_value)
			{
				min_value = v_value;
				direction = 2;
			}

		}
		else
		{

			h_value = current_value - ((matrix_bit[column_start + 3] >> back_track_site)&(Word)1);


			h_value = h_value + ((matrix_bit[column_start + 4] >> back_track_site)&(Word)1);

	
			v_value = current_value - ((matrix_bit[column_start + 1] >> (back_track_site - 1))&err_mask);
			v_value = v_value + ((matrix_bit[column_start + 2] >> (back_track_site - 1))&err_mask);


			min_value = delta_value;
			direction = 0;

			///if (v_value < min_value)
			if ((v_value < min_value)
				||
				(v_value != current_value && pre_direction == 2 && v_value == min_value))
			{
				min_value = v_value;
				direction = 2;
			}
			
			
			

			/**
			if (strcmp("NCATGGGATTATAGGCGTGAGTTATTGTGTTTGGTTTTATTTTTTTAATGGGAATTTTAGTTTTATAAGAGTTGTAGTTTGATTTAGAGTTTGTGTTAGTTAGTGGAATAGATGTATTTTATATTTGTAGTATTAGGG", text) == 0)
			{
				fprintf(stderr, "\npath_length: %d\n", path_length);
				
				fprintf(stderr, "current_value: %d\n", current_value);
				fprintf(stderr, "delta_value: %d\n", delta_value);
				fprintf(stderr, "h_value: %d\n", h_value);
				fprintf(stderr, "min_value: %d\n", min_value);
				fprintf(stderr, "pre_direction: %d\n", pre_direction);
				fprintf(stderr, "back_track_site: %d\n", back_track_site);
				fprintf(stderr, "low_bound: %d\n", low_bound);
				fprintf(stderr, "i: %d\n", i);
				dec_bit(matrix_bit[column_start + 3]);
				dec_bit(matrix_bit[column_start + 4]);
				
			}
			**/


			///if (h_value < min_value)
			if ((h_value < min_value)
				||
				(h_value != current_value && pre_direction == 3 && h_value == min_value))
			{
				min_value = h_value;
				direction = 3;
			}


			

			

		}


		if (direction == 0)
		{

			if (delta_value != current_value)
			{
				direction = 1;
			}

			i--;

			start_site--;

		}
		if (direction == 2)///ru guo xiang shang yi dong, bing bu huan lie
		{
			back_track_site--;
			start_site--;
		}
		else if (direction == 3)///ru guo xiang zuo yi dong
		{
			i--;
			back_track_site++;
		}


		path[path_length++] = direction;


		current_value = min_value;

		pre_direction = direction;

	}

	
	if (i > 0)
	{
		memset(path + path_length, 0, i);
		start_site = start_site - i;
		direction = 0;
		path_length = path_length + i;
	}
	
	/**
	while (i > 0)
	{
		path[path_length++] = 0;
		i--;
		start_site--;
		direction = 0;

	}
	**/

	if (direction != 3)
	{
		start_site++;
	}
	(*return_start_site) = start_site;
    (*return_path_length) = path_length;




	return 1;
}









inline int fast_bs_Calculate_Cigar_score(
	char *pattern, int p_length,
	char *text, int t_length,
	unsigned short errthold,
	int* return_err,
	char* cigar,
	int end_site,
	int* return_start_site,
	char* path,
	int* return_path_length,
	Word* matrix_bit,
	int* local_score
	)
{

	int start_site = end_site - t_length + 1;
	int i = 0;
	int tmp_err = 0;

	int ma = 2;
	int mp = 6;
	int gap_open = 5;
	int gap_extension = 3;

	if ((*return_err) == 0)
	{
		///其实这里还要置位path, 要把path全部置为0
		(*return_start_site) = start_site;

		return 1;
	}




	if (start_site >= 0)
	{

		///第一个字符单独拿出来处理

		for (i = 0; i<t_length; i++)
		{

			path[t_length - i - 1] = 0;
			if (text[i] != pattern[i + start_site])
			{
				path[t_length - i - 1] = 1;
				tmp_err++;
			}
		}






		if (tmp_err == (*return_err))
		{

			(*return_path_length) = t_length;

			(*return_start_site) = start_site;

			return 1;
		}






	}


	///这个是那个需要预处理的向量
	Word Peq[256];

	int band_length = (errthold << 1) + 1;
	///int i = 0;
	Word tmp_Peq_1 = (Word)1;

	Peq['A'] = (Word)0;
	Peq['T'] = (Word)0;
	Peq['G'] = (Word)0;
	Peq['C'] = (Word)0;


	Word Peq_A;
	Word Peq_T;
	Word Peq_C;
	Word Peq_G;

	///band_length = 2k + 1
	///这是把pattern的前2k + 1个字符预处理
	///pattern[0]对应Peq[0]
	///pattern[2k]对应Peq[2k]
	for (i = 0; i<band_length; i++)
	{
		Peq[pattern[i]] = Peq[pattern[i]] | tmp_Peq_1;
		tmp_Peq_1 = tmp_Peq_1 << 1;
	}

	Peq['T'] = Peq['T'] | Peq['C'];

	Peq_A = Peq['A'];
	Peq_C = Peq['C'];
	Peq_T = Peq['T'];
	Peq_G = Peq['G'];


	memset(Peq, 0, sizeof(Word)* 256);


	Peq['A'] = Peq_A;
	Peq['C'] = Peq_C;
	Peq['T'] = Peq_T;
	Peq['G'] = Peq_G;


	Word Mask = ((Word)1 << (errthold << 1));

	Word VP = 0;
	Word VN = 0;
	Word X = 0;
	Word D0 = 0;
	Word HN = 0;
	Word HP = 0;


	i = 0;

	int err = 0;

	Word err_mask = (Word)1;


	///band_down = 2k
	///i_bd = 2k
	///int i_bd = i + band_down;
	int i_bd = (errthold << 1);


	int last_high = (errthold << 1);


	/// t_length_1 = SEQ_LENGTH - 1
	int t_length_1 = t_length - 1;
	//while(i<t_length)

	///Word inner_i;
	Word column_start;

	while (i<t_length_1)
	{

		///pattern[0]在Peq[2k], 而pattern[2k]在Peq[0]
		X = Peq[text[i]] | VN;

		D0 = ((VP + (X&VP)) ^ VP) | X;

		HN = VP&D0;

		HP = VN | ~(VP | D0);

		X = D0 >> 1;

		VN = X&HP;

		VP = HN | ~(X | HP);

		///pattern[0]在Peq[2k], 而pattern[2k]在Peq[0]
		//右移实际上是把pattern[0]移掉了
		Peq['A'] = Peq['A'] >> 1;
		Peq['C'] = Peq['C'] >> 1;
		Peq['G'] = Peq['G'] >> 1;
		Peq['T'] = Peq['T'] >> 1;


		++i;
		++i_bd;
		///这是把新的pattern[2k]加进来, 这貌似是加到Peq[2k]上了
		Peq[pattern[i_bd]] = Peq[pattern[i_bd]] | Mask;


		Peq['T'] = Peq['T'] | Peq['C'];

		///每8个元素一存
		column_start = i << 3;

		matrix_bit[column_start] = D0;
		matrix_bit[column_start + 1] = VP;
		matrix_bit[column_start + 2] = VN;
		matrix_bit[column_start + 3] = HP;
		matrix_bit[column_start + 4] = HN;

	}



	///这个循环拿出来是为了防止内存泄露
	///其实也就是循环里的最后一行语句吧
	///完全可以把pattern增大一位
	///不过这样也好，可以减少计算开销
	X = Peq[text[i]] | VN;
	D0 = ((VP + (X&VP)) ^ VP) | X;
	HN = VP&D0;
	HP = VN | ~(VP | D0);
	X = D0 >> 1;
	VN = X&HP;
	VP = HN | ~(X | HP);


	///每8个元素一存
	column_start = (i + 1) << 3;

	matrix_bit[column_start] = D0;
	matrix_bit[column_start + 1] = VP;
	matrix_bit[column_start + 2] = VN;
	matrix_bit[column_start + 3] = HP;
	matrix_bit[column_start + 4] = HN;


	int back_track_site = band_length - (p_length - end_site);

	Word v_value, h_value, delta_value, min_value, current_value;
	Word direction, is_mismatch; ///0 is match, 1 is mismatch, 2 is xiang shang, 3 is shuiping

	i = t_length;
	int path_length = 0;
	start_site = end_site;

	current_value = *return_err;

	int low_bound = band_length - 1;

	while (i>0)
	{

		///每8个元素一存
		column_start = i << 3;


		///如果斜对角线方向匹配则D0是1
		///所以当D0是1, 减0
		///D0是0, 减1
		delta_value = current_value -
			((~(matrix_bit[column_start] >> back_track_site))&err_mask);


		if (back_track_site == 0)
		{
			///HP
			h_value = current_value - ((matrix_bit[column_start + 3] >> back_track_site)&err_mask);
			//HN
			h_value = h_value + ((matrix_bit[column_start + 4] >> back_track_site)&err_mask);






			min_value = delta_value;
			direction = 0;

			if (h_value < min_value)
			{
				min_value = h_value;
				direction = 3;
			}

		}
		else if (back_track_site == low_bound)
		{
			v_value = current_value - ((matrix_bit[column_start + 1] >> (back_track_site - 1))&err_mask);
			v_value = v_value + ((matrix_bit[column_start + 2] >> (back_track_site - 1))&err_mask);

			min_value = delta_value;
			direction = 0;

			if (v_value < min_value)
			{
				min_value = v_value;
				direction = 2;
			}

		}
		else
		{

			h_value = current_value - ((matrix_bit[column_start + 3] >> back_track_site)&(Word)1);

			h_value = h_value + ((matrix_bit[column_start + 4] >> back_track_site)&(Word)1);

			v_value = current_value - ((matrix_bit[column_start + 1] >> (back_track_site - 1))&err_mask);
			v_value = v_value + ((matrix_bit[column_start + 2] >> (back_track_site - 1))&err_mask);


			min_value = delta_value;
			direction = 0;

			if (v_value < min_value)
			{
				min_value = v_value;
				direction = 2;
			}


			if (h_value < min_value)
			{
				min_value = h_value;
				direction = 3;
			}

		}


		if (direction == 0)
		{

			if (delta_value != current_value)
			{
				direction = 1;
			}

			i--;

			start_site--;

		}
		if (direction == 2)///ru guo xiang shang yi dong, bing bu huan lie
		{
			back_track_site--;
			start_site--;
		}
		else if (direction == 3)///ru guo xiang zuo yi dong
		{
			i--;
			back_track_site++;
		}


		path[path_length++] = direction;


		current_value = min_value;

	}

	if (direction != 3)
	{
		start_site++;
	}
	(*return_start_site) = start_site;
	(*return_path_length) = path_length;


	return 1;
}






/***************************************************4条比对純sse**************************************************/
inline int BS_Reserve_Banded_BPM_4_SSE_only(char *pattern1, char *pattern2, char *pattern3, char *pattern4, int p_length, char *text, int t_length,
	int* return_sites, unsigned int* return_sites_error, unsigned short errthold, __m128i* Peq_SSE)

{


	memset(return_sites, -1, sizeof(int)* 4);
	memset(return_sites_error, -1, sizeof(unsigned int)* 4);

	Word_32 Peq[256][4];
	int band_length = (errthold << 1) + 1;


	int i;

	Word_32 tmp_Peq_1 = 1;


	memset(Peq['A'], 0, sizeof(Word_32)* 4);
	memset(Peq['C'], 0, sizeof(Word_32)* 4);
	memset(Peq['G'], 0, sizeof(Word_32)* 4);
	memset(Peq['T'], 0, sizeof(Word_32)* 4);

	for (i = 0; i<band_length; i++)
	{
		Peq[pattern1[i]][0] = Peq[pattern1[i]][0] | tmp_Peq_1;
		Peq[pattern2[i]][1] = Peq[pattern2[i]][1] | tmp_Peq_1;
		Peq[pattern3[i]][2] = Peq[pattern3[i]][2] | tmp_Peq_1;
		Peq[pattern4[i]][3] = Peq[pattern4[i]][3] | tmp_Peq_1;

		tmp_Peq_1 = tmp_Peq_1 << 1;
	}

	Peq_SSE['A'] = _mm_set_epi32(Peq['A'][3], Peq['A'][2], Peq['A'][1], Peq['A'][0]);
	Peq_SSE['C'] = _mm_set_epi32(Peq['C'][3], Peq['C'][2], Peq['C'][1], Peq['C'][0]);
	Peq_SSE['G'] = _mm_set_epi32(Peq['G'][3], Peq['G'][2], Peq['G'][1], Peq['G'][0]);
	Peq_SSE['T'] = _mm_set_epi32(Peq['T'][3], Peq['T'][2], Peq['T'][1], Peq['T'][0]);

	Peq_SSE['T'] = _mm_or_si128(Peq_SSE['T'], Peq_SSE['C']);



	Word_32 Mask = ((Word_32)1 << (errthold << 1));

	__m128i Mask1 = _mm_set_epi32(0, 0, 0, Mask);
	__m128i Mask2 = _mm_set_epi32(0, 0, Mask, 0);
	__m128i Mask3 = _mm_set_epi32(0, Mask, 0, 0);
	__m128i Mask4 = _mm_set_epi32(Mask, 0, 0, 0);


	__m128i VP = _mm_setzero_si128();
	__m128i VN = _mm_setzero_si128();
	__m128i X = _mm_setzero_si128();
	__m128i D0 = _mm_setzero_si128();
	__m128i HN = _mm_setzero_si128();
	__m128i HP = _mm_setzero_si128();
	__m128i tmp_process;
	__m128i tmp_process1;



	__m128i Err_4 = _mm_setzero_si128();
	__m128i err_mask = _mm_set_epi32(1, 1, 1, 1);
	///for_not li quan shi 1
	__m128i for_not = _mm_set1_epi32(-1);
	__m128i err_arry;
	__m128i cmp_result;




	int i_bd = (errthold << 1);
	int last_high = (errthold << 1);
	int t_length_1 = t_length - 1;
	int err1;
	int err2;
	int err3;
	int err4;



	__m128i pre_end = _mm_set_epi32
		(last_high + errthold, last_high + errthold, last_high + errthold, last_high + errthold);


	i = 0;
	while (i<t_length_1)
	{


		///X = Peq[text[i]] | VN;
		X = _mm_or_si128(Peq_SSE[text[i]], VN);



		/*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/
		///X&VP
		tmp_process1 = _mm_and_si128(X, VP);
		///(VP + (X&VP))
		tmp_process = _mm_add_epi32(tmp_process1, VP);
		///((VP + (X&VP)) ^ VP)
		tmp_process = _mm_xor_si128(tmp_process, VP);
		///((VP + (X&VP)) ^ VP) | X
		D0 = _mm_or_si128(tmp_process, X);
		/*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/

		///HN = VP&D0;
		HN = _mm_and_si128(D0, VP);

		///HP = VN | ~(VP | D0);
		tmp_process = _mm_or_si128(D0, VP);
		tmp_process = _mm_andnot_si128(tmp_process, for_not);
		HP = _mm_or_si128(tmp_process, VN);


		///X = D0 >> 1;
		X = _mm_srli_epi32(D0, 1);
		///VN = X&HP;
		VN = _mm_and_si128(X, HP);
		///VP = HN | ~(X | HP);
		tmp_process = _mm_or_si128(X, HP);
		tmp_process = _mm_andnot_si128(tmp_process, for_not);
		VP = _mm_or_si128(HN, tmp_process);

		///D0&err_mask
		err_arry = _mm_and_si128(D0, err_mask);
		Err_4 = _mm_add_epi32(Err_4, err_mask);
		Err_4 = _mm_sub_epi32(Err_4, err_arry);



		Peq_SSE['A'] = _mm_srli_epi32(Peq_SSE['A'], 1);
		Peq_SSE['T'] = _mm_srli_epi32(Peq_SSE['T'], 1);
		Peq_SSE['G'] = _mm_srli_epi32(Peq_SSE['G'], 1);
		Peq_SSE['C'] = _mm_srli_epi32(Peq_SSE['C'], 1);

		++i;
		++i_bd;

		Peq_SSE[pattern1[i_bd]] = _mm_or_si128(Mask1, Peq_SSE[pattern1[i_bd]]);
		Peq_SSE[pattern2[i_bd]] = _mm_or_si128(Mask2, Peq_SSE[pattern2[i_bd]]);
		Peq_SSE[pattern3[i_bd]] = _mm_or_si128(Mask3, Peq_SSE[pattern3[i_bd]]);
		Peq_SSE[pattern4[i_bd]] = _mm_or_si128(Mask4, Peq_SSE[pattern4[i_bd]]);


		Peq_SSE['T'] = _mm_or_si128(Peq_SSE['T'], Peq_SSE['C']);

	}







	///X = Peq[text[i]] | VN;
	X = _mm_or_si128(Peq_SSE[text[i]], VN);

	/*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/
	///X&VP
	tmp_process1 = _mm_and_si128(X, VP);
	///(VP + (X&VP))
	tmp_process = _mm_add_epi32(tmp_process1, VP);
	///((VP + (X&VP)) ^ VP)
	tmp_process = _mm_xor_si128(tmp_process, VP);
	///((VP + (X&VP)) ^ VP) | X
	D0 = _mm_or_si128(tmp_process, X);
	/*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/

	///HN = VP&D0;
	HN = _mm_and_si128(D0, VP);

	///HP = VN | ~(VP | D0);
	tmp_process = _mm_or_si128(D0, VP);
	tmp_process = _mm_andnot_si128(tmp_process, for_not);
	HP = _mm_or_si128(tmp_process, VN);


	///X = D0 >> 1;
	X = _mm_srli_epi32(D0, 1);
	///VN = X&HP;
	VN = _mm_and_si128(X, HP);
	///VP = HN | ~(X | HP);
	tmp_process = _mm_or_si128(X, HP);
	tmp_process = _mm_andnot_si128(tmp_process, for_not);
	VP = _mm_or_si128(HN, tmp_process);

	///D0&err_mask
	err_arry = _mm_and_si128(D0, err_mask);
	Err_4 = _mm_add_epi32(Err_4, err_mask);
	Err_4 = _mm_sub_epi32(Err_4, err_arry);

	///shi ji shang zhe ge zhi hen xiao d
	cmp_result = _mm_cmpgt_epi32(Err_4, pre_end);

	///jian zhi
	if (_mm_extract_epi32(cmp_result, 0) && _mm_extract_epi32(cmp_result, 1)
		&& _mm_extract_epi32(cmp_result, 2) && _mm_extract_epi32(cmp_result, 3))
		return 1;








	int site = t_length - 1;
	err1 = _mm_extract_epi32(Err_4, 0);
	err2 = _mm_extract_epi32(Err_4, 1);
	err3 = _mm_extract_epi32(Err_4, 2);
	err4 = _mm_extract_epi32(Err_4, 3);









	/**
	if (strcmp(text, "TTTTAGGTTTAAGTAATTTTTTTGTTTTAGTTTTTTAAGTAGTTGGGGTTATAGGTGTATGTTATTATNTTTAGTTAATTTTTT") == 0
	&&
	strcmp(pattern1, "TAGCTCACTGAAGCCTCAGATGATCCTCCCACCTCAGCCTCCCAAGTAGCTGGGGCTACAGGTGCATGCTACCACGACTGGCTAATTTTAATATTTTTA") == 0)
	{
	fprintf(stderr, "\n\n\n\n*****************************\ntext: %s\n", text);
	fprintf(stderr, "text: %s\n", pattern1);


	fprintf(stderr, "err1: %d\n", err1);
	fprintf(stderr, "err2: %d\n", err2);
	fprintf(stderr, "err3: %d\n", err3);
	fprintf(stderr, "err4: %d\n", err4);

	fprintf(stderr, "return_sites[0]: %d\n", return_sites[0]);
	fprintf(stderr, "return_sites[1]: %d\n", return_sites[1]);
	fprintf(stderr, "return_sites[2]: %d\n", return_sites[2]);
	fprintf(stderr, "return_sites[3]: %d\n", return_sites[3]);
	fprintf(stderr, "site: %d\n", site);

	fprintf(stderr, "*****************************\n\n\n\n\n");
	}
	**/






	if ((err1 <= errthold) && (err1 <= return_sites_error[0]))
	{
		return_sites[0] = site;
		return_sites_error[0] = err1;
	}
	if ((err2 <= errthold) && (err2 <= return_sites_error[1]))
	{
		return_sites[1] = site;
		return_sites_error[1] = err2;
	}
	if ((err3 <= errthold) && (err3 <= return_sites_error[2]))
	{
		return_sites[2] = site;
		return_sites_error[2] = err3;
	}
	if ((err4 <= errthold) && (err4 <= return_sites_error[3]))
	{
		return_sites[3] = site;
		return_sites_error[3] = err4;
	}






	i = 0;



	while (i<errthold)
	{
		///err = err + ((VP >> i)&(Word_32)1);
		tmp_process = _mm_srli_epi32(VP, i);
		tmp_process = _mm_and_si128(tmp_process, err_mask);
		Err_4 = _mm_add_epi32(Err_4, tmp_process);

		///err = err - ((VN >> i)&(Word_32)1);
		tmp_process1 = _mm_srli_epi32(VN, i);
		tmp_process1 = _mm_and_si128(tmp_process1, err_mask);
		Err_4 = _mm_sub_epi32(Err_4, tmp_process1);
		++i;

		err1 = _mm_extract_epi32(Err_4, 0);
		err2 = _mm_extract_epi32(Err_4, 1);
		err3 = _mm_extract_epi32(Err_4, 2);
		err4 = _mm_extract_epi32(Err_4, 3);


		if ((err1 <= errthold) && (err1 <= return_sites_error[0]))
		{
			return_sites[0] = site + i;
			return_sites_error[0] = err1;
		}
		if ((err2 <= errthold) && (err2 <= return_sites_error[1]))
		{
			return_sites[1] = site + i;
			return_sites_error[1] = err2;
		}
		if ((err3 <= errthold) && (err3 <= return_sites_error[2]))
		{
			return_sites[2] = site + i;
			return_sites_error[2] = err3;
		}
		if ((err4 <= errthold) && (err4 <= return_sites_error[3]))
		{
			return_sites[3] = site + i;
			return_sites_error[3] = err4;
		}
	}


	/**
	if (strcmp(text, "TTTTAGGTTTAAGTAATTTTTTTGTTTTAGTTTTTTAAGTAGTTGGGGTTATAGGTGTATGTTATTATNTTTAGTTAATTTTTT") == 0
	&&
	strcmp(pattern1, "TAGCTCACTGAAGCCTCAGATGATCCTCCCACCTCAGCCTCCCAAGTAGCTGGGGCTACAGGTGCATGCTACCACGACTGGCTAATTTTAATATTTTTA") == 0)
	{
	fprintf(stderr, "\n\n\n\n*****************************\ntext: %s\n", text);
	fprintf(stderr, "text: %s\n", pattern1);


	fprintf(stderr, "err1: %d\n", err1);
	fprintf(stderr, "err2: %d\n", err2);
	fprintf(stderr, "err3: %d\n", err3);
	fprintf(stderr, "err4: %d\n", err4);

	fprintf(stderr, "return_sites[0]: %d\n", return_sites[0]);
	fprintf(stderr, "return_sites[1]: %d\n", return_sites[1]);
	fprintf(stderr, "return_sites[2]: %d\n", return_sites[2]);
	fprintf(stderr, "return_sites[3]: %d\n", return_sites[3]);

	fprintf(stderr, "*****************************\n\n\n\n\n");
	}
	**/


	unsigned int ungap_err1;
	unsigned int ungap_err2;
	unsigned int ungap_err3;
	unsigned int ungap_err4;
	ungap_err1 = err1;
	ungap_err2 = err2;
	ungap_err3 = err3;
	ungap_err4 = err4;




	while (i<last_high)
	{
		///err = err + ((VP >> i)&(Word_32)1);
		tmp_process = _mm_srli_epi32(VP, i);
		tmp_process = _mm_and_si128(tmp_process, err_mask);
		Err_4 = _mm_add_epi32(Err_4, tmp_process);

		///err = err - ((VN >> i)&(Word_32)1);
		tmp_process1 = _mm_srli_epi32(VN, i);
		tmp_process1 = _mm_and_si128(tmp_process1, err_mask);
		Err_4 = _mm_sub_epi32(Err_4, tmp_process1);
		++i;

		err1 = _mm_extract_epi32(Err_4, 0);
		err2 = _mm_extract_epi32(Err_4, 1);
		err3 = _mm_extract_epi32(Err_4, 2);
		err4 = _mm_extract_epi32(Err_4, 3);


		if ((err1 <= errthold) && (err1 <= return_sites_error[0]))
		{
			return_sites[0] = site + i;
			return_sites_error[0] = err1;
		}
		if ((err2 <= errthold) && (err2 <= return_sites_error[1]))
		{
			return_sites[1] = site + i;
			return_sites_error[1] = err2;
		}
		if ((err3 <= errthold) && (err3 <= return_sites_error[2]))
		{
			return_sites[2] = site + i;
			return_sites_error[2] = err3;
		}
		if ((err4 <= errthold) && (err4 <= return_sites_error[3]))
		{
			return_sites[3] = site + i;
			return_sites_error[3] = err4;
		}
	}


	/**
	if (strcmp(text, "TTTTAGGTTTAAGTAATTTTTTTGTTTTAGTTTTTTAAGTAGTTGGGGTTATAGGTGTATGTTATTATNTTTAGTTAATTTTTT") == 0
	&&
	strcmp(pattern1, "TAGCTCACTGAAGCCTCAGATGATCCTCCCACCTCAGCCTCCCAAGTAGCTGGGGCTACAGGTGCATGCTACCACGACTGGCTAATTTTAATATTTTTA") == 0)
	{
	fprintf(stderr, "\n\n\n\n*****************************\ntext: %s\n", text);
	fprintf(stderr, "text: %s\n", pattern1);


	fprintf(stderr, "err1: %d\n", err1);
	fprintf(stderr, "err2: %d\n", err2);
	fprintf(stderr, "err3: %d\n", err3);
	fprintf(stderr, "err4: %d\n", err4);

	fprintf(stderr, "return_sites[0]: %d\n", return_sites[0]);
	fprintf(stderr, "return_sites[1]: %d\n", return_sites[1]);
	fprintf(stderr, "return_sites[2]: %d\n", return_sites[2]);
	fprintf(stderr, "return_sites[3]: %d\n", return_sites[3]);

	fprintf(stderr, "*****************************\n\n\n\n\n");
	}
	**/



	if ((ungap_err1 <= errthold) && ungap_err1 == return_sites_error[0])
	{
		return_sites[0] = site + errthold;
	}


	if ((ungap_err2 <= errthold) && ungap_err2 == return_sites_error[1])
	{
		return_sites[1] = site + errthold;
	}


	if ((ungap_err3 <= errthold) && ungap_err3 == return_sites_error[2])
	{
		return_sites[2] = site + errthold;
	}


	if ((ungap_err4 <= errthold) && ungap_err4 == return_sites_error[3])
	{
		return_sites[3] = site + errthold;
	}


	/**
	if (strcmp(text, "TTTTAGGTTTAAGTAATTTTTTTGTTTTAGTTTTTTAAGTAGTTGGGGTTATAGGTGTATGTTATTATNTTTAGTTAATTTTTT") == 0
	&&
	strcmp(pattern1, "TAGCTCACTGAAGCCTCAGATGATCCTCCCACCTCAGCCTCCCAAGTAGCTGGGGCTACAGGTGCATGCTACCACGACTGGCTAATTTTAATATTTTTA") == 0)
	{
	fprintf(stderr, "\n\n\n\n*****************************\ntext: %s\n", text);
	fprintf(stderr, "text: %s\n", pattern1);


	fprintf(stderr, "err1: %d\n", err1);
	fprintf(stderr, "err2: %d\n", err2);
	fprintf(stderr, "err3: %d\n", err3);
	fprintf(stderr, "err4: %d\n", err4);

	fprintf(stderr, "return_sites[0]: %d\n", return_sites[0]);
	fprintf(stderr, "return_sites[1]: %d\n", return_sites[1]);
	fprintf(stderr, "return_sites[2]: %d\n", return_sites[2]);
	fprintf(stderr, "return_sites[3]: %d\n", return_sites[3]);

	fprintf(stderr, "*****************************\n\n\n\n\n");
	}
	**/




	return 1;

}



/*************************************************************************************************************************************************************************/




/***************************************************2条比对純sse**************************************************/
inline int BS_Reserve_Banded_BPM_2_SSE_only(char *pattern1, char *pattern2, int p_length, char *text, int t_length,
	int* return_sites, unsigned int* return_sites_error, unsigned short errthold, __m128i* Peq_SSE)

{

	memset(return_sites, -1, sizeof(int)* 2);
	memset(return_sites_error, -1, sizeof(unsigned int)* 2);

	Word Peq[256][2];
	int band_length = (errthold << 1) + 1;


	int i;

	Word tmp_Peq_1 = 1;


	memset(Peq['A'], 0, sizeof(Word)* 2);
	memset(Peq['C'], 0, sizeof(Word)* 2);
	memset(Peq['G'], 0, sizeof(Word)* 2);
	memset(Peq['T'], 0, sizeof(Word)* 2);

	for (i = 0; i<band_length; i++)
	{
		Peq[pattern1[i]][0] = Peq[pattern1[i]][0] | tmp_Peq_1;
		Peq[pattern2[i]][1] = Peq[pattern2[i]][1] | tmp_Peq_1;

		tmp_Peq_1 = tmp_Peq_1 << 1;
	}

	Peq_SSE['A'] = _mm_set_epi64x(Peq['A'][1], Peq['A'][0]);
	Peq_SSE['C'] = _mm_set_epi64x(Peq['C'][1], Peq['C'][0]);
	Peq_SSE['G'] = _mm_set_epi64x(Peq['G'][1], Peq['G'][0]);
	Peq_SSE['T'] = _mm_set_epi64x(Peq['T'][1], Peq['T'][0]);

	Peq_SSE['T'] = _mm_or_si128(Peq_SSE['T'], Peq_SSE['C']);



	Word Mask = ((Word)1 << (errthold << 1));

	__m128i Mask1 = _mm_set_epi64x(0, Mask);
	__m128i Mask2 = _mm_set_epi64x(Mask, 0);



	__m128i VP = _mm_setzero_si128();
	__m128i VN = _mm_setzero_si128();
	__m128i X = _mm_setzero_si128();
	__m128i D0 = _mm_setzero_si128();
	__m128i HN = _mm_setzero_si128();
	__m128i HP = _mm_setzero_si128();
	__m128i tmp_process;
	__m128i tmp_process1;



	__m128i Err_2 = _mm_setzero_si128();
	__m128i err_mask = _mm_set_epi64x(1, 1);
	///for_not li quan shi 1
	__m128i for_not = _mm_set1_epi32(-1);
	__m128i err_arry;
	__m128i cmp_result;




	int i_bd = (errthold << 1);
	int last_high = (errthold << 1);
	int t_length_1 = t_length - 1;
	int err1;
	int err2;




	__m128i pre_end = _mm_set_epi64x(last_high + errthold, last_high + errthold);


	i = 0;
	while (i<t_length_1)
	{


		///X = Peq[text[i]] | VN;
		X = _mm_or_si128(Peq_SSE[text[i]], VN);



		/*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/
		///X&VP
		tmp_process1 = _mm_and_si128(X, VP);
		///(VP + (X&VP))
		tmp_process = _mm_add_epi64(tmp_process1, VP);
		///((VP + (X&VP)) ^ VP)
		tmp_process = _mm_xor_si128(tmp_process, VP);
		///((VP + (X&VP)) ^ VP) | X
		D0 = _mm_or_si128(tmp_process, X);
		/*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/

		///HN = VP&D0;
		HN = _mm_and_si128(D0, VP);

		///HP = VN | ~(VP | D0);
		tmp_process = _mm_or_si128(D0, VP);
		tmp_process = _mm_andnot_si128(tmp_process, for_not);
		HP = _mm_or_si128(tmp_process, VN);


		///X = D0 >> 1;
		X = _mm_srli_epi64(D0, 1);
		///VN = X&HP;
		VN = _mm_and_si128(X, HP);
		///VP = HN | ~(X | HP);
		tmp_process = _mm_or_si128(X, HP);
		tmp_process = _mm_andnot_si128(tmp_process, for_not);
		VP = _mm_or_si128(HN, tmp_process);

		///D0&err_mask
		err_arry = _mm_and_si128(D0, err_mask);
		Err_2 = _mm_add_epi64(Err_2, err_mask);
		Err_2 = _mm_sub_epi64(Err_2, err_arry);



		Peq_SSE['A'] = _mm_srli_epi64(Peq_SSE['A'], 1);
		Peq_SSE['T'] = _mm_srli_epi64(Peq_SSE['T'], 1);
		Peq_SSE['G'] = _mm_srli_epi64(Peq_SSE['G'], 1);
		Peq_SSE['C'] = _mm_srli_epi64(Peq_SSE['C'], 1);

		++i;
		++i_bd;

		Peq_SSE[pattern1[i_bd]] = _mm_or_si128(Mask1, Peq_SSE[pattern1[i_bd]]);
		Peq_SSE[pattern2[i_bd]] = _mm_or_si128(Mask2, Peq_SSE[pattern2[i_bd]]);



		Peq_SSE['T'] = _mm_or_si128(Peq_SSE['T'], Peq_SSE['C']);

	}







	///X = Peq[text[i]] | VN;
	X = _mm_or_si128(Peq_SSE[text[i]], VN);

	/*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/
	///X&VP
	tmp_process1 = _mm_and_si128(X, VP);
	///(VP + (X&VP))
	tmp_process = _mm_add_epi64(tmp_process1, VP);
	///((VP + (X&VP)) ^ VP)
	tmp_process = _mm_xor_si128(tmp_process, VP);
	///((VP + (X&VP)) ^ VP) | X
	D0 = _mm_or_si128(tmp_process, X);
	/*************D0 = ((VP + (X&VP)) ^ VP) | X*********************/

	///HN = VP&D0;
	HN = _mm_and_si128(D0, VP);

	///HP = VN | ~(VP | D0);
	tmp_process = _mm_or_si128(D0, VP);
	tmp_process = _mm_andnot_si128(tmp_process, for_not);
	HP = _mm_or_si128(tmp_process, VN);


	///X = D0 >> 1;
	X = _mm_srli_epi64(D0, 1);
	///VN = X&HP;
	VN = _mm_and_si128(X, HP);
	///VP = HN | ~(X | HP);
	tmp_process = _mm_or_si128(X, HP);
	tmp_process = _mm_andnot_si128(tmp_process, for_not);
	VP = _mm_or_si128(HN, tmp_process);

	///D0&err_mask
	err_arry = _mm_and_si128(D0, err_mask);
	Err_2 = _mm_add_epi64(Err_2, err_mask);
	Err_2 = _mm_sub_epi64(Err_2, err_arry);

	///shi ji shang zhe ge zhi hen xiao d
	cmp_result = _mm_cmpgt_epi64(Err_2, pre_end);

	///jian zhi
	if (_mm_extract_epi64(cmp_result, 0) && _mm_extract_epi64(cmp_result, 1))
		return 1;








	int site = t_length - 1;
	err1 = _mm_extract_epi64(Err_2, 0);
	err2 = _mm_extract_epi64(Err_2, 1);




	if ((err1 <= errthold) && (err1 <= return_sites_error[0]))
	{
		return_sites[0] = site;
		return_sites_error[0] = err1;
	}
	if ((err2 <= errthold) && (err2 <= return_sites_error[1]))
	{
		return_sites[1] = site;
		return_sites_error[1] = err2;
	}






	i = 0;



	while (i<errthold)
	{
		///err = err + ((VP >> i)&(Word)1);
		tmp_process = _mm_srli_epi64(VP, i);
		tmp_process = _mm_and_si128(tmp_process, err_mask);
		Err_2 = _mm_add_epi64(Err_2, tmp_process);

		///err = err - ((VN >> i)&(Word)1);
		tmp_process1 = _mm_srli_epi64(VN, i);
		tmp_process1 = _mm_and_si128(tmp_process1, err_mask);
		Err_2 = _mm_sub_epi64(Err_2, tmp_process1);
		++i;

		err1 = _mm_extract_epi64(Err_2, 0);
		err2 = _mm_extract_epi64(Err_2, 1);


		if ((err1 <= errthold) && (err1 <= return_sites_error[0]))
		{
			return_sites[0] = site + i;
			return_sites_error[0] = err1;
		}
		if ((err2 <= errthold) && (err2 <= return_sites_error[1]))
		{
			return_sites[1] = site + i;
			return_sites_error[1] = err2;
		}

	}





	unsigned int ungap_err1;
	unsigned int ungap_err2;

	ungap_err1 = err1;
	ungap_err2 = err2;





	while (i<last_high)
	{
		///err = err + ((VP >> i)&(Word)1);
		tmp_process = _mm_srli_epi64(VP, i);
		tmp_process = _mm_and_si128(tmp_process, err_mask);
		Err_2 = _mm_add_epi64(Err_2, tmp_process);

		///err = err - ((VN >> i)&(Word)1);
		tmp_process1 = _mm_srli_epi64(VN, i);
		tmp_process1 = _mm_and_si128(tmp_process1, err_mask);
		Err_2 = _mm_sub_epi64(Err_2, tmp_process1);
		++i;

		err1 = _mm_extract_epi64(Err_2, 0);
		err2 = _mm_extract_epi64(Err_2, 1);


		if ((err1 <= errthold) && (err1 <= return_sites_error[0]))
		{
			return_sites[0] = site + i;
			return_sites_error[0] = err1;
		}
		if ((err2 <= errthold) && (err2 <= return_sites_error[1]))
		{
			return_sites[1] = site + i;
			return_sites_error[1] = err2;
		}
	}






	if ((ungap_err1 <= errthold) && ungap_err1 == return_sites_error[0])
	{
		return_sites[0] = site + errthold;
	}


	if ((ungap_err2 <= errthold) && ungap_err2 == return_sites_error[1])
	{
		return_sites[1] = site + errthold;
	}



	return 1;

}



/*************************************************************************************************************************************************************************/












#endif
