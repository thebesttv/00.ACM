#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100050];
int size[100050];
vector<int> G[100050];
void dfs(int x){
	size[x]=1;
	for(int i=0;i<G[x].size();i++){
		int nex=G[x][i];
		dfs(nex);
		size[x]+=size[nex];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int x;
		scanf("%d%lld",&x,&a[i]);
		G[x].push_back(i);
	}
	dfs(1);
	long long ans=0;
	for(int i=2;i<=n;i++)
		ans+=a[i]*(long long)(size[i])*(long long)(n-size[i]);
	printf("%lld\n",ans);
	scanf("%d",&m);
	while(m--){
		int x;long long y;
		scanf("%d%lld",&x,&y);
		ans+=(y-a[x])*(long long)(size[x])*(long long)(n-size[x]);
		printf("%lld\n",ans);
		a[x]=y;
	}
}
