int preProcess[1000][10];
template
class RMQMin
{
  T *A;
  public:
    RMQMin(int N,T *array):A(array)
    {
        int i,j;
        for (i=0;i<N;i++)
            preProcess[i][0]=i;
        for (j=1; (1<<j)<=N; j++)
            for (i=0; i+(1<<j)-1<N; i++)
                preProcess[i][j]=
                A[preProcess[i][j-1]]<=
                A[preProcess[i+(1<<(j-1))][j-1]]?
                preProcess[i][j-1]
                :preProcess[i+(1<<(j-1))][j-1];
    }
   
    int query(int start,int end)
    {
        int diff=end-start;
        diff=31 - __builtin_clz(diff+1);
        return A[preProcess[start][diff]]
          <=A[preProcess[end-(1<<diff)+1][diff]]?
          preProcess[start][diff]
          :preProcess[end-(1<<diff)+1][diff];
    }
};
