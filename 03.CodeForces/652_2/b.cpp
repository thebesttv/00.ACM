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

const int MAX = 1e5 + 20;
int n; char s[MAX];
deque<char> q;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    q.clear();
    scanf("%d%s",&n,s);
    FOR(i,0,n) q.push_back(s[i]);
    int a = 0, b = 0;
    while(!q.empty() && q.front() == '0')
      ++a, q.pop_front();
    while(!q.empty() && q.back() == '1')
      ++b, q.pop_back();
    while(a--) putchar('0');
    if(!q.empty()) putchar('0');
    while(b--) putchar('1');
    putchar('\n');
  }

  return 0;
}
