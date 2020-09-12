// Tag: DP 矩阵快速幂
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MOD = 998244353;
int n; char s[20];

struct Matrix{
  int n; VR<VR<int>> v;
  Matrix(int n) : n(n), v(n) {
    FOR(i,0,n) v[i].resize(n);
  }
  void clear(){
    FOR(i,0,n) FOR(j,0,n)
      v[i][j] = 0;
  }
  void one(){
    FOR(i,0,n) v[i][i] = 1;
  }
  VR<int> & operator [] (int n) {
    return v[n];
  }
};

Matrix mul(Matrix &a, Matrix &b){
  Matrix c(a.n); int n = a.n;
  FOR(i,0,n) FOR(j,0,n){
    int &x = c[i][j];
    FOR(k,0,n) x = (x + 1ll * a[i][k] * b[k][j])%MOD;
  }
  return c;
}

Matrix pow_mod(Matrix &a, int x){
  Matrix ans(a.n); ans.one();
  while(x){
    if(x&1) ans = mul(ans, a);
    a = mul(a, a); x>>=1;
  }
  return ans;
}

struct F1{
  Matrix tran;
  LL f[2][4];

  F1() : tran(4) {
    tran[0][2] = tran[1][0] = tran[2][1] = tran[2][3] = tran[3][2] = tran[3][3] = 1;
  }

  int cal(int n){
    Matrix a = pow_mod(tran, n);

    f[0][0] = 1;
    FOR(i,0,4) FOR(j,0,4) if(a[i][j]){
      f[1][i] = (f[1][i] + a[i][j] * f[0][j])%MOD;
    }
    int x = s[0] == '1' ? 0 : s[0] == '2' ? 1 : s[0] == '4' ? 2 : 3;
    return f[1][x];
  }
}f1;

struct F2{
  Matrix tran;
  int mp[10][10], IDcnt; bool vis[120];
  LL f[2][14];

  int ID(pii p){
    int &a = mp[p.FI][p.SE];
    if(a==-1){
      a = IDcnt++;
#ifdef DEBUG
      printf("ID(%d, %d): %d\n",p.FI,p.SE,a);
#endif
    }
    return a;
  }

  F2() : tran(14){
    MST(mp,-1);

    int id1 = ID({0,1}), id2 = ID({0,2}), id4 = ID({0,4}), id6 = ID({0,6}),
        id16 = ID({1,6}), id64 = ID({6,4});
    tran[id1][id4] = tran[id2][id1] = tran[id4][id2] = tran[id4][id6] = tran[id6][id4] = tran[id6][id6] = 1;

    queue<pii> q; q.push({1,6}), q.push({6,4}); vis[id16] = vis[id64] = 1;
    tran[id16][id4] = tran[id64][id6] = 1;

    while(!q.empty()){
      pii u = q.front(); q.pop();
      pii v = {(1<<u.FI)%10, 1<<u.SE};
      while(v.SE>10) v.SE/=10;
#ifdef DEBUG
      printf("%d%d -> %d%d\n",u.FI,u.SE,v.FI,v.SE);
#endif

      tran[ID(v)][ID(u)] = 1;
      if(!vis[ID(v)]) vis[ID(v)] = 1, q.push(v);
    }
#ifdef DEBUG
    printf("cnt: %d\n",IDcnt);
    FOR(i,0,IDcnt){
      FOR(j,0,IDcnt) printf("%d ",tran[i][j]);
      putchar('\n');
    }
#endif
  }

  int cal(int n){
    Matrix a = pow_mod(tran, n);

    f[0][0] = 1;
    FOR(i,0,14) FOR(j,0,14) if(a[i][j]){
      f[1][i] = (f[1][i] + a[i][j] * f[0][j])%MOD;
    }
    return f[1][ID({s[0]-'0', s[1]-'0'})];
  }
}f2;

int main(void){
  scanf("%d%s",&n,s);
  if(strlen(s) == 1){
    printf("%d\n",f1.cal(n));
  }else{
    printf("%d\n",f2.cal(n));
  }

  return 0;
}

/*
const int MAX = 1020;
const LL MOD = 998244353;
int n; char s[4];
LL a[4][4],b[4][4],c[4][4],f[2][4];

void mul(LL a[][4], LL b[][4], LL c[][4]){
  LL res[4][4];
  FOR(i,0,4) FOR(j,0,4){
    res[i][j] = 0;
    FOR(k,0,4) res[i][j] = (res[i][j] + a[i][k]*b[k][j])%MOD;
  }
  memcpy(c,res,sizeof(res));
}

void print(LL a[][4]){
  FOR(i,0,4){
    FOR(j,0,4) printf("%lld ",a[i][j]);
    putchar('\n');
  }
}

void pow_mod(int x){
  FOR(i,0,4) c[i][i]=1;
  while(x){
    if(x&1) mul(a,c,c);
    mul(a,a,a); x>>=1;
  }
}

VR<int> v[30];

void expand(int i){
  VR<int> &v2 = v[i];
  for(int x : v[i-1]){
    if(x == 1) v2.pb(2);
    else if(x == 2) v2.pb(4);
    else if(x == 4) v2.pb(1), v2.pb(6);
    else v2.pb(6), v2.pb(4);
  }
}

int main(void){
  scanf("%d%s",&n,s);
  if(strlen(s) == 1){
    a[0][2] = a[1][0] = a[2][1] = a[2][3] = a[3][2] = a[3][3] = 1;
    pow_mod(n);
    f[0][0] = 1;
    FOR(i,0,4) FOR(j,0,4) if(c[i][j]){
      f[1][i] = (f[1][i] + c[i][j] * f[0][j]);
    }
    int x = s[0] == '1' ? 0 : s[0] == '2' ? 1 : s[0] == '4' ? 2 : 3;
    printf("%lld\n",f[1][x]);
  }else{
    v[0].pb(1);
    FORR(i,1,20) expand(i);
    int cnt = 0; s[0]-='0', s[1]-='0';
    FOR(i,1,v[n].size())
      if(v[n][i-1] == s[0] && v[n][i] == s[1]) ++cnt;
    printf("%d\n",cnt);
  }

  return 0;
}
*/

/*
const int MAX = 1020;
const LL MOD = 998244353;
int n; char s[4];
int f[MAX][4];

int main(void){
  f[0][0] = 1;
  scanf("%d%s",&n,s);
  FORR(i,1,n){
    f[i][0] = f[i-1][2];
    f[i][1] = f[i-1][0];
    f[i][2] = (f[i-1][1] + f[i-1][3])%MOD;
    f[i][3] = (f[i-1][2] + f[i-1][3])%MOD;
    printf("%d: %d, %d, %d, %d\n",i,f[i][0],f[i][1],f[i][2],f[i][3]);
  }

  return 0;
}
*/

/*
VR<int> v[40];

void expand(int i){
  VR<int> &v2 = v[i];
  for(int x : v[i-1]){
    if(x == 1) v2.pb(2);
    else if(x == 2) v2.pb(4);
    else if(x == 4) v2.pb(1), v2.pb(6);
    else v2.pb(6), v2.pb(4);
  }
}

int main(void){
  v[0].pb(1);
  FORR(i,1,30){
    expand(i);
    printf("%2d: %d\n",i,(int)v[i].size()); fflush(stdout);
    //for(int x : v[i]) printf("%d",x); putchar('\n');
  }
  FOR(i,0,100){
    printf("%2d: ",i);
    FORR(j,0,30)
      if(v[j].size() > i)
        printf("%d",v[j][i]);
      else putchar(' ');
    putchar('\n');
  }

  return 0;
}
*/
