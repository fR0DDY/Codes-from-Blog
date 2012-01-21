#include"iostream"
int a,t,s;
main()
{
      for(std::cin>>t;t--;std::cin>>a,s+=a>0?a:0);
      std::cout<<s;
} 
