#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=100020;
int n,m,k;
struct Point{
  int x,y;
}p[MAX];
struct Node{
  int pos,n;
  bool operator < (const Node &b) const {
    return pos < b.pos;
  }
}nx[MAX],ny[MAX];

int getObs(int dir, int x, int y){
  if(dir==1 || dir==3){
    int l = lower_bound(nx,nx+k,Node{x,0})-nx;
    int r = upper_bound(nx,nx+k,Node{x,0})-nx;
    VR<int> v;
    FOR(i,l,r) v.push_back(p[nx[i].n].y);
    sort(ALL(v));
    if(dir==1){
      VR<int>::iterator it;
      it = upper_bound(ALL(v),y);
      if(it!=v.end()) return *it;
      else return m+1;
    }else{
      VR<int>::iterator it;
      it = lower_bound(ALL(v),y);
      if(it!=v.begin()){
        it--; return *it;
      }else return 0;
    }
  }else{
    int l = lower_bound(ny,ny+k,Node{y,0})-ny;
    int r = upper_bound(ny,ny+k,Node{y,0})-ny;
    VR<int> v;
    FOR(i,l,r) v.push_back(p[ny[i].n].x);
    sort(ALL(v));
    if(dir==2){
      VR<int>::iterator it;
      it = upper_bound(ALL(v),x);
      if(it!=v.end()) return *it;
      else return n+1;
    }else{
      VR<int>::iterator it;
      it = lower_bound(ALL(v),x);
      if(it!=v.begin()){
        it--; return *it;
      }else return 0;
    }
  }
}

int main(void){
  scanf("%d%d%d",&n,&m,&k);
  FOR(i,0,k){
    scanf("%d%d",&p[i].x,&p[i].y);
    nx[i]=Node{p[i].x,i};
    ny[i]=Node{p[i].y,i};
  }
  sort(nx,nx+k); sort(ny,ny+k);

  int x=1,y=1;
  int x1=1, x2=n+1, y1=0, y2=m+1;
  LL cnt=1, ans=1ll*n*m-k;
  int dir=1;
  while(true){
    bool hasMov=0;
    int obs = getObs(dir,x,y);
    if(dir==1){
      int ty = min(obs,y2)-1;
      if(ty!=y){
        cnt += ty-y;
        y=y2=ty;
        hasMov=1;
      }
    }else if(dir==2){
      int tx = min(obs,x2)-1;
      if(tx!=x){
        cnt += tx-x;
        x=x2=tx;
        hasMov=1;
      }
    }else if(dir==3){
      int ty = max(obs,y1)+1;
      if(ty!=y){
        cnt += y-ty;
        y=y1=ty;
        hasMov=1;
      }
    }else{
      int tx = max(obs,x1)+1;
      if(tx!=x){
        cnt += x-tx;
        x=x1=tx;
        hasMov=1;
      }
    }
    dir = dir==4 ? 1 : dir+1;
    if(!hasMov) break;
  }
  printf("%s\n", cnt==ans ? "Yes" : "No" );

  return 0;
}
