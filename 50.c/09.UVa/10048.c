#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int INF=0x7fffffff;
int G[120][120];
int c,s,q;

int main(void){
	int kase=0;
	while(scanf("%d%d%d",&c,&s,&q)==3 && (c || s || q)){
		for(int i=1;i<=c;i++) for(int j=1;j<=c;j++) G[i][j]=INF;
		for(int i=1;i<=c;i++) G[i][i]=0;
		int u,v,w;
		for(int i=0;i<s;i++){
			scanf("%d%d%d",&u,&v,&w);
			G[u][v]=G[v][u]=min(G[u][v],w);
		}
		for(int k=1;k<=c;k++)
			for(int i=1;i<=c;i++)
				for(int j=1;j<=c;j++)
					G[i][j]=min(G[i][j],max(G[i][k],G[k][j]));
		if(kase) putchar('\n');
		printf("Case #%d\n",++kase);
		for(int i=0;i<q;i++){
			scanf("%d%d",&u,&v);
			if(G[u][v]==INF) printf("no path\n");
			else printf("%d\n",G[u][v]);
		}
	}
	return 0;
}
