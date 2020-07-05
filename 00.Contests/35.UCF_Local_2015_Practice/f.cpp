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

const int MAX = 100;
int n,m,fault,tail,cell[MAX],hand;
int pos[MAX]; bool isNew[MAX];

void cal(int x){
  if(tail <= n){
    cell[tail] = x;
    isNew[tail] = 1;
    pos[x] = tail;
    tail++;
    return;
  }

  while(true){
    if(!isNew[hand]){
      pos[cell[hand]] = 0;

      cell[hand] = x;
      isNew[hand] = 1;
      pos[x] = hand;
      hand = hand==n ? 1 : hand + 1;
      return;
    }

    isNew[hand] = 0;
    hand = hand==n ? 1 : hand + 1;
  }
}

int main(void){
  int kase = 0;
  while(scanf("%d%d",&n,&m)==2 && n && m){
    MST(pos,0); MST(cell,0); fault = 0, hand = tail = 1;

    printf("Program %d\n",++kase);
    while(m--){
      int x; scanf("%d",&x);
      if(pos[x]){
        isNew[pos[x]] = 1;
        printf("Access page %d in cell %d.\n",x,pos[x]);
      }else{
        ++fault; cal(x);
        printf("Page %d loaded into cell %d.\n",x,pos[x]);
      }
    }
    printf("There are a total of %d page faults.\n\n",fault);
  }

  return 0;
}
