#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long unsigned LLU;
const int MAX=100020;
int let[MAX],rit[MAX];
int n,m;

inline void link(int l, int r) {let[r]=l; rit[l]=r;}

int main(void){
	int kase=0;
	while(scanf("%d%d",&n,&m)==2){
		memset(let,0,sizeof(let)); memset(rit,0,sizeof(rit));
		for(int i=1;i<=n;i++) let[i]=i-1,rit[i]=i+1;
		let[0]=n; rit[0]=1; rit[n]=0;
		int op,x,y;
		bool inv=0;
		while(m--){
			scanf("%d",&op);
			if(op==4) inv=!inv;
			else{
				scanf("%d%d",&x,&y);
				if(op==3 && rit[y]==x) swap(x,y);
				if(op!=3 && inv) op=3-op;
				if(op==1 && let[y]==x) continue;
				else if(op==2 && rit[y]==x) continue;
				
				int lx=let[x],rx=rit[x],ly=let[y],ry=rit[y];
				if(op==1) {link(lx,rx); link(ly,x); link(x,y);}
				else if(op==2){ link(lx,rx); link(x,ry); link(y,x);}
				else{
					if(rx==y) {link(lx,y); link(x,ry); link(y,x);}
					else {link(lx,y); link(ly,x); link(y,rx); link(x,ry);}
				}
			}
		}
		LLU ans=0,pos=0;
		for(int i=1;i<=n;i++){
			pos=rit[pos];
			if(i&1) ans+=pos;
		}
		if(inv && !(n&1)) ans=1LL*n*(n+1)/2-ans;
		printf("Case %d: %llu\n",++kase,ans);
	}
	return 0;
}
