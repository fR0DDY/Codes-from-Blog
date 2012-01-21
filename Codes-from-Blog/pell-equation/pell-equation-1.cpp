double PellSolution(double D)
{
       double x1,y1;
       double Pn[100],Qn[100],a[100],p[100],q[100];
       long long n,r;
       if (sqrt(D)!=floor(sqrt(D)))
       {
          //Initialization
          Pn[0]=0;Qn[0]=1;
          a[0]=floor(sqrt(D));
          p[0]=a[0];q[0]=1;

          n=1;
          Pn[1]=a[0];Qn[1]=D-a[0]*a[0];
          a[1]=floor((a[0]+Pn[1])/Qn[1]);
          p[1]=a[0]*a[1]+1.0;
          q[1]=a[1];

          while (a[n]!=2.0*a[0])
          {
                n=n+1;
                Pn[n]=a[n-1]*Qn[n-1]-Pn[n-1];
                Qn[n]=(D-Pn[n]*Pn[n])/Qn[n-1];
                a[n]=floor((a[0]+Pn[n])/Qn[n]);
                p[n]=a[n]*p[n-1]+p[n-2];
                q[n]=a[n]*q[n-1]+q[n-2];
          }
          r=n-1;
          if (r%2==0)
          {
             for (n=r+2;n<=2*r+1;n++)
             {
                 Pn[n]=a[n-1]*Qn[n-1]-Pn[n-1];
                 Qn[n]=(D-Pn[n]*Pn[n])/Qn[n-1];
                 a[n]=floor((a[0]+Pn[n])/Qn[n]);
                 p[n]=a[n]*p[n-1]+p[n-2];
                 q[n]=a[n]*q[n-1]+q[n-2];
             }
             x1=p[2*r+1];
             y1=q[2*r+1];
          }
          else
          {
              x1=p[r];
              y1=q[r];
          }
          return x1;
       }
       else
           return 0;
}
