#include <stdio.h>
#include <math.h>

double funcos( double e, double x ){
  int cnt=0;
  double s = 0, cur = 1;
  while(1){
#ifdef DEBUG
    printf("  %lf\n",cur);
#endif
    s += cur;
    if(fabs(cur)<e) break;
    cur = -cur * x*x/(cnt+1)/(cnt+2); cnt+=2;
  }
  return s;
}

/*
// WSQ
double funcos( double e, double x )
{

  int n=0;
  double m=0;
  double t;
  do
  {
    if (n==0)
    {
      t=1.0/1;
      m=t;
    }
    else
    {
      //t=t*x*x/(n*(n+1));
      t=t*x*x/((n-1)*n);
      printf(" %lf\n",t);
      m+=1.0*pow(-1,n/2)*t;
    }
    n+=2;
  }while(fabs(t)>=e);
  return m;

}
*/

int main()
{    
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));

    return 0;
}
