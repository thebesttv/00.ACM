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
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 120;
int n,m;
string s[MAX];
bool isP[MAX], isPair[MAX][MAX];
bool vis[MAX];
VR<int> ansL, ansR;

int main(void){
  cin >> n >> m;
  FOR(i,0,n) cin >> s[i];

  FOR(i,0,n){
    string r = s[i];
    reverse(ALL(r));
    if( s[i] == r ) isP[i] = 1;
    FOR(j,0,n) if(s[j] == r)
      isPair[i][j] = isPair[j][i] = 1;
  }

  FOR(i,0,n) if(!vis[i])
    FOR(j,i+1,n) if(!vis[j] && isPair[i][j]){
      ansL.push_back(i);
      ansR.push_back(j);
      vis[i] = vis[j] = 1;
    }

  FOR(i,0,n) if(!vis[i] && isP[i]){
    ansL.push_back(i); break;
  }
  reverse(ALL(ansR));

  cout << m * (ansL.size()+ansR.size()) << endl;
  for(int idx : ansL) cout << s[idx];
  for(int idx : ansR) cout << s[idx];
  cout << endl;

  return 0;
}
