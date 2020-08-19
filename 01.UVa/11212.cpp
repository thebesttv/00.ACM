// Tag: IDA* 优化 迭代加深搜索 TODO ii
// 考虑每个数字的后继数字，令 h 表示 a[n] 中后继数字失配的个数
// 每次剪切粘贴最多使得 h 减少 3，即最多使得三个后继失配的数能够配对
// 因此当 (maxd - dep) * 3 < h 时结束搜索
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

int n,a[10],maxd;

int cal(int *v){
  int c = 0;
  FOR(i,1,n) c += (v[i-1]+1 != v[i]);
  return c;
}

bool dfs(int dep, int cnt, int *v){
  if((maxd - dep)*3 < cnt) return false;
#ifdef DEBUG
  printf("(%d): dfs(%d,",maxd,dep);
  FOR(i,0,n) printf(" %d",v[i]); printf(")\n");
#endif
  if(dep == maxd){
    FOR(i,0,n) if(v[i]!=i+1) return false;
    return true;
  }

  int v2[10],tail;
  FOR(i,0,n) FOR(j,i+1,n){
    if(i){  // front
      tail = 0;
      FOR(k,i,j) v2[tail++] = v[k];
      FOR(k,0,i) v2[tail++] = v[k];
      FOR(k,j,n) v2[tail++] = v[k];
      if(dfs(dep+1, cal(v2), v2)) return true;
    }

    FORR(cnt,1,n-(j-i)){ // 先放 cnt 个
      tail = 0;
      FOR(k,0,n) if(k<i || k>=j){
        v2[tail++] = v[k];
        if(tail == cnt){
          FOR(kk,i,j) v2[tail++] = v[kk];
        }
      }
      if(dfs(dep+1, cal(v2), v2)) return true;
    }

  }
  return false;
}

int main(void){
  int kase = 0;
  while(scanf("%d",&n)==1 && n){
    FOR(i,0,n) scanf("%d",&a[i]);
    for(maxd=0;maxd<n;++maxd) if(dfs(0,cal(a),a)){
      printf("Case %d: %d\n",++kase,maxd); break;
    }
  }

  return 0;
}
