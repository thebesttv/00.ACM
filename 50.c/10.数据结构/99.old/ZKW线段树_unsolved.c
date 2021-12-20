#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

int M.n;

void build(int n){
  for(M=1;M<n;M<<=1);
  FOR(i,M,M+n) st[i]=read();
  //[1]
  ROR(i,M-1,1) st[i]=st[i<<1]+st[i<<1|1];
  //[2]差分
  ROR(i,M-1,1){
    st[i]=min(st[i<<1],st[i<<1|1]);
    st[i<<1]-=st[i]; st[i<<1|1]-=st[i];
  }
}
int sum(int x){ //查询sum{a[1:x]} 差分版
  int res=0;
  while(x) {res+=st[x]; x>>=1;}
  return res;
}
int sum(int l, int r){
  l+=M-1; r+=M-1;
  int res=st[l]+st[r];
  if(l==r) return res-=st[l];
  for(;l^r^1;l>>=1,r>>=1){
    //s^t^1: 如果s,t在同一父节点下，则值为0，说明已经累加到树的底部了
    if(!(l&1)) res+=st[l^1];  //若l为左子树，则它的兄弟（右子树）一定在[l,r]内，否则一定不在
    if(r&1) res+=st[r^1];     //若r为右子树，则它的兄弟（左子树）一定在[l,r]内，否则一定不在
  }
  return res;
}
