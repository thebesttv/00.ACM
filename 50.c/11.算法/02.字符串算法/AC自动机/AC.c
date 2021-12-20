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

struct AC{
  int to[MAX_NODE][TOT],val[MAX_NODE],siz;
  int P[MAX_NODE],last[MAX_NODE];
  bool vis[MAX_NODE]; //记录模式串是否被匹配

  void init() {siz=1; MST(to[0],0); val[0]=0;}
  int idx(int ch) {return ch-'a';}
  void insert(char *s){
    int u=0,ch;
    while(ch=*s++){
      ch=idx(ch);
      if(!to[u][ch]){
        MST(to[siz],0), val[siz]=0;
        to[u][ch]=siz++;
      }
      u=to[u][ch];
    }
    val[u]++; //可能会有重复模式串
  }
  void getP(){
    queue<int> q; P[0]=0; last[0]=0;
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
        last[v] = val[P[v]] ? P[v] : last[P[v]] ;
      }
    }
  }
  void find(char *T){ //对文本串 T 进行匹配
    int j=0,ch; int n=strlen(T);
    FOR(i,0,n){
      ch=idx(T[i]);
      while(j && !to[j][ch]) j=P[j];
      j=to[j][ch];
      if(val[j]) mark(j);
      else if(last[j]) mark(last[j]);
    }
  }
  void mark(int u){
    if(u) vis[u]=1, mark(last[u]);
  }
};












































void Trie::find(char *T){
  int j=0;  //<b> j 是指针 </b>
  FOR(i,0,len){
    int ch=idx(T[i]);
    while(j && !to[j][ch]) j=P[j];
    j=to[j][ch];  //若 to[j][ch] 为 0 ，没关系，因为根节点即为 0
    if(val[j]){
      // 串 j 以及其所有合法子串（对于一个串，当且仅当它为模式串时合法）都为 T 的匹配
      // find match for string T, which is **every string** represented by node j
    }else if(last[j]){
      // 串 j 的所有合法子串都为 T 的匹配（串 j 非模式串）
      // also find match for string T, which is **every string** represented by node last[j]
      // aka: string j is not a legal word, but there're some strings that end with node[j] and are legal
    }
  }
}

/*
P[i]: same as KMP
  i代表在 Trie 中以 i 结尾的串
  P[i]: 若P[i]等于j，它表示串 j 即为串 i 的 proper suffix
  if P[i] points at node j, it means: string j is equal to the proper suffix of string i

last[i]: 节点 j 顺着失配指针走的时候，第一个遇到的单词节点编号
  if P[i] 是单词节点 then last[i] = P[i]
  else last[i] = last[P[i]]
*/
void Trie::getP(){
  queue<int> q;
  P[0]=0;
  int u,v;
  FOR(i,0,TOT){ //TOT: 单词集合大小
    u = to[0][i];
    if(u) q.push(u), P[u]=0, last[u]=0;
  }
  int j=0;
  while(!q.empty()){
    u=q.front(); q.pop();
    FOR(i,0,TOT){ //对节点 u 扩展，计算 v 节点
      v = to[u][i];
      if(!v) continue;
      q.push(v);

      j=P[u]; //<b> </b>
      while(j && !to[j][i]) j=P[j];
      j=to[j][i];
      P[v]=j;
      last[v] = val[P[v]] ? P[v] : last[P[v]];
    }
  }
}
