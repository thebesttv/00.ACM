/*
描述
利用公式x1 = (-b + sqrt(b*b-4*a*c))/(2*a), x2 = (-b - sqrt(b*b-4*a*c))/(2*a)求一元二次方程ax2+ bx + c =0的根，其中a不等于0。

输入
输入一行，包含三个浮点数a, b, c（它们之间以一个空格分开），分别表示方程ax2 + bx + c =0的系数。

输出
输出一行，表示方程的解。
若b2 = 4 * a * c,则两个实根相等，则输出形式为：x1=x2=...。
若b2 > 4 * a * c,则两个实根不等，则输出形式为：x1=...;x2 = ...，其中x1>x2。
若b2 < 4 * a * c，则有两个虚根，则输出：x1=实部+虚部i; x2=实部-虚部i，即x1的虚部系数大于等于x2的虚部系数，实部为0时不可省略。实部 = -b / (2*a), 虚部 = sqrt(4*a*c-b*b) / (2*a)
所有实数部分要求精确到小数点后5位，数字、符号之间没有空格。
*/

#include<iostream>
#include<cstdio>
#include<cmath>	//cmath中包含sqrt函数

int main(){
	double a,b,c;
	double x1,x2;
	double squb,fac,i;
	double eps=0.0000001;

	scanf("%lf%lf%lf",&a,&b,&c);
	squb=b*b;
	fac=4*a*c;
	if(fabs(squb-fac)<eps){	//判断两个浮点数相等不能用a==b，要用a-b>-eps && a-b<eps，即fabs(a-b)<eps
		x1=(-b+sqrt(squb-fac))/(2*a);	//sqrt函数用于开方
		printf("x1=x2=%.5lf\n",x1);
	}else if(squb>fac){
		x1=(-b+sqrt(squb-fac))/(2*a);
		x2=(-b-sqrt(squb-fac))/(2*a);
		printf("x1=%.5lf;x2=%.5lf\n",x1,x2);
	}else if(squb<fac){
		x1=((fabs(-b/(2*a))<eps) ? 0 : -b/(2*a));
		x2=x1;
		i=sqrt(fac-squb)/(2*a);
		printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n",x1,i,x2,i);
	}

	return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cmath>	//cmath中包含sqrt函数

int main(){
	double a,b,c;
	double x1,x2;
	double squb,fac,i;

	scanf("%lf%lf%lf",&a,&b,&c);
	squb=b*b;
	fac=4*a*c;
	if(squb==fac){
		x1=(-b+sqrt(squb-fac))/(2*a);	//sqrt函数用于开方
		printf("x1=x2=%.5lf\n",x1);
	}else if(squb>fac){
		x1=(-b+sqrt(squb-fac))/(2*a);
		x2=(-b-sqrt(squb-fac))/(2*a);
		printf("x1=%.5lf;x2=%.5lf\n",x1,x2);
	}else if(squb<fac){
		x1=(-b/(2*a)==0 ? 0 : -b/(2*a));
		x2=x1;
		i=sqrt(fac-squb)/(2*a);
		printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n",x1,i,x2,i);
	}

	return 0;
}
*/
