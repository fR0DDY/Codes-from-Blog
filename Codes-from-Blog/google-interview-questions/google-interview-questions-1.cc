void solution(vector<int> A) 
{   
    int N=A.size(),i,j;
    vector<int> L(N,0);
    vector<int> R(N,0);
    vector<int> B(N,0);
    for (i=0,j=N-1; i<N && j>=0 ;i++, j--)
    {   
        L[i] = i==0? 1 : A[i-1] * L[i-1];   
        R[j] = j==N-1? 1 : R[j+1] * A[j+1];   
    }   
    
    for (i=0; i<N ; i++)   
    {
        B[i] = L[i] * R[i];   
        printf("%d ",B[i]);
    }
}
