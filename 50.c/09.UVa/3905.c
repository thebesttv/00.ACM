#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define DEBUG 0
using namespace std;

const double EPS=1e-6;
int w,h,n;
struct Event{
	double x;
	int pos;
}eve[(100000+10)*2];
struct Rule{
	bool operator()(const Event & a, const Event & b){
		if(fabs(a.x-b.x)<EPS)
			if(a.pos==1) return true;
			else return false;
		else return a.x<b.x;
	}
};

double Solve(int w, int x, int a, double * pL, double * pR);
	//通过指针对L,R修改

int main(void){
	int T; scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		int x,y,a,b,tail=0;
		scanf("%d%d%d",&w,&h,&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d%d",&x,&y,&a,&b);
			double L=0,R=1e8;
			Solve(w,x,a,&L,&R);
			Solve(h,y,b,&L,&R);
			if(R-L>EPS){
				eve[tail].x=L; eve[tail].pos=0; tail++;
				eve[tail].x=R; eve[tail].pos=1; tail++;
			}
		}
		sort(eve,eve+tail,Rule());
		#if DEBUG
		for(int i=0;i<tail;i++){
			printf("eve[%d]: %lf, %d\n",i,eve[i].x,eve[i].pos);
		}
		#endif
		int cou=0,maxn=0;
		for(int i=0;i<tail;i++){
			if(eve[i].pos==0) maxn=max(maxn,++cou);
			else cou--;
		}
		printf("%d\n",maxn);
	}

	return 0;
}

double Solve(int w, int x, int a, double * pL, double * pR){
	if(a==0)
		if(x>0 && x<w){
			*pL=max(*pL,0.0);
			*pR=min(*pR,1e8);
		}else *pR=*pL-1;
	else if(a>0){
		*pL=max((double)(0-x)/a,*pL);
		*pR=min((double)(w-x)/a,*pR);
	}else{
		*pL=max((double)(w-x)/a,*pL);
		*pR=min((double)(0-x)/a,*pR);
	}
}
