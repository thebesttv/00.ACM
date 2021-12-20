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

union one4all{
  int a;
  long long b;
  double c;
  char d;
};

void print(one4all &u){
  printf("a: %d\nb: %lld\nc: %lf\nd: %c\n\n",u.a,u.b,u.c,u.d);
}

int main(void){
  cout << "size of one4all: " << sizeof(one4all) << endl;
  one4all u;
  u.a = 123; print(u);

  u.b = 1234567890123; print(u);

  u.c = 123122.12321; print(u);

  u.d = 'a'; print(u);
  return 0;
}
