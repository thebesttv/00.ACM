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
#include<unordered_set>
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

int n; deque<int> q[7],v;
unordered_set<LL> st;

bool ok(int x){
  return x == 10 || x == 20 || x == 30;
}

LL cal(){
  LL sum = 0;
  FOR(i,0,7){
    LL cur = 0;
    for(int x : q[i])
      cur = cur * 11 + x;
    sum = sum * int(1e6+7) + cur;
  }
  LL cur = 0;
  for(int x : v)
    cur = cur * 11 + x;
  sum = sum * int(1e6+7) + cur;

  return sum;
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    FOR(i,0,7){
      q[i].clear();
      q[i].push_back(n);
      if(i!=6) scanf("%d",&n);
    }
    v.clear();
    FOR(i,7,52) scanf("%d",&n), v.push_back(n);
    int zcnt = 0, idx = 0, cnt = 7; bool rep = 0;
    while(!v.empty() && zcnt < 7){
      ++cnt;
#ifdef DEBUG
      printf("%d:  card %d, idx: %d, v.size(): %d\n",cnt,v.front(),idx,(int)v.size());
#endif
      deque<int> &q = ::q[idx];
      q.push_back(v.front());
      v.pop_front();

      while(q.size()>=3){
        if(ok(q[0] + q[1] + q.back())){
          v.push_back(q.front()); q.pop_front();
          v.push_back(q.front()); q.pop_front();
          v.push_back(q.back()); q.pop_back();
        }else if(ok(q[0] + q[q.size()-2] + q[q.size()-1])){
          v.push_back(q.front());
          v.push_back(q[q.size()-2]);
          v.push_back(q.back());
          q.pop_front();
          q.pop_back();
          q.pop_back();
        }else if(ok(q[q.size()-3] + q[q.size()-2] + q[q.size()-1])){
          v.push_back(q[q.size()-3]);
          v.push_back(q[q.size()-2]);
          v.push_back(q.back());
          q.pop_back(); q.pop_back(); q.pop_back();
        }else break;
      }
      if(q.empty()) ++zcnt;
      if(zcnt == 7) break;

      LL h = cal();
      if(st.count(h)){
        rep = 1; break;
      }else st.insert(h);

      do idx = (idx+1)%7; while(::q[idx].empty());
    }
#ifdef DEBUG
    printf("cnt: %d, zcnt: %d\n",cnt,zcnt);
#endif

    if(rep) printf("Draw: %d\n",cnt);
    else if(zcnt == 7) printf("Win : %d\n",cnt);
    else printf("Loss: %d\n",cnt);
  }

  return 0;
}
