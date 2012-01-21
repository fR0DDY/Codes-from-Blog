#include<iostream>
using namespace std;

#define MAXN 35

int main()
{
    long long t[MAXN+1][MAXN+1]={0},n,h,m,i;
    
    t[0][0]=1;
    for (n=1;n<=MAXN;n++)
        for (h=1;h<=n;h++)
            for (m=1;m<=n;m++)
            {
                for (i=0;i<h;i++)
                    t[n][h]+=t[m-1][h-1]*t[n-m][i];
                
                for (i=0;i<h-1;i++)
                    t[n][h]+=t[n-m][h-1]*t[m-1][i];
            }
            
    while (scanf("%lld%lld",&n,&h))
          printf("%lld\n",t[n][h]);
}
