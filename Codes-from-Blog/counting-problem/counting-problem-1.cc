int a[21];
int main()
{
    int t,N,M,i,j,k,sum;
    bool F;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&N,&M);
        for (i=0;i<N;i++)
            scanf("%d",&a[i]); 

        F=0;
        j=1<<N;
        for (i=1;i<j && F==0;i++)
        {
            sum=0;
            for (k=0;k<N;k++)
            {
                if ((i & (1<<k)) == (1<<k))
                   sum += a[k];
            }
            if (sum == M)
            {
                F=1;
                printf("Yes\n");
            }

        }
        if (F==0)
           printf("No\n");

    }
}
