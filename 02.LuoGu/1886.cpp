// Tag: 单调队列
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

int n, k;
struct Node{
  int pos, v;
};
deque<Node> qmin,qmax;
vector<int> amin,amax;

void clean(deque<Node> &q, int i){
  while(!q.empty() && i - q.front().pos + 1 > k)
    q.pop_front();
}

void print(vector<int> &v){
  for(auto x : v) printf("%d ",x);
  putchar('\n');
}

int main(void){
  scanf("%d%d",&n,&k);
  for(int i = 1; i <= n; i++){
    int x; scanf("%d",&x);
    clean(qmin, i);
    clean(qmax, i);

    while(!qmax.empty() && qmax.back().v <= x){
      qmax.pop_back();
    }
    qmax.push_back({i, x});

    while(!qmin.empty() && qmin.back().v >= x){
      qmin.pop_back();
    }
    qmin.push_back({i, x});

    if(i >= k){
      amax.push_back(qmax.front().v);
      amin.push_back(qmin.front().v);
    }
  }
  print(amin);
  print(amax);

  return 0;
}
