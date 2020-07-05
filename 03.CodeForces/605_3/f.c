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

const int MAX = 220;
const int INF = 0x3f3f3f3f;

int len1, len2;
char s1[MAX], s2[MAX];
int f[MAX][MAX][MAX*2];
struct Node{
  int i,j,bal;
  char ch;
}p[MAX][MAX][MAX*2];

int main(void){
  scanf("%s%s",s1,s2);
#ifdef DEBUG
  printf("  %s\n  %s\n",s1,s2);
#endif
  len1 = strlen(s1);
  len2 = strlen(s2);
  MST(f,0x3f);
  f[0][0][0] = 0;

  FORR(i,0,len1) FORR(j,0,len2) FOR(bal, 0, MAX*2){
    if(f[i][j][bal] == INF) continue;
#ifdef DEBUG
    if(bal < 10)
      printf("  f(%d,%d,%d): %d\n",i,j,bal,f[i][j][bal]);
#endif

    int ti = i + (i<len1 && s1[i]=='(');
    int tj = j + (j<len2 && s2[j]=='(');
    if(bal < MAX*2 && f[ti][tj][bal + 1] > f[i][j][bal]){
      f[ti][tj][bal+1] = f[i][j][bal] + 1;
      p[ti][tj][bal+1] = {i,j,bal,'('};
    }

    ti = i + (i<len1 && s1[i]==')');
    tj = j + (j<len2 && s2[j]==')');
    if(bal > 0 && f[ti][tj][bal - 1] > f[i][j][bal]){
      f[ti][tj][bal-1] = f[i][j][bal] + 1;
      p[ti][tj][bal-1] = {i,j,bal,')'};
    }
  }

  int rbal = 0;
  FOR(bal,1,2*MAX) if(f[len1][len2][bal] + bal < f[len1][len2][rbal] + rbal){
    rbal = bal;
  }
#ifdef DEBUG
  printf("  rbal: %d\n",rbal);
#endif

  string ans(rbal, ')');
  int i = len1, j = len2, bal = rbal;
  while(i || j || bal){
    Node &t = p[i][j][bal];
    ans += t.ch;
    i = t.i, j = t.j, bal = t.bal;
  }
  reverse(ALL(ans));
  cout << ans << endl;

  return 0;
}
