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

const int MAX = 3e5  +20;
int n;

struct Node{
  int ch, cnt;
};
VR<Node> v;

bool ok(){
  if((n&1)==0) return false;
  if(v[n/2].cnt + 1 < 3) return false;
  FOR(i,0,n/2) if(v[i].ch != v[n-i-1].ch
               || v[i].cnt + v[n-i-1].cnt<3)
    return false;
  return true;
}

int main(void){
  int ch = getchar(), last = 0, cnt = 0;
  while(isalpha(ch)){
    if(ch==last){
      ++cnt;
    }else{
      if(isalpha(last))
        v.push_back({last,cnt});
      last = ch, cnt = 1;
    }
    ch = getchar();
  }
  if(isalpha(last))
    v.push_back({last,cnt});

  n = v.size();
  if(!ok()) printf("0\n");
  else printf("%d\n",v[n/2].cnt+1);

  return 0;
}
