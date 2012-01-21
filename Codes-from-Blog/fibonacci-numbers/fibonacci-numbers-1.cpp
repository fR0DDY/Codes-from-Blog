#include<iostream>
using namespace std;

long long F[93];
long long Fib(int N)
{
    if (N==1)
       return 1;
    if (N==0)
       return 0;
    else
    {
        if (F[(N+1)/2-1]==0)
           F[(N+1)/2-1]=Fib((N+1)/2-1);
        if (F[(N+1)/2]==0)
           F[(N+1)/2]=Fib((N+1)/2);
        if (N%2==0)
           return 
           ((2*F[(N+1)/2-1]+F[(N+1)/2])*F[(N+1)/2]);
        else
            return 
            ((F[(N+1)/2-1]*F[(N+1)/2-1]+
            F[(N+1)/2]*F[(N+1)/2]));
    }
}

int main()
{
    int N;
    while (scanf("%d",&N),N>=0&&N<93)
    {
          printf("%lld\n",Fib(N));
    }
}
