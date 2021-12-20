#include<stdio.h>
#include<stdlib.h>

#define MAX(x,y) (x)>(y) ? (x) : (y)

struct Sol{
	int b;
	int j;
}sol[1000],temp;

void Sort(struct Sol * p, int left, int right);

int main(void){
	int n,kase=0;
	while(scanf("%d",&n)==1){
		if(n==0) break;
		for(int i=0;i<n;i++) scanf("%d%d",&sol[i].b,&sol[i].j);
		Sort(sol,0,n-1);

		long ans=0,sum=0;
		for(int i=0;i<n;i++){
			sum+=sol[i].b;
			ans=MAX(ans,sum+sol[i].j);
		}
		printf("Case %d: %ld\n",++kase,ans);
	}

	return 0;
}

void Sort(struct Sol * p, int left, int right){
	if(left>=right) return;
	int i=left,j=right;
	int k=p[left].j;
	while(i!=j){
		while(i<j && p[j].j<=k) j--;
		while(i<j && p[i].j>=k) i++;
		temp=p[i];p[i]=p[j];p[j]=temp;
	}
	temp=p[i];p[i]=p[left];p[left]=temp;
	Sort(p,left,i-1);
	Sort(p,i+1,right);
}
