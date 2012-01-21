#include<iostream>
#include<map>
#include<vector>
using namespace std;

typedef pair < int , int > PI;

vector<int> LIS(vector<int> A)
{
    int N = A.size(),i,j=-1,t;
    vector<int> pre(N,-1),res;
    map<int,int> m;
    map<int,int>::iterator k,l;
    for (i=0;i<N;i++)
    {
        if (m.insert(PI(A[i],i)).second)
        {
           k = m.find(A[i]);
           l = k;
           k++;
           if (l==m.begin())
                  pre[i]=-1;
           else
           {
               l--;
               pre[i]=l->second;
           }
           if (k!=m.end())
              m.erase(k);
        }
    }
    k=m.end();
    k--;
    j = k->second;
    while (j!=-1)
    {
          res.push_back(A[j]);
          j = pre[j];
    }
    reverse (res.begin(),res.end());
    return res;
}
