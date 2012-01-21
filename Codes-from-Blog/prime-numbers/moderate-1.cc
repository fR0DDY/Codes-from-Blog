void moderate1(int N)
{
     vector<int> p(N/2,0);
     int i,j,k,F,c=0;
     long long s=0;
     for (i=2;i<=N;i++)
     {
         F=1;
         for (j=2;j*j<=i && F==1;j++)
             if (i%j==0)
                F=0;
         if (F)
         {
            p[c++]=i;
            s+=i;
         }
     }
     cout<<s<<endl;
}
