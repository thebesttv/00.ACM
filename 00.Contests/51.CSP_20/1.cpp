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

const int MAX = 220;
int n,x,y;

int dis(int x1, int y1, int x2, int y2){
  return (x1-x2)*(x1-x2) + (y1-y2) * (y1 - y2);
}

struct Node{
  int x,y,idx,d;
  bool operator < (const Node &b) const {
    return d != b.d ? d < b.d : idx < b.idx;
  }
}v[MAX];


int main(void){
  scanf("%d%d%d",&n,&x,&y);
  FORR(i,1,n){
    scanf("%d%d",&v[i].x,&v[i].y);
    v[i].idx = i, v[i].d = dis(x,y,v[i].x,v[i].y);
  }
  sort(v+1,v+1+n);
  FORR(i,1,3) printf("%d\n",v[i].idx);
  return 0;
}