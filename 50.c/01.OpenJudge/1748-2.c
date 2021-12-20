#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[310],m,n;

int main(void){
	while(scanf("%d%d",&n,&m)==2 && n){
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++) a[i]=i+1;
		int cur=0;
		for(int cou=0;cou<n-1;cou++){
			for(int i=0;i<m;){
				if(a[cur]) i++;
				if(i==m) a[cur]=0;
				cur=(cur+1)%n;
			}
		}
		for(int i=0;i<n;i++) if(a[i]){
			printf("%d\n",i+1); break;
		}
	}

	return 0;
}
