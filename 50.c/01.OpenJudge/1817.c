/*
描述

     1   2   3   4   5   6   7          N
   #############################      W   E
 1 #   |   #   |   #   |   |   #        S
   #####---#####---#---#####---#
 2 #   #   |   #   #   #   #   #
   #---#####---#####---#####---#
 3 #   |   |   #   #   #   #   #
   #---#########---#####---#---#
 4 #   #   |   |   |   |   #   #
   #############################
           (图 1)

   # = Wall   
   | = No wall
   - = No wall

图1是一个城堡的地形图。请你编写一个程序，计算城堡一共有多少房间，最大的房间有多大。城堡被分割成m*n(m≤50,n≤50)个方块，每个方块可以有0~4面墙。

输入
程序从标准输入设备读入数据。
第一行是两个整数，分别是南北向、东西向的方块数。在接下来的输入行里，每个方块用一个数字(0≤p≤50)描述。用一个数字表示方块周围的墙，1表示西墙，2表示北墙，4表示东墙，8表示南墙。每个方块用代表其周围墙的数字之和表示。城堡的内墙被计算两次，方块(1,1)的南墙同时也是方块(2,1)的北墙。输入的数据保证城堡至少有两个房间。

输出
两行，第一行为城堡的房间数，第二行为城堡中最大房间所包括的方块数。结果显示在标准输出设备上。
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,maxArea=0,curArea,tot=0;
int a[50][50],to[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
bool book[50][50];

void dfs(int x, int y);
inline bool canGo(int x, int y, int dir);

int main(void){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++)
		scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!book[i][j]){
		book[i][j]=1; curArea=0;
		dfs(i,j); tot++;
		maxArea=max(maxArea,curArea);
	}
	printf("%d\n%d\n",tot,maxArea);

	return 0;
}

void dfs(int x, int y){
	curArea++;
	for(int i=0;i<4;i++) if(canGo(x,y,i)){
		int tx=x+to[i][0], ty=y+to[i][1];
		if(tx<0 || tx>n-1 || ty<0 || ty>m-1) continue;
		if(book[tx][ty]) continue;
		#ifdef DEBUG
		printf("--(%d,%d) to (%d,%d)\n",x,y,tx,ty);
		#endif
		book[tx][ty]=1;
		dfs(tx,ty);
	}
}
inline bool canGo(int x, int y, int dir){
	return !((a[x][y]>>dir)&1);
}
