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
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 120;
int n; char s[MAX];

bool isV(char s){
  return s=='a' || s=='e' || s=='i' || s=='o' || s=='u';
}

bool ok(){
  int i = 0;
  while(i<n && !isV(s[i])) ++i;
  if(i>=n) return false;

  ++i;
  while(i<n && isV(s[i])) ++i;
  if(i>=n) return false;

  ++i;
  while(i<n && !isV(s[i])) ++i;
  if(i>=n) return false;

  i = i+1;
  while(i<n && isV(s[i])) ++i;
  return i==n;
}

int main(void){
  scanf("%s",s);
  n = strlen(s);
  printf("%s\n", ok() ? "yes" : "no");

  return 0;
}
