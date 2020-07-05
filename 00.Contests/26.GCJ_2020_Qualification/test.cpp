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

int n, a[20][20],b[20];
void print(){
  FORR(i,1,n){
    FORR(j,1,n) printf("%d ",a[i][j]);
    putchar('\n');
  }
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) FORR(j,1,n){
    a[i][ (i+j-2)%n+1]=j;
  }
  print();
  while(true){
    int op, x, y; scanf("%d%d%d",&op,&x,&y);
    if(op==1){
      FORR(i,1,n) swap(a[x][i],a[y][i]);
    }else{
      FORR(i,1,n) swap(a[i][x],a[i][y]);
    }
    print();
  }

  return 0;
}
