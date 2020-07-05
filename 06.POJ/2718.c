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
#include<sstream>
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

const int INF=0x3f3f3f3f;
int n,l,ansMin;
VR<int> v;
bool use[20];

void dfs(int cur, int cnt){
  if(cnt==l){
    VR<int> a,b;
    FOR(i,0,n){
      if(use[i]) a.push_back(v[i]);
      else b.push_back(v[i]);
    }
    do{
      if(a.size()>1 && a[0]==0) continue;
      int na = 0;
      //for(int x : a) na=na*10+x;
      FOR(i,0,a.size()) na=na*10+a[i];

      do{
        if(b.size()>1 && b[0]==0) continue;
        int nb = 0;
        //for(int x : b) nb=nb*10+x;
        FOR(i,0,b.size()) nb=nb*10+b[i];

        ansMin=min(ansMin,abs(na-nb));
      }while(next_permutation(ALL(b)));
    }while(next_permutation(ALL(a)));

    return;
  }
  if(n-cur+cnt<l) return;
  use[cur]=1; dfs(cur+1,cnt+1);
  use[cur]=0; dfs(cur+1,cnt);
}

int main(void){
  ios::sync_with_stdio(false);
  int T; cin >> T; cin.get();
  while(T--){
    ansMin=INF; v.clear();
    string s; getline(cin,s);
    stringstream ss(s);
    int x;
    while(ss >> x) v.push_back(x);
    n=v.size(), l=n/2;
    dfs(0,0);
    cout << ansMin << endl;
  }

  return 0;
}
