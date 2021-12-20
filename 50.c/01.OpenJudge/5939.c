/*
描述
定义一个数组，初始化为空。在数组上执行两种操作：
1、增添1个元素，把1个新的元素放入数组。
2、输出并删除数组中最小的数。
使用堆结构实现上述功能的高效算法。

输入
第一行输入一个整数t，代表测试数据的组数。
对于每组测试数据，第一行输入一个整数n，代表操作的次数。
每次操作首先输入一个整数type。
当type=1，增添操作，接着输入一个整数u，代表要插入的元素。
当type=2，输出删除操作，输出并删除数组中最小的元素。
1<=n<=100000。

输出
每次删除操作输出被删除的数字。

提示
每组测试数据的复杂度为O(nlgn)的算法才能通过本次，否则会返回TLE(超时)
需要使用最小堆结构来实现本题的算法
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[100000],tail=0;

void Insert(int n){
	a[tail]=n;
	int i=(tail-1)/2, j=tail; tail++;
	while(a[i]>a[j] && i>=0){
		swap(a[i],a[j]);
		j=i; i=(j-1)/2;
	}
}
void Delete(){
	printf("%d\n",a[0]);
	a[0]=a[tail-1]; a[--tail]=0;
	int i=0,j=1;
	while(j<tail){
		if(j+1<tail && a[j+1]<a[j]) j++;
		if(a[j]>=a[i]) break;
		swap(a[i],a[j]);
		i=j; j=i*2+1;
	}
}

int main(void){
	int T; scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		tail=0; memset(a,0,sizeof(a));
		int t; scanf("%d",&t);
		int type,n;
		for(int i=0;i<t;i++){
			scanf("%d",&type);
			if(type==1){
				scanf("%d",&n);
				Insert(n);
			}else{
				Delete();
			}
		}
	}

	return 0;
}
