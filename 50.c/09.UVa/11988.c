#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int MAX=100020;
char s[MAX];
int to[MAX];

int main(void){
	while(scanf("%s",s+1)==1){
		memset(to,0,sizeof(to));
		int last=0,cur=0;
		int len=strlen(s+1);
		for(int i=1;i<=len;i++){
			char ch=s[i];
			if(ch=='[') cur=0;
			else if(ch==']') cur=last;
			else{
				to[i]=to[cur];
				to[cur]=i;
				if(last==cur) last=i;
				cur=i;
			}
		}
		for(int i=to[0];i;i=to[i]) putchar(s[i]);
		putchar('\n');
	}

	return 0;
}
