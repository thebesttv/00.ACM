/*
描述
利用公式e = 1 + 1/1! + 1/2! + 1/3! + ... + 1/n! 求e 。

输入
输入只有一行，该行包含一个整数n（2<=n<=15），表示计算e时累加到1/n！。

输出
输出只有一行，该行包含计算出来的e的值，要求打印小数点后10位。
*/

#include<iostream>
#include<cstdio>
using namespace std;

long long int a[20];	//阶乘不能用int存储

int main(void){
	double sum=1;
	int n;
	a[0]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i]=i*a[i-1];
		sum+=1.0/a[i];
	}
	printf("%.10lf\n",sum);

	return 0;
}
