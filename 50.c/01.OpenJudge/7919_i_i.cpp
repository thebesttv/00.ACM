/*
描述
给定一个整数，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零。

输入
输入共 1 行，一个整数N，-1,000,000,000 ≤ N≤ 1,000,000,000。

输出
输出共 1 行，一个整数，表示反转后的新数。
*/

#include<iostream>
#include<cstdio>
#include<cmath>		//使用abs函数时两条都需要
using namespace std;	//

int main(){
	long n;
	int a[20];
	int i,j;

	scanf("%ld",&n);
	if(n!=0){
		a[0]=(n>=0 ? 0 : 1);
		n=abs(n);
		for(i=1;n;i++){	//将n倒序输入数组(若n高位有一个或多个0，那几个0不计入数组)
			a[i]=n%10;
			n/=10;
		}
		if(a[0]) printf("-");	//判断是否输出负号
		j=1;
		for(;a[j]==0;j++);	//逆序输出时开头可能有多个0
		for(;j<i;j++){
			printf("%d",a[j]);
		}
		printf("\n");
	}else{
		printf("0\n");
	}

	return 0;
}

/*
//网络答案，c语言
#include<stdio.h>

int main(){
	int n,f=0,t;

	scanf("%d",&n);
	if(n==0){
		printf("%d\n",n);
	}else{
		if(n<0){
			f=1;//表示n是负数
			n=-n;
		}
		t=0;
		while(n>0){
			t=n%10+t*10;
			n/=10;
		}
		if(f==1) printf("-");
		printf("%d\n",t);
	}
	return 0;
}
*/
