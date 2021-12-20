/*
描述
假定多项式的形式为x^n+x^(n-1)+…+x^2+x+1，请计算给定单精度浮点数x和正整数n值的情况下这个多项式的值。

输入
输入仅一行，包括x和n，用单个空格隔开。x在float范围内，n <= 1000000。

输出
输出一个实数，即多项式的值，精确到小数点后两位。保证最终结果在float范围内。
*/

#include<iostream>
#include<cstdio>
using namespace std;

int main(void){
	float n,x,t,sum=1;
	scanf("%f%f",&x,&n);
	t=x;
	for(int i=0;i<n;i++){
		sum+=t;
		t*=x;
	}
	printf("%.2f\n",sum);

	return 0;
}
