#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=104;
bool G[MAX][MAX];
int c[MAX],topo[MAX];
int n,m,t;

bool topo_sort();
bool dfs(int u);

int main(void){
	while(scanf("%d%d",&n,&m)==2 && n){
		memset(G,0,sizeof(G)); memset(c,0,sizeof(c));
		int a,b;
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b); G[a-1][b-1]=1;	//<b>输入时要减 1 </b>
		}
		topo_sort();
		printf("%d",topo[0]+1);
		for(int i=1;i<n;i++) printf(" %d",topo[i]+1);
		printf("\n");
	}

	return 0;
}

bool topo_sort(){
	t=n;
	for(int u=0;u<n;u++) if(!c[u])
		if(!dfs(u)) return false;
	return true;
}
bool dfs(int u){
	c[u]=-1;
	for(int v=0;v<n;v++) if(G[u][v])
		if(c[v]<0) return false;
		else if(!c[v] && !dfs(v)) return false;
	c[u]=1; topo[--t]=u;
	return true;
}
