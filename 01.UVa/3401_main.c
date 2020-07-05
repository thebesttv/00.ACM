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
typedef long long LL;
typedef long long unsigned LLU;

const int rot[24][6] = { // rot[i][j]=k: 第i种姿态中，原本在 j 方向的面变换到 k 方向
  {0,1,2,3,4,5},{1,5,2,3,0,4},{5,4,2,3,1,0},{4,0,2,3,5,1},
  {2,1,5,0,4,3},{2,5,4,1,0,3},{2,4,0,5,1,3},{2,0,1,4,5,3},
  {5,1,3,2,4,0},{4,5,3,2,0,1},{0,4,3,2,1,5},{1,0,3,2,5,4},
  {3,1,0,5,4,2},{3,5,1,4,0,2},{3,4,5,0,1,2},{3,0,4,1,5,2},
  {0,3,1,4,2,5},{1,3,5,0,2,4},{5,3,4,1,2,0},{4,3,0,5,2,1},
  {5,2,1,4,3,0},{4,2,5,0,3,1},{0,2,4,1,3,5},{1,2,0,5,3,4}
};
int n,cube[5][6]; // cube[i][j]=k: 方块 i 在 j 方向的初始颜色
int color[5][6],rec[5]; // color: 旋转后的颜色
int ansMin;
map<string,int> mp;

int color_cnt;
int ID(string &s){
  if(mp.count(s)) return mp[s];
  else return mp[s] = color_cnt++;
}
void calc(){
  FOR(i,0,n) FOR(j,0,6)
    color[i][ rot[rec[i]][j] ] = cube[i][j];  // 旋转后，新方向 得到 旧方向的颜色

  int tot=0;  // 一共改变的数量
  FOR(j,0,6){ // 对每个方向
    int cnt[24]={0}, tMax=0;
    FOR(i,0,n) tMax = max(tMax, ++cnt[color[i][j]]);  // 找到出现次数最多的颜色的出现次数
    tot += n-tMax;
  }
  ansMin = min(ansMin,tot);
}
void dfs(int cur){
  if(cur==n){
    calc(); return;
  }
  FOR(i,0,24){
    rec[cur]=i;
    dfs(cur+1);
  }
}

int main(void){
  while((cin >> n) && n){
    mp.clear(); color_cnt=0;
    ansMin = 0x3f3f3f3f;
    FOR(i,0,n) FOR(j,0,6){
      string s; cin >> s;
      cube[i][j] = ID(s);
    }

    dfs(1);

    printf("%d\n",ansMin);
  }

  return 0;
}
