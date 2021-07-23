//PARALLEL Col*Row multiplication and sequential addition
#define N 8
void mul1(int A[N][N],int B[N][N],int C[N][N])
{

	int i,j,k;
	for(k=0;k<N;k++)
	{
	for(i=0;i<N;i++)
	{
#pragma HLS loop_unroll

		for(j=0;j<N;j++)
		{
#pragma HLS loop_unroll
			C[i][j]+=A[i][k]*B[k][j];
		}
	}
	}
}
