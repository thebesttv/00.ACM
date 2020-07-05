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

const int MAX = 1e5 + 20;
int n, v[MAX][3], ord[MAX], ans[MAX];
struct Node{
  int v;
  Node *next;
};

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    map<int, Node*> mp;
    scanf("%d",&n);
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    v[0][0] = a, v[0][1] = b, v[0][2] = c;

    int tail = 0;
    ord[0] = tail++;

    Node *p1 = new Node, *p2 = new Node, *p3 = new Node;
    p1->v = a, p1->next = p2;
    p2->v = b, p2->next = p3;
    p3->v = c, p3->next = p1;
    mp[a] = p1, mp[b] = p2, mp[c] = p3;

    queue<int> q1, q0;

    FOR(i,1,n-1){
      scanf("%d%d%d",&a,&b,&c);
      int cnt = 0, r1 = -1, r2 = -1;

      if(mp.count(a)){
        ++cnt, r1 = a;
      }
      if(mp.count(b)){
        ++cnt;
        if(r1==-1) r1 = b;
        else r2 = b;
      }
      if(mp.count(c)){
        ++cnt;
        if(r1==-1) r1 = c;
        else r2 = c;
      }

      if(cnt==2){
        ord[i] = tail++;
        p1 = mp[r1], p2 = mp[r2];
        p3 = new Node;
        if(r1==a){
          if(r2==b) p3->v = c;
          else p3->v = b;
        }else{  // r1 == b
          p3->v = a;
        }

        if(p1->next->v != p2->v)
          swap(p1, p2);

        p1->next = p3;
        p3->next = p2;

      }else if(cnt==1){
        q1.push(i);
      }else{
        q0.push(i);
      }
    }

    while(!q1.empty() || !q0.empty()){
      if(!q1.empty()){
        int i = q1.front(); q1.pop();

        a = v[i][0], b = v[i][1], c = v[i][2];
        int cnt = 0, r1 = -1, r2 = -1;

        if(mp.count(a)){
          ++cnt, r1 = a;
        }
        if(mp.count(b)){
          ++cnt;
          if(r1==-1) r1 = b;
          else r2 = b;
        }
        if(mp.count(c)){
          ++cnt;
          if(r1==-1) r1 = c;
          else r2 = c;
        }
        if(cnt==2){

          ord[i] = tail++;
          p1 = mp[r1], p2 = mp[r2];
          p3 = new Node;
          if(r1==a){
            if(r2==b) p3->v = c;
            else p3->v = b;
          }else{  // r1 == b
            p3->v = a;
          }

          if(p1->next->v != p2->v)
            swap(p1, p2);

          p1->next = p3;
          p3->next = p2;
        }else{
          q1.push(i);
        }
      }else{
        int i = q0.front(); q0.pop();

        a = v[i][0], b = v[i][1], c = v[i][2];
        int cnt = 0, r1 = -1, r2 = -1;

        if(mp.count(a)){
          ++cnt, r1 = a;
        }
        if(mp.count(b)){
          ++cnt;
          if(r1==-1) r1 = b;
          else r2 = b;
        }
        if(mp.count(c)){
          ++cnt;
          if(r1==-1) r1 = c;
          else r2 = c;
        }
        if(cnt==2){

          ord[i] = tail++;
          p1 = mp[r1], p2 = mp[r2];
          p3 = new Node;
          if(r1==a){
            if(r2==b) p3->v = c;
            else p3->v = b;
          }else{  // r1 == b
            p3->v = a;
          }

          if(p1->next->v != p2->v)
            swap(p1, p2);

          p1->next = p3;
          p3->next = p2;
        }else{
          q0.push(i);
        }
      }
    }
    FOR(i,0,n-2) ans[ord[i]] = i;
    Node *head = mp[1], *p = head;
    printf("%d",p->v); p = p->next;
    while(p!=head){
      printf(" %d",p->v); p = p->next;
    }
    putchar('\n');
    FOR(i,0,n-2) printf("%d ",ans[i]); putchar('\n');
  }

  return 0;
}
