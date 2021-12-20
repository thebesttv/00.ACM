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

//Trie
const int MAXN=10000;
const int MAXL=60;
int n,m;
char t1[MAXL];
struct Trie{
  int to[MAXN*MAXL][26],siz;
  bool val[MAXN*MAXL],vis[MAXN*MAXL];

  void init() {siz=1; MST(to[0],0);}
  void insert(char *s){
    int u=0,ch;
    while(ch=*s++){
      ch-='a';
      if(!to[u][ch]){
        MST(to[siz],0), val[siz]=0;
        to[u][ch]=siz++;
      }
      u=to[u][ch];
    }
    val[u]=1;
  }
  int find(char *s){  //0: 未找到，1: 找到且之前没找过，-1: 找到且之前找过
    int u=0,ch;
    while(ch=*s++){
      ch-='a';
      u=to[u][ch];
      if(!u) return 0;
    }
    if(!vis[u]) {vis[u]=1; return 1;}
    else return -1;
  }
}tr;

int main(void){
  scanf("%d",&n); tr.init();
  while(n--){
    scanf("%s",t1); tr.insert(t1);
  }

  scanf("%d",&m);
  while(m--){
    scanf("%s",t1);
    int t=tr.find(t1);
    printf("%s\n", !t ? "WRONG" : (t==1 ? "OK" : "REPEAT") );
  }

  return 0;
}

/*
//hash 然而没卡过……
const int MAXL=60;
const int MOD=3e7+7;
int n,m;
char t1[MAXL];
bool isword[MOD],vis[MOD];

int h(char *s){
  int a=0,ch;
  while(ch=*s++){
    a = a*10 + ch;
    if(a>MOD) a%=MOD;
  }
  return a;
}

int main(void){
  scanf("%d",&n);
  while(n--){
    scanf("%s",t1); isword[h(t1)]=1;
  }
  
  scanf("%d",&m);
  while(m--){
    scanf("%s",t1);
    int idx=h(t1);
    if(!isword[idx]) printf("WRONG\n");
    else{
      if(!vis[idx]) vis[idx]=1, printf("OK\n");
      else printf("REPEAT\n");
    }
  }

  return 0;
}
*/
