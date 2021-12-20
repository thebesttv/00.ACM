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
typedef long long LL;
typedef long long unsigned LLU;

struct inflatable{
  char name[20];
  float volume;
  double price;
};
int main(void){
  inflatable bouquet = {"sunflowers", 0.20, 12.49 };
  inflatable choice;
  //cout << "bouquet: " << bouquet.name << " for $";
  //cout << bouquet.price << endl;
  ((cout << "bouquet: " << bouquet.name << " for $") << bouquet.price).put('\n');

  choice = bouquet;
  cout << "choice: " << choice.name << " for $";
  cout << choice.price << endl;

  return 0;
}
