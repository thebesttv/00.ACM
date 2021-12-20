#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double a[1000+5];

int main(void){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		double ans=0;
		for(int i=0;i<n;i++) a[i]=((double)i/n)*(m+n);
		for(int i=0;i<n;i++) ans+=fabs(a[i]-floor(a[i]+0.5));
		ans/=(m+n);
		printf("%.4lf\n",ans*10000);
	}
	return 0;
}
