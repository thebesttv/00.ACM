//TLE
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=80;
bool a[MAX][MAX],book[MAX][MAX];
int w,h,strx,stry,endx,endy,Min;
int Next[4][2]={{0,1},{0,-1},{1,0},{-1,0}};	//Next一定要大写，否则会CE

void dfs(int x, int y, int step, int dir);

int main(void){
#ifdef LOCAL
	freopen("in","r",stdin);
#endif
	int kase=1;
	while(scanf("%d%d",&w,&h)==2 && w){
		memset(a,0,sizeof(a)); memset(book,0,sizeof(book));
		char c;
		for(int i=1;i<=h;i++) for(int j=1;j<=w;j++){
			c=getchar();
			while(c!=' ' && c!='X') c=getchar();
			a[i][j]=(c=='X' ? 1 : 0);
		}
#ifdef DEBUG
printf("map readed\n");
for(int i=1;i<=h;i++){
	for(int j=1;j<=w;j++) printf("%c",(a[i][j] ? 'x' : ' '));
	printf("\n");
}
#endif
		printf("Board #%d:\n",kase++);
		int kkase=1;
		while(scanf("%d%d%d%d",&stry,&strx,&endy,&endx) && strx){
			printf("Pair %d: ",kkase++);
			Min=1<<20;
			book[strx][stry]=1;
			dfs(strx,stry,0,-1);
			if(Min<1<<20) printf("%d segments.\n",Min);
			else printf("impossible.\n");
			book[strx][stry]=0;
		}
	}

	return 0;
}

void dfs(int x, int y, int step, int dir){
	if(step>Min) return;
	if(x==endx && y==endy){
		Min=min(step,Min);
		return;
	}
	for(int i=0;i<4;i++){
		int tx=x+Next[i][0];
		int ty=y+Next[i][1];
		if(book[tx][ty] || (a[tx][ty] && !(tx==endx && ty==endy))) continue;
		if(x<0 || x>h+2 || y<0 || y>w+2) continue;
		book[tx][ty]=1;
		if(i==dir) dfs(tx,ty,step,dir);
		else dfs(tx,ty,step+1,i);
		book[tx][ty]=0;
	}
}
