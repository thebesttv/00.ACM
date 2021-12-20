#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char token[8][(1<<7)+10];

bool convert();
int read(int len);

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif
	while(convert()){
		int len;
		while((len=read(3)) != 0){
			int t;
			while((t=read(len)) != ((1<<len)-1)){
				putchar(token[len][t]);
			}
		}
		putchar('\n'); getchar();
		memset(token,0,sizeof(token));
	}

	return 0;
}

bool convert(){
	bool first=0;
	for(int i=1;;i++){
		for(int j=0;j<(1<<i)-1;j++){
			int c=getchar();	//<b>getchar的返回值是int</b>
								//当getchar返回-1时，(c=getchar())==255
			if(c==EOF) return 0;
			if(c=='\n' || c=='\r') return 1;
			token[i][j]=c;
			#ifdef DEBUG
			printf("  token[%d][%d]: %c\n",i,j,c);
			#endif
		}
	}
}

int read(int len){
	int sum=0;
	while(len--){
		int c;
		do{
			c=getchar();
		}while(c=='\n' || c=='\r');
		sum=sum*2 + c - '0';
	}
	return sum;
}
