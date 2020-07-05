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

int k; char s[6];
int cnt1[5][26], cnt2[5][26];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(cnt1,0), MST(cnt2,0);
    scanf("%d",&k); --k;
    FOR(i,0,6){
      scanf("%s",s);
      FOR(j,0,5) ++cnt1[j][s[j]-'A'];
    }
    FOR(i,0,6){
      scanf("%s",s);
      FOR(j,0,5) ++cnt2[j][s[j]-'A'];
    }

    VR<char> v[5];
    bool bad = 0;
    FOR(i,0,5){
      FOR(j,0,26) if(cnt1[i][j] && cnt2[i][j])
        v[i].push_back(j+'A');
      if(v[i].size()==0) bad = 1;
    }
    if(bad) { printf("NO\n"); continue; }

    char ans[6]; ans[5]=0;
    ROR(i,4,0){
      ans[i] = v[i][k % v[i].size()];
      k /= v[i].size();
    }
    if(k>0) printf("NO\n");
    else printf("%s\n",ans);
  }

  return 0;
}

/*
int k,mul[5]; char s[6],r[6];
set<char> sta[5],stb[5],same[5];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    FOR(i,0,5) sta[i].clear(), stb[i].clear(), same[i].clear();

    scanf("%d",&k);
    FOR(i,0,6){
      scanf("%s",s);
      FOR(j,0,5) sta[j].insert(s[j]);
    }
    FOR(i,0,6){
      scanf("%s",s);
      FOR(j,0,5) stb[j].insert(s[j]);
    }
    FOR(i,0,5) set_intersection(ALL(sta[i]),ALL(stb[i]),INS(same[i]));

    mul[4] = same[4].size();
    ROR(i,3,0) mul[i] = mul[i+1]*same[i].size();
    int kMax = mul[0];

    if(k>kMax){
      printf("NO\n");
    }else{
      VR<char> res[5];
      FOR(i,0,5){
        VR<char> &v = res[i];
        v.push_back(0);
        for(char ch : same[i])
          v.push_back(ch);
      }
      FOR(i,0,4){
        int idx = ceil(1.0*k / mul[i+1]);
        r[i] = res[i][idx];
        k = k % mul[i+1];
        if(!k) k = mul[i+1];
      }
      r[4] = res[4][k];
      printf("%s\n",r);
    }
  }

  return 0;
}
*/

/*
int k; char s[6],r[6];
set<char> sta[5],stb[5],same[5];

int num=0;
void dfs(int cur){
  if(cur==5){
    if(++num==k) printf("%s\n",r);
    return;
  }
  for(char c : same[cur]){
    r[cur] = c;
    dfs(cur+1);
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    FOR(i,0,5) sta[i].clear(), stb[i].clear(), same[i].clear();

    scanf("%d",&k);
    FOR(i,0,6){
      scanf("%s",s);
      FOR(j,0,5) sta[j].insert(s[j]);
    }
    FOR(i,0,6){
      scanf("%s",s);
      FOR(j,0,5) stb[j].insert(s[j]);
    }
    FOR(i,0,5) set_intersection(ALL(sta[i]),ALL(stb[i]),INS(same[i]));

    int kMax = 1;
    FOR(i,0,5) kMax *= same[i].size();

    if(k>kMax){
      printf("NO\n");
    }else{
      num = 0;
      dfs(0);
    }
  }

  return 0;
}
*/
