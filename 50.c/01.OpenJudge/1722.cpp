/*
描述
一只大象口渴了，要喝20升水才能解渴，但现在只有一个深h厘米，底面半径为r厘米的小圆桶(h和r都是整数)。问大象至少要喝多少桶水才会解渴。

输入
输入有一行：包行两个整数，以一个空格分开，分别表示小圆桶的深h和底面半径r，单位都是厘米。

输出
输出一行，包含一个整数，表示大象至少要喝水的桶数。
*/

#include<iostream>
#include<cstdio>

int main(){
	double h,r,v,n;
	double pi=3.14159;
	scanf("%lf%lf",&h,&r);
	v=pi*r*r*h;
	n=20000/v;
	if(n-int(n)==0) printf("%d\n",int(n));	/*<b>判断是否为整数也可以用if(int(n)==n)</b>*/
	else		printf("%d\n",int(n)+1);	

	return 0;
}
