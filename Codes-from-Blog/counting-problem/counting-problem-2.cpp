#include<iostream>
using namespace std;
#include<set>

int a[21];
int main()
{
    int t,N,M,i,j,k,sum,x;
    set<int> s1,s2;
    set<int>::iterator l;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d%d",&N,&M);
        s1.clear();
        s2.clear();
        for (i=0;i<N;i++)
            scanf("%d",&a[i]); 

        
        j=1<<(N/2);
        for (i=0;i<j;i++)
        {
            sum=0;
            for (k=0;k<N/2;k++)
            {
                if ((i & (1<<k)) == (1<<k))
                   sum += a[k];
            }
            s1.insert(sum);
        }
        
        x=N-N/2;
        j=1<<x;
        for (i=0;i<j;i++)
        {
            sum=0;
            for (k=0;k<x;k++)
            {
                if ((i & (1<<k)) == (1<<k))
                   sum += a[k+N/2];
            }
            s2.insert(sum);
        }
        
        for (l=s1.begin();l!=s1.end();l++)
        {
            if (binary_search(s2.begin(),s2.end(),M-*l))
            {
               printf("Yes\n");
               break;
            }
        }
        if (l==s1.end())
           printf("No\n");
    }
}
