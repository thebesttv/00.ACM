#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<queue>
using namespace std;

signed char a[240][240];
int r,c;
struct Node{
	int x,y;
}que[240*240];
char save[200];
int tSave=0;
//const char get[6] = {'W','A','K','J','S','D'};	//<b>不能用 get 命名变量</b>
const char token[6] = {'W','A','K','J','S','D'};
const int to[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int bfs(int x, int y, int tar, int col, int dir);
void dfs(int x, int y, int tar, int col);
void convert(int x, int y, char c);
void ind_search(int x, int y);
inline bool isInside(int x, int y);
void debug_print();

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif
	int kase=0;
	while(scanf("%d%d",&r,&c)==2 && r){
		memset(a,0,sizeof(a)); memset(save,0,sizeof(save)); tSave=0;
		char ch; getchar();
		for(int i=1;i<=r;i++){	//<b>从 a[1][1] 开始输入，防止象形文字占满边界</b>
			for(int j=1;j<=c;j++){
				ch=getchar();
				convert(i,j,ch);
			}
			getchar();
		}
		r+=2; c=(c+2)*4;	//<b>防止象形文字占满边界</b>
		bfs(0,0,0,-1,8);	//根据定义，外围白色背景是八连块，象形文字黑色和内部的才是四连块
//		bfs(0,0,0,-1,4);	//但实测输入与四连块或八连块无关
		#ifdef DEBUG
		printf("processed: r: %d, c: %d\n",r,c);
		debug_print();
		#endif

		for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(a[i][j]==1){
			ind_search(i,j);
			#ifdef DEBUG
			printf("after search:\n");
			debug_print();
			#endif
		}
		sort(save,save+tSave);	//不要忘了字典序输出
		printf("Case %d: ",++kase);
		for(int i=0;i<tSave;i++) printf("%c",save[i]);
		printf("\n");
	}

	return 0;
}

int bfs(int x, int y, int tar, int col, int dir){
	int head=0, tail=0;
	que[0].x=x; que[0].y=y; tail++;
	a[x][y]=col;
	while(head<tail){
		int tx,ty;
		if(dir==4){
			for(int i=0;i<4;i++){
				tx = que[head].x + to[i][0];
				ty = que[head].y + to[i][1];
				if(isInside(tx,ty) && a[tx][ty]==tar){
					que[tail].x=tx; que[tail++].y=ty; a[tx][ty]=col;
				}
			}
		}else{
			for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) if(i!=0 || j!=0){
				tx = que[head].x + i;
				ty = que[head].y + j;
				if(isInside(tx,ty) && a[tx][ty]==tar){
					que[tail].x=tx; que[tail++].y=ty; a[tx][ty]=col;
				}
			}
		}
		head++;
	}
	return tail;
}
void dfs(int x, int y, int tar, int col){
	int tx,ty;
	for(int i=0;i<4;i++){
		tx=x+to[i][0];
		ty=y+to[i][1];
		if(isInside(tx,ty) && a[tx][ty]==tar){
			a[tx][ty]=col;
			dfs(tx,ty,tar,col);
		}
	}
}
void convert(int x, int y, char c){
	int n; y*=4;
	if(isdigit(c)) n = c-'0';
	else n = c-'a'+10;
	#ifdef DEBUG
//	printf("  in convert(%d,%d,%c), %c -> %d\n",x,y,c,c,n);
	#endif
	for(int i=0;i<4;i++){
		a[x][y+i] = (n>>(3-i))&1;
	}
}
void ind_search(int x, int y){
	#ifdef DEBUG
	printf("  ind_search(%d,%d)\n",x,y);
	#endif
	int tail=bfs(x,y,1,-1,4);
	int tx,ty,col=2;
	for(int i=0;i<tail;i++){
		for(int j=0;j<4;j++){
			tx=que[i].x+to[j][0];
			ty=que[i].y+to[j][1];
			if(!isInside(tx,ty)) continue;
			if(a[tx][ty]==0)
				dfs(tx,ty,0,++col);
			#ifdef DEBUG
			if(a[tx][ty]==col) printf("    trying for (%d,%d), using dfs(%d,%d,%d,%d)\n",tx,ty,tx,ty,0,col);
			#endif
		}
	}
	#ifdef DEBUG
//	printf("    color: %d\n",col);
	#endif
	save[tSave++]=token[col-2];
}
inline bool isInside(int x, int y){
	return (x>=0 && x<=r-1 && y>=0 && y<=c-1);
}
void debug_print(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			if(a[i][j]==-1) printf("*");
			else printf("%d",a[i][j]);
		printf("\n");
	}
}
