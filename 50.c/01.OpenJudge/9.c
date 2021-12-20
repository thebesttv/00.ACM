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

const int MAXN=120;
const int MAXL=60;
int n,m;
char t[MAXL];
struct Node{
  int rev;
  char s[MAXL];
  bool operator < (const Node & b) const {
    return rev<b.rev;
  }
}node[MAXN];

int main(void){
  scanf("%d%d",&m,&n);
  FOR(i,0,n){
    scanf("%s",t); strcpy(node[i].s,t);
    int & cnt=node[i].rev;
    FOR(j,0,m) FOR(k,j,m) if(t[j]>t[k]) cnt++;
  }
#ifdef DEBUG
  FOR(i,0,n) printf("  %s: %d\n",node[i].s,node[i].rev);
#endif
  stable_sort(node,node+n);
  FOR(i,0,n) printf("%s\n",node[i].s);

  return 0;
}
