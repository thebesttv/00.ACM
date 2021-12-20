#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>

int a[110];
char c[5];

int Get();
void Print(int n);

int main(void){
	int n;
	while(scanf("%d",&n)==1 && n){
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++) a[Get()]++;
		int first=0;
		for(int i=1;i<=100;i++){
			for(int j=0;j<a[i];j++){
				if(first!=0) putchar(' ');
				Print(i);
				first++;
			}
		}
		putchar('\n');
	}

	return 0;
}

int Get(){
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	int sum=c-'0';
	while(isdigit(c=getchar())) sum=sum*10+(c-'0');
	return sum;
}

void Print(int n){
	int i;
	for(i=0;n>0;i++){
		c[i]=n%10+'0'; n/=10;
	}
	for(int j=i-1;j>=0;j--) putchar(c[j]);
}
