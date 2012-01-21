#include
using namespace std;

char str[1000],cj[]="welcome to code jam";
int M[30][1000]={0};

int main()
{
    int t,i,j,k,l,lcj=strlen(cj);;
    scanf("%d\n",&t);
    for (j=1;j<=1000;j++)
        M[0][j]=1;
    for (j=1;j<=lcj;j++)
        M[j][0]=0;
    for (k=1;k<=t;k++)
    {
        gets(str);
        l=strlen(str);
        for (i=1;i<=lcj;i++)
        {
            M[i][0]=0;
            for (j=1;j<=l;j++)
                if (cj[i-1]==str[j-1])
                M[i][j]=(M[i-1][j]+M[i][j-1])%10000;
                else M[i][j]= M[i][j-1];
        }
        printf("Case #%d: %04d\n",k,M[lcj][l]);
    }
}
