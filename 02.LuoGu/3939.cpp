// Tag: 二分
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

const int MAX = 3e5 + 20;
int n,m,a[MAX]; VR<int> v[MAX];

void add(int c, int x, int val){
  auto it = lower_bound(ALL(v[c]), x);
  *it += val;
}

int query(int l, int r, int c){
  auto il = lower_bound(ALL(v[c]), l);
  auto ir = upper_bound(ALL(v[c]), r);
  return ir - il;
}

int main(void){
  n = read(), m = read();
  FORR(i,1,n) v[a[i] = read()].pb(i);
  while(m--){
    int op = read();
    if(op == 1){
      int l = read(), r = read(), c = read();
      printf("%d\n",query(l,r,c));
    }else{
      int i = read();
      if(a[i] != a[i+1]){
        add(a[i], i, 1);
        add(a[i+1], i+1, -1);
        swap(a[i], a[i+1]);
      }
    }
  }

  return 0;
}

