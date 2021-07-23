#define N 8
#define S 6
void mul1(int A[N][N],int B[N][N],int C[N][N],int sparse_new[S][3])
{
	int r=0,c=0,val=0,i,j;
	for(i=0;i<S;i++)
	{
		r=sparse_new[i][0];
		c=sparse_new[i][1];
		val=sparse_new[i][2];
		for(j=0;j<N;j++)
		{
#pragma HLS loop_unroll
			C[r][j]+=val*B[c][j];
		}
	}
}
