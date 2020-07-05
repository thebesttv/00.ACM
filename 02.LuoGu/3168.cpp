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

const int MAX = 100020, PSIZE = 16000000;
int m,n,v[MAX],tail;
VR<int> A[MAX], B[MAX];

int idx(int x){
  return lower_bound(v,v+tail,x)-v + 1;
}

struct ST{
  int n, tail=0;
  struct Node{
    LL sum; int cnt;
    Node *l, *r;
    Node() { sum = cnt = 0; }
    Node(Node *p) { sum = cnt = 0; l = r = p; }
  }*head[MAX], **av[500], *sv[500], *zero, pool[PSIZE];
  void init(){
    zero = new Node;
    zero->l = zero->r = zero;
    FOR(i,0,MAX) head[i] = zero;
  }

  void add(Node **v[], int len, int l, int r, int p, int val){
    int ori = ::v[p-1];
    while(true){
      FOR(i,0,len){
        if((*v[i])==zero){
          // (*v[i]) = new Node(zero);
          (*v[i]) = pool + (tail++);
          (*v[i])->l = (*v[i])->r = zero;
        }
        (*v[i])->sum += val==1 ? ori : -ori;
        (*v[i])->cnt += val;
      }
      if(l==r) break;

      int m = (l+r)/2;
      if(p <= m){
        FOR(i,0,len) v[i] = &((*v[i])->l);
        r = m;
      }else{
        FOR(i,0,len) v[i] = &((*v[i])->r);
        l = m+1;
      }
    }
  }
  void add(int x, int p, int v){
    int len = 0;
    while(x <= n){
      av[len++] = head + x;
      x += x&-x;
    }
    add(av, len, 1, n, p, v);
  }

  LL query(Node *v[], int len, int l, int r, int k){
    LL sum = 0;
    while(true){
#ifdef DEBUG
      printf("  query(%d, %d, %d)",l,r,k);
#endif
      if(l==r){
#ifdef DEBUG
        printf("\n");
#endif
        int cnt = 0;
        FOR(i,0,len) cnt += v[i]->cnt;
        sum += 1ll * min(cnt, k) * ::v[l-1];
        break;
      }

      int m = (l+r)/2, ls = 0, s = 0;
      FOR(i,0,len) ls += v[i]->l->cnt, s += v[i]->cnt;
#ifdef DEBUG
        printf(": cnt: %d, ls: %d\n",s,ls);
#endif
      if(k >= s){
        FOR(i,0,len) sum += v[i]->sum;
        break;
      }else if(k >= ls){
        FOR(i,0,len) sum += v[i]->l->sum, v[i] = v[i]->r;
        if(k==ls) break;
        k -= ls; l = m+1;
      }else{
        FOR(i,0,len) v[i] = v[i]->l;
        r = m;
      }
    }
    return sum;
  }
  LL query(int x, int k){
#ifdef DEBUG
    printf("query(%d, %d)\n",x,k);
#endif
    int len = 0;
    while(x) sv[len++] = head[x], x -= x&-x;
    return query(sv, len, 1, n, k);
  }
}sg;

int main(void){
  scanf("%d%d",&m,&n);
  int l,r,p;
  while(m--){
    scanf("%d%d%d",&l,&r,&p);
    A[l].push_back(p); B[r+1].push_back(p);
    v[tail++] = p;
  }
  sort(v,v+tail); tail = unique(v, v+tail) - v;
  sg.n = n; sg.init();
  FORR(i,1,n){
    for(int x : A[i]) sg.add(i, idx(x), 1);
    for(int x : B[i]) sg.add(i, idx(x), -1);
  }

  int x,a,b,c,k; LL pre=1;
  FORR(i,1,n){
    scanf("%d%d%d%d",&x,&a,&b,&c);
    k = 1 + (pre%c*a + b)%c;
    pre = sg.query(x,k);
    printf("%lld\n",pre);
  }

  return 0;
}
