#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

map<int,vector<int> > a;
int n,m;

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif
	while(scanf("%d%d",&n,&m)==2){
		a.clear();
		int t;
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			if(!a.count(t)) a[t]=vector<int>();
			a[t].push_back(i+1);
		}
		int k,v;
		for(int i=0;i<m;i++){
			scanf("%d%d",&k,&v);
			if(!a.count(v) || a[v].size()<k) printf("0\n");
			else printf("%d\n",a[v][k-1]);
		}
	}

	return 0;
}
