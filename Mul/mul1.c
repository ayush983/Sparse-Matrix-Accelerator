void mul1(int A[4][4],int B[4][4],int C[4][4])
{
int i;
int j;
int k;
	for(k=0;k<4;k++)
	{
	for(i=0;i<4;i++)
	{
#pragma HLS loop_unroll

		for(j=0;j<4;j++)
		{
#pragma HLS loop_unroll
			C[i][j]+=A[i][k]*B[k][j];
		}
	}
	}
}
