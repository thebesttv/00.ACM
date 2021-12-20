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
#include<utility>
#include<iomanip>
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

using pds = pair<double,string>;
int n;
VR<pds> v;

int main(void){
  string s; double d;
  cin >> n; cin.get();
  FOR(i,0,n){
    getline(cin, s);
    cin >> d; cin.get();
    v.push_back({d,s});
  }
  sort(ALL(v));
  cout << setiosflags(ios::fixed) << setprecision(2);
  cout << v[n-1].first << ", " << v[n-1].second << endl;
  cout << v[0].first << ", " << v[0].second << endl;

  return 0;
}
