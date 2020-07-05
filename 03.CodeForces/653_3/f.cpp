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

const int MAX = 520;
int n,a[MAX];
VR<int> ans;

void swap(int i){
  ans.push_back(i);
  swap(a[i],a[i+2]);
  swap(a[i+1],a[i+2]);
#ifdef DEBUG
  printf("swap(%d):",i);
  FORR(j,1,n) printf(" %d",a[j]); putchar('\n');
#endif
}

void move(int r, int i, int &cnt){
  while(r != i){
    if(r >= i+2){
      swap(r-2);
      ++cnt, r-=2;
    }else{
      swap(r-1), swap(r-1);
      cnt += 2, --r;
    }
  }
}

bool isOk(){
  FORR(i,2,n) if(a[i-1] > a[i]){
    return false;
  }
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n); ans.clear();
    FORR(i,1,n) scanf("%d",&a[i]);
    if(n == 3){
      if(isOk()) printf("0\n\n");
      else{
        swap(1);
        if(isOk()) printf("1\n1\n");
        else{
          swap(1);
          if(isOk()) printf("2\n1 1\n");
          else printf("-1\n");
        }
      }
      continue;
    }

    int cnt = 0;
    FORR(i,1,n-2){
      int tMin = a[i], r = i;
      FORR(j,i+1,n) if(a[j] < tMin){
        tMin = a[r=j];
      }
      move(r, i, cnt);
    }

    if(a[n-1] > a[n]){
      if(a[n] <= a[n-2]){
        swap(n-2);
      } else {
        int dup = -1;
        ROR(i,n-3,1) if(a[i] == a[i+1]){
          dup = i; break;
        }
#ifdef DEBUG
        printf("dup: %d\n",dup);
#endif
        if(dup != -1){
          FORR(i,dup,n-4) swap(i);
          swap(n-3), swap(n-3);
          swap(n-2), swap(n-2);

          move(n-3, dup, cnt);
          if(a[n-2] == a[dup]) move(n-2, dup+1, cnt);
        }
      }
    }

    bool ok = 1;
    FORR(i,2,n) if(a[i-1] > a[i]){
      ok = 0; break;
    }
    if(!ok || cnt > n*n) printf("-1\n");
    else{
      printf("%d\n",(int)ans.size());
      for(int x : ans) printf("%d ",x); putchar('\n');
    }
  }

  return 0;
}
