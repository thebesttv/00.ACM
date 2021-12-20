/*
有一张N×m的数表，其第i行第j列（1 < =i < =礼，1 < =j < =m）的数值为
能同时整除i和j的所有自然数之和。给定a，计算数表中不大于a的数之和。

Input
输入包含多组数据。
输入的第一行一个整数Q表示测试点内的数据组数，接下来Q行，每行三个整数n，m，a(|a| < =10^9)描述一组数据。

Output
对每组数据，输出一行一个整数，表示答案模2^31的值。

Sample Input
2
4 4 3
10 10 5

Sample Output
20
148

Hint
1 < =N．m < =10^5  ， 1 < =Q < =2×10^4
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
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
typedef long long LL;
typedef long long unsigned LLU;

//线性筛求 F
const int MAX=100020;
const int MAXN=MAX-20;
const int MAXQ=20020;
int n,m,a;
int prime[MAX],tail,mu[MAX];
int g[MAX],s[MAX];  // g 函数 和前缀和
int tf[MAX];  //tf[n] = p1^k1
bool vis[MAX];
struct Query{ //询问
  int n,m,a,num;
  bool operator < (const Query & b) const {
    return a<b.a;
  }
}query[MAXQ];
int ans[MAXQ];
struct sF{  //F(a) = b
  int a,b;
  bool operator < (const sF & bb) const {
    return b<bb.b;
  }
}F[MAX];

inline int sum(int x){
  int ans=0;
  while(x>0) {ans+=s[x]; x-=x&(-x);}
  return ans;
}
inline void add(int x, int a){
  while(x<=MAXN) {s[x]+=a; x+=x&(-x);}
}
void init(int n=MAXN){
  //线性筛中计算出 mu 和 F(i) ，并按照 F 升序排列
  mu[1]=1; F[1].a=1; F[1].b=1;
  FORR(i,2,n){
    F[i].a=i;
    if(!vis[i]){
      prime[tail++]=i; mu[i]=-1;
      F[i].b=i+1; tf[i]=i;
    }
    int t,p;
    FOR(j,0,tail){
      p=prime[j]; t=i*p;
      if(t>n) break;
      vis[t]=1;
      if(i%p==0){
        mu[t]=0; tf[t]=tf[i]*p;
        F[t].b = F[i].b + tf[t]*F[t/tf[t]].b;
        break;
      }else{
        mu[t]=-mu[i]; tf[t]=p;
        F[t].b=(1+p)*F[i].b;
      }
    }
  }
  sort(F+1,F+1+n);
}
void update_g(int a, int b, int n=MAXN){ //用 F(a)=b 更新 g(n) = \sum_{d|n} F(d)*mu[n/d];
  for(RE int j=a,cnt=1,t;j<=n;j+=a,cnt++)
    if(t=b*mu[cnt]){
      add(j,t); //g[j] += b*mu[cnt]
    }
}
int f(int n, int m){  //分块
  if(n>m) swap(n,m);
  RE int ans=0,j,t1,t2;
  for(RE int i=1;i<=n;i=j+1){
    j=min(n/(t1=(n/i)),m/(t2=(m/i)));
    ans += t1*t2*(sum(j)-sum(i-1));
  }
  return ans;
}

int main(void){
  init();
  int T; scanf("%d",&T);
  FOR(i,0,T){
    scanf("%d%d%d",&n,&m,&a);
    query[i]=(Query){n,m,a,i};
  }
  sort(query,query+T);  //询问按照 a 升序排列

  int a,j=1;
  FOR(i,0,T){
    Query & Q=query[i];
    while(j<=MAXN && F[j].b<=Q.a){ //更新 F
      update_g(F[j].a,F[j].b); j++;
    }
    ans[Q.num]=f(Q.n,Q.m) & ((1LL<<31)-1);  //去掉符号位
  }
  FOR(i,0,T) printf("%d\n",ans[i]);

  return 0;
}

/*
//枚举求 F
const int MAX=100020;
const int MAXN=MAX-20;
const int MAXQ=20020;
int n,m,a;
int prime[MAX],tail,mu[MAX];
int g[MAX],s[MAX];  // g 函数 和前缀和
bool vis[MAX];
struct Query{ //询问
  int n,m,a,num;
  bool operator < (const Query & b) const {
    return a<b.a;
  }
}query[MAXQ];
int ans[MAXQ];
struct sF{  //F(a) = b
  int a,b;
  bool operator < (const sF & bb) const {
    return b<bb.b;
  }
}F[MAX];

inline int sum(int x){
  int ans=0;
  while(x>0) {ans+=s[x]; x-=x&(-x);}
  return ans;
}
inline void add(int x, int a){
  while(x<=MAXN) {s[x]+=a; x+=x&(-x);}
}
void init(int n=MAXN){
  //F(i): i的约数和，计算出所有 F 并按照 F 升序排列
  FORR(i,1,n){
    F[i].a=i;
    for(int j=i;j<=n;j+=i){
      F[j].b+=i;
    }
  }
  sort(F+1,F+1+n);

  //计算出 mu
  mu[1]=1;
  FORR(i,2,n){
    if(!vis[i]){
      prime[tail++]=i; mu[i]=-1;
    }
    FOR(j,0,tail){
      int t=i*prime[j];
      if(t>n) break;
      vis[t]=1;
      if(i%prime[j]==0){
        mu[t]=0;
        break;
      }else{
        mu[t]=-mu[i];
      }
    }
  }
}
void update_g(int a, int b, int n=MAXN){ //用 F(a)=b 更新 g(n) = \sum_{d|n} F(d)*mu[n/d];
  for(int j=a,cnt=1;j<=n;j+=a,cnt++) if(b*mu[cnt]){
    add(j,b*mu[cnt]); //g[j] += b*mu[cnt]
  }
}
int f(int n, int m){  //分块
  if(n>m) swap(n,m);
  int ans=0,j;
  for(int i=1;i<=n;i=j+1){
    j=min(n/(n/i),m/(m/i));
    ans += (n/i)*(m/i)*(sum(j)-sum(i-1));
  }
  return ans;
}

int main(void){
  init();
  int T; scanf("%d",&T);
  FOR(i,0,T){
    scanf("%d%d%d",&n,&m,&a);
    query[i]=(Query){n,m,a,i};
  }
  sort(query,query+T);  //询问按照 a 升序排列

  int a,j=1;
  FOR(i,0,T){
    Query & Q=query[i];
    while(j<=MAXN && F[j].b<=Q.a){ //更新 F
      update_g(F[j].a,F[j].b); j++;
    }
    ans[Q.num]=f(Q.n,Q.m) & ((1LL<<31)-1);  //去掉符号位
  }
  FOR(i,0,T) printf("%d\n",ans[i]);

  return 0;
}
*/
