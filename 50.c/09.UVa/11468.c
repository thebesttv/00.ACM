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

// f[i][j]: 当前在节点 i ，还要匹配 j 个，个，不走到“禁止”节点的可能性大小
// f[i][j] = sum{ posi[ch] * f[to[i][ch]][j-1] }
// f[i][0] = 1
// ans = f[0][L]

const int TOT=26+26+10; //一共的有效字符数
const int MAX_PNUM=40, MAX_PLEN=40, MAX_NODE=20*20+10;  //模式串的个数、长度，AC自动机的总节点数
const int MAX_LEN=120;  //文本串长度
int n,k,l,idx[256]; //idx[i]: 字符 i 的索引
char t1[MAX_PLEN], ori[MAX_PNUM][MAX_PLEN]; //记录模式串
double posi[TOT];
double check_f[MAX_NODE][MAX_LEN];
bool vis_f[MAX_NODE][MAX_LEN];

struct AC{
  int to[MAX_NODE][TOT],P[MAX_NODE],siz;
  bool match[MAX_NODE];

  void init(){
    siz=1; MST(to[0],0), match[0]=0;
  }
  void insert(char *s){
    int u=0,ch;
    while(ch=*s++){
      ch=idx[ch];
      if(!to[u][ch]){
        MST(to[siz],0), match[siz]=0;
        to[u][ch]=siz++;
      }
      u=to[u][ch];
    }
    match[u]=1;
  }
  void getP(){
    queue<int> q; P[0]=0;
    int u,v,j;
    FOR(i,0,n){
      u=to[0][i];
      if(u) q.push(u), P[u]=0;
    }
    while(!q.empty()){
      u=q.front(); q.pop();
      FOR(i,0,n){
        v=to[u][i];
        if(!v) {to[u][i]=to[P[u]][i]; continue;}
        q.push(v);

        j=P[u];
        while(j && !to[j][i]) j=P[j];
        P[v]=to[j][i];
        match[v]|=match[P[v]];
      }
    }
  }
}ac;

// f[u][j] = sum{ posi[ch] * f[to[u][ch]][j-1] }
// f[u][0] = 1
double f(int u, int j){
  if(!j) return 1.0;
  if(vis_f[u][j]) return check_f[u][j];
  vis_f[u][j]=1;  //<b> </b>
  double &a=check_f[u][j]; a=0;
  int v;
  FOR(ch,0,n) if(!ac.match[v=ac.to[u][ch]]){
    a += posi[ch] * f(v,j-1);
  }
  return a;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    ac.init();

    scanf("%d",&k);
    FOR(i,0,k) scanf("%s",ori[i]);
    scanf("%d",&n); //有效字符数
    FOR(i,0,n){
      scanf("%s%lf",t1,&posi[i]);
      idx[t1[0]]=i;
    }
    FOR(i,0,k) ac.insert(ori[i]);
    ac.getP();  //怎么老是忘……

    MST(vis_f,0); scanf("%d",&l);
    printf("Case #%d: %.6lf\n",kase,f(0,l));
  }

  return 0;
}
