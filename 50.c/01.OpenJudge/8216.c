/*
描述
编写程序，计算下列分段函数y=f(x)的值。

y=-x+2.5; 0 <= x < 5

y=2-1.5(x-3)(x-3); 5 <= x < 10

y=x/2-1.5; 10 <= x < 20

输入
一个浮点数N,0 <= N < 20
输出
输出N对应的分段函数值：f(N)。结果保留到小数点后三位。
*/

#include<iostream>
#include<cstdio>
using namespace std;

//const double EPS=1e-10;

int main(void){
	double x,y;
	scanf("%lf",&x);
	if(x<5)
		y=-x+2.5;
	else if(x<10)
		y=2-1.5*(x-3)*(x-3);
	else
		y=x/2.0-1.5;
	printf("%.3lf\n",y);

	return 0;
}
