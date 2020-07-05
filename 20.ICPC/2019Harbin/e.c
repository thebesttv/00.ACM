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
#include<unordered_map>
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

const int MAX=1e6+20;
 
int n;
 
LL cnt[MAX];  // 第一种节点出现次数 
vector<int> v[MAX];
 
struct Node{
  int n;
  Node *lc, *rc;
}node[MAX];
 
int mpCnt=0;
unordered_map<int,int> mp;
int ID(int n){
  if(mp.count(n)) return mp[n];
  else return mp[n] = ++mpCnt;
}
 
LL capacity[MAX];
 
int main(void){
  int T; scanf("%d",&T);
  while(T--){
    mpCnt=0; mp.clear(); 
    scanf("%d",&n);
 
    VR<int> isNode;
    int op,x,y,k;
    for(int i=1;i<=n;++i){
      scanf("%d",&op);
      Node *p = node + i;
      p->n = i;
 
      if(op==1){
        scanf("%d",&k);
        cnt[i]=0; v[i].clear(); 
 
        while(k--){
          scanf("%d",&x);
          v[i].push_back(x);
        }
        p->lc = p->rc = NULL;
        isNode.push_back(i);
      }else{
        scanf("%d%d",&x,&y);
        p->lc = node+x;
        p->rc = node+y;
        cnt[i] = 0;
      }
    }
    cnt[n] = 1;
    ROR(i,n,1) if(cnt[i] && node[i].lc){
      cnt[node[i].lc->n] += cnt[i];
      cnt[node[i].rc->n] += cnt[i];
    }
 
    for(int i : isNode) if(cnt[i]){
      for(int x : v[i]){
        capacity[ID(x)] += cnt[i];
      }
    }
 
    LL sum = 0, tMax = 0;
    FORR(i,1,mpCnt){
      sum += capacity[i];
      tMax = max(tMax,capacity[i]);
      capacity[i]=0;
    }
 
    LL ans;
    if(tMax * 2 > sum) ans = 2 * (sum - tMax);
    else ans = sum;
 
    printf("%lld\n",ans);
  }
 
  return 0;
}

/*
const int MAX=1e6+20;
int n;

inline int read(){
  int ch, sum = 0;
  do ch = getchar(); while(!isdigit(ch));
  do sum = (sum<<3) + (sum<<1) + ch-'0', ch=getchar(); while(isdigit(ch));
  return sum;
}

LL cnt[MAX];  // 第一种节点出现次数 
vector<int> v[MAX];

struct Node{
  int l,r;
}node[MAX];

unordered_map<int,LL> mp;

int main(void){
  int T = read();
  while(T--){
    mp.clear(); 
    n = read();

    VR<int> isNode;
    int op,x,y,k;
    FORR(i,1,n){
      op = read();
      cnt[i] = 0;
      if(op==1){
        k = read();
        v[i].clear(); 

        while(k--){
          v[i].push_back(read());
        }
        node[i].l = node[i].r = 0;
        isNode.push_back(i);
      }else{
        x = read(), y = read();
        node[i].l = x, node[i].r = y;
      }
    }

    cnt[n] = 1;
    ROR(i,n,1) if(cnt[i] && node[i].l){
      cnt[node[i].l] += cnt[i];
      cnt[node[i].r] += cnt[i];
    }

    LL sum = 0, tMax = 0;
    for(int i : isNode) if(cnt[i]){
      for(int x : v[i]){
        LL &t = mp[x];
        t += cnt[i]; sum += cnt[i];
        tMax = max(tMax,t);
      }
    }

    LL ans;
    if(tMax * 2 > sum) ans = 2 * (sum - tMax);
    else ans = sum;

    printf("%lld\n",ans);
  }

  return 0;
}
*/

/*
const int MAX=1e6+20;
int n;

inline int read(){
  int ch, sum = 0;
  do ch = getchar(); while(!isdigit(ch));
  do sum = (sum<<3) + (sum<<1) + ch-'0', ch=getchar(); while(isdigit(ch));
  return sum;
}

LL cnt[MAX];  // 第一种节点出现次数 
vector<int> v[MAX];

struct Node{
  int l,r;
}node[MAX];

int mpCnt=0;
unordered_map<int,int> mp;
int ID(int n){
  if(mp.count(n)) return mp[n];
  else return mp[n] = ++mpCnt;
}

LL capacity[MAX];

int main(void){
  int T=read();
  while(T--){
    mpCnt=0; mp.clear(); 
    n=read();

    VR<int> isNode;
    int op,x,y,k;
    FORR(i,1,n){
      op=read();
      cnt[i] = 0;
      if(op==1){
        k=read();
        v[i].clear(); 

        while(k--){
          v[i].push_back(read());
        }
        node[i].l = node[i].r = 0;
        isNode.push_back(i);
      }else{
        x=read(), y=read();
        node[i].l = x, node[i].r = y;
      }
    }

    cnt[n] = 1;
    ROR(i,n,1) if(cnt[i] && node[i].l){
      cnt[node[i].l] += cnt[i];
      cnt[node[i].r] += cnt[i];
    }

    for(int i : isNode) if(cnt[i]){
      for(int x : v[i]){
        capacity[ID(x)] += cnt[i];
      }
    }

    LL sum = 0, tMax = 0;
    FORR(i,1,mpCnt){
      sum += capacity[i];
      tMax = max(tMax,capacity[i]);
      capacity[i]=0;
    }

    LL ans;
    if(tMax * 2 > sum) ans = 2 * (sum - tMax);
    else ans = sum;

    printf("%lld\n",ans);
  }

  return 0;
}
*/

/*
const int MAX=1e6+20;

int n;

LL cnt[MAX];  // 第一种节点出现次数 
vector<int> v[MAX];

struct Node{
  int n;
  Node *lc, *rc;
}node[MAX];

int mpCnt=0;
unordered_map<int,int> mp;
int ID(int n){
  if(mp.count(n)) return mp[n];
  else return mp[n] = ++mpCnt;
}

LL capacity[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    mpCnt=0; mp.clear(); 
    scanf("%d",&n);

    VR<int> isNode;
    int op,x,y,k;
    for(int i=1;i<=n;++i){
      scanf("%d",&op);
      Node *p = node + i;
      p->n = i;

      if(op==1){
        scanf("%d",&k);
        cnt[i]=0; v[i].clear(); 

        while(k--){
          scanf("%d",&x);
          v[i].push_back(x);
        }
        p->lc = p->rc = NULL;
        isNode.push_back(i);
      }else{
        scanf("%d%d",&x,&y);
        p->lc = node+x;
        p->rc = node+y;
        cnt[i] = 0;
      }
    }

    cnt[n] = 1;
    ROR(i,n,1) if(cnt[i] && node[i].lc){
      cnt[node[i].lc->n] += cnt[i];
      cnt[node[i].rc->n] += cnt[i];
    }

    for(int i : isNode) if(cnt[i]){
      for(int x : v[i]){
        capacity[ID(x)] += cnt[i];
      }
    }

    LL sum = 0, tMax = 0;
    FORR(i,1,mpCnt){
      sum += capacity[i];
      tMax = max(tMax,capacity[i]);
      capacity[i]=0;
    }

    LL ans;
    if(tMax * 2 > sum) ans = 2 * (sum - tMax);
    else ans = sum;

    printf("%lld\n",ans);
  }

  return 0;
}
*/
