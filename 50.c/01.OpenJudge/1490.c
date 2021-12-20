/*
背景
The knight is getting bored of seeing the same black and white squares again and again and has decided to make a journey
around the world. Whenever a knight moves, it is two squares in one direction and one square perpendicular to this. The world of a knight is the chessboard he is living on. Our knight lives on a chessboard that has a smaller area than a regular 8 * 8 board, but it is still rectangular. Can you help this adventurous knight to make travel plans?

描述
Find a path such that the knight visits every square once. The knight can start and end on any square of the board.

输入
The input begins with a positive integer n in the first line. The following lines contain n test cases. Each test case consists of a single line with two positive integers p and q, such that 1 <= p * q <= 26. This represents a p * q chessboard, where p describes how many different square numbers 1, . . . , p exist, q describes how many different square letters exist. These are the first q letters of the Latin alphabet: A, . . .

输出
The output for every scenario begins with a line containing "Scenario #i:", where i is the number of the scenario starting at 1. Then print a single line containing the lexicographically first path that visits all squares of the chessboard with knight moves followed by an empty line. The path should be given on a single line by concatenating the names of the visited squares. Each square name consists of a capital letter followed by a number.
If no such path exist, you should output impossible on a single line.
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct Node{
	int x,y;
}rec[26*26];
bool board[26][26],flag;
int r,c,des;
int to[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

void dfs(int x, int y, int step);

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int T; scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		flag=0; memset(board,0,sizeof(board));
		scanf("%d%d",&c,&r); des=c*r;
/*		for(int i=0;i<r;i++) for(int j=0;j<c;j++)
			if(!flag){
				rec[0].x=i; rec[0].y=j;
				board[i][j]=1; dfs(i,j,1); board[i][j]=0;
			}else break;
*/
		rec[0].x=0; rec[0].y=0;
		board[0][0]=1; dfs(0,0,1); board[0][0]=0;
		if(kase) printf("\n");
		printf("Scenario #%d:\n",kase+1);
		if(flag)
			for(int i=0;i<des;i++) printf("%c%d",rec[i].x+'A',rec[i].y+1);
		else
			printf("impossible");
		printf("\n");
	}
	return 0;
}

void dfs(int x, int y, int step){
	if(step==des) {flag=1; return;}
	int tx,ty;
	for(int i=0;i<8;i++){
		if(flag) return;
		tx=x+to[i][0]; ty=y+to[i][1];
		if(tx<0 || tx>r-1 || ty<0 || ty>c-1) continue;
		if(board[tx][ty]) continue;
		#ifdef DEBUG
		for(int j=0;j<step;j++) printf("  ");
		printf("%d: %c%d\n",step,tx+'A',ty+1);
		#endif
		board[tx][ty]=1; rec[step].x=tx; rec[step].y=ty;
		dfs(tx,ty,step+1);
		board[tx][ty]=0;
	}
}
