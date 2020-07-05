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

const int MAX=2020;
int n;
struct Point{
  int x, y, z, n;
};
VR<Point> v;

bool ok(int i, int j){
  Point &a=v[i], &b=v[j];
  FOR(k,0,v.size()) if(k!=i && k!=j){
    if(min(a.x,b.x)<=v[k].x && v[k].x<=max(a.x,b.x)
        && min(a.y,b.y)<=v[k].y && v[k].y<=max(a.y,b.y)
        && min(a.z,b.z)<=v[k].z && v[k].z<=max(a.z,b.z))
      return false;
  }
  return true;
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n){
    int a,b,c; scanf("%d%d%d",&a,&b,&c);
    v.push_back(Point{a,b,c,i+1});
  }
  int cnt=0;
  while(cnt<n){
    int siz=v.size();
    FOR(i,0,siz) FOR(j,i+1,siz){
      if(ok(i,j)){
        printf("%d %d\n",v[i].n,v[j].n);
        v.erase(v.begin()+j);
        v.erase(v.begin()+i);
        cnt+=2;
        goto DONE;
      }
    }
DONE:
    1;
  }

  return 0;
}
