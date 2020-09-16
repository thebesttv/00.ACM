// Tag: set
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

const int MAX = 1e5 + 20;
int n,a[MAX],q;
set<int> st1; multiset<int> st2;

void remove(int x){
  auto it = st2.find(x); st2.erase(it);
}

int cal(){
  if(st1.size() <= 2) return 0;
  return *st1.rbegin() - *st1.begin() - *st2.rbegin();
}

int main(void){
  scanf("%d%d",&n,&q);
  FORR(i,1,n) scanf("%d",&a[i]), st1.insert(a[i]);
  sort(a+1,a+1+n);
  FORR(i,2,n) st2.insert(a[i] - a[i-1]);

  printf("%d\n",cal());

  int op,x;
  while(q--){
    scanf("%d%d",&op,&x);
    if(!op){  // remove
      auto oit = st1.find(x); auto it = oit;
      if(st1.size() >= 2){
        if(it == st1.begin()){
          ++it; int r = *it;
          remove(r - x);
        }else if(x == *st1.rbegin()){
          --it; int l = *it;
          remove(x - l);
        }else{
          auto it2 = it;
          ++it; int r = *it;
          --it2; int l = *it2;
          remove(r - x); remove(x - l);
          st2.insert(r - l);
        }
      }
      st1.erase(oit);
    }else{
      st1.insert(x); auto it = st1.find(x);
      if(st1.size() >= 2){
        if(it == st1.begin()){
          ++it; int r = *it;
          st2.insert(r - x);
        }else if(x == *st1.rbegin()){
          --it; int l = *it;
          st2.insert(x - l);
        }else{
          auto it2 = it;
          ++it; int r = *it;
          --it2; int l = *it2;
          remove(r - l);
          st2.insert(r-x), st2.insert(x-l);
        }
      }
    }
#ifdef DEBUG
    printf("st1:"); for(int x : st1) printf(" %d",x); putchar('\n');
    printf("st2:"); for(int x : st2) printf(" %d",x); putchar('\n');
#endif
    printf("%d\n",cal());
  }

  return 0;
}
