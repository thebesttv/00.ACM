// Tag: 模拟 队列
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

bool locked = 0;
int n, t[5], quan, var[128];
struct Node{
  int id;
  deque<string> cmd;
};
deque<Node*> rq, bq;  // ready queue, blocked queue

int main(void){
  int T; scanf("%d",&T);
  FOR(kase,0,T){
    MST(var, 0); rq.clear(), bq.clear();
    if(kase) putchar('\n');
    scanf("%d",&n); FOR(i,0,5) scanf("%d",&t[i]); scanf("%d",&quan);
    FORR(i,1,n){
      Node *p = new Node;
      p->id = i; string s;
      while(true){
        getline(cin, s);
        if(s.empty()) continue;
        p->cmd.push_back(s);
        if(s == "end") break;
      }
#ifdef DEBUG
      printf("PRO %d: (%d)\n",p->id,(int)p->cmd.size());
      for(string &s : p->cmd) printf("  %s\n", s.c_str());
#endif
      rq.push_back(p);
    }

    while(!rq.empty()){
      Node *p = rq.front(); rq.pop_front();
#ifdef DEBUG
      printf("RUNNING: %d\n",p->id);
#endif
      int left = quan; bool ok = 1;
      while(left > 0){
        string s = p->cmd.front();
        p->cmd.pop_front();
        if(s == "lock"){
          if(locked){
            p->cmd.push_front("lock");
            bq.push_back(p);
            ok = 0; break;
          }
          locked = true;
          left -= t[2];
        }else if(s == "unlock"){
          locked = false;
          if(!bq.empty()){
            rq.push_front(bq.front());
            bq.pop_front();
          }
          left -= t[3];
        }else if(s == "end"){
          ok = 0; break;
          left -= t[4];
        }else if(s[1] == 'r'){  // print
          printf("%d: %d\n",p->id,var[s[6]]);
          left -= t[1];
        }else{
          var[s[0]] = atoi(s.c_str() + 4);
          left -= t[0];
        }
      }
      if(ok) rq.push_back(p);
    }
  }

  return 0;
}
