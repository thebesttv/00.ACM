#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Ind{
	int x;
	int y;

	bool operator < (const Ind & b) const{
		if(x<b.x) return 1;
		else if(x==b.x) return y<b.y;
		else return 0;
	}
}a[5000];

int n,r,c,ans;

int Solve(int i, int j);
bool Search(int x, int y);

int main(void){
  //	freopen("in","r",stdin);
  scanf("%d%d%d",&r,&c,&n);
  for(register int i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
  sort(a,a+n);
  for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
    ans=max(ans,Solve(i,j));
  printf("%d\n",ans);
  return 0;
}

int Solve(int i, int j){
	int tans=0;
	int dx=a[j].x-a[i].x,tx=a[i].x;
	int dy=a[j].y-a[i].y,ty=a[i].y;
	if(tx-dx>=1 && ty-dy>=1) return 0;
	if(tx+(ans-1)*dx>r || ty+(ans-1)*dy>c) return 0;
	while(tx<=r && ty<=c){
		if(Search(tx,ty)) tans++;
		else return 0;
		tx+=dx; ty+=dy;
	}
	return (tans>2 ? tans : 0);
}

bool Search(int x, int y){
	int L=0,R=n-1;
	while(L<=R){
		int M=(L-R)/2+R;
		if(a[M].x<x) L=M+1;
		else if(a[M].x>x) R=M-1;
		else{
			if(a[M].y<y) L=M+1;
			else if(a[M].y>y) R=M-1;
			else return true;
		}
	}
	return false;
}

/*
struct Ind{
	int x;
	int y;
}ind[5000+4];
bool f[5000+4][5000+4];
int r,c,n,ans=0;

int Solve(Ind * a, Ind * b);

int main(void){
	scanf("%d%d%d",&r,&c,&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&ind[i].x,&ind[i].y);
		f[ind[i].x][ind[i].y]=1;
	}
	for(int i=0;i<n;i++) for(int j=i+1;j<n; j++)
		ans=max(ans,Solve(&ind[i],&ind[j]));
	if(ans<3) ans=0;
	printf("%d\n",ans);

	return 0;
}

int Solve(Ind * a, Ind * b){
	int dx=b->x-a->x, dy=b->y-a->y;
	if(a->x-dx>=1 && a->x-dx<=r && a->y-dy>=1 && a->y-dy<=c)
		return 0;
	int ans=0;
//printf("f[%d][%d] to f[%d][%d]\n",a->x,a->y,b->x,b->y);
//printf("***successful***\n");
	int i=a->x,j=a->y;
	while(i>=1 && i<=r && j>=1 && j<=c){
//printf("  f[%d][%d]\n",i,j);
		if(f[i][j]==0) {ans=0; break;}
		else ans++;
		i+=dx; j+=dy;
	}
//printf("\n");
	return ans;
}
*/
