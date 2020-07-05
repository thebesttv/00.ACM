#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+10;
int n;
int lazy[10][4*maxn];
int tree[10][4*maxn];
void build(int f){
  for(int i=1;i<=4*n;i++){
    tree[f][i]=0;
  }
}
void pushdown(int f,int k){
  lazy[f][2*k]+=lazy[f][k];
  lazy[f][2*k+1]+=lazy[f][k];
  tree[f][2*k]+=lazy[f][k];
  tree[f][2*k+1]+=lazy[f][k];
  lazy[f][k]=0;
}
void updata(int f,int L,int R,int l,int r,int k){
  if(L<=l&&r<=R){
    lazy[f][k]++;
    tree[f][k]++;
  }
  else{
    pushdown(f,k);
    int mid=l+(r-l)/2;
    if(L<=mid)
      updata(f,L,R,l,mid,k*2);
    if(R>mid)
      updata(f,L,R,mid+1,r,2*k+1);
    tree[f][k]=max(tree[f][2*k],tree[f][2*k+1]);
  }
}
ll query(int f,int L,int R,int l,int r,int k){
  if(L<=l&&r<=R){
    return tree[f][k];
  }
  pushdown(f,k);
  ll res=0;
  int mid=l+(r-l)/2;
  if(L<=mid)
    res=max(res,query(f,L,R,l,mid,k*2));
  if(R>mid)
    res=max(res,query(f,L,R,mid+1,r,k*2+1));
  return res;
}
int main()
{
  int q;
  scanf("%d%d",&n,&q);
  build(2);
  build(3);
  build(5);
  build(7);
  while(q--){
    char s1[10];
    scanf("%s",s1);
    if(s1[1]=='U'){
      int l,r,v;
      scanf("%d%d%d",&l,&r,&v);
      switch(v){
        case 2:updata(2,l,r,1,n,1);break;
        case 3:updata(3,l,r,1,n,1);break;
        case 4:updata(2,l,r,1,n,1);updata(2,l,r,1,n,1);break;
        case 5:updata(5,l,r,1,n,1);break;
        case 6:updata(2,l,r,1,n,1);updata(3,l,r,1,n,1);break;
        case 7:updata(7,l,r,1,n,1);break;
        case 8:updata(2,l,r,1,n,1);updata(2,l,r,1,n,1);updata(2,l,r,1,n,1);break;
        case 9:updata(3,l,r,1,n,1);updata(3,l,r,1,n,1);break;
        case 10:updata(2,l,r,1,n,1);updata(5,l,r,1,n,1);break;
      }
    }
    else{
      int l,r;
      scanf("%d%d",&l,&r);
      ll res=0;
      res=max(res,query(2,l,r,1,n,1));
      res=max(res,query(3,l,r,1,n,1));
      res=max(res,query(5,l,r,1,n,1));
      res=max(res,query(7,l,r,1,n,1));
      printf("ANSWER %d\n",res);
    }
  }
  return 0;
}
