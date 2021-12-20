#include<bits/stdc++.h>
using namespace std;
int len,n,m,a[30050],g[30050];
int abs(int x){
	return x>0?x:-x;
}
struct node{
	int id,l,r;
} q[30050]; 
int ans[30050],vis[30050];
bool operator<(node x,node y){
	if(x.l/len==y.l/len) return x.r<y.r;
	else return x.l/len<y.l/len;
}
int lowbit(int x){
	return x&(-x);
}
void insert(int id,int num){
	for(int i=id;i<=n;i+=lowbit(i))
		g[i]+=num;
}
int getsum(int id){
	int sum=0;
	for(int i=id;i;i-=lowbit(i))
		sum+=g[i];
	return sum;
}
int main(){
	scanf("%d",&n);
    memset(g, 0, sizeof(g));
    memset(ans, 0, sizeof(ans));
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	int cnt=0;
	for(int i=1;i<=m;i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i,cnt+=abs(q[i].l-q[i-1].l)+abs(q[i].r-q[i-1].r);
	int nl=1,nr=0,nans=0;
	for(int i=1;i<=m;i++){
		while(nr<q[i].r){
			nr++;nans+=getsum(n)-getsum(a[nr]);
			insert(a[nr],1);
		}
		while(nr>q[i].r){
			insert(a[nr],-1);nans-=getsum(n)-getsum(a[nr]);
			nr--;
		}
		while(nl<q[i].l){
			insert(a[nl],-1);nans-=getsum(a[nl]);
			nl++;
		}
		while(nl>q[i].l){
			nl--;nans+=getsum(a[nl]);
			insert(a[nl],1);
		}
		ans[q[i].id]=nans;
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
}
