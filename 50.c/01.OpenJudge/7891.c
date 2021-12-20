/*
描述
有形如：ax^3+bx^2+cx+d=0  这样的一个一元三次方程。
给出该方程中各项的系数(a，b，c，d  均为实数)，并约定该方程存在三个不同实根(根的范围在-100至100之间)，且根与根之差的绝对值>=1。要求由小到大依次在同一行输出这三个实根(根与根之间留有空格)，并精确到小数点后2位。

输入
一行，包含四个实数a，b，c，d，相邻两个数之间用单个空格隔开。

输出
一行，包含三个实数，为该方程的三个实根，按从小到大顺序排列，相邻两个数之间用单个空格隔开，精确到小数点后2位。
*/

#include<iostream>
#include<cstdio>
using namespace std;

const double EPS=1e-6;
double a,b,c,d;
double res[3]; int tail=0;

double f(double x){
	return ((a*x+b)*x+c)*x+d;
}

int main(void){
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	double t=-100;
	for(;t<100;t+=0.001){
		if(f(t)*f(t+0.001)<0) res[tail++]=t;
	}
	printf("%.2lf %.2lf %.2lf\n",res[0],res[1],res[2]);

	return 0;
}
