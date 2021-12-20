#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int MAX=320;
struct Edge{
	int from,to,a,b,t;
};
struct Node{
	int u,d;
	bool operator < (const Node & b) const {
		return d>b.d;
	}
};
vector<Edge> edge;
vector<int> G[MAX];
int n,m,s,t;
int d[MAX];

void Dij(int s){
	memset(d,0x3f,sizeof(d)); d[s]=0;
	priority_queue<Node> q; q.push((Node){s,0});
	while(!q.empty()){
		Node t=q.top(); q.pop();
		int u=t.u;
		if(d[u]!=t.d) continue;
		for(int i=0;i<G[u].size();i++){
			Edge & e=edge[G[u][i]];
			int left=e.a-d[u]%(e.a+e.b);
			if(left>=e.t) d[e.to]=min(d[e.to],d[u]+e.t);
			else d[e.to]=min(d[e.to],d[u]+left+e.b+e.t);
			q.push((Node){e.to,d[e.to]});
		}
	}
}

int main(void){
	int kase=0;
	while(scanf("%d%d%d%d",&n,&m,&s,&t)==4){
//printf("n: %d, m: %d, s: %d, t: %d\n",n,m,s,t);
		for(int i=0;i<=n;i++) G[i].clear(); edge.clear();
		int u,v,a,b,tt;
		for(int i=0;i<m;i++){
			scanf("%d%d%d%d%d",&u,&v,&a,&b,&tt);
			edge.push_back((Edge){u,v,a,b,tt});
			G[u].push_back(edge.size()-1);
		}
		Dij(s);
//for(int i=0;i<=n;i++) printf("d[%d]: %d\n",i,d[i]);
		printf("Case %d: %d\n",++kase,d[t]);
	}
	return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

const int MAX=320;
int n,m,s,t;
bool G[MAX][MAX];
struct Edge{
	int a,b,t;
}edge[MAX][MAX];
struct Node{
	int d,u;
	bool operator < (const Node & b) const {
		return d>b.d;
	}
};
int d[MAX];

inline int timeLeft(int u, int v, int t){
	Edge & e=edge[u][v];
	return e.a-t%(e.a+e.b);
}
void Dij(int s){
	memset(d,0x3f,sizeof(d)); d[s]=0;
	priority_queue<Node> q; q.push((Node){0,s});
	while(!q.empty()){
		Node t=q.top(); q.pop();
		int u=t.u;
		if(d[u]!=t.d) continue;
		for(int i=1;i<=n;i++) if(G[u][i]){
			Edge & e=edge[u][i];
			int left=timeLeft(u,i,d[u]);
			if(left>=e.t) d[i]=min(d[i],d[u]+e.t);
			else d[i]=min(d[i],d[u]+left+e.b+e.t);
			q.push((Node){d[i],i});
		}
	}
}

int main(void){
	//freopen("in.txt","r",stdin);
	int kase=0;
	while(scanf("%d%d%d%d",&n,&m,&s,&t)==4){
//printf("n: %d, m: %d, s: %d, t: %d\n",n,m,s,t);
		memset(G,0,sizeof(G)); memset(edge,0,sizeof(edge));
		int u,v,a,b,tt;
		for(int i=0;i<m;i++){
			scanf("%d%d%d%d%d",&u,&v,&a,&b,&tt);
			G[u][v]=1;
			edge[u][v].a=a;
			edge[u][v].b=b;
			edge[u][v].t=tt;
		}
		Dij(s);
//for(int i=0;i<=n;i++) printf("d[%d]: %d\n",i,d[i]);
		printf("Case %d: %d\n",++kase,d[t]);
	}
	return 0;
}
*/
