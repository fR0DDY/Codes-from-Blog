int main()
{
    int N,maxsum=1<<31,i,j,k,l,m,sum,p;
    scanf("%d",&N);
    vector< vector > M(N+1,vector(N+1,0));
    vector< vector > S(N+1,vector(N+1,0));
    for (i=1;i<N+1;i++)
        for (j=1;j<N+1;j++)
            scanf("%d",&M[i][j]);
            
    for (i=1;i<N+1;i++)
        for (j=1;j<N+1;j++)
            S[i][j]=M[i][j]+
            S[i-1][j]+S[i][j-1]-S[i-1][j-1];
            
    maxsum=-128;
    for (i=1;i<N+1;i++)
        for (j=1;j<N+1;j++)
            for (k=i;k<N+1;k++)
                for (l=j;lmaxsum)
                       maxsum=sum;
                }
    printf("%d\n",maxsum);
}
