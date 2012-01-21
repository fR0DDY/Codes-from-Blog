int MaxSum1D(vector M)
{
    int N=M.size(),i,t=0,S=1<<31;
    for (i=0;i<N;i++)
    {
        t=t+M[i];
        S=max(t,S);
        if (t<0)
           t=0;
    }
    return S;
}
