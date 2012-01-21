main(a,b,m)
{
    while (~scanf("%d%d",&a,&b))
    {
          m=0;
          while (a)
          {
                if (a&1)
                   m+=b;
                a>>=1;
                b<<=1;
          }
          printf("%d\n",m);
    }
}
