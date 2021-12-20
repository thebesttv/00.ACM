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

const int MAX=100020;
struct Node{
  int address, n, to;
}node[MAX];
VR<Node> v;

int main(void){
  int head, n, k; scanf("%d%d%d",&head,&n,&k);
  FOR(i,0,n){
    int a,n,t; scanf("%d%d%d",&a,&n,&t);
    node[a].address = a;
    node[a].n = n;
    node[a].to = t;
  }
  int p = head;
  while(p!=-1){
    v.push_back(node[p]);
    p = node[p].to;
  }
  for(int l=0;l<v.size();l+=k){
    int r = l+k-1; if(r>=v.size()) break;
    int m = (l+r)/2;
    FORR(k,l,m) swap(v[k], v[r-k+l]);
  }

  n = v.size();
  FOR(i,0,n-1){
    printf("%05d %d %05d\n",v[i].address,v[i].n,v[i+1].address);
  }
  printf("%05d %d -1\n",v[n-1].address,v[n-1].n);

  return 0;
}
