/*
描述
给定n行m列的图像各像素点的灰度值，要求用如下方法对其进行模糊化处理：

1. 四周最外侧的像素点灰度值不变；

2. 中间各像素点新灰度值为该像素点及其上下左右相邻四个像素点原灰度值的平均（舍入到最接近的整数）。

输入
第一行包含两个整数n和m，表示图像包含像素点的行数和列数。1 <= n <= 100，1 <= m <= 100。
接下来n行，每行m个整数，表示图像的每个像素点灰度。相邻两个整数之间用单个空格隔开，每个元素均在0~255之间。

输出
n行，每行m个整数，为模糊处理后的图像。相邻两个整数之间用单个空格隔开。
*/

#include<iostream>
#include<cstdio>

#define DEBUG 0

int main(){
	double a[100][100];	//若用unsigned char定义数组，该怎么写？
	double b[100][100];
	int m,n;

	#if DEBUG
		freopen("in","r",stdin);
	#endif

	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%lf",&a[i][j]);
		}
	}

	#if DEBUG
		printf("original:\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%.0lf ",a[i][j]);
			}
			printf("\n");
		}
		printf("output:\n");
	#endif

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0 || i==n-1 || j==0 || j==m-1){
				b[i][j]=a[i][j];
			}
			else{
				b[i][j]=(a[i][j]+a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1])/5;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%.0lf ",b[i][j]);
		}
		printf("\n");
	}

	return 0;
}
