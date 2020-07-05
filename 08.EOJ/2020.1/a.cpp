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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

int n;
int idx[4];
int v[4] = {60, 60, 5, 2};
VR<string> s[4];
char ori[60][3] = {"00", "01", "02", "03", "04", "05", "10", "11", "12", "13", "14", "15", "20", "21", "22", "23", "24", "25", "30", "31", "32", "33", "34", "35", "40", "41", "42", "43", "44", "45", "50", "51", "52", "53", "54", "55", "60", "61", "62", "63", "64", "65", "70", "71", "72", "73", "74", "75", "80", "81", "82", "83", "84", "85", "90", "91", "92", "93", "94", "95"};

int main(void){
  FOR(i,0,60) s[0].push_back(string(ori[i]));
  FOR(i,0,60) s[1].push_back(string(ori[i]));
  s[2] = VR<string>{"01", "02", "10", "11", "12"};
  s[3] = VR<string>{"1", "2"};

  scanf("%d",&n); --n; n += 43322;
  string ans;
  ROR(i,3,0){
    idx[i] = n % v[i];
    n /= v[i];
  }
  FOR(i,0,4) ans += s[i][idx[i]];
  string t = ans; reverse(ALL(t));
  ans += t;
  cout << ans << endl;

  return 0;
}
