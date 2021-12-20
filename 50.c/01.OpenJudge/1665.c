/*
描述
一张普通的国际象棋棋盘，它被分成 8 乘 8 (8 行 8 列) 的 64 个方格。设有形状一样的多米诺牌，每张牌恰好覆盖棋盘上相邻的两个方格，即一张多米诺牌是一张 1 行 2 列或者 2 行 1 列的牌。那么，是否能够把 32 张多米诺牌摆放到棋盘上，使得任何两张多米诺牌均不重叠，每张多米诺牌覆盖两个方格，并且棋盘上所有的方格都被覆盖住？我们把这样一种排列称为棋盘被多米诺牌完美覆盖。这是一个简单的排列问题，同学们能够很快构造出许多不同的完美覆盖。但是，计算不同的完美覆盖的总数就不是一件容易的事情了。不过，同学们 发挥自己的聪明才智，还是有可能做到的。
现在我们通过计算机编程对 3 乘 n 棋盘的不同的完美覆盖的总数进行计算。

任务
对 3 乘 n 棋盘的不同的完美覆盖的总数进行计算。

输入
一次输入可能包含多行，每一行分别给出不同的 n 值 ( 即 3 乘 n 棋盘的列数 )。当输入 -1 的时候结束。
n 的值最大不超过 30.

输出
针对每一行的 n 值，输出 3 乘 n 棋盘的不同的完美覆盖的总数。
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX=34;
int save[1000],mul[MAX];
long long sum=0;

void f(int n, int step){
	if(n==0){
		long long temp=1;
		for(int i=0;i<step;i++){
			temp*=mul[save[i]];
		}
		sum+=temp;
		return;
	}
	for(int i=2;i<=n;i+=2){
		save[step]=i;
		f(n-i,step+1);
	}

}

int main(void){
	mul[2]=3; for(int i=3;i<MAX;i++) mul[i]=2;
	int n;
	while(scanf("%d",&n) && n!=-1){
		sum=0;
		if(!(n&1)) f(n,0);
		printf("%lld\n",sum);
	}

	return 0;
}
