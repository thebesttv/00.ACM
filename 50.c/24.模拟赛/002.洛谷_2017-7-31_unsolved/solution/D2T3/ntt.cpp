#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;
const int MAXN=500005,MAXM=1<<16;
struct node{
  int a,b,c;
}q[MAXN];
bool cmp(node x,node y){
  return x.a>y.a;
}
bool cmp1(node x,node y){
  return x.c<y.c;
}
int N,n,m,i,j,k,l,r,mid,a[100000],b[40],a2[100000],t[MAXM],ans[MAXN];
int Pow(int a,int b,int c){
  int s=1;
  while(b)
  {
    if(b&1)s=(ll)(s)*a%c;
    a=(ll)(a)*a%c;
    b>>=1;
  }
  return s;
}
bool check(int x){
  return Pow(7,x-1,x)==1 && Pow(13,x-1,x)==1 && Pow(19,x-1,x)==1;
}
int find(int x){
  l=0;
  r=n;
  while(l+1<r)
  {
    mid=l+r>>1;
    if(a2[mid]>=x)r=mid;
    else l=mid;
  }
  return r;
}

int main(){
  freopen("ntt.in","r",stdin);
  freopen("ntt.out","w",stdout);
  scanf("%d",&m);
  for(i=1;i<=m;i++){
    scanf("%d%d",&q[i].a,&q[i].b);
    q[i].c=i;
  }
  sort(q+1,q+m+1,cmp);
  N=q[m].a;
  for(i=30;i>=N;b[i--]=n) for(j=1;j<1<<31-i;j+=2)
    if((i&1)+(j%3)!=2&&check((1<<i)*j+1))a[++n]=(1<<i)*j+1;
  for(i=1;i<=n;i++) a2[i]=a[i];
  sort(a2+1,a2+n+1);
  for(i=1;i<=n;i++) a[i]=find(a[i]);
  for(i=j=1;i<=m;i++){
    if(j<=b[q[i].a]) for(k=b[q[i].a];j<=k;j++) for(l=a[j];l<MAXM;l+=l&-l) t[l]++;
    l=k=0;
    r=MAXM;
    while(l+1<r){
      k+=t[mid=l+r>>1];
      if(k>=q[i].b){
        k-=t[mid];
        r=mid;
      }else l=mid;	
    }
    ans[q[i].c]=a2[r];
  }
  for(i=1;i<=m;i++)printf("%d\n",ans[i]);

  return 0;
}

