// Tag: iiii 欧拉回路 并查集判连通
// 用并查集判断连通性
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
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX =1020;
int n,in[128],out[128]; char s[MAX];

int p[128];
int fa(int x){
  return p[x] == -1 ? x : p[x] = fa(p[x]);
}
void merge(int x, int y){
  x = fa(x), y = fa(y);
  if(x == y) return;
  p[x] = y;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(in,0); MST(out,0); MST(p,-1);
    scanf("%d",&n);
    while(n--){
      scanf("%s",s);
      int len = strlen(s);
      in[s[0]]++;
      out[s[len-1]]++;
      merge(s[0],s[len-1]);
    }

    int c1 = 0, c2 = 0, ok = 1;
    FORR(i,'a','z'){
      if(in[i] == out[i]) continue;
      if(in[i] == out[i]+1) ++c1;
      else if(in[i]+1 == out[i]) ++c2;
      else ok = 0;
    }

    FORR(i,'a','z') if(in[i] || out[i]){
      FORR(j,i+1,'z') if(in[j] || out[j])
        if(fa(i) != fa(j)) { ok = 0; break; }
      break;
    }

    if(!ok || c1 > 1 || c2 > 1)
      printf("The door cannot be opened.\n");
    else
      printf("Ordering is possible.\n");
  }

  return 0;
}
