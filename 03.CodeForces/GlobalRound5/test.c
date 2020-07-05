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

const int MAX=50020;
const int D = 3;
int n;
int p[MAX][D];

struct Node{
  int pos, n;
  bool operator < (const Node &b) const {
    return pos < b.pos;
  }
};

set<int> s[MAX];

void solve(set<int> &s, int cur){  // solve a (cur+1)-D probem with nodes in s
#ifdef DEBUG
  printf("in %d\n",cur);
  for(int i : s) printf("%d ",i); putchar('\n');
#endif
  VR<Node> v; VR<int> notDone;
  for(int i : s) v.push_back(Node{p[i][cur],i});
  s.clear(); sort(ALL(v));

  if(cur==0){
    for(int i=1;i<v.size();i+=2){
      printf("%d %d\n",v[i-1].n,v[i].n);
    }
    if(v.size()&1) s.insert(v[v.size()-1].n);
    return;
  }
  int l=0,r;
  while(l<v.size()){
    int r = upper_bound(ALL(v),v[l]) - v.begin();
    set<int> ts;
    FOR(k,l,r) ts.insert(v[k].n);
    solve(ts,cur-1);
    if(ts.size()) notDone.push_back(*ts.begin());
    l = r;
  }
  for(int i=1;i<notDone.size();i+=2){
    printf("%d %d\n",notDone[i-1],notDone[i]);
  }
  if(notDone.size()&1) s.insert(notDone[notDone.size()-1]);
}

int main(void){
  scanf("%d",&n);
  set<int> s;
  FORR(i,1,n){
    scanf("%d%d%d",&p[i][0],&p[i][1],&p[i][2]);
    s.insert(i);
  }
  solve(s,2);

  return 0;
}

/*
const int MAX=50020;
int n;
struct Point{
  int x,y,z;
}p[MAX];

struct Node{
  int pos, n;
  bool operator < (const Node &b) const {
    return pos < b.pos;
  }
}vx[MAX],vy[MAX],vz[MAX];

set<int> s[MAX];

void solve(set<int> &s){  // solve a 2D probem with nodes in s
  int n = s.size(),tail=0;
  for(int i : s){
    vy[tail++]=Node{p[i].y,i};
  }
  sort(vy,vy+n);  // sort y

  int l=0,r;
  VR<int> notDone;
  while(l<n){
    r = upper_bound(vy,vy+n,vy[l])-vy;
    FOR(k,l,r){
      vx[k] = Node{p[vy[k].n].x,vy[k].n};
    }
    sort(vx+l,vx+r);  // sort x (final)
    for(int k=l+1;k<r;k+=2){
      printf("%d %d\n",vx[k-1].n+1,vx[k].n+1);
      s.erase(vx[k-1].n); s.erase(vx[k].n);
    }
    if((r-l)&1) notDone.push_back(vx[r-1].n);
    l = r;
  }
  for(int i=1;i<notDone.size();i+=2){
    printf("%d %d\n",notDone[i-1]+1,notDone[i]+1);
    s.erase(notDone[i-1]); s.erase(notDone[i]);
  }
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n){
    scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
    vz[i]=Node{p[i].z,i};
  }

  sort(vz,vz+n);  // sort z
  int l=0,r,cnt=0;
  VR<int> notDone;
  while(l<n){
    r = upper_bound(vz,vz+n,vz[l])-vz;
    FOR(k,l,r) s[cnt].insert(vz[k].n);
    if(s[cnt].size()>1)
      solve(s[cnt]);
    if(s[cnt].size())
      notDone.push_back(*s[cnt].begin());
    cnt++; l = r;
  }

  for(int i=1;i<notDone.size();i+=2){
    printf("%d %d\n",notDone[i-1]+1,notDone[i]+1);
  }

  return 0;
}
*/
