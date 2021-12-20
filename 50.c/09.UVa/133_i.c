#include<iostream>
#include<cstdio>
using namespace std;

int a[30],n,k,m;

int go(int cur, int d, int k){
	for(int i=0;i<k;i++){
		do{
			cur=(cur+d+n)%n;
		}while(a[cur]==0);
	}
	return cur;
}

int main(void){
	while(scanf("%d%d%d",&n,&k,&m)==3 && n){
		for(int i=0;i<n;i++) a[i]=i+1;
		int A=n-1,B=0,remain=n;	//A，B的初始位置
		while(remain){
			#ifdef DEBUG
			printf("**%d**",remain);
			#endif
			A=go(A,1,k); B=go(B,-1,m);
			printf("%3d",a[A]); remain--;
			if(B!=A) {printf("%3d",a[B]); remain--;}
			if(remain) printf(",");
			a[A]=a[B]=0;	//<b>被选出的设为0，否则可能会无限循环</b>
							//因为当n为奇数时，某次进入while，remain可能为1，再自减两次，变成-1，成为死循环
		}
		printf("\n");
	}

	return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,k,m,remain;
int a[30];

int Go(int cur, int d, int k){	//d为步长
	while(k--){	//共走k次
		do{cur=(cur+d+n-1)%n + 1;} while(a[cur]==0);	//<b>cur=(cur+d+n-1)%n+1;</b>
	}
	return cur;
}

int main(void){
	while(scanf("%d%d%d",&n,&k,&m)==3 && n){
		remain=n; int A=n, B=1;	//第一次只要走k-1，m-1次
		for(int i=1;i<=n;i++) a[i]=i;
		int kase=0;
		while(remain){
			#ifdef DEBUG
			printf("  DEBUG: A: %d, B: %d\n",A,B);
			#endif
			A=Go(A,1,k), B=Go(B,-1,m);
			if(kase++) printf(",");
			printf("%3d",a[A]); remain--;
			if(A!=B) {printf("%3d",a[B]); remain--;}
			a[A]=a[B]=0;
		}
		printf("\n");
	}

	return 0;
}
*/
