#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int At = 1<<30;
int r,c;
int a[104][104];

void dfs(int x, int y, int color){
	a[x][y]=color;
	for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) if(i!=0 || j!=0){
		int tx=x+i, ty=y+j;
		if(tx<0 || tx>r-1 || ty<0 || ty>c-1) continue;
		if(a[tx][ty]!=At) continue;
		dfs(tx,ty,color);
	}
}

int main(void){
	while(scanf("%d%d",&r,&c)==2 && r){
		memset(a,0,sizeof(a));
		getchar();
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				a[i][j] = (getchar() == '@' ? At : 0);
			getchar();
		}
		int col=0;
		for(int i=0;i<r;i++) for(int j=0;j<c;j++)
			if(a[i][j]==At) dfs(i,j,++col);
		printf("%d\n",col);
		#ifdef DEBUG
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				if(a[i][j]!=0) printf("%d",a[i][j]);
				else printf(" ");
			printf("\n");
		}
		#endif
	}

	return 0;
}
