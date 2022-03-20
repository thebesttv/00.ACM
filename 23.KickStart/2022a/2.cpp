// Tag: 
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
#include<numeric>
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

int T;
const int MAX = 2e5 + 20;
string s;
vector<char> v;

void cal(int x) {
  if (x == 0) {
    printf("%c0", s[0]);
    printf("%s\n", s.c_str() + 1);
    return;
  }

  int i = 0;
  while (i < s.size() && (s[i]-'0') <= x) {
    putchar(s[i]); ++i;
  }
  putchar(x + '0');
  while (i < s.size()) {
    putchar(s[i]); ++i;
  }
  putchar('\n');
}

int main(void){
  // FORR(i,0,9) {
  //   FORR(j,0,9) {
  //     if ((i + j) % 9 == 0) {
  //       printf("%d + %d\n", i, j);
  //     }
  //   }
  // }
  int T; cin >> T;
  FORR(kase,1,T) {
    cin >> s;
    int sum = 0;
    for (char ch : s) {
      sum = (sum + ch - '0') % 9;
    }

    printf("Case #%d: ", kase);
    FORR(i,0,9) if ((i + sum) % 9 == 0) {
      cal(i);
      break;
    }
  }

  return 0;
}
