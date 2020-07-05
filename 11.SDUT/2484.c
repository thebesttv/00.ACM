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

const int MAX=1020;
char s[MAX];
int nc,lc[MAX],rc[MAX]; char op[MAX];

int dfs(char *s, int l, int r){
  if(l+1==r){ // only one element
    int u=++nc;
    op[u]=s[l];
    return u;
  }
  int p=0,ch1=-1,ch2=-1;
  FOR(i,l,r) switch(s[i]){
    case '(': p++; break;
    case ')': p--; break;
    case '+': case '-':
      if(!p) ch1=i; break;
    case '*': case '/':
      if(!p) ch2=i; break;
  }
#ifdef DEBUG
  printf("in dfs(%d,%d), get ch1: %d, ch2: %d\n",l,r,ch1,ch2);
#endif
  if(ch1<0) ch1=ch2;
  if(ch1<0) return dfs(s,l+1,r-1);

  int u=++nc; op[u]=s[ch1];
  lc[u]=dfs(s,l,ch1);
  rc[u]=dfs(s,ch1+1,r);
  return u;
}

void pre(int u){
  putchar(op[u]);
  if(lc[u]) pre(lc[u]);
  if(rc[u]) pre(rc[u]);
}
void mid(int u){
  if(lc[u]) mid(lc[u]);
  putchar(op[u]);
  if(rc[u]) mid(rc[u]);
}
void last(int u){
  if(lc[u]) last(lc[u]);
  if(rc[u]) last(rc[u]);
  putchar(op[u]);
}

int main(void){
  scanf("%s",s); int len=0;
  while(s[len]!='#') len++;
#ifdef DEBUG
  printf("get %d: %s\n",len,s);
#endif

  int u=dfs(s,0,len);

  pre(u); putchar('\n');
  mid(u); putchar('\n');
  last(u); putchar('\n');

  return 0;
}
