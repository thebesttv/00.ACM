#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[310],m,n;

int main(void){
	scanf("%d%d",&n,&m);
		memset(a,-1,sizeof(a));
		for(int i=1;i<=n;i++) a[i]=i;
		int cou=1,cur=1;
		while(cou<n){
			for(int i=0;i<=m;){
				if(a[cur]!=-1) i++;
				if(i==m){
					a[cur]=-1; i++;
				}
				cur=(cur+1)%(n+1);
			}
			cou++;
		}
		for(int i=1;i<=n;i++) if(a[i]!=-1) printf("%d\n",i);

	return 0;
}
