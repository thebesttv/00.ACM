/*
描述
Sudoku is a very simple task. A square table with 9 rows and 9 columns is divided to 9 smaller squares 3x3 as shown on the Figure. In some of the cells are written decimal digits from 1 to 9. The other cells are empty. The goal is to fill the empty cells with decimal digits from 1 to 9, one digit per cell, in such way that in each row, in each column and in each marked 3x3 subsquare, all the digits from 1 to 9 to appear. Write a program to solve a given Sudoku-task.

输入
The input data will start with the number of the test cases. For each test case, 9 lines follow, corresponding to the rows of the table. On each line a string of exactly 9 decimal digits is given, corresponding to the cells in this line. If a cell is empty it is represented by 0.

输出
For each test case your program should print the solution in the same format as the input data. The empty cells have to be filled according to the rules. If solutions is not unique, then the program may print any one of them. 
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool dfs(int x, int y);
void setAll(int x, int y, int n, bool stat);
inline int getBlock(int x, int y);

int a[9][9];
bool used_row[9][10], used_col[9][10], used_block[9][10];

int main(void){
	int T; scanf("%d",&T); getchar();
	while(T--){
		memset(a,0,sizeof(a));
		for(int i=0;i<9;i++) for(int j=0;j<10;j++){
			used_row[i][j]=0; used_col[i][j]=0; used_block[i][j]=0;
		}
		int c;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				c=getchar();
				a[i][j] = c-'0';
				if(a[i][j]) setAll(i,j,a[i][j],1);
			}
			getchar();
		}
		bool flag=0;
		if(a[8][8]) flag=dfs(8,8);
		else{
			for(int i=1;i<=9;i++){
				a[8][8]=i; setAll(8,8,i,1);
				if(flag=dfs(8,8)) break;
				a[8][8]=0; setAll(8,8,i,0);
			}
		}
		if(flag){
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++) printf("%d",a[i][j]);
				printf("\n");
			}
		}else{
			printf("no answer\n");
		}
	}
	return 0;
}

bool dfs(int x, int y){
	if(x==0 && y==0) return true;
	int tx,ty;
	if(y==0) {tx=x-1; ty=8;}
	else {tx=x; ty=y-1;}
	if(a[tx][ty]) return dfs(tx,ty);
	else{
		for(int i=1;i<=9;i++){
			if(used_row[tx][i] || used_col[ty][i] || used_block[getBlock(tx,ty)][i]) continue;
			a[tx][ty]=i; setAll(tx,ty,i,1);
			if(dfs(tx,ty)) return true;
			a[tx][ty]=0; setAll(tx,ty,i,0);
		}
	}
	return false;
}
void setAll(int x, int y, int n, bool stat){
	used_row[x][n]=stat;
	used_col[y][n]=stat;
	used_block[getBlock(x,y)][n]=stat;
}
inline int getBlock(int x, int y){
	return (x/3)*3 + y/3;
}
