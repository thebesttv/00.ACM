// Tag: 模拟
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

const int MAX = 2e5 + 20;
int n,v[MAX]; char s[MAX];
queue<int> q0,q1;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    while(!q0.empty()) q0.pop();
    while(!q1.empty()) q1.pop();
    scanf("%d%s",&n,s); int tail = 0;
    FOR(i,0,n){
      if(s[i] == '0'){
        if(q1.empty()){
          q0.push(v[i] = ++tail);
        }else{
          q0.push(v[i] = q1.front());
          q1.pop();
        }
      }else{
        if(q0.empty()){
          q1.push(v[i] = ++tail);
        }else{
          q1.push(v[i] = q0.front());
          q0.pop();
        }
      }
    }
    printf("%d\n",tail);
    FOR(i,0,n) printf("%d ",v[i]); putchar('\n');
  }

  return 0;
}
