// C program to multiply two square matrices.
#include <stdio.h>
#define N 4

// This function multiplies mat1[][] and mat2[][],
// and stores the result in res[][]
void mul1(int mat1[N][N], int mat2[N][N], int res[N][N])
{
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			res[i][j] = 0;
			for (k = 0; k < N; k++)
				res[i][j] += mat1[i][k]*mat2[k][j];
		}
	}
}
