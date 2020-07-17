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

const int MAX = 2e5 + 20;
int n; char s[20];
set<int> st[MAX];

struct Query{
  int op,x,y,x2,y2;
}Q[MAX];

VR<int> v;
int ID(int x){
  return lower_bound(ALL(v), x) - v.begin();
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n){
    scanf("%s",s);
    if(s[0] == 'q'){
      Q[i].op = 3;
      scanf("%d%d%d%d",&Q[i].x,&Q[i].y,&Q[i].x2,&Q[i].y2);
      v.push_back(Q[i].x);
      v.push_back(Q[i].x2);
    }else{
      Q[i].op = s[0] == 'a' ? 1 : 2;
      scanf("%d%d",&Q[i].x,&Q[i].y);
      v.push_back(Q[i].x);
    }
  }
  sort(ALL(v)), v.erase(unique(ALL(v)), v.end());

  FOR(i,0,n){
    Query &q = Q[i]; q.x = ID(q.x);
    if(q.op == 1) st[q.x].insert(q.y);
    else if(q.op == 2) st[q.x].erase(q.y);
    else{
      q.x2 = ID(q.x2); int sum = 0;
      FORR(x,q.x,q.x2) if(st[x].size()){
        auto it = st[x].lower_bound(q.y);
        while(it != st[x].end() && *it <= q.y2)
          ++sum, ++it;
      }
      printf("%d\n",sum);
    }
  }

  return 0;
}

/*
const int MAX = 2e5 + 20;
int n; char s[20];
set<pii> st;

int main(void){
  scanf("%d",&n);
  while(n--){
    scanf("%s",s);

    if(s[0] == 'q'){
      int x1, y1, x2, y2, sum = 0;
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      for(auto p : st)
        if(x1 <= p.FI && p.FI <= x2 && y1 <= p.SE && p.SE <= y2)
          ++sum;
      printf("%d\n",sum);
    }else{
      int x, y; scanf("%d%d",&x,&y);
      if(s[0] == 'a') st.insert({x,y});
      else st.erase({x,y});
    }
  }

  return 0;
}
*/
