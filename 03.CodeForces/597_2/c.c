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

const int MAX=1e5;
const int MOD=1e9+7;
int n; char s[MAX+20];
LL f[MAX+20];

void gcd(LL a, LL b, LL &d, LL &x, LL &y){
  if(!b) { d=a; x=1; y=0; }
  else { gcd(b,a%b,d,y,x); y -= x*(a/b); }
}

LL get(LL x, LL y){
  LL d,tx,ty;
  gcd(f[x],MOD,d,tx,ty);
  LL rx = (tx + MOD)%MOD;

  gcd(f[y],MOD,d,tx,ty);
  LL ry = (tx + MOD)%MOD;
  //printf("    rx: %lld, ry: %lld\n",rx,ry);

  return f[x+y] * rx % MOD * ry % MOD;
}

int main(void){
  f[0] = f[1] = 1ll;
  FORR(i,2,MAX) f[i] = f[i-1] * i % MOD;

  scanf("%s",s); n=strlen(s);
  FOR(i,0,n) if(s[i]=='m' || s[i]=='w'){
    printf("0\n"); return 0;
  }

  int l=0,r=0; LL ans=1;
  while(l<n){
    if(s[l]=='n' || s[l]=='u'){
      if(s[l]=='n'){
        r=l; while(r<n && s[r]=='n') ++r;
      }else if(s[l]=='u'){
        r=l; while(r<n && s[r]=='u') ++r;
      }
      //printf("%d,%d\n",l,r);
      int len = r-l; LL sum = 0;
      for(int y=0;y*2<=len;++y){
        int x = len - y*2;
        //ans = (ans * get(x,y))%MOD;
        sum = (sum + get(x,y)) % MOD;
        //printf("  x: %d, y: %d, %lld\n",x,y,get(x,y));
      }
      ans = ans * sum % MOD;
      l = r;
    }else ++l;
  }
  printf("%lld\n",ans);

  return 0;
}
