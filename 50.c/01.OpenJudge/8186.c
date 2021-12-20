/*
描述
有一个集合M是这样生成的：
(1) 已知 k 是集合 M 的元素；
(2) 如果 y 是 M 的元素，那么， 2y+1 和 3y+1 都是 M 的元素；
(3) 除了上述二种情况外，没有别的数能够成为 M 的一个元素。

问题：任意给定 k 和 x，请判断 x 是否是 M 的元素。这里的 k是无符号整数，x 不大于 100000， 如果是，则输出YES，否则，输出 NO

输入
输入整数 k 和 x, 逗号间隔。

输出
如果是，则输出 YES，否则，输出NO
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=100000;
bool a[MAX];

void ADD(int n){
	if(n>MAX) return;
	a[n]=true;
	ADD(2*n+1);
	ADD(3*n+1);
}

int main(void){
	int k,x;
	scanf("%d,%d",&k,&x);
	ADD(k);
	if(a[x]) printf("YES\n");
	else printf("NO\n");

	return 0;
}
