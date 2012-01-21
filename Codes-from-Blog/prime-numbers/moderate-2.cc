void moderate2(int N)
{
     vector<int> p(N/2,0);
     p[0]=2;
     int i,j,F,c=1;
     long long s=2;
     for (i=3;i<=N;i+=2)
     {
         F=1;
         for (j=0; p[j]*p[j]<=i && F==1; j++)
             if (i%p[j] == 0)
                F=0;
         if (F)
         {
            p[c++]=i;
            s+=i;
         }
     }
     cout<<s<<endl;
}
