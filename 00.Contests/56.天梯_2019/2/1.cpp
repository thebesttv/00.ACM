// Tag: 
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
int d[MAX];
VR<int> G[MAX], G2[MAX];
bool vis[MAX], bad[MAX];
int l, r, n;

bool prime(int x){
  int r = sqrt(x + 0.5);
  FORR(i,2,r) if(x%i==0)
    return false;
  return true;
}

int f(int x){
  int s = 0;
  while(x){
    s += (x%10) * (x%10);
    x /= 10;
  }
  return s;
}

int cal(int x){
  MST(vis, 0); vis[x] = 1;
  int u = f(x), c = 1;
  while(u != 1 && !vis[u]){
    ++c; vis[u] = 1;
    if(l <= u && u <= r) bad[u] = 1;
    u = f(u);
  }
  return u==1 ? c : -1;
}

int main(void){
  l = read(), r = read();
  FORR(i,l,r) d[i] = cal(i);
  bool done = false;
  FORR(i,l,r) if(d[i]>0 && !bad[i]){
    printf("%d %d\n",i,prime(i) ? d[i] * 2 : d[i]);
    done = true;
  }
  if(!done) printf("SAD\n");

  return 0;
}

