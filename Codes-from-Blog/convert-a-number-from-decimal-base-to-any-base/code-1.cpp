#include<iostream>
using namespace std;

void convert10tob(int N,int b)
{
     if (N==0)
        return;
     
     int x = N%b;
     N/=b;
     if (x<0)
        N+=1;
        
     convert10tob(N,b);
     printf("%d",x<0?x+(b*-1):x);
     return;
}


int main()
{
    int N,b;
    while (scanf("%d%d",&N,&b)==2)
    {
          if (N!=0)
          {
              convert10tob(N,b);
              printf("\n");
          }
          else
              printf("0\n");
    }
}
