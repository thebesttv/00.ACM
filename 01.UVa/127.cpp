// Tag: notag
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

const int MAX = 60;
int n; char s[4];
struct Card{
  char x,y;
  bool operator == (const Card &b) const {
    return x == b.x || y == b.y;
  }
};
stack<Card> st[MAX];

void simplify(){
  int tail = 1;
  FOR(i,1,52) if(!st[i].empty()){
    if(i != tail){
      st[tail] = st[i];
      while(!st[i].empty()) st[i].pop();
    }
    tail++;
  }
}

int main(void){
  while(scanf("%s",s)==1 && s[0]!='#'){
    FOR(i,0,52){
      while(!st[i].empty()) st[i].pop();
      st[i].push({s[0],s[1]});
      if(i!=51) scanf("%s",s);
    }

    while(true){
      bool ok = 0;
      FOR(i,0,52) if(!st[i].empty()){
        if(i>=3 && st[i].top() == st[i-3].top()){
          st[i-3].push(st[i].top()); st[i].pop();
          ok = 1; break;
        } else if(i>=1 && st[i].top() == st[i-1].top()){
          st[i-1].push(st[i].top()); st[i].pop();
          ok = 1; break;
        }
      }else break;
      if(!ok) break;
      simplify();
    }
    int cnt = 0;
    FOR(i,0,52)
      if(!st[i].empty()) ++cnt;
      else break;
    if(cnt == 1) printf("1 pile remaining:");
    else printf("%d piles remaining:",cnt);
    FOR(i,0,cnt) printf(" %d",(int)st[i].size());
    putchar('\n');
  }

  return 0;
}
