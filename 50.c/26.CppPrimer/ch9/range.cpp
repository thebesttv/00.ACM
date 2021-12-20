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
#include<forward_list>
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

int main(void){
  list<string> ls;
  list<char *> lc;
  vector<string> vs;
  vector<char *> vc;

  forward_list<string> list1(ALL(ls));
  list<string> list2(ALL(lc));
  //list<char *> list3(ALL(ls));
  list<char *> list4(ALL(lc));
  list<string> list5(ALL(vs));
  list<string> list6(ALL(vc));
  //list<char *> list7(ALL(vs));
  list<char *> list8(ALL(vc));

  return 0;
}
