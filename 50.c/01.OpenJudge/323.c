/*
描述
在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。

输入
输入含有多组测试数据。
每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。n<=8, k<=n
当为-1 -1时表示输入结束。
随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。
 ...#
 ..#.
 .#..
 #...

输出
    对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。
*/

//直接存储地图
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool board[10][10];
struct Node{
	int x,y;
}ind[10];
int n,k,cou;

void dfs(int x, int y, int used){
	#ifdef DEBUG
	for(int i=0;i<used;i++) printf("  ");
	printf("dfs(%d,%d,%d)\n",x,y,used);
	#endif
	if(used==k) {cou++; return;}
	for(int i=x+1;i<n;i++) for(int j=0;j<n;j++) if(board[i][j]){
		bool ok=1;
		for(int m=used-1;m>=0;m--) if(ind[m].x==i || ind[m].y==j){
			ok=0; break;
		}
		if(!ok) continue;
		ind[used].x=i; ind[used].y=j;
		dfs(i,j,used+1);
	}
}

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif
	while(scanf("%d%d",&n,&k)==2 && n!=-1){
		int c,tail=0; cou=0; memset(board,0,sizeof(board)); memset(ind,0,sizeof(ind));
		for(int i=0;i<n;i++) for(int j=0;j<n;j++){
				do c=getchar(); while(c!='.' && c!='#');
				board[i][j]=(c=='#' ? 1 : 0);
		}
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(board[i][j]){
			ind[0].x=i; ind[0].y=j;
			dfs(i,j,1);
		}
		printf("%d\n",cou);
	}
	return 0;
}

/*
//用结构体存储地图，慢
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class Node{
public:
	int x,y;
}ind[8],canPut[64];
int n,k,cou,tail;

void dfs(int n, int step){
	if(step==k) {cou++; return;}
	for(int i=n+1;i<tail;i++){
		if(canPut[i].x==ind[step-1].x || canPut[i].y==ind[step-1].y) continue;
		bool ok=1;
		for(int j=0;j<step-1;j++) if(ind[j].x==canPut[i].x || ind[j].y==canPut[i].y){
			ok=0; break;
		}
		if(!ok) continue;
		ind[step].x=canPut[i].x; ind[step].y=canPut[i].y;
		dfs(i,step+1);
	}
}

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif
	while(scanf("%d%d",&n,&k)==2 && n!=-1){
		tail=0; cou=0; memset(ind,0,sizeof(ind)); memset(canPut,0,sizeof(canPut));
		getchar();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) if(getchar()=='#'){
				canPut[tail].x=i; canPut[tail++].y=j;
			}
			getchar();
		}
		for(int i=0;i<=(tail-k);i++){
			ind[0]=canPut[i];
			dfs(i,1);
		}
		printf("%d\n",cou);
	}
	return 0;
}
*/
