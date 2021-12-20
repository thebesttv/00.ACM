#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[104][104],r,c;
int check[104][104];
int Next[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int maxLen(int x, int y){
	if(check[x][y]) return check[x][y];
	int maxl=1;
	for(int i=0;i<4;i++){
		int tx=x+Next[i][0];
		int ty=y+Next[i][1];
		if(tx<0 || tx>r-1 || ty<0 || ty>c-1) continue;
		if(a[tx][ty]<a[x][y]){
			maxl=max(maxl,maxLen(tx,ty)+1);
		}
	}
	return check[x][y]=maxl;
}

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif
	scanf("%d%d",&r,&c);
	for(int i=0;i<r;i++) for(int j=0;j<c;j++)
		scanf("%d",&a[i][j]);
	int maxl=0;
	for(int i=0;i<r;i++) for(int j=0;j<c;j++){
		maxl=max(maxl,maxLen(i,j));
	}
	printf("%d\n",maxl);

	return 0;
}
