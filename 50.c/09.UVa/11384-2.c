//非递归形式
#include<stdio.h>
#include<stdlib.h>

int main(void){
	long long n, cou;
	while(scanf("%lld",&n)==1){
		cou=0;
		while(n>0){n/=2; cou++;}
		printf("%lld\n",cou);
	}

	return 0;
}
