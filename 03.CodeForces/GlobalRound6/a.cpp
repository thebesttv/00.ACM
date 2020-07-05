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

const int MAX = 120;
int n;

bool ok(string &s){
  // 判断 s 是否可能为 2 * 3 * 10 的倍数
  if(s=="0") return true;

  int cnt0=0, cntEven = 0, sum = 0;
  for(char ch : s){
    if(ch=='0') ++cnt0;
    if((ch-'0')%2==0) ++cntEven;
    sum += ch-'0';
  }
  if(!cnt0) return 0; // 10
  if(sum%3) return 0; // 3
  if(cntEven - 1 ==0) return 0; // 2

  return 1;
}

int main(void){
  scanf("%d",&n);
  while(n--){
    int sum = 0;
    string s; cin >> s;
    printf("%s\n",ok(s) ? "red" : "cyan");
  }

  return 0;
}
