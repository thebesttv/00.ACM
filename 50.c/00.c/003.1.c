//筛法求素数，优化版
//数组中只存储基数

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100000000

#define TRUE 0
#define FALSE 1
bool a[MAX/2];

int main(void){
	long long tot=MAX/2-1,cou=0;
	for(long long i=0;i<tot;i++)
		if(a[i]==TRUE)
			for(long long j=i*2+3;j<tot;j+=i*2+3) a[j]=FALSE;
	a[0]=TRUE;
	for(long long i=0;i<tot;i++) if(a[i]==TRUE) cou++;
	printf("%lld\n",cou+1);

	return 0;
}
