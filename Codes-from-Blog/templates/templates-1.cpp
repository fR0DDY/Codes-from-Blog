template <class myType>
myType GetMax (myType a, myType b)
{
       return (a>b?a:b);
}

int main ()
{
    long long a=10183273822013LL,b=10000011010021LL;
    printf("%d\n",GetMax<int>(10,12));
    printf("%lld\n",GetMax<long long>(a,b));
    return 0;
}
