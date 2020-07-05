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
#include<utility>
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
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 2e5 + 20;
int n, a[MAX], f[MAX];

struct Node{
  int l, r;
}*node[MAX];

int main(void){
  scanf("%d",&n);

  a[0] = 2e9;
  node[0] = new Node;
  node[1] = new Node;
  node[1]->l = 1;

  int ansMax = 0;
  FORR(i,1,n){
    scanf("%d",&a[i]);
    if(a[i] > a[i-1]){
      f[i] = f[i-1] + 1;
      node[i] = node[i-1];
    }else{
      f[i] = 1;
      node[i-1]->r = i-1;
      node[i] = new Node;
      node[i]->l = i;
    }
    ansMax = max(ansMax, f[i]);
  }
  node[n]->r = n;


  FORR(i,2,n-1) if(node[i-1] != node[i+1] && a[i-1]<a[i+1]){
    int cnt = node[i-1]->r - node[i-1]->l + 1
            + node[i+1]->r - node[i+1]->l + 1
            - 1;
    ansMax = max(ansMax,cnt);
  }
  printf("%d\n",ansMax);

  return 0;
}
