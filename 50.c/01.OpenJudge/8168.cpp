/*
述
给出一个整数a和一个正整数n，求乘方a^n。

输入
一行，包含两个整数a和n。-1000000 <= a <= 1000000，1 <= n <= 10000。

输出
一个整数，即乘方结果。题目保证最终结果的绝对值不超过1000000。
*/

#include<iostream>
#include<cstdio>

int main(){
	long a,tot=1;
	int n;

	scanf("%ld%d",&a,&n);
	for(int i=0;i<n;i++){
		tot*=a;
	}
	printf("%ld\n",tot);

	return 0;
}
