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

const int MAX=120;
int n; char ch;
string v1[MAX], v2[MAX];

bool same(string *v1, string *v2){
  FOR(i,0,n) if(v1[i]!=v2[i]) return 0;
  return 1;
}

int main(void){
  scanf("%c %d",&ch,&n); cin.get();
  FOR(i,0,n){
    getline(cin,v1[i]);
    v2[n-1-i]=v1[i];
    reverse(ALL(v2[n-1-i]));
  }
  if(same(v1,v2)) printf("bu yong dao le\n");
  FOR(i,0,n){
    for(char c : v2[i])
      if(c=='@') putchar(ch);
      else putchar(' ');
    putchar('\n');
  }

  return 0;
}
