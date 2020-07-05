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

const int MAX=1000020;
int n,m;

struct Node{
  int pos, st;
  bool operator < (const Node &b) const {
    return pos < b.pos;
  }
}v[2020];
int tail=0;

inline int read(){
  int sum=0,ch;
  do ch=getchar(); while(!isdigit(ch));
  do{ sum=sum*10+ch-'0'; ch=getchar(); } while(isdigit(ch));
  return sum;
}

int main(void){
  int T=read();
  FORR(kase,1,T){
    tail=0;
    n=read(); m=read();
    int l,r;
    while(m--){
      l=read(); r=read();
      v[tail++]=(Node){l,1};
      v[tail++]=(Node){r+1,-1};
    }
    sort(v,v+tail);
    int st=0,ans=0;
    FOR(i,0,tail){
      st+=v[i].st;
      if(st&1) ans+=v[i+1].pos-v[i].pos;
    }
    printf("Case #%d: %d\n",kase,ans);
  }

  return 0;
}

/*
const int MAX=1000020;
int n,m,v[MAX];

inline int read(){
  int sum=0,ch;
  do ch=getchar(); while(!isdigit(ch));
  do{ sum=sum*10+ch-'0'; ch=getchar(); } while(isdigit(ch));
  return sum;
}

int main(void){
  int T=read();
  FORR(kase,1,T){
    n=read(); m=read();
    int l,r;
    while(m--){
      l=read(); r=read();
      v[l]++, v[r+1]--;
    }
    int d=0,ans=0;
    FOR(i,0,n){
      d+=v[i];
      if(d&1) ans++;
    }
    printf("Case #%d: %d\n",kase,ans);
  }

  return 0;
}
*/

/*
int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d",&n,&m);
    int l,r;
    while(m--){
      scanf("%d%d",&l,&r);
      v[l]++, v[r+1]--;
    }
    int d=0,ans=0;
    FOR(i,0,n){
      d+=v[i];
      if(d&1) ans++;
    }
    printf("Case #%d: %d\n",kase,ans);
  }

  return 0;
}
*/
