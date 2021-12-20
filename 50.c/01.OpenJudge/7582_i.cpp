/*
描述
读入n（1 <= n <= 10000）个整数，求它们的和与均值。

输入
输入第一行是一个整数n，表示有n个整数。
第2~n+1行每行包含1个整数。每个整数的绝对值均不超过10000。

输出
输出一行，先输出和，再输出平均值（保留到小数点后5位），两个数间用单个空格分隔。
*/

#include<iostream>
#include<cstdio>

int main(){
	int n,t,sum=0;
	double ave=0;

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		sum+=t;
/*		if(i==0) ave=temp;
		ave=(ave+t)/2;
*/	}
	ave=double(sum)/n;	//为什么在循环中连续连续计算平均数不对？ 答：精度问题
	printf("%d %.5lf\n",sum,ave);

	return 0;
}
