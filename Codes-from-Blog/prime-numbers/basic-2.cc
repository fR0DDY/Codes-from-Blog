void basic2(int N)
{
     int i,j,k,F;
     long long s=0;
     for (i=2;i<=N;i++)
     {
         F=1;
         for (j=2;j<=i/2 && F==1;j++)
             if (i%j==0)
                F=0;
         if (F)
            s+=i;
     }
     cout<<s<<endl;
}
