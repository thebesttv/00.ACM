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
#include<set>
#include<map>
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

//#define DEBUG

const int MAXN = 54;
const LL MOD = 998244353;
int n,m; pii page[26][MAXN];
VR<string> dic; char s[60];
 
void read(pii &p){
  int ch, s = 0;
  do ch = getchar(); while(!isalpha(ch));
  p.FI = ch-'a';
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  p.SE = s;
}

struct F1{  // m <= 4
  int ans[20]; char r[20];

  void decode(char *s, char *res, int n){
    int idx = 1;
    FOR(i,0,n){
      pii &p = page[s[i]-'a'][idx];
      res[i] = p.FI + 'a'; idx = p.SE;
    }
  }

  bool match(const char *s, const char *p, int n){
    FOR(i,0,n) if(s[i]!=p[i]) return false;
    return true;
  }
  
  bool ok(int n){
    char res[20]; decode(r, res, n);
    for(string &s : dic) FORR(i,0,n-(int)s.size())
      if(match(s.c_str(), r+i, s.size())){
        return false;
      }
  
    int i = 0, j;
    while(i < n){
      bool ok = 0;
      for(string &s : dic) if(i + s.size() <= n &&
        match(s.c_str(), res + i, s.size())){
          ok = 1; i += s.size();
        }
      if(!ok) return false;
    }
    return true;
  }
  
  void dfs(int cur){
    if(cur && ok(cur)){
      ++ans[cur];
    }
    if(cur == m) return;
    FORR(i,'a','z') r[cur] = i, dfs(cur + 1);
  }

  void process(){
    dfs(0);
    FORR(i,1,m) printf("%d\n",ans[i]);
  }
}f1;

struct F2{  // all 1 && n = 1
  int cnt = 0; bool vis[26],aval[26];
  LL pow_mod(LL a, LL x){
    LL ans = 1;
    while(x){
      ans = x&1 ? ans * a %MOD : ans;
      a = a*a%MOD; x>>=1;
    }
    return ans;
  }
  void process(){
    for(string &s : dic) vis[s[0]-'a'] = aval[s[0]-'a'] = 1;
    for(string &s : dic) if(vis[page[s[0]-'a'][1].FI])
      aval[s[0]-'a'] = 0;
    int cnt = 0; FOR(i,0,26) cnt += aval[i];
    FORR(i,1,m) printf("%lld\n",pow_mod(cnt,i));
  }
}f2;

int main(void){
  #ifdef DEBUG
  freopen("in.txt","r",stdin);
  #endif
  scanf("%d%d",&n,&m);
  FOR(i,0,26) FORR(j,1,n) read(page[i][j]);
  bool all1 = true, alllarge = true;
  while(scanf("%s",s)==1){
    #ifdef DEBUG
    printf("dic: %s\n",s);
    #endif
    dic.pb(string(s));
    if(dic.back().size() != 1) all1 = false;
    if(dic.back().size() < 7) alllarge = false;
  }

  if(m <= 4) f1.process();
  else if(n == 1){  // one page
    if(all1){
      f2.process();
    }else if(alllarge){
    }else{
    }
  }

  return 0;
}