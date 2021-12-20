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

/*
  解题报告：
  [1]
    采用类似 [LA 3942] 的方法，令 f[i] 表示 S[i:end] 中，是否能被字典匹配（被字典匹配的次数），则有
      f[i] = sum{ f[i+len(x)] | x 为 S[i:end] 的前缀 }
    因为题目要求的是从左往右的最大匹配长度，而 f 是倒过来的，则将所有输入的字符串都反转。
    最后找到第一个不为0的 f[i] ，答案即为 len-i 。
  [2]
    令 f[i] 表示 S[1:i] 能否被匹配，则
      f[i] -> f[i+len(x)] | x 为 S[i+1:end] 的前缀
    注意循环时的边界，不然可能会在小数据上出错。
*/

//[2]
const int MAX_NODE=1000;
const int MAXL=1000020;
int n,m; bool f[MAXL]; //f[i]: S[1:i] 能否被匹配
char t1[MAXL];

struct Trie{
  int to[MAX_NODE][26];
  int siz; bool vis[MAX_NODE];

  void clear(){
    siz=1; MST(to[0],0);
  }
  void insert(char *s){
    int u=0,ch;
    while(ch=*s++){
      ch-='a';
      if(!to[u][ch]){
        MST(to[siz],0); vis[siz]=0;
        to[u][ch]=siz++;
      }
      u=to[u][ch];
    }
    vis[u]=1;
  }
  void calc(char *s, int i){ //在串 s 中，用 f[i] 更新其他的 f
    int u=0,ch,j=i;
    bool &a=f[i];
    if(!a) return;  //<b> </b>
    while(ch=*s++){
      ch-='a';
      u=to[u][ch], j++;
      if(!u) break;
      if(vis[u]) f[j]=a;
    }
  }
}tr;

void read(char *s){
  int ch;
  do ch=getchar(); while(!isalpha(ch));
  while(isalpha(ch)){
    *s++=ch; ch=getchar();
  }
}

int main(void){
  scanf("%d%d",&n,&m); tr.clear();
  while(n--){
    scanf("%s",t1); tr.insert(t1);
  }

  while(m--){
    // f[i]: S[1:i] 能否被匹配
    // f[i] -> f[i+len(x)] | x 为 s[i+1:end] 前缀
    scanf("%s",t1+1); MST(f,0);
    int len=strlen(t1+1); f[0]=1;
    FORR(i,1,len){  //<b> 1<=i<=len </b>
      tr.calc(t1+i,i-1);
      if(f[len]) break;
    }

    ROR(i,len,0) if(f[i]){
      printf("%d\n",i); break;
    }
  }

  return 0;
}

/*
//[1]
const int MAX_NODE=1000;
const int MAXL=1000020;
int n,m,f[MAXL]; //f[i]: S[i:...] 能否被匹配
char t1[MAXL],t2[MAXL];

void reverse(char *s, char *t){
  int len=strlen(s); t[len]=0;
  FOR(i,0,len) t[len-i-1]=s[i];
  strcpy(s,t);
}
struct Trie{
  int to[MAX_NODE][26];
  int siz; bool vis[MAX_NODE];

  void clear(){
    siz=1; MST(to[0],0);
  }
  void insert(char *s){
    int u=0,ch;
    while(ch=*s++){
      ch-='a';
      if(!to[u][ch]){
        MST(to[siz],0); vis[siz]=0;
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
      if(!u || a) break;
      if(vis[u]){ //匹配到一个字符串
        a+=f[j];
      }
    }
  }
}tr;

int main(void){
  scanf("%d%d",&n,&m); tr.clear();
  while(n--){
    scanf("%s",t1); reverse(t1,t2);
    tr.insert(t1);
  }

  while(m--){
    //f[i] = sum{ f[i+len(x)] | x为s[i:...]前缀 }
    scanf("%s",t1); reverse(t1,t2); //MST(f,0);
    int len=strlen(t1); f[len]=1;
    ROR(i,len-1,0){
      tr.calc(t1+i,i);
    }
    FORR(i,0,len) if(f[i]){
      printf("%d\n",len-i); break;
    }
  }

  return 0;
}
*/
