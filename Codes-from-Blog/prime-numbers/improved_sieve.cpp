void improved_sieve(int N)
{
     int M=(N-1)/2;
     int x=(floor(sqrt(N))-1)/2,i,j;
     vector<bool> S(M+1,0);
     for (i=1;i<=x;i++)
         if (!S[i])
            for (j=2*i*(i+1);j<=M;j+=(2*i+1))
                S[j]=1;

     long long s=2;
     for (i=1;i<=M;i++)
         if (!S[i])
            s+=(2*i+1);

     printf("%lld\n",s);
}
