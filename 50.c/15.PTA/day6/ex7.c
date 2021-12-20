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

int n; double sum;
struct Ind{
  string num, name;
  int sum;
  bool operator < (const Ind &b) const {
    return sum > b.sum;
  }
};
VR<Ind> v;

int main(void){
  string num, name; int s1,s2,s3;
  cin >> n;
  FOR(i,0,n){
    cin >> num >> name >> s1 >> s2 >> s3;
    v.push_back({num,name,s1+s2+s3});
  }
  sort(ALL(v));
  cout << v[0].name << " " << v[0].num << " " << v[0].sum << endl;

  return 0;
}
