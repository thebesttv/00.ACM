/*
ID: taozhij1
PROG: ride
LANG: C++
*/

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

const int MOD=47;
char a[20],b[20];
int main(void){
  freopen("ride.in","r",stdin);
  freopen("ride.out","w",stdout);
  scanf("%s%s",a,b);
  int lena=strlen(a),lenb=strlen(b);
  int sa=1,sb=1;
  FOR(i,0,lena) sa = sa*(a[i]-'A'+1)%MOD;
  FOR(i,0,lenb) sb = sb*(b[i]-'A'+1)%MOD;
  printf("%s\n",sa==sb ? "GO" : "STAY" );
  return 0;
}
