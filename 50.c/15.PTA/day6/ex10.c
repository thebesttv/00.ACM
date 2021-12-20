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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

int n;
deque<string> a, b;
VR<int> ord;

int main(void){
  scanf("%d",&n); int x; string s;
  FOR(i,0,n){
    cin >> x >> s;
    if(x) b.push_back(s);
    else a.push_back(s);
    ord.push_back(x);
  }
  n /= 2;
  FOR(i,0,n){
    if(!ord[i]){
      cout << a.front() << " " << b.back();
      a.pop_front(), b.pop_back();
    }else{
      cout << b.front() << " " << a.back();
      b.pop_front(), a.pop_back();
    }
    cout << endl;
  }

  return 0;
}
