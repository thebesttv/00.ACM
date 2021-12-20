/*
描述
我们经常遇到两多项式相加的情况，在这里，我们就需要用程序来模拟实现把两个多项式相加到一起。首先，我们会有两个多项式，每个多项式是独立的一行，每个多项式由系数、幂数这样的多个整数对来表示。
如多项式2x^20 - x^17 + 5x^9 - 7x^7 + 16x^5 + 10x^4 + 22x^2 - 15
对应的表达式为：2 20 -1 17 5 9 -7 7 16 5 10 4 22 2 -15 0。  
为了标记每行多项式的结束，在表达式后面加上了一个幂数为负数的整数对。
同时输入表达式的幂数大小顺序是随机的。
我们需要做的就是把所给的两个多项式加起来。

输入
输入包括多行。
第一行整数n,表示有多少组的多项式需要求和。(1 < n < 100)
下面为2n行整数，每一行都是一个多项式的表达式。表示n组需要相加的多项式。
每行长度小于300。

输出
输出包括n行，每行为1组多项式相加的结果。
在每一行的输出结果中，多项式的每一项用“[x y]”形式的字符串表示，x是该项的系数、y 是该项的幂数。要求按照每一项的幂从高到低排列，即先输出幂数高的项、再输出幂数低的项。
系数为零的项不要输出。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX_TERM=300;
struct Poly{
	int coef;
	int expo;

	bool operator < (const Poly & b) const {
		return expo>b.expo;
	}
}a[MAX_TERM],b[MAX_TERM],c[MAX_TERM*2];
int terma,termb;

int read(Poly * a);
void insert(Poly * a, int coef, int expo);
void add(Poly * a, Poly * b, Poly * c);
void print(Poly * a);
void clear(Poly * a, int len);
int compare(int a, int b);

int main(void){
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		memset(a,0,sizeof(a)); memset(b,0,sizeof(b)); memset(c,0,sizeof(c));
		terma=read(a); termb=read(b);
		add(a,b,c);
		print(c);
	}

	return 0;
}

int read(Poly * a){
	int coef,expo,cou=0;
	while(scanf("%d%d",&coef,&expo)==2 && expo>=0){
		insert(a,coef,expo);
		cou++;
	}
	sort(a,a+cou);
	return cou;
}
void insert(Poly * a, int coef, int expo){
	int i;
	for(i=0;i<MAX_TERM;i++){
		if(!a[i].coef && !a[i].expo) break;
		if(a[i].expo==expo) break;
	}
	if(a[i].expo==expo){
		a[i].coef+=coef;
	}else{
		a[i].coef=coef; a[i].expo=expo;
	}
}
void add(Poly * a, Poly * b, Poly * c){
	int termc=0,cura=0,curb=0;
	for(;cura<terma && curb<termb;){
		switch(compare(a[cura].expo,b[curb].expo)){
			case 0:
				c[termc].expo=a[cura].expo;
				c[termc].coef=a[cura].coef+b[curb].coef;
				termc++; cura++; curb++;
				break;
			case -1:
				c[termc].expo=b[curb].expo;
				c[termc].coef=b[curb].coef;
				termc++; curb++;
				break;
			case 1:
				c[termc].expo=a[cura].expo;
				c[termc].coef=a[cura].coef;
				termc++; cura++;
		}
	}
	for(;cura<terma;){
		c[termc].expo=a[cura].expo;
		c[termc].coef=a[cura].coef;
		termc++; cura++;
	}
	for(;curb<termb;){
		c[termc].expo=b[curb].expo;
		c[termc].coef=b[curb].coef;
		termc++; curb++;
	}
	clear(c,termc);
	sort(c,c+termc);
}
void print(Poly * a){
	bool first=0;
	for(int i=0;i<MAX_TERM;i++){
		if(!a[i].expo && !a[i].coef) break;
		if(a[i].coef){
			if(!first) first=1;
			else printf(" ");
			printf("[ %d %d ]",a[i].coef,a[i].expo);
		}
	}
	printf("\n");
}
void clear(Poly * a, int len){
	for(int i=0;i<len;i++){
		if(!a[i].coef){
			a[i].coef=0; a[i].expo=0;
			int j;
			for(j=i;j<len;j++){
				a[j].expo=a[j+1].expo; a[j].coef=a[j+1].coef;
			}
		}
	}
}
int compare(int a, int b){
	return a==b ? 0 : (a>b ? 1 : -1);
}
