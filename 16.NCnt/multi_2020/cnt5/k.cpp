// Tag: DP 优化 iii
// f[i][j]: 输出A前i行，B前j行所需最小行数
//   f[i][j] = f[i-1][j-1] + 1 (if a[i] == b[j])
//   f[i][j] = min( f[x][y] + i-x + j-y + 3,  [1]
//                  f[i][y] + j-y + 2,        [2]
//                  f[x][j] + i-x + 2 )       [3]
//                                      其中 0 <= x < i, 0 <= y < j
// 对三种分别优化，使得 n^4 -> n^2
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

const int MAX = 4020;
const int INF = 0x3f3f3f3f;
int a[MAX],b[MAX],la,lb;
int f[MAX][MAX]; pii rec[MAX][MAX];
int fMin3[MAX], r3[MAX];
int fMin1[MAX]; pii r1[MAX];
string fa[MAX],fb[MAX],s;
map<string,int> mp;

int IDcnt = 0;
string IDv[MAX];
int ID(const string &s){
  if(mp.count(s)) return mp[s];
  IDv[++IDcnt] = s;
  return mp[s] = IDcnt;
}

void read(){
  bool ra = true, rb = true;
  const char *strbeg = "<<<<<<< branch1";
  const char *strmid = "=======";
  const char *strend = ">>>>>>> branch2";
  int lenbeg = strlen(strbeg);
  int lenmid = strlen(strmid);
  int lenend = strlen(strend);

  while(getline(cin, s)){
    if(!strncmp(s.c_str(), strbeg, lenbeg)){
      ra = true, rb = false;
    }else if(!strncmp(s.c_str(), strmid, lenmid)){
      ra = false, rb = true;
    }else if(!strncmp(s.c_str(), strend, lenend)){
      ra = rb = true;
    }else{
      int id = ID(s);
      if(ra) a[++la] = id;
      if(rb) b[++lb] = id; 
    }
  }
}

int main(void){
  read();
#ifdef DEBUG
  {
    auto f = [=](int *v, int n, const char *str){
      printf("=== %s ===\n",str);
      FORR(i,1,n) printf("%s\n",IDv[v[i]].c_str());
    };
    f(a,la,"file1");
    f(b,lb,"file2");
    //printf("a:"); FORR(i,1,la) printf(" %d",a[i]); putchar('\n');
    //printf("b:"); FORR(i,1,lb) printf(" %d",b[i]); putchar('\n');
  }
#endif
  MST(fMin1,0x3f); MST(r1,-1);
  MST(fMin3,0x3f); MST(r3,-1);

  MST(f,0x3f);
  FORR(i,1,la) f[i][0] = i + 2;

  f[0][0] = 0;
  fMin1[0] = 0, r1[0] = {0,0};
  FORR(j,1,lb){
    f[0][j] = j + 2;
    fMin1[j] = f[0][j] - j;
    r1[j] = {0,j};
  }

  FORR(i,1,la){
    int cfMin1 = fMin1[0]; pii cr1 = r1[0];
    int fMin2 = INF; int r2 = -1;
    FORR(j,1,lb){
      int &v = f[i][j]; pii &r = rec[i][j];
      if(a[i] == b[j] && f[i-1][j-1] + 1 < v){
        v = f[i-1][j-1] + 1;
        r = {i-1,j-1};
      }

      // FOR(x,0,i) FOR(y,0,j) v = min(v, f[x][y] + i-x + j-y + 3);

      // zero:
      if(i + j + 3 < v){
        v = i + j + 3;
        r = {0,0};
      }

      if(cfMin1 + i + j + 3 < v){
        v = cfMin1 + i + j + 3;
        r = cr1;
      }

      // FOR(y,0,j) v = min(v, f[i][y] + j-y + 2);
      if(fMin2 + 2 + j < v){
        v = fMin2 + 2 + j;
        r = {i, r2};
      }
      //FOR(x,0,i) v = min(v, f[x][j] + i-x + 2);
      if(fMin3[j] + 2 + i < v){
        v = fMin3[j] + 2 + i;
        r = {r3[j], j};
      }

      if(fMin1[j] < cfMin1){
        cfMin1 = fMin1[j];
        cr1 = r1[j];
      }

      if(v - j < fMin2){
        fMin2 = v - j, r2 = j;
      }

      if(v - i < fMin3[j]){
        fMin3[j] = v - i; r3[j] = i;
      }
    }

    FORR(j,0,lb) if(f[i][j] - i - j < fMin1[j]){
      fMin1[j] = f[i][j]- i - j;
      r1[j] = {i,j};
    }
  }
#ifdef DEBUG
  FORR(i,1,la) FORR(j,1,lb)
    printf("f[%d][%d]: %d <- f[%d][%d]\n",i,j,f[i][j],rec[i][j].FI,rec[i][j].SE);
#endif
  pii p = {la,lb}; VR<pii> v;
  while(p.FI || p.SE){
    v.push_back(p);
    p = rec[p.FI][p.SE];
  }
  reverse(ALL(v));
#ifdef DEBUG
  for(auto p : v) printf("  %d %d\n",p.FI,p.SE);
#endif
  pii last = {0,0};
  for(auto p : v){
    if(a[p.FI] == b[p.SE] && p.FI == last.FI + 1 && p.SE == last.SE + 1){
      printf("%s\n",IDv[a[p.FI]].c_str());
      last = p; continue;
    }

    if(p.FI == last.FI){
#ifdef DEBUG
      printf("=== FI same ===\n");
#endif
      printf("#ifdef branch2\n");
      FORR(k,last.SE + 1,p.SE)
        printf("%s\n",IDv[b[k]].c_str());
      printf("#endif\n");
    }else if(p.SE == last.SE){
#ifdef DEBUG
      printf("=== SE same ===\n");
#endif
      printf("#ifdef branch1\n");
      FORR(k,last.FI + 1,p.FI)
        printf("%s\n",IDv[a[k]].c_str());
      printf("#endif\n");
    }else{
#ifdef DEBUG
      printf("=== no same ===\n");
#endif
      printf("#ifdef branch1\n");
      FORR(k,last.FI + 1,p.FI)
        printf("%s\n",IDv[a[k]].c_str());
      printf("#else\n");
      FORR(k,last.SE + 1,p.SE)
        printf("%s\n",IDv[b[k]].c_str());
      printf("#endif\n");
    }

    last = p;
  }

  return 0;
}
