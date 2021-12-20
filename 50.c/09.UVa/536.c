#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int MAX=34;
char pre[MAX],mid[MAX];

void dfs(int pl, int pr, int ml, int mr){
	if(pl>pr || ml>mr) return;
	if(pl==pr && ml==mr){
		putchar(pre[pl]); return;
	}
	char root=pre[pl];
	int pos;
	for(pos=ml;pos<=mr;pos++) if(mid[pos]==root) break;
	dfs(pl+1,pos-ml+pl,ml,pos-1);
	dfs(pl+pos-ml+1,pr,pos+1,mr);
	putchar(root);
}

int main(void){
	while(scanf("%s%s",pre,mid)==2){
		int len=strlen(pre);
		dfs(0,len-1,0,len-1); putchar('\n');
		memset(pre,0,sizeof(pre)); memset(mid,0,sizeof(mid));
	}

	return 0;
}
