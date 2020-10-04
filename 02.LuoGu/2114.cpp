// Tag: 贪心
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

int nread(){
  int s = 0, ch, neg = 0;
  do ch = getchar(), neg |= (ch == '-'); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return neg ? -s : s;
}

const int MAX = 1e5 + 20;
int n,m,v0[40],v1[40];

struct Node{
  int op, t;
  void read(){
    char s[4]; scanf("%s%d",s,&t);
    op = s[0] == 'A' ? 1 : s[0] == 'O' ? 2 : 3;
  }
  void cal(int *v){
    int ot = t;
    if(op == 1){
      FORR(i,1,30) v[i] &= (t&1), t >>= 1;
    }else if(op == 2){
      FORR(i,1,30) v[i] |= (t&1), t >>= 1;
    }else{
      FORR(i,1,30) v[i] ^= (t&1), t >>= 1;
    }
    t = ot;
  }
}node[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,30) v1[i] = 1;
  FORR(i,1,n) node[i].read(), node[i].cal(v0), node[i].cal(v1);
  FORR(i,1,30) v0[i] <<= (i-1), v1[i] <<= (i-1);
#ifdef DEBUG
  FORR(i,1,30) printf("%2d: 0 -> %d, 1 -> %d\n",i,v0[i],v1[i]);
#endif
  int ans = 0; bool limited = true;
  ROR(i,30,1){
    if(limited){
      if(m & (1<<(i-1))){ // 0 / 1
        if(v0[i] >= v1[i])
          limited = false;
        ans |= max(v0[i], v1[i]);
      }else{  // 0
        ans |= v0[i];
      }
    }else ans |= max(v0[i], v1[i]);
  }
  printf("%d\n",ans);

  return 0;
}
