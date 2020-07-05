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

const int MAX = 200020;
int n; char s[MAX];
VR<int> pos[4];

int getPos(int p, int x){
  auto it = lower_bound(ALL(pos[x]), p);
  if(it == pos[x].end())
    return -1;
  return *it;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    FORR(i,1,3) pos[i].clear();
    scanf("%s",s); n = strlen(s);
    FOR(i,0,n) pos[s[i]-'0'].push_back(i);

    if(pos[1].empty() || pos[2].empty() || pos[3].empty()){
      printf("0\n"); continue;
    }

    int ansMin = n;
    FOR(i,0,n){
      int p1 = -1, p2 = -1;
      if(s[i]=='1'){
        p1 = getPos(i, 2);
        p2 = getPos(i, 3);
      }else if(s[i]=='2'){
        p1 = getPos(i, 1);
        p2 = getPos(i, 3);
      }else{
        p1 = getPos(i, 1);
        p2 = getPos(i, 2);
      }
      if(p1<0 || p2<0) break;
#ifdef DEBUG
      printf("  (%d, %d, %d)\n",i,p1,p2);
#endif
      ansMin = min(ansMin, max(p1,p2) - i + 1);
    }
    printf("%d\n",ansMin);
  }

  return 0;
}
