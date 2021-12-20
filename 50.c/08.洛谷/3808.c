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
const int MAX=1000020;
int n; char t1[MAX];

struct AC{
  int to[MAX][TOT],siz; //Trie
  int val[MAX];
  int P[MAX],last[MAX]; bool vis[MAX]; //vis[i]=1: 模式串 i 在文本串中出现过

  void init() {siz=1; MST(to[0],0); val[0]=0;}
  void insert(char *s){
    int u=0,ch;
    while(ch=*s++){
      ch-='a';
      if(!to[u][ch]){
        MST(to[siz],0); val[siz]=0;
        to[u][ch]=siz++;
      }
      u=to[u][ch];
    }
    val[u]++;
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
        j=to[j][i];
        P[v]=j;
        last[v] = val[P[v]] ? P[v] : last[P[v]];
      }
    }
  }
  void mark(int u){ //对模式串 u 以及被 u 包含的其他所有模式串都进行标记
    if(u) vis[u]=1, mark(last[u]);
  }
  int cnt(){  //计算所有被标记的模式串个数
    int ans=0;
    FOR(i,1,siz) if(vis[i]) ans+=val[i];
    return ans;
  }
}ac;

int main(void){
  scanf("%d",&n); ac.init();
  while(n--){
    scanf("%s",t1); ac.insert(t1);
  }
  ac.getP();

  scanf("%s",t1);
  ac.find(t1,strlen(t1));
  printf("%d\n",ac.cnt());

  return 0;
}

/*
const int TOT=26;
const int MAX=1000020;
int n; char t1[MAX];

struct AC{
  int to[MAX][TOT],siz; //Trie
  int val[MAX];
  int P[MAX],last[MAX]; bool vis[MAX]; //vis[i]=1: 模式串 i 在文本串中出现过

  void init() {siz=1; MST(to[0],0); val[0]=0;}
  void insert(char *s){
    int u=0,ch;
    while(ch=*s++){
      ch-='a';
      if(!to[u][ch]){
        MST(to[siz],0); val[siz]=0;
        to[u][ch]=siz++;
      }
      u=to[u][ch];
    }
    val[u]++;
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
        j=to[j][i];
        P[v]=j;
        last[v] = val[P[v]] ? P[v] : last[P[v]];
      }
    }
  }
  void mark(int u){ //对模式串 u 以及被 u 包含的其他所有模式串都进行标记
    if(u) vis[u]=1, mark(last[u]);
  }
  int cnt(){  //计算所有被标记的模式串个数
    int ans=0;
    FOR(i,1,siz) if(vis[i]) ans+=val[i];
    return ans;
  }
}ac;

int main(void){
  scanf("%d",&n); ac.init();
  while(n--){
    scanf("%s",t1); ac.insert(t1);
  }
  ac.getP();

  scanf("%s",t1);
  ac.find(t1,strlen(t1));
  printf("%d\n",ac.cnt());

  return 0;
}
*/
