#define N 8
#define S 6
void mul1(int B[N][N],int C[N][N],int sparse_new[S][3])
{
#pragma HLS array_partition variable=C complete dim=2
#pragma HLS array_partition variable=B complete dim=2
	int r=0,c=0,val=0,i,j;
	for(i=0;i<S;i++)
	{
//#pragma HLS pipeline ii=3

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
