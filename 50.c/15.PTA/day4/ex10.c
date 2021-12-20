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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

int a,b;
char s[10020];

int get(char *p){
  int s=0;
  while(*p){
    if(isdigit(*p)){
      s = s*10 + (*p-'0');
      p++;
    }else return -1;
  }
  return s;
}

int main(void){
  char *p = s; int ch;
  bool first=1;
  while((ch=getchar())!='\n'){
    if(ch==' ' && first){
      *p=0; a=get(s);
      first=0; p=s;
      continue;
    }
    *p++ = ch;
  }
  *p = 0;
  b = get(s);
  if(a>1000 || a<1) a=-1;
  if(b>1000 || b<1) b=-1;

  if(a==-1) printf("?");
  else printf("%d",a);

  printf(" + ");

  if(b==-1) printf("?");
  else printf("%d",b);

  printf(" = ");

  if(a>0 && b>0) printf("%d",a+b);
  else printf("?");
  printf("\n");


  return 0;
}
