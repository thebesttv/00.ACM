#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int pat[32];
char temp[100];

void update(unsigned int t);
unsigned int read();
inline int getBit(int a, int n);

int main(void){
	int m;
	while(scanf("%d",&m)==1){
		memset(pat,0,sizeof(pat));
		unsigned int t;
		t=read();
		for(int i=0;i<32;i++) pat[i]=getBit(t,i);
		for(int i=1;i<m;i++){
			t=read();
			update(t);
		}
		int len=0; unsigned int IP=0;
		for(int i=31;i>=0;i--)
			if(pat[i]!=-1){
				IP=(IP<<1)+pat[i];
				len++;
			}else{
				IP<<=1;
			}
		#ifdef DEBUG
		printf("  pat:");
		for(int i=31;i>=0;i--){
			if((i+1)%8==0) putchar(' ');
			if(pat[i]==-1) putchar('X');
			else putchar(pat[i]+'0');
		}
		putchar('\n');
		printf("  len: %d\n",len);
		#endif
		printf("%d.%d.%d.%d\n",(char)(IP>>24),(char)(IP>>16),(char)(IP>>8),(char)(IP));
		IP=( ((unsigned)(~0)) >> (32-len) )<<(32-len);
		printf("%d.%d.%d.%d\n",(char)(IP>>24),(char)(IP>>16),(char)(IP>>8),(char)(IP));
	}

	return 0;
}

void update(unsigned int t){
	for(int i=31;i>=0;i--){
		if(pat[i]==getBit(t,i)) continue;
		for(int j=i;j>=0;j--) pat[j]=-1;
		break;
	}
}
unsigned int read(){
	scanf("%s",temp); unsigned int ans=0;
	char *p=strtok(temp,"."); ans=(unsigned)atoi(p);
	while((p=strtok(NULL,".")) != NULL)
		ans=(ans<<8)+(unsigned)atoi(p);
	#ifdef DEBUG
	printf("  read: ");
	printf("%d.%d.%d.%d\n",(char)(ans>>24),(char)(ans>>16),(char)(ans>>8),(char)(ans));
	#endif
	return ans;
}
inline int getBit(int a, int n){
	return (a>>n)&1==1;
}
