#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int ACCURACY=100;
const double e=2.718281828;
void Triangle(double a, double b, double c);
void Trapezoidal(double a, double b, double c, double d);
void Gaussian(double m, double u);
void BellShaped(double a, double b, double c);
void Sigmoid(double a, double b);

int main(void){
	freopen("miu","w",stdout);
	double a,b,c,d,m,u;

	printf("Triangle(x;a,b,c):\n");
	scanf("%lf%lf%lf",&a,&b,&c);
	Triangle(a,b,c);
	printf("\n");

	printf("Trapezoidal(x;a,b,c,d):\n");
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	Trapezoidal(a,b,c,d);
	printf("\n");

	printf("Gaussian(x;m,u):\n");
	scanf("%lf%lf",&m,&u);
	Gaussian(m,u);
	printf("\n");

	printf("Bell-Shaped(x;a,b,c):\n");
	scanf("%lf%lf%lf",&a,&b,&c);
	BellShaped(a,b,c);
	printf("\n");

	printf("Sigmoid(x;a,b):\n");
	scanf("%lf%lf",&a,&b);
	Sigmoid(a,b);

	return 0;
}

void Triangle(double a, double b, double c){
	double delta=(c-a)/ACCURACY,y;
	for(double x=0.0;x<a+c;x+=delta){
		y=max(min((x-a)/(b-a),(x-c)/(b-c)),0.0);
		printf("%lf\t%lf\n",x,y);
	}
}

void Trapezoidal(double a, double b, double c, double d){
	double delta=(d-a)/ACCURACY,y;
	for(double x=0.0;x<a+d;x+=delta){
		y=max(min((x-a)/(b-a),(x-d)/(c-d)),0.0);
		printf("%lf\t%lf\n",x,y);
	}
}

void Gaussian(double m, double u){
	double delta=2*m/ACCURACY,y;
	for(double x=0.0;x<2*m;x+=delta){
		y=1.0/(pow(e,0.5*((x-m)/u)*((x-m)/u)));
		printf("%lf\t%lf\n",x,y);
	}
}

void BellShaped(double a, double b, double c){
	double delta=2*c/ACCURACY,y;
	for(double x=0.0;x<2*c;x+=delta){
		y=1.0/(1+pow(abs((x-c)/a),2*b));
		printf("%lf\t%lf\n",x,y);
	}
}

void Sigmoid(double a, double b){
	double delta=2*b/ACCURACY,y;
	for(double x=0.0;x<x*b;x+=delta){
		y=1.0/(1+pow(e,-a*(x-b)));
		printf("%lf\t%lf\n",x,y);
	}
}
