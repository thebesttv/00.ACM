#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[10000+10];

int main(void){
	int n,m,kase=0;
	while(scanf("%d%d",&n,&m)==2 && n){
		printf("CASE# %d:\n",++kase);
		int t,p;
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		for(int i=0;i<m;i++){
			scanf("%d",&t);
			p=lower_bound(a,a+n,t)-a;
			if(a[p]==t) printf("%d found at %d\n",t,p+1);
			else printf("%d not found\n",t);
		}
	}

	return 0;
}
