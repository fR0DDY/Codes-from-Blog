int binarygcd(int u,int v)
{
    int k=0,t=0,i;
    while (!(u&1) && !(v&1))
    {
          k++;
          u>>=1;
          v>>=1;
    }
    if (u&1)
       t=u;
    else
        t=-v;
    do
    {
        while (!(t&1))
              t>>=1;
        if (t>0)
           u=t;
        else
            v=-t;
        t=u-v;
    }while (t);
    for (i=0;i<k;i++)
        u<<=1;
    return(u);
}
