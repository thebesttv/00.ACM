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

const int MAXL1=300020, MAXL2=120;
const int MAX=4020;
const int MOD=20071027;
int s,f[MAXL1]; //f[i]: S[i:...] 中的匹配次数
char t1[MAXL1],t2[MAXL2];

struct Trie{
  int to[MAX*MAXL2][26];
  int siz; bool vis[MAX*MAXL2];

  void clear(){
    siz=1; MST(to[0],0);
  }
  void insert(char *s){
    int u=0,ch;
    while(ch=*s++){
      ch-='a';
      if(!to[u][ch]){
        MST(to[siz],0); vis[siz]=0; //在插入的同时清除，在多组输入时能快很多
        to[u][ch]=siz++;
      }
      u=to[u][ch];
    }
    vis[u]=1;
  }
  void calc(char *s, int i){ //计算f[i]=a
    int u=0,ch,j=i; //f[i]=sum{f[j]}
    int &a=f[i]; a=0;
    while(ch=*s++){
      ch-='a';
      u=to[u][ch], j++;
      if(!u) break;
      if(vis[u]){ //匹配到一个字符串
        a+=f[j];
        if(a>MOD) a-=MOD; //因为 f[j] 和之前的 a 总是小于 MOD 的，现在的 a 一定小于 2*MOD ，所以可以用减号
      }
    }
  }
}tr;

int main(void){
  int kase=0;
  while(scanf("%s",t1)==1){
    tr.clear(); //MST(f,0);
    scanf("%d",&s);
    while(s--){
      scanf("%s",t2); tr.insert(t2);
    }

    //f[i] = sum{ f[i+len(x)] | x为s[i:...]前缀 }
    int len=strlen(t1); f[len]=1;
    ROR(i,len-1,0){
      tr.calc(t1+i,i);
    }
    printf("Case %d: %d\n",++kase,f[0]);
  }

  return 0;
}

/*
const int MAXL1=300020, MAXL2=120;
const int MAX=4020;
const int MOD=20071027;
int s,f[MAXL1]; //f[i]: S[i:...] 中的匹配次数
char t1[MAXL1],t2[MAXL2];

struct Trie{
  int to[MAX*MAXL2][26];
  int siz; bool vis[MAX*MAXL2];

  void clear(){
    siz=1; MST(to,0); MST(vis,0);
  }
  void insert(char *s){
    int u=0,ch;
    while(ch=*s++){
      ch-='a';
      if(!to[u][ch]) to[u][ch]=siz++;
      u=to[u][ch];
    }
    vis[u]=1;
  }
  void calc(char *s, int i){ //计算f[i]=a
    int u=0,ch,j=i; //f[i]=sum{f[j]}
    int &a=f[i]; a=0;
    while(ch=*s++){
      ch-='a';
      u=to[u][ch], j++;
      if(!u) break;
      if(vis[u]){ //匹配到一个字符串
        a+=f[j];
        if(a>MOD) a-=MOD;
      }
    }
  }
}tr;

int main(void){
  int kase=0;
  while(scanf("%s",t1)==1){
    tr.clear(); //MST(f,0);
    scanf("%d",&s);
    FOR(i,0,s){
      scanf("%s",t2); tr.insert(t2);
    }

    //f[i] = sum{ f[i+len(x)] | x为s[i:...]前缀 }
    int len=strlen(t1); f[len]=1;
    ROR(i,len-1,0){
      tr.calc(t1+i,i);
    }
    printf("Case %d: %d\n",++kase,f[0]);
  }

  return 0;
}
*/
