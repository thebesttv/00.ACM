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

const int MAX=1e6+20;
int n,st[MAX];
VR<int> cur, ans;
enum { WAIT, ENTERED, LEFT };

int main(void){
  cin >> n;
  if(n&1) { printf("-1\n"); return 0; }
  int cnt = 0;
  bool impossible = 0;
  while(n--){
    int x,u; cin >> x;
    u = abs(x);
    if(st[u]==WAIT){
      if(x<0) { impossible = 1; break; }
      st[u] = ENTERED;
    }else if(st[u]==ENTERED){
      if(x>0) { impossible = 1; break; }
      st[u] = LEFT;
    }else{
      impossible = 1; break;
    }
    cur.push_back(u);
    cnt++;

    bool ok = 1;
    for(int x : cur) if(st[x]!=LEFT){
      ok=0; break;
    }

    if(ok){
      for(int x : cur) st[x] = WAIT;
      cur.clear(); ans.push_back(cnt); cnt=0;
    }
  }
  if(cnt) impossible = 1;

  if(impossible) printf("-1\n");
  else{
    printf("%d\n",(int)ans.size());
    for(int x : ans)
      printf("%d ",x);
    putchar('\n');
  }

  return 0;
}

/*
const int MAX=1e5+20;
int n;
//st[i]: 1: in, 2: out, 3: in & out
map<int, int> mp; // mp内状态必合法

bool day(){
  for(const auto &w : mp){
    if(w.second != 3) return 0;
  }
  return 1;
}

bool add(int x){
  if(mp.count(abs(x))){ // already in
    if(x>0 || (x<0 && mp[-x]&2)) return false;
    mp[-x] |= 2;
  }else{  // not yet in
    if(x<0) return false;
    mp[x] = 1;
  }
  return true;
}

int main(void){
  VR<int> v; int x;
  scanf("%d",&n);
  bool impossible = 0;
  int cnt = 0;

  FOR(k,0,n){
    scanf("%d",&x);
    if(mp.count(abs(x))){
      if(x>0 || (x<0 && mp[-x]&2)){ // 必为新的一天
        if(!day()){
          impossible = 1; break;
        }
        mp.clear(); v.push_back(cnt);
        cnt = 0;
      }
    }
    if(cnt && day()){ // 最小贪心
      mp.clear(); v.push_back(cnt);
      cnt = 0;
    }
    if(!add(x)){
      impossible = 1; break;
    }
    cnt++;
  }
  if(!day()) impossible = 1;
  v.push_back(cnt);

  if(impossible) printf("-1\n");
  else{
    printf("%d\n",(int)v.size());
    printf("%d",v[0]);
    if(v.size()>1)
      FOR(i,1,v.size()) printf(" %d",v[i]);
    putchar('\n');
  }

  return 0;
}
*/
