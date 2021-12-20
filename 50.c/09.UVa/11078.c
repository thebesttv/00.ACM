#include<iostream>
#include<cstdio>
using namespace std;

int main(void){
	int T;
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		int maxi,ans,n,temp;
		scanf("%d",&n); n-=2;
		scanf("%d",&temp); maxi=temp;
		scanf("%d",&temp); ans=maxi-temp;
		for(int i=0;i<n;i++){
			maxi=max(maxi,temp);
			scanf("%d",&temp);
			ans=max(ans,maxi-temp);
		}
		printf("%d\n",ans);
	}

	return 0;
}
