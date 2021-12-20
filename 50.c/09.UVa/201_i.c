//based on the Internet
//faster
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool H[10][10],V[10][10];
int cou[10],n,m,kase=1;

void check(int x, int y);

int main(void){
	while(scanf("%d%d",&n,&m)==2){
		memset(H,0,sizeof(H)); memset(V,0,sizeof(V)); memset(cou,0,sizeof(cou));
		int x,y; char c;
		for(int i=0;i<m;i++){
			scanf("\n%c%d%d",&c,&x,&y);
			if(c=='H')	H[x][y]=1;
			else		V[y][x]=1;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
			if(H[i][j] && V[i][j]) check(i,j);

		if(kase!=1) printf("\n**********************************\n\n");
		printf("Problem #%d\n\n",kase++);
		bool flag=0;
		for(int i=1;i<=9;i++) if(cou[i]){ flag=1;
			printf("%d square (s) of size %d\n",cou[i],i);
		}
		if(!flag) printf("No completed squares can be found.\n");
	}
	return 0;
}

void check(int x, int y){
	int Max=max(x,y);
	for(int i=0;i+Max<n;i++){
		if(H[x][y+i] && V[x+i][y]){
			int j;
			for(j=0;j<=i;j++)	//<b>it should be "j<=i" instead of "j<i"</b>
				if(!(H[x+i+1][y+j] && V[x+j][y+i+1])) break;
			if(j==i+1) cou[i+1]++;

/*			bool flag=1; int j=0;
			do{
			if(!(H[x+i+1][y+j] && V[x+j][y+i+1])){
					flag=0; break;
				}
			}while((j++)<i);
			if(flag) cou[i+1]++;
*/		}else{
			break;
		}
	}
}

/*
//original
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

bool g[100][100];
int cou[10];

inline bool connected(int x1, int y1, int x2, int y2);
bool check(int a, int b);

int main(void){
	int n,m,kase=1;
	while(scanf("%d%d",&n,&m)==2){
		memset(g,0,sizeof(g)); memset(cou,0,sizeof(cou));
		for(int i=0;i<m;i++){
			int c,x,y;
			do{
				c=getchar();
			}while(!isalpha(c));
			scanf("%d%d",&x,&y);
			if(c=='H'){
				int a=x*10+y, b=x*10+y+1;
				g[a][b]=g[b][a]=1;
			}else{
				swap(x,y);
				int a=x*10+y, b=(x+1)*10+y;
				g[a][b]=g[b][a]=1;
			}
		}

		int t=n*11;
		for(int a=11;a<t;a++){
			if(a%10 > n) continue;
			for(int b=a+1;b<=t;b++){
				if(b%10 > n || a/10>=b/10 || a%10>=b%10) continue;
				if(b/10-a/10 != b%10-a%10) continue; //only square instead of rectangle
				if(check(a,b)){
					cou[(b-a+100)%10]++;
					#ifdef DEBUG
					printf("--(%d,%d), (%d,%d)\n",a/10,a%10,b/10,b%10);
					#endif
				}
			}
		}

		if(kase!=1) printf("\n**********************************\n\n");
		printf("Problem #%d\n\n",kase++);
		bool flag=0;
		for(int i=1;i<=9;i++) if(cou[i]){ flag=1;
			printf("%d square (s) of size %d\n",cou[i],i);
		}
		if(!flag) printf("No completed squares can be found.\n");
	}

	return 0;
}

bool check(int a, int b){
	if(a>b) swap(a,b);
	int x1=a/10,y1=a%10,x2=b/10,y2=b%10;
	for(int i=x1;i<x2;i++){
		if(!connected(i,y1,i+1,y1)) return 0;
		if(!connected(i,y2,i+1,y2)) return 0;
	}
	for(int j=y1;j<y2;j++){
		if(!connected(x1,j,x1,j+1)) return 0;
		if(!connected(x2,j,x2,j+1)) return 0;
	}
	return 1;
}

inline bool connected(int x1, int y1, int x2, int y2){
	return g[x1*10+y1][x2*10+y2];
}
*/
