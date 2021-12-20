/*
描述
给出一个含有n（0 < n <= 1000）个整数的数组，请找出其中出现次数超过一半的数。

数组中的数大于-50且小于50。

输入
第一行包含一个整数n，表示数组大小；
第二行包含n个整数，分别是数组中的每个元素，相邻两个元素之间用单个空格隔开。

输出
如果存在这样的数，输出这个数；否则输出no。
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[1000+10],n,app;

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);  //在一有序数列中，若一个数出现次数超过一半，那么它一定会出现在数列的正中间
	int t=a[n/2];
	for(int i=0;i<n;i++) if(a[i]==t) app++;
	if(app>n/2) printf("%d\n",t);
	else  printf("no\n");

	return 0;
}

/*
//计数
int a[1000+10],n,app[110];

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++) {scanf("%d",&a[i]); a[i]+=50; app[a[i]]++;}
	int flag=0;
	for(int i=0;i<110;i++)
		if(app[i]>n/2) {flag=i; break;}
	if(flag==0) printf("NO\n");
	else printf("%d\n",flag-50);

	return 0;
}
*/
