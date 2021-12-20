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
#include<locale>
#include<codecvt>
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
typedef long long LL;
typedef long long unsigned LLU;

int main(void){
  wchar_t title[] = L"Chief Astrogator";
  char16_t name[] = u"Felonia Ripova";
  char32_t car[] = U"Humber Super Snipe";

  // not ok, only prints the first line. ???
  //wcout << title << endl;
  //cout << R"(This is my raw string "" \n \r a\ ds\f \e \\f)" << endl;

  // ok, prints both lines
  //cout << R"(This is my raw string "" \n \r a\ ds\f \e \\f)" << endl;
  //wcout << title << endl;

  cout << R"la(This is my lalala raw string: LAfldsf efs d & * 2 \\\\\nn\re\
)la";
  cout << R"*******(This is my another raw string without line break: LAfldsf efs d & * 2 \\\\\nn\re\)*******" << endl;

  return 0;
}
