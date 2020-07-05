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

const int MAX = 1e6 + 20;
int n; char s[1020];
bool vis[MAX];

int main(void){
  scanf("%d",&n);
  while(n--){
    scanf("%s",s);
    if(s[0] == '-') continue;
    int len = strlen(s);
    if(len >= 8) continue;
    int sum = 0;
    FOR(i,0,len) sum = sum * 10 + s[i]-'0';
    if(sum <= int(1e6)) vis[sum] = 1;
  }
  FORR(i,0,int(1e6)) if(!vis[i]){
    printf("%d\n",i); return 0;
  }

  return 0;
}
