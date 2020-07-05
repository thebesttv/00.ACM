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

int main(void){
  int T; cin >> T;
  bool first = 1;
  FORR(kase,1,T){
    string s1,s2,a1,a2;
    cin >> s1 >> s2;
    reverse(ALL(s1));
    reverse(ALL(s2));
    int n = min(s1.size(),s2.size())-1;
    bool done = 0;
    FOR(i,0,n) if(s1[i]!=s2[i]){
      done = 1;
      FOR(j,i,s1.size()) a1 += s1[j];
      FOR(j,i,s2.size()) a2 += s2[j];
      break;
    }
    if(!done){
      FOR(j,n,s1.size()) a1 += s1[j];
      FOR(j,n,s2.size()) a2 += s2[j];
    }
    reverse(ALL(a1)); reverse(ALL(a2));
    reverse(ALL(s1)); reverse(ALL(s2));
    if(first) first = 0;
    else cout << "\n";
    cout << "Game #" << kase << ":\n";
    cout << "   The input words are " << s1 << " and " << s2 << ".\n";
    cout << "   The words entered in the notebook are " << a1 << " and " << a2 << ".\n";
  }

  return 0;
}
