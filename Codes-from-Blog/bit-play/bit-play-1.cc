int add(int a,int b)
{
    if(!a)
          return b;
    else
        return(add((a&b)<<1,a^b));
}
