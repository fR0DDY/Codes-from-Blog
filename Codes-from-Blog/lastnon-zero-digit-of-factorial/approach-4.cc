#include
using namespace std;

int A[4][5][5] = {
{0,6,2,6,4,2,2,4,2,8,4,4,8,4,6,6,6,2,6,4,8,8,6,8,2},
{0,2,8,8,4,2,4,6,6,8,4,8,2,2,6,6,2,8,8,4,8,6,4,4,2},
{0,4,2,4,4,2,8,4,8,8,4,6,8,6,6,6,4,2,4,4,8,2,6,2,2},
{0,8,8,2,4,2,6,6,4,8,4,2,2,8,6,6,8,8,2,4,8,4,4,6,2}
};

char num[200];
char* dto5(int n)
{
     int b=5;
     int j,l;
     register int i=0;
     do
     {
           j=n%b;
           num[i++]=(j<10) ? (j+'0'): ('A'+j-10);
     }while((n/=b)!=0);

     num[i]='';
     l=strlen(num);
     reverse(num,num+l);
     return num;
}

int last_digit_factorial(int N)
{
    char *num=dto5(N);
    int l = strlen(num),s=0,i;
    for (i=0;i<l;i++)
    {
        s=A[(l-1-i)%4][s/2][num[i]-'0'];
    }
    return s;
}

int main()
{
  int N;

  while (scanf("%d", &N) == 1)
  {
        printf("%d\n", last_digit_factorial(N));
  }
  return 0;
}
