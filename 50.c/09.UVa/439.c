#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int INF=0x3f3f3f3f;
struct Node{
	int x,y,step;
};
int d[9][9];
int to[8][2]={{2,-1},{2,1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

void bfs(int x, int y){
	memset(d,0x3f,sizeof(d)); d[x][y]=0;
	queue<Node> q; q.push((Node){x,y,0});
	while(!q.empty()){
		Node t=q.front(); q.pop();
		for(int i=0;i<8;i++){
			int tx=t.x+to[i][0];
			int ty=t.y+to[i][1];
			//if(tx>=1 && tx<=15 && ty>=1 && ty<=15){
			if(tx>=1 && tx<=8 && ty>=1 && ty<=8){
				if(d[tx][ty]!=INF) continue;
				d[tx][ty]=t.step+1;
				q.push((Node){tx,ty,d[tx][ty]});
			}
		}
	}
}

int main(void){
	char start[3],end[3];
	while(scanf("%s%s",start,end)==2){
		int sx=9-(start[1]-'0'),sy=start[0]-'a'+1;
		int ex=9-(end[1]-'0'),ey=end[0]-'a'+1;
		bfs(sx,sy);
		printf("To get from %s to %s takes %d knight moves.\n",start,end,d[ex][ey]);
	}

	return 0;
}

/*
  不能使用“绝对图”，即先初始化一张很大的图（15*15）（终点在图的正中间(8,8)），
  然后对于每次询问，将标准图放在大图上面，两个终点对准，直接输出对应坐标的值。
  因为当终点在标准图的“边界”时，有一些点不能走到，而这些不能走到的点却被用来更新能走到的点。
    例子：a1 b2
*/

/*
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int INF=0x3f3f3f3f;
struct Node{
	int x,y,step;
};
int d[16][16];
int to[8][2]={{2,-1},{2,1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

void init(){
	queue<Node> q; q.push((Node){8,8,0});
	while(!q.empty()){
		Node t=q.front(); q.pop();
		for(int i=0;i<8;i++){
			int tx=t.x+to[i][0];
			int ty=t.y+to[i][1];
			if(tx>=1 && tx<=15 && ty>=1 && ty<=15){
				if(d[tx][ty]!=INF) continue;
				d[tx][ty]=t.step+1;
				q.push((Node){tx,ty,d[tx][ty]});
			}
		}
	}
}

int main(void){
	memset(d,0x3f,sizeof(d)); d[8][8]=0;
	init();
	//#ifdef DEBUG
	for(int i=1;i<=15;i++){
		for(int j=1;j<=15;j++) printf("%d ",d[i][j]); printf("\n");
	}
	//#endif
	char start[3],end[3];
	while(scanf("%s%s",start,end)==2){
		int sx=9-(start[1]-'0'),sy=start[0]-'a'+1;
		int ex=9-(end[1]-'0'),ey=end[0]-'a'+1;
		ex=8+ex-sx; ey=8+ey-sy;
		printf("To get from %s to %s takes %d knight moves.\n",start,end,d[ex][ey]);
	}

	return 0;
}
*/