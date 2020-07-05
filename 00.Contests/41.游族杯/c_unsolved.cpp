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

const int MAX = 1e5 + 20;
int n; LLU k1, k2;
struct Point{
  int n; LLU x,y,z;
  bool operator < (const Point &b) const {
    if(x != b.x) return x < b.x;
    return y != b.y ? y < b.y : z < b.z;
  }
}p[MAX];

LLU CoronavirusBeats() {
  LLU k3 = k1, k4 = k2;
  k1 = k4; k3 ^= k3 << 23;
  k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
  return k2 + k4;
}

int main(void){
  scanf("%d%llu%llu",&n,&k1,&k2);

  FOR(i,0,n){
    p[i].n = i;
    p[i].x = CoronavirusBeats();
    p[i].y = CoronavirusBeats();
    p[i].z = CoronavirusBeats();
  }
  sort(p, p+n);

  return 0;
}
