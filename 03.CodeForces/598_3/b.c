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

const int MAX=120;
int n,a[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d",&a[i]);
    int i = 0;
    while(i < n){
      int r = i, tMin = a[i];
      FOR(j,i+1,n) if(a[j]<tMin){
        tMin = a[j], r=j;
      }
      if(i==r) { i++; continue; }
      ROR(j,r-1,i) a[j+1]=a[j];
      a[i] = tMin;
      i = r;
    }
    printf("%d",a[0]);
    FOR(j,1,n) printf(" %d",a[j]);
    putchar('\n');
  }

  return 0;
}

/*
const int MAX=120;
int n,a[MAX]; bool vis[MAX];

void move(int l, int r){
#ifdef DEBUG
        printf(" %d, %d\n",l,r);
#endif
  --r;
  //FOR(k,l,r){
  ROR(k,r-1,l){
#ifdef DEBUG
    printf("  swap(%d, %d)\n",k,k+1);
#endif
    swap(a[k],a[k+1]);
    vis[k]=1;
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(vis,0);
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d",&a[i]);
    int l=0, r; bool done=0;
    do{
      done = 0; l=0;
      while(l<n && vis[l]) l++;

      while(l<n){
        r = l + 1;
        while(r<n && !vis[r-1] && a[r]<=a[r-1]) r++;
        if(r-l>1){
          move(l,r); done=1;
        }
        l = r;
        while(l<n && vis[l]) l++;
      }
    }while(done);

    printf("%d",a[0]);
    FOR(i,1,n) printf(" %d",a[i]);
    putchar('\n');
  }

  return 0;
}
*/
