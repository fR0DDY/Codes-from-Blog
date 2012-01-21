void basic1(int N)
{
     int i,j,k,c;
     long long s=0;
     for (i=1;i<=N;i++)
     {
         c=0;
         for (j=1;j<=i && c<3;j++)
             if (i%j==0)
                c++;
         if (c==2)
            s+=i;
     }
     cout<<s<<endl;
}
