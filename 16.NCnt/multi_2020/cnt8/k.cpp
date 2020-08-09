// Tag: 坑 int128 ST表 ii
// 能爆LL也是很过分……
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

const int MAX = 1e5 + 20;
int n,a[MAX],b[MAX],lg[MAX];
char str[int(1e5*20)];

struct Node{
  __int128 sum; int pos;
  bool operator < (const Node &b) const {
    return sum != b.sum ? sum > b.sum : pos < b.pos;
  }
}v[MAX];

struct ST{
  int f[MAX][20];
  void build(){
    FORR(i,1,n) f[i][0] = b[i];
    ROR(i,n,1) for(int j=1;i+(1<<j)-1<=n;j++)
      f[i][j] = min( f[i][j-1], f[i+(1<<(j-1))][j-1] );
  }
  int qmin(int l, int r){
    int k=lg[r-l+1];
    return min( f[l][k], f[r-(1<<k)+1][k] );
  }
  int next(int p, int c){
    int l = 1, r = p+1;
    while(l<r){
      int m = (l+r)/2;
      if(qmin(1,m) <= c) r = m;
      else l = m+1;
    }
#ifdef DEBUG
    printf("next(%d, %d): %d\n",p,c,l);
#endif
    return l;
  }
}sg;

void reada(){
  FGETS(str); int j = 0;
  FORR(i,1,n){
    int sum = 0; bool neg = 0;
    while(!isdigit(str[j])){
      neg = neg || str[j]=='-'; ++j;
    }
    while(isdigit(str[j]))
      sum = sum*10 + str[j]-'0', ++j;
    a[i] = neg ? -sum : sum;
    v[i] = {v[i-1].sum + a[i], i};
  }
}

void readb(){
  FGETS(str); int j = 0;
  FORR(i,1,n){
    int sum = 0;
    while(!isdigit(str[j])) ++j;
    while(isdigit(str[j]))
      sum = sum*10 + str[j]-'0', ++j;
    b[i] = sum;
  }
}

void print(__int128 x){
  if(x < 0){
    putchar('-'); x = -x;
  }
  stack<char> st;
  while(x) st.push(x%10+'0'), x/=10;
  while(!st.empty()) putchar(st.top()), st.pop();
}

int main(void){
  for(int i=2;i<MAX;i<<=1) lg[i]=1;
  FOR(i,3,MAX) lg[i]+=lg[i-1];

  int T; scanf("%d",&T); getchar();
  FORR(kase,1,T){
    scanf("%d",&n); getchar();
    reada(); readb();
#ifdef DEBUG
    FORR(i,1,n) printf(" %d",a[i]) ;putchar('\n');
    FORR(i,1,n) printf(" %d",b[i]) ;putchar('\n');
#endif
    sg.build();

    sort(v+1,v+1+n);
    int cnt = 0, i = 1, p = n; __int128 ans = 0;
    p = sg.next(p,0) - 1;
#ifdef DEBUG
    printf("ori p: %d\n",p);
#endif
    while(i<=n){
      if(v[i].pos <= p){
        ++cnt; ans += v[i].sum;
#ifdef DEBUG
        printf("choose [1:%d] sum: ",v[i].pos); print(v[i].sum); putchar('\n');
#endif
        p = sg.next(p, cnt) - 1;
      }else ++i;
    }
    printf("Case #%d: %d ",kase,cnt); print(ans); putchar('\n');
  }

  return 0;
}
