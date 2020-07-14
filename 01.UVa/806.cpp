// Tag: quadtree fun
// Link: [UVa 297]
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

const int MAX = 70;
int n,rec[MAX*MAX],s[MAX][MAX]; char G[MAX][MAX];
VR<int> ans,v;

int sum(int l1, int r1, int l2, int r2){
  --r1, --r2;
  return s[r1][r2] - s[r1][l2-1] - s[l1-1][r2] + s[l1-1][l2-1];
}

void dfs(int l1, int r1, int l2, int r2, int cur){
  int s = sum(l1,r1,l2,r2);
  if(s == 0) return;
  if(s == (r1-l1)*(r2-l2)){
    int sum = 0;
    ROR(i,cur-1,0) sum = sum * 5 + rec[i];
    ans.push_back(sum); return;
  }
  int m1 = (l1+r1)/2, m2 = (l2+r2)/2;
  rec[cur] = 1;
  dfs(l1,m1,l2,m2,cur+1); // NW

  rec[cur] = 2;
  dfs(l1,m1,m2,r2,cur+1); // NE

  rec[cur] = 3;
  dfs(m1,r1,l2,m2,cur+1); // SW

  rec[cur] = 4;
  dfs(m1,r1,m2,r2,cur+1); // SE
}

int main(void){
  int kase = 0;
  while(scanf("%d",&n)==1 && n){
    if(kase) putchar('\n');

    printf("Image %d\n",++kase);
    if(n > 0){
      ans.clear();
      FORR(i,1,n) scanf("%s",G[i]+1);
      FORR(i,1,n) FORR(j,1,n){
        s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + (G[i][j]=='1');
      }
      dfs(1,n+1,1,n+1,0);

      sort(ALL(ans));
      FOR(i,0,ans.size()){
        if(i%12) putchar(' ');
        printf("%d",ans[i]);
        if(i%12 == 11 || i == ans.size()-1) putchar('\n');
      }
      printf("Total number of black nodes = %d\n",(int)ans.size());
    }else{
      n = -n; v.clear(); int x;
      while(scanf("%d",&x) && x!=-1)
        v.push_back(x);
      MST(G,'.');
      for(int x : v){
        int l1 = 1, r1 = n+1, l2 = 1, r2 = n+1;
        VR<int> rec;
        while(x) rec.push_back(x%5), x/=5;
        for(int t : rec){
          int m1 = (l1+r1)/2, m2 = (l2+r2)/2;
          switch(t){
            case 1: r1 = m1, r2 = m2; break;
            case 2: r1 = m1, l2 = m2; break;
            case 3: l1 = m1, r2 = m2; break;
            case 4: l1 = m1, l2 = m2; break;
          }
        }
        FOR(i,l1,r1) FOR(j,l2,r2)
          G[i][j] = '*';
      }
      FORR(i,1,n){
        FORR(j,1,n) putchar(G[i][j]);
        putchar('\n');
      }
    }
  }

  return 0;
}
