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
int n; bool vis[MAX];
int a[MAX],b[MAX],c[MAX];

int main(void){
  scanf("%d",&n); int t;
  FORR(i,1,n) { scanf("%d",&t); a[i]=t; }
  FORR(i,1,n) { scanf("%d",&t); b[t]=i; }
  FORR(i,1,n) { c[i] = b[a[i]]; }
  int cnt=0,tMax=c[1];
  FORR(i,2,n){
    if(c[i]<tMax) cnt++;
    else tMax=c[i];
  }
  printf("%d\n",cnt);
  return 0;
}

/*
const int MAX=100020;
int n; bool vis[MAX];
queue<int> a,b;

int main(void){
  scanf("%d",&n); int t;
  FOR(i,0,n){ scanf("%d",&t); a.push(t); }
  FOR(i,0,n){ scanf("%d",&t); b.push(t); }

  int cnt=0;
  while(!a.empty() && !b.empty()){
    while(!a.empty() && !b.empty() && a.front() != b.front()){
      cnt++; vis[b.front()]=1;
      b.pop();
    }
    while(!a.empty() && vis[a.front()]) a.pop();
    while(!b.empty() && a.front() == b.front()){
      a.pop(); b.pop();
    }
    while(!a.empty() && vis[a.front()]) a.pop();
  }
  printf("%d\n",cnt);
  return 0;
}
*/
