#include<stdio.h>
#define N 4

void add(int mat1[N][N],int mat2[N][N],int mat3[N][N])
{

	int x=10;
	int y=20;
	for(int i=0;i<N;++i)
	{


			int j=0;
			mat3[i][j]=(x*mat1[i][j])+(y*mat2[i][j]);
			mat3[i][j+1]=(x*mat1[i][j+1])+(y*mat2[i][j+1]);

			mat3[i][j+2]=(x*mat1[i][j+2])+(y*mat2[i][j+2]);

			mat3[i][j+3]=(x*mat1[i][j+3])+(y*mat2[i][j+3]);



	}



	}

