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

const int MAX = 120;
int n,cnt;
char s[MAX];
bool ok=0;
set<int> pos[128];

bool can(int p, int c){
  int l=p-1,r=p+1;
  while(l>=1 && s[l]==0) --l;
  while(r<=n && s[r]==0) ++r;
  return (l>=1 && s[l]+1==c) || (r<=n && s[r]+1==c);
}

void elim(){
  RORR(ch,'z','a') if(pos[ch].size()){
    bool ok2 = 0;
    do{
      ok2 = 0;
      for(int i : pos[ch]){
        if(can(i,ch)){
          s[i]=0, ok2=ok=1, ++cnt;
          pos[ch].erase(i);
          break;
        }
      }
    }while(ok2);
  }
}

int main(void){
  scanf("%d%s",&n,s+1);
  FORR(i,1,n) pos[s[i]].insert(i);

  do{
    ok = 0;
    elim();
  }while(ok);
  printf("%d\n",cnt);

  return 0;
}
