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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=120;
int n;
struct Node{
  int l,r;
  bool operator < (const Node &b) const {
    return r!=b.r ? r<b.r : l>b.l;
  }
}node[MAX];

int main(void){
  while(scanf("%d",&n)==1 && n){
    FOR(i,0,n) scanf("%d%d",&node[i].l,&node[i].r);
    sort(node,node+n);
    int end=0,cnt=0;
    FOR(i,0,n){
      if(node[i].l>=end){
        cnt++; end=node[i].r;
      }
    }
    printf("%d\n",cnt);
  }

  return 0;
}
