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

Position BinarySearch( List L, ElementType X ){
  int i, n = L->Last;
  for(i=1; i<=n; i++)
    if(L->Data[i] == X) return i;
  return NotFound;
}

Position BinarySearch( List L, ElementType X ){
  int i, n = L->Last;
  int l=1, r=n+1;
  while(l<r){
    int m = (l+r)/2;
    if(L->Data[m] < X) l = m+1;
    else r = m;
  }
  if(L->Data[l] == X) return l;
  else return NotFound;
}
