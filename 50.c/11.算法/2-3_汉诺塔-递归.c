//递归解决
#include<iostream>
#include<cstdio>
using namespace std;

void Hanoi(int n, char str, char mid, char dest){
	if(n==1){
		printf("%c -> %c\n",str,dest); return;
	}
	Hanoi(n-1,str,dest,mid);
	printf("%c -> %c\n",str,dest);
	Hanoi(n-1,mid,str,dest);
	return;
}

int main(void){
	int n;
	scanf("%d",&n);
	Hanoi(n,'A','B','C');

	return 0;
}
