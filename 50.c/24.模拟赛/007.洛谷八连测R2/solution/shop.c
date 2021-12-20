#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define L long long
using namespace std;

int n,m,w[100010];
L s[100010];
struct goods{
  int v,x;
}a[100010];
inline bool cmp(goods a,goods b){
  return a.v<b.v;
}

int main(){
  freopen("shop.in","r",stdin);
  freopen("shop.out","w",stdout);
  int i,j,l,r;
  L k;
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++)
    scanf("%d%d",&a[i].v,&a[i].x);
  sort(a+1,a+n+1,cmp);
  for(i=1;i<=n;i++){
    s[i]=s[i-1]+(L)a[i].v*a[i].x;
    w[i]=w[i-1]+a[i].x;
  }
  while(m--){
    scanf("%lld",&k);
    for(i=n,j=0;i>0 && k>=a[1].v;){
      for(l=1,r=i;l<r;)
        if(k>=a[l+r+1>>1].v) l=(l+r+1>>1);
        else r=(l+r+1>>1)-1;
      i=l;
      if(k>=s[i]){
        j+=w[i]; break;
      }
      for(l=1,r=i;l<r;)
        if(k>=s[i]-s[l+r>>1]) r=(l+r>>1);
        else l=(l+r>>1)+1;
      k-=s[i]-s[l];
      j+=w[i]-w[l]+k/a[l].v;
      k%=a[l].v;
      i=l-1;
    }
    printf("%d\n",j);
  }
  return 0;
}
