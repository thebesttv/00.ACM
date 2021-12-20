/*
描述
你买了一箱n个苹果，很不幸的是买完时箱子里混进了一条虫子。虫子每x小时能吃掉一个苹果，假设虫子在吃完一个苹果之前不会吃另一个，那么经过y小时你还有多少个完整的苹果？

输入
输入仅一行，包括n，x和y（均为整数）。

输出
输出也仅一行，剩下的苹果个数
*/

#include<iostream>
#include<cstdio>
#include<cmath>

int main(){
	int n,x,y;
	double apple;
	double eps=0.00000001;

	scanf("%d%d%d",&n,&x,&y);
	apple=double(y)/x;
	if(fabs(apple-int(apple))<eps)	//如果apple近似为整数
		printf("%d\n",n-int(apple) <0 ? 0 : n-int(apple));	//剩下苹果个数不能小于0
	else
		printf("%d\n",n-int(apple)-1 <0 ? 0 : n-int(apple)-1);

	return 0;
}
