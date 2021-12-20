/*
描述
给定一个5*5的矩阵，每行只有一个最大值，每列只有一个最小值，寻找这个矩阵的鞍点。
鞍点指的是矩阵中的一个元素，它是所在行的最大值，并且是所在列的最小值。
例如：在下面的例子中（第4行第1列的元素就是鞍点，值为8 ）。
11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8 6 4 7 2
15 10 11 20 25

输入
输入包含一个5行5列的矩阵

输出
如果存在鞍点，输出鞍点所在的行、列及其值，如果不存在，输出"not found"
*/

#include<iostream>
#include<cstdio>

#define DEBUG 0

int main(){
	int a[5][5];
	int max,minState,totalState=0;

//	freopen("in","r",stdin);

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			scanf("%d",&a[i][j]);
		}
	}

	for(int i=0;i<5;i++){
		max=0;
		for(int j=1;j<5;j++){	//寻找该行最大值位置
			if(a[i][j]>a[i][max]) max=j;
		}

		#if DEBUG
			printf("max: a[%d][%d]=%d\n",i,max,a[i][max]);
		#endif

		minState=1;	//假设max为该列最小值
		for(int j=0;j<5;j++){
			if(a[i][max]>a[j][max]) minState=0;
		}

		#if DEBUG
			printf("a[%d][%d]: minState=%d\n",i,max,minState);
		#endif

		if(minState==1){
			totalState=1;
			printf("%d %d %d\n",i+1,max+1,a[i][max]);
		}
	}
	if(totalState==0) printf("not found\n");

	return 0;
}
