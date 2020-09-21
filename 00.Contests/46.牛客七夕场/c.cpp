// Tag: notag
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

int n;

int main(void){
  scanf("%d",&n);
  printf("I love U forever.\n");
  int cnt = n, blk = n, blk2 = 2*n-1;
  FOR(k,0,n){
    FOR(i,0,blk) putchar(' ');
    FOR(i,0,cnt) putchar('*');
    FOR(i,0,blk2) putchar(' ');
    FOR(i,0,cnt) putchar('*');
    putchar('\n');
    cnt+=2, blk--, blk2-=2;
  }

  cnt = 6*n-1, blk = 0;
  while(cnt>0){
    FOR(i,0,blk) putchar(' ');
    FOR(i,0,cnt) putchar('*');
    putchar('\n');
    cnt -= 2, blk ++;
  }

  return 0;
}
