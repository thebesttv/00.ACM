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

int a[4], b;

bool ok(int n){
  int v[5] = {a[0], a[1], a[2], a[3], n};
  sort(v,v+5);
  if(v[1] + v[2] + v[3] <= b*3)
    return true;
  else
    return false;
}

int get(){
  int ch, s = 0;
  do ch = getchar(); while(!isdigit(ch));
  do{
    if(ch != '.')
      s = s*10 + ch-'0';
    ch = getchar();
  }while(isdigit(ch) || ch=='.');
  return s;
}

int main(void){
  FOR(i,0,4){
    a[i] = get();
  }
  b = get();
  sort(a,a+4);

  ROR(i,4001,1) if(ok(i)){
    if(i >= a[3]){
      printf("infinite\n");
    }else{
      printf("%d.%02d\n",i/100,i%100);
    }
    return 0;
  }
  printf("impossible\n");

  return 0;
}
