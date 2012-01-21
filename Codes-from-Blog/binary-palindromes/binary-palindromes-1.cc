main(v,r,t,x)
{scanf("%d",&t);while(t--){
for(scanf("%d",&v),x=v,r=0;v;r<<=1,r|=v&1,v>>=1){}
puts(r-x?"NO":"YES");}}
