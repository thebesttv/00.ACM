#include<bits/stdc++.h>
using namespace std;

const int MAX = 1020;
int n,m;

struct Node{
	int x, y;
}v[MAX*MAX], G[MAX][MAX];
int color[MAX][MAX];

const int to[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

void dfs(int i, int j, int c){
	color[i][j] = c;
	for(int k=0;k<4;++k){
		int tx = i + to[k][0],
		    ty = j + to[k][1];
		if(tx<1 || tx>n || ty<1 || ty>m) continue;
		if(color[tx][ty]) continue;
		if(G[tx][ty].x == G[i][j].x + to[k][0]
		&& G[tx][ty].y == G[i][j].y + to[k][1])
			dfs(tx,ty,c);
	}
}

int up[MAX][MAX];
int lt[MAX][MAX];
int rh[MAX][MAX];

int main(void){
	scanf("%d%d",&n,&m);
	int x;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&x);
			v[x] = {i,j};
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&x);
			G[i][j] = v[x];
		}
	}

	int c = 0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!color[i][j]){
				dfs(i,j,++c);
			}
#ifdef DEBUG
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			printf("%d ",color[i][j]);
		printf("\n");
	}
#endif

	int ansMax = 0;
	memset(rh,0x3f,sizeof(rh));
	for(int i=1;i<=n;++i){
		int lo = 0, ro = m+1;
		for(int j=1;j<=m;++j){
			if(color[i][j] != color[i-1][j]){
				up[i][j] = 1;
			}else{
				up[i][j] = up[i-1][j] + 1;
			}

			if(color[i][j] != color[i][j-1]){
				lo = j;
			}
			if(color[i][j] == color[i-1][j])
				lt[i][j] = max(lt[i-1][j], lo);
			else lt[i][j] = lo;
		}
		for(int j=m;j>=1;--j){
			if(color[i][j] != color[i][j+1]){
				ro = j;
			}
			if(color[i][j] == color[i-1][j])
				rh[i][j] = min(rh[i-1][j], ro);
			else rh[i][j] = ro;
			ansMax = max(ansMax, up[i][j] * (rh[i][j] - lt[i][j] + 1));
#ifdef DEBUG
			printf("  (%d, %d) %d %d %d\n",i,j,up[i][j],lt[i][j],rh[i][j]);
#endif
		}
	}
	printf("%d\n",ansMax);

	return 0;
}
