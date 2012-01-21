int main()
{
    char str[20];
    int dec,l,i,n;
    while (1)
    {
          scanf("%s",str);
          if (str[0]=='-')
             break;
          else if (str[1]=='x')
          {
               str[0]=str[1]=' ';
               sscanf(str,"%X",&amp;n);
               printf("%d o%o\n",n,n);
          }
          else if (str[0]=='o')
          {
               str[0]=' ';
               sscanf(str,"%o",&amp;n);
               printf("%d 0x%X\n",n,n);
          }
          else
          {
              n=atoi(str);
              printf("0x%X o%o\n",n,n);
          }
    }
}
