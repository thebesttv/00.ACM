#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char mahjong[][10]={
	"1T","2T","3T","4T","5T","6T","7T","8T","9T",
	"1S","2S","3S","4S","5S","6S","7S","8S","9S",
	"1W","2W","3W","4W","5W","6W","7W","8W","9W",
	"DONG","NAN","XI","BEI","ZHONG","FA","BAI"};
int a[34];

int Jiang(int n);
int Check(int n);
void Convert(char t[]);
void Print(int n);

int main(void){
	int kase=0; char temp[10];
	while(scanf("%s",temp)==1){
		if(temp[0]=='0') break;
		printf("Case %d:",++kase);
		int flag=0;
		memset(a,0,sizeof(a));
		Convert(temp);
		for(int i=0;i<12;i++){scanf("%s",temp); Convert(temp);}
		for(int i=0;i<34;i++){
			if(a[i]==4) continue;
			a[i]++;
			if(Jiang(0)==1) {Print(i); flag=1;}
			a[i]--;
		}
		if(flag==0) printf(" Not ready");
		printf("\n");
	}

	return 0;
}

int Jiang(int n){
	for(int i=0;i<34;i++){
		if(a[i]>=2){
			a[i]-=2;
			if(Check(n+1)==1){a[i]+=2; return 1;}
			a[i]+=2;
		}
	}
	return 0;
}

int Check(int n){
	if(n==5) return 1;
	for(int i=0;i<34;i++){
		if(a[i]>=3){
			a[i]-=3;
			if(Check(n+1)==1){a[i]+=3; return 1;}
			a[i]+=3;
		}
	}
	for(int i=0;i<34;i++){
		if(a[i]>=1 && a[i+1]>=1 && a[i+2]>=1 && i<=24 && i%9<=6){
			a[i]--;a[i+1]--;a[i+2]--;
			if(Check(n+1)==1){a[i]++;a[i+1]++;a[i+2]++; return 1;}
			a[i]++;a[i+1]++;a[i+2]++;
		}
	}
	return 0;
}

void Convert(char t[]){
	for(int i=0;i<34;i++)
		if(strcmp(t,mahjong[i])==0)
			a[i]++;
}

void Print(int n){
	printf(" %s",mahjong[n]);
}
