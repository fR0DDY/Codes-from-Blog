#include<iostream>
using namespace std;
 
int P(int K)
{
        int A[]={6,2,4,8};
        if (K<1) return 1;
        return A[K%4];
}
 
int L(int N)
{
        int A[]={1,1,2,6,4};
        if (N<5) return A[N];
        return (P(N/5)*L(N/5)*L(N%5))%10;
}
 
int main()
{
        int N;
        while (scanf("%d", &N) == 1)
                printf("%d\n", L(N));
        return 0;
}
