/*
有函数：

f(x) = x^5 - 15 * x^4+ 85 * x^3- 225 * x^2+ 274 * x - 121

已知 f(1.5) > 0 , f(2.4) < 0 且方程 f(x) = 0 在区间 [1.5,2.4] 有且只有一个根，请用二分法求出该根。

输入
无。

输出
该方程在区间[1.5,2.4]中的根。要求四舍五入到小数点后6位。
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const double EPS=1e-8;

double f(double x){
	return x*x*x*x*x - 15*x*x*x*x + 85*x*x*x - 225*x*x + 274*x -121;
}

int main(void){
	double L=1.5,R=2.4;
	while(fabs(L-R)>EPS){
		double M=L+(R-L)/2;
		if(f(M)>EPS) L=M;
		else R=M;
	}
	printf("%.6lf\n",(double)floor(L*1e6+0.5)/1e6);	//四舍五入
	return 0;
}
