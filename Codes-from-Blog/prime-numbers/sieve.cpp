void sieve(int N)
{
     int x=sqrt(N),i,j;
     vector<bool> S(N+1,0);
     for (i=4;i<=N;i+=2)
         S[i]=1;
     for (i=3;i<=x;i+=2)
         if (!S[i])
            for (j=i*i;j<=N;j+=2*i)
                S[j]=1;

     long long s=0;
     for (i=2;i<=N;i++)
         if (!S[i])
            s+=i;

     printf("%lld\n",s);
}
