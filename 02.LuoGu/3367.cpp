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
#include<numeric>
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

const int MAX = 1e4 + 20;
int n, m, p[MAX];

int find(int x){
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int x, int y){
  x = find(x); y = find(y);
  if(x == y) return;
  if(p[x] < p[y]){
    p[x] += p[y];
    p[y] = x;
  }else{
    p[y] += p[x];
    p[x] = y;
  }
}

int main(void){
  memset(p, -1, sizeof(p));
  scanf("%d%d", &n, &m);
  while(m--){
    int z, x, y;
    scanf("%d%d%d", &z, &x, &y);

    if(z == 1){
      merge(x, y);
    }else{
      printf("%s\n", find(x) == find(y) ? "Y" : "N");
    }
  }

  return 0;
}
