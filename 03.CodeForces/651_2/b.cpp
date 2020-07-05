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

const int MAX = 2020;
int n,a[MAX];
queue<int> odd,even;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    while(!odd.empty()) odd.pop();
    while(!even.empty()) even.pop();
    scanf("%d",&n); n*=2;
    FORR(i,1,n){
      scanf("%d",&a[i]);
      if(a[i]&1) odd.push(i);
      else even.push(i);
    }

    if(odd.size() & 1){
      odd.pop(); even.pop();
    }else{
      if(odd.size() > 2)
        odd.pop(), odd.pop();
      else
        even.pop(), even.pop();
    }

    int x, y;
    while(!odd.empty()){
      x = odd.front(); odd.pop();
      y = odd.front(); odd.pop();
      printf("%d %d\n",x,y);
    }
    while(!even.empty()){
      x = even.front(); even.pop();
      y = even.front(); even.pop();
      printf("%d %d\n",x,y);
    }
  }

  return 0;
}
