#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
using namespace std;

const int MAX_LEN=100;
char a[MAX_LEN];

int eval(char a[]);

int main(void){
	fgets(a,sizeof(a),stdin);
	printf("%d\n",eval(a));

	return 0;
}

int eval(char a[]){
	int st[MAX_LEN],top=0;
	int len=strlen(a),x,y,r;
	for(int i=0;i<len;i++){
		if(isdigit(a[i])){
			st[top++]=a[i]-'0'; continue;
		}else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/' || a[i]=='%'){
			y=st[--top]; x=st[--top];
			switch(a[i]){
				case '+': r=x+y; break;
				case '-': r=x-y; break;
				case '*': r=x*y; break;
				case '/': r=x/y; break;
				case '%': r=x%y; break;
			}
			st[top++]=r;
		}
	}
	return st[0];
}
