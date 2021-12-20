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
typedef long long LL;
typedef long long unsigned LLU;

const int TOT=26;
const int MAXN=160, MAXL=80;
const int MAX_NODE=MAXN*MAXL;
const int MAX=1000020;
int n; char t1[MAX];
char ori[MAXN][MAXL];
bool isans[MAXN];

struct AC{
  int to[MAX_NODE][TOT],val[MAX_NODE],siz;
  int P[MAX_NODE],last[MAX_NODE];
  int cnt[MAX_NODE]; //cnt[i]: 模式串 i 在文本串中出现的次数

  void init(){
    siz=1; MST(to[0],0); val[0]=0;
    MST(cnt,0); MST(last,0); MST(P,0);
  }
  void insert(char *s, int v){
    int u=0,ch;
    while(ch=*s++){
      ch-='a';
      if(!to[u][ch]){
        MST(to[siz],0); val[siz]=0;
        to[u][ch]=siz++;
      }
      u=to[u][ch];
    }
    val[u]=v;
  }
  void find(char *T, int n){ //对长 n 的文本串 T 匹配
    int j=0,ch;
    FOR(i,0,n){
      ch=T[i]-'a';
      while(j && !to[j][ch]) j=P[j];
      j=to[j][ch];
      if(val[j]) mark(j); //若 j **是**单词节点
      else if(last[j]) mark(last[j]); //若 j **包含**单词节点
    }
  }
  void getP(){
    queue<int> q; P[0]=0, last[0]=0;
    int u;
    FOR(i,0,TOT){
      u=to[0][i];
      if(u) q.push(u), P[u]=0, last[u]=0;
    }
    int v,j;
    while(!q.empty()){
      u=q.front(); q.pop();
      FOR(i,0,TOT){
        v=to[u][i];
        if(!v) continue;
        q.push(v);

        //自我匹配
        j=P[u];
        while(j && !to[j][i]) j=P[j];
        P[v]=to[j][i];
        last[v] = val[P[v]] ? P[v] : last[P[v]];
      }
    }
  }
  void mark(int u){ //对模式串 u 以及被 u 包含的其他所有模式串都进行标记
    if(u) cnt[u]++, mark(last[u]);
  }
  void print(){
    MST(isans,0); int max_cnt=0;
    FOR(i,1,siz) if(cnt[i]>max_cnt) max_cnt=cnt[i];
    FOR(i,1,siz) if(cnt[i]==max_cnt) isans[val[i]]=1;
    printf("%d\n",max_cnt);
    FORR(i,1,n) if(isans[i]) printf("%s\n",ori[i]);
  }
}ac;

int main(void){
  while(scanf("%d",&n)==1 && n){
    ac.init();
    FORR(i,1,n){
      scanf("%s",ori[i]); ac.insert(ori[i],i);
    }
    ac.getP();

    scanf("%s",t1);
    ac.find(t1,strlen(t1));
    ac.print();
  }

  return 0;
}
