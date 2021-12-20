//筛法求素数，原版

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100000000

#define TRUE 0
#define FALSE 1
bool a[MAX];

int main(void){
	long long cou=0;
	a[0]=FALSE;a[1]=FALSE;
	for(long long i=2;i<MAX;i++)
		if(a[i]==TRUE)
			for(long long j=i*2;j<MAX;j+=i) a[j]=FALSE;
	for(long long i=0;i<MAX;i++) if(a[i]==TRUE) cou++;
	printf("%lld\n",cou);

	return 0;
}
