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

const int MAX = 1e5 + 4;
int n,m,a[MAX],pos[MAX];
LL Q[MAX];

struct ST{
  struct Node{
    int s; Node *l, *r;
    Node() { }
    Node(Node *p) { s = 0, l = r = p; }
  }*head[MAX], **av[500], *sv1[500], *sv2[500], *zero;
  int tail = 0;

  void init(){
    zero = new Node;
    zero->s = 0; zero->l = zero->r = zero;
    FORR(i,0,n) head[i] = zero;
  }
  void update(Node **v[], int len, int l, int r, int p){
    while(true){
      FOR(i,0,len) if((*v[i])==zero)
        (*v[i]) = new Node(zero);

      FOR(i,0,len) (*v[i])->s += 1;
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
  void add(int x, int p){
    int len = 0;
    while(x <= n){
      av[len++] = head + x;
      x += x&-x;
    }
    update(av, len, 1, n, p);
  }

  int qLt(Node *vl[], Node *vr[], int len1, int len2, int l, int r, int x){
    int sum = 0;
    while(true){
      if(l==r){
        FOR(i,0,len1) sum -= vl[i]->s;
        FOR(i,0,len2) sum += vr[i]->s;
        break;
      }

      int m = (l+r)/2;
      if(m < x){
        // left
        FOR(i,0,len1) sum -= vl[i]->l->s, vl[i] = vl[i]->r;
        FOR(i,0,len2) sum += vr[i]->l->s, vr[i] = vr[i]->r;
        // right
        if(m+1 < x) l = m+1;
        else break;
      }else if(l < x){
        FOR(i,0,len1) vl[i] = vl[i]->l;
        FOR(i,0,len2) vr[i] = vr[i]->l;
        r = m;
      }else break;
    }
    return sum;
  }
  int qLt(int l, int r, int x){
    int l1=0, l2=0; --l;
    while(l) sv1[l1++] = head[l], l -= l&-l;
    while(r) sv2[l2++] = head[r], r -= r&-r;
    return qLt(sv1, sv2, l1, l2, 1, n, x);
  }

  int qGt(Node *vl[], Node *vr[], int len1, int len2, int l, int r, int x){
    int sum = 0;
    while(true){
      if(l==r){
        FOR(i,0,len1) sum -= vl[i]->s;
        FOR(i,0,len2) sum += vr[i]->s;
        break;
      }

      int m = (l+r)/2;
      if(x < m+1){
        FOR(i,0,len1) sum -= vl[i]->r->s, vl[i] = vl[i]->l;
        FOR(i,0,len2) sum += vr[i]->r->s, vr[i] = vr[i]->l;
        if(x < m) r = m;
        else break;
      }else if(x < r){
        FOR(i,0,len1) vl[i] = vl[i]->r;
        FOR(i,0,len2) vr[i] = vr[i]->r;
        l = m+1;
      }else break;
    }
    return sum;
  }
  int qGt(int l, int r, int x){
    int l1=0, l2=0; --l;
    while(l) sv1[l1++] = head[l], l -= l&-l;
    while(r) sv2[l2++] = head[r], r -= r&-r;
    return qGt(sv1, sv2, l1, l2, 1, n, x);
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m); sg.init();
  FORR(i,1,n) scanf("%d",&a[i]), pos[a[i]] = i;
  int x;
  FORR(i,1,m) scanf("%d",&x), Q[i]=x, a[pos[x]]=0;

  LL sum = 0;
  FORR(i,1,n) if(a[i]){
    sg.add(i, a[i]);
    sum += sg.qGt(1,i,a[i]) + sg.qLt(i,n,a[i]);
#ifdef DEBUG
    printf("qGt(%d, %d, %d): %d\n",1,i,a[i],sg.qGt(1,i,a[i]));
    printf("qLt(%d, %d, %d): %d\n",i,n,a[i],sg.qLt(i,n,a[i]));
#endif
  }

  ROR(i,m,1){
    x = Q[i]; sg.add(pos[x],x);
    sum += sg.qGt(1,pos[x],x) + sg.qLt(pos[x],n,x);
#ifdef DEBUG
    printf("qGt(%d, %d, %d): %d\n",1,pos[x],x,sg.qGt(1,pos[x],x));
    printf("qLt(%d, %d, %d): %d\n",pos[x],n,x,sg.qLt(pos[x],n,x));
#endif
    Q[i] = sum;
  }
  FORR(i,1,m) printf("%lld\n",Q[i]);

  return 0;
}
