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

int n,k,h;

int height(int n){
  int h = 0, s = 0;
  for(int t=1;s<n;++h,s+=t,t*=k);
  return s!=n ? -1 : h;
}

bool ask(int a, int b, int c){
  char s[20];
  printf("? %d %d %d\n",a,b,c);
  fflush(stdout);
  scanf("%s",s);
  return s[0] == 'Y';
}

void chainSort(int u, VR<int> &v){
  map<int,int> mp;
  for(int x : v){
    int &a = mp[x];
    for(int y : v) if(x!=y && ask(x,y,u)){
      ++a;
    }
  }

  for(auto p : mp)
    v[p.SE] = p.FI;
#ifdef DEBUG
  printf("  sort(%d):",u);
  for(int x : v) printf(" %d",x);
  putchar('\n');
#endif
}

int cal(int a, int b){
  VR<int> v;
  FORR(i,1,n) if(i!=a && i!=b)
    if(ask(i,a,b)) a = i;
  FORR(i,1,n) if(i!=a && i!=b)
    if(ask(a,b,i)) b = i;
  FORR(i,1,n) if(i!=a && i!=b)
    if(ask(a,i,b)) v.push_back(i);
#ifdef DEBUG
  printf("  get chain(%d, %d)\n",a,b);
#endif
  if(v.size()+2 != h*2-1)
    return -1;
  chainSort(a, v);
  return v[h-2];
}

int main(void){
  scanf("%d%d",&n,&k); h = height(n);
#ifdef DEBUG
  printf("  height: %d\n",h);
#endif

  srand(n);
  while(1){
    int a = rand()%n+1, b;
    do b = rand()%n+1; while(a==b);
#ifdef DEBUG
    printf("  try chain(%d,%d)\n",a,b);
#endif
    int res = cal(a,b);
    if(res!=-1){
      printf("! %d\n",res);
      return 0;
    }
  }

  return 0;
}
