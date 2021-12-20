#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,f[400010],l[100010],r[100010],x[100010],p;

inline void add(int i,int j,int k,int l,int r,int x){
  if(l<=j && k<=r) f[i]&=x;
  else{
    if(l<=(j+k>>1))
      add(i<<1,j,j+k>>1,l,r,x);
    if(r>(j+k>>1))
      add(i<<1|1,(j+k>>1)+1,k,l,r,x);
  }
}
inline int sum(int i,int j,int k,int l,int r)
{
  if(l<=j && k<=r) return f[i];
  else{
    int p=0;
    if(l<=(j+k>>1))
      p|=sum(i<<1,j,j+k>>1,l,r);
    if(r>(j+k>>1))
      p|=sum(i<<1|1,(j+k>>1)+1,k,l,r);
    return p;
  }
}
int main()
{
  freopen("or.in","r",stdin);
  freopen("or.out","w",stdout);
  int i,j,k;
  scanf("%d%d",&n,&m);
  for(p=1;p<n;p<<=1);
  for(i=1;i<2*p;i++) f[i]=(1<<30)-1;
  for(i=1;i<=m;i++){
    scanf("%d%d%d",&l[i],&r[i],&x[i]);
    add(1,1,p,l[i],r[i],x[i]);
  }
  for(i=1;i<p;i++){
    f[i<<1]&=f[i];
    f[i<<1|1]&=f[i];
  }
  for(i=p-1;i>0;i--)
    f[i]=f[i<<1]|f[i<<1|1];
  for(i=1;i<=m;i++)
    if(sum(1,1,p,l[i],r[i])!=x[i])
      break;
  if(i<=m) printf("No\n");
  else{
    printf("Yes\n");
    for(i=1;i<=n;i++)
      printf("%d ",f[p+i-1]);
    printf("\n");
  }
  return 0;
}

