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

const int MAX = 100000 + 10;
const int MAX_R = MAX<<1;
int n, ori[MAX], a[MAX], t[MAX], cnt[MAX_R];
set<int> st;

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&ori[i]), st.add(ori[i]);
  int tail=0;
  for(iterator::set<int> it=st.begin();it!=st.end();it++)
    t[tail++]=*it;
  //

  //
}

/*
const int MAX = 100000 + 10;
int n, a[MAX];
bool flag[MAX];

bool ok(int x){
  int cnt=0; MST(flag,0);
  while(cnt<n){ // try make everyone part of the team
    int l=0; while(flag[l]) l++;  // l: the first that isn't used
    //greedy: always try to make up the largest team possible
    int last=a[l]-1, tcnt=0;
    FOR(r,l,n) if(!flag[r]){
      if(a[r]==last+1){
        flag[r]=1, tcnt++, last++;
      }else if(a[r]==last){
        continue;
      }else break;
    }
    if(tcnt<x) return false;
    else cnt+=tcnt;
  }
  return true;
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&a[i]);
  sort(a,a+n);

  int l=0, r=n; //[l,r]
  while(l<r){
    int m=((l+r)>>1) + 1;
    #ifdef DEBUG
    printf("l: %d, r: %d, m: %d\n",l,r,m);
    #endif
    if(ok(m)) l=m;
    else r=m-1;
  }
  printf("%d\n",l);

  return 0;
}
*/
