#include<iostream>
#include<cstdio>
#include<cstring>

int main(void){
	int n,t;
	int a[100+4];
	while(scanf("%d",&n)){
		if(n==0) break;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){scanf("%d",&t); a[t]++;}
		int first=0;
		for(int i=1;i<=100;i++){
			for(int j=0;j<a[i];j++){
				if(first==1) printf(" ");
				printf("%d",i);
				first=1;
			}
		}
		printf("\n");
	}
	return 0;
}
