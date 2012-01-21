int main()
{
    int coin[7]={1,2,5,10,20,50,100},i,j,x,c;
    x=100;
    vector<long long> ways(x+1,0);
    ways[0]=1;
    for (i=0;i<7;i++)
    {
      c=coin[i];
      for (j=c;j<=x;j++)
          ways[j]+=ways[j-c];
    }
    cout<<ways[100]<<endl;
}
