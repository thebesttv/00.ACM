#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char ori[100],gus[100];
bool win,lose;
int remain,drawn;

void Guess(char c, int len){
	bool correct=0;
	for(int i=0;i<len;i++) if(ori[i]==c){
		correct=1; remain--; ori[i]=' ';
	}
	if(!correct) drawn++;
	if(drawn==7) lose=1;
	if(remain==0) win=1;
}

int main(void){
	int kase;
	while(scanf("%d",&kase)==1 && kase!=-1){
		win=0; lose=0;
		scanf("%s%s",ori,gus);
		int len=strlen(gus),oL=strlen(ori);
		remain=strlen(ori); drawn=0;
		for(int i=0;i<len;i++){
			Guess(gus[i],oL);
			if(win || lose) break;
		}
		printf("Round %d\n",kase);
		if(win) printf("You win.\n");
		else if(lose) printf("You lose.\n");
		else printf("You chickened out.\n");
	}

	return 0;
}
