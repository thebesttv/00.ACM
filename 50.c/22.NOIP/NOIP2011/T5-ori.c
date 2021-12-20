#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long LL;
const int MAX=200020;
LL sum[MAX];
int cnt[MAX], quest[MAX][2];
struct Ind{
  int w,v;
}ind[MAX];
int n,m;
LL s;

LL check(int w);
void init(int w);

int main(void){
  scanf("%d%d%lld",&n,&m,&s);
  int wMax=0;
  for(int i=1;i<=n;i++) {scanf("%d%d",&ind[i].w,&ind[i].v); ind[i].w>wMax ? wMax=ind[i].w : 0 ;}
  for(int i=0;i<m;i++) scanf("%d%d",&quest[i][0],&quest[i][1]);

  LL ans=s;
  int u;
  for(LL w=0;w<=wMax;w++){
    LL t=abs(check(w)-s);
    //ans=min(t,ans);
    if(t<ans) {ans=t; u=w;}
  }
#ifdef DEBUG
  printf("%d\n",u);
#endif
  printf("%lld\n",ans);

  return 0;
}

LL check(int w){
  init(w);
  LL ans=0;
  for(int i=0;i<m;i++){
    int l=quest[i][0],r=quest[i][1];
    ans+=(cnt[r]-cnt[l-1])*(sum[r]-sum[l-1]);
  }
  return ans;
}
void init(int w){
  sum[0]=cnt[0]=0;
  for(int i=1;i<=n;i++){
    sum[i] = sum[i-1] + (ind[i].w>=w ? ind[i].v : 0);
    cnt[i] = cnt[i-1] + (ind[i].w>=w ? 1 : 0);
  }
}

