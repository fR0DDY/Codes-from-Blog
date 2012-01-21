template< class T >
T gcd( T a, T b )
{
       return( b == 0 ? a : gcd( b, a % b ));
}

int main ()
{
    long long a=10183273823013LL,b=10000011010121LL;
    printf("%d\n",gcd<int>(10,12));
    printf("%lld\n",gcd<long long>(a,b));
    return 0;
}
