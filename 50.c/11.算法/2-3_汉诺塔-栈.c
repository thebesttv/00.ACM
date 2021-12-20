//栈解决
#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=100;
struct Stack{
	int n;
	char str;
	char mid;
	char dest;
}stk[MAX*3];
int tail=0;

void Push(int n, char str, char mid, char dest){
	stk[tail].n=n; stk[tail].str=str; stk[tail].mid=mid; stk[tail].dest=dest;
	tail++;
}

int main(void){
	int n; scanf("%d",&n);
	if(n>MAX) printf("too big\n");
	Push(n,'A','B','C');
	while(tail>0){
		if(stk[tail-1].n==1){
			tail--;
			printf("%c -> %c\n",stk[tail].str,stk[tail].dest);
		}else{
			Stack temp; tail--;
			temp.n=stk[tail].n; temp.str=stk[tail].str;
			temp.mid=stk[tail].mid; temp.dest=stk[tail].dest;
			Push(temp.n-1,temp.mid,temp.str,temp.dest);
			Push(1,temp.str,temp.mid,temp.dest);
			Push(temp.n-1,temp.str,temp.dest,temp.mid);
		}
	}

	return 0;
}
