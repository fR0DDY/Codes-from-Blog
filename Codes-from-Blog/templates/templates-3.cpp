template <class T>
class mypair
{
      T a, b;
      public:
             mypair (T first, T second)
             {
                  a=first; b=second;
             }
             T getmax ()
             {
                     return a>b? a : b;
             }
};

int main ()
{
    mypair<long long> p(1018333013LL,1000100121LL);
    printf("%lld\n",p.getmax());
    return 0;
}
