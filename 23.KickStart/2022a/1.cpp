// Tag: 
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
#include<numeric>
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

const int MAX = 1e5 + 20;
int T;
char s[MAX];

void get(queue<char> &q) {
  scanf("%s", s);
  int l = strlen(s);
  for (int i = 0; i < l; ++i) {
    q.push(s[i]);
  }
}

int main(void){
  scanf("%d",&T);
  FORR(kase,1,T) {
    queue<char> i, p;
    get(i); get(p);
    int cnt = 0;
    while (!i.empty() && !p.empty()) {
      if (p.front() == i.front()) {
        p.pop(); i.pop();
      } else {
        p.pop(); ++cnt;
      }
    }
    printf("Case #%d: ", kase);
    if (!i.empty()) printf("IMPOSSIBLE\n");
    else printf("%d\n", cnt + p.size());
  }

  return 0;
}
