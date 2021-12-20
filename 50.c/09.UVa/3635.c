#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

const double PI=acos(-1.0);
double a[10000+4],sum;
int n,f;

bool Check(double s);

int main(void){
	int T; scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		sum=0;
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&f);
		for(int i=0;i<n;i++){
			scanf("%lf",&a[i]);
			a[i]=PI*a[i]*a[i];
			sum+=a[i];
		}
		double L=0,R=sum/(f+1);
		while(fabs(L-R)>1e-6){
			double M=L+(R-L)/2;
			if(Check(M)) L=M;
			else R=M;
		}
		printf("%.4lf\n",L);
	}

	return 0;
}

bool Check(double s){
	int cou=0;
	for(int i=0;i<n;i++)
		cou+=floor(a[i]/s);
	return cou>=f+1;
}
