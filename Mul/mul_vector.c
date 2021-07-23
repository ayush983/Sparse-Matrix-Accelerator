#include<stdio.h>
#define N 12

void mul_vec(int mat1[N][N],int mat2[N],int mat3[N])
{

	for(int i=0;i<N;++i)
	{

		for(int j=0;j<N;j++)
		{
#pragma HLS loop_unroll
			mat3[j]+=mat1[j][i]*mat2[j];
		}

	}



	}

