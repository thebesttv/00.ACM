/*
描述
试计算在区间 1 到 n 的所有整数中，数字 x（0 ≤ x ≤ 9）共出现了多少次？例如，在 1 到 11 中，即在 1、2、3、4、5、6、7、8、9、10、11 中，数字 1 出现了 4 次。

输入
输入共 1 行，包含 2 个整数 n、x，之间用一个空格隔开。

输出
输出共 1 行，包含一个整数，表示 x 出现的次数
*/

#include<iostream>
#include<cstdio>
using namespace std;

int n,x;

int count(int n){
	int sum=0;
	while(n>0){
		if(n%10==x) sum++;
		n/=10;
	}
	return sum;
}

int main(void){
	scanf("%d%d",&n,&x);
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=count(i);
	printf("%d\n",sum);
	return 0;
}

