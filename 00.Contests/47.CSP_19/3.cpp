// Tag: 大模拟
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

const int MAX = 40 * 1024 * 1024;
int w; char str[MAX];
VR<int> vec;

int para(char *s, int n, int offset, int &left){
  int cnt = 0;
  while(left >= w-offset) left -= w-offset, ++cnt;
  FOR(i,0,n) if(left || s[i]!=' '){
    ++left;
    if(left == w-offset) left = 0, ++cnt;
  }
  return cnt;
}

int main(void){
  scanf("%d",&w); getchar();
  int st = 0, cnt = 0, left = 0; // 0: blank, 1: para, 2: list
  int lcnt = 0;

  while(FGETS(str)){
    int n = strlen(str); str[--n] = 0;  // delete newline character
#ifdef DEBUG
    printf("st: %d, lcnt: %d, |%s|\n",st,lcnt,str);
#endif
    int i = 0, j = n;
    while(i<n && str[i]==' ') ++i;
    while(i<j && str[j-1]==' ') --j;

    if(i == j){
#ifdef DEBUG
      printf("  empty\n");
#endif
      if(st==2 && lcnt==0){
        vec.pb(++cnt); cnt = 0;
      }else if(st){
        if(left) ++cnt, left = 0;
        if(cnt) vec.pb(cnt), cnt = 0;
      }
      st = 0; continue;
    }

    if(str[0]=='*' && str[1]==' '){ // new list
#ifdef DEBUG
      printf("  new list\n");
#endif
      if(st==2){
        if(lcnt==0){
          ++cnt;
        }else{
          if(left) ++cnt, left = 0;
        }
      }else if(st!=2){
        if(left) ++cnt, left = 0;
        if(cnt) vec.pb(cnt), cnt = 0;
      }

      ++i; while(i<j && str[i]==' ') ++i;
      cnt += para(str + i, j-i, 3, left);
      lcnt = j-i; st = 2;
#ifdef DEBUG
      printf("  new lcnt = %d - %d = %d\n",j,i,j-i);
#endif
    }else if(st==2 && str[0]==' ' && str[1]==' '){  // continue list
#ifdef DEBUG
      printf("  continue list\n");
#endif
      if(lcnt && left){
        ++left;
      }
      cnt += para(str + i, j-i, 3, left);
      lcnt += j-i;
    }else if(st == 1){  //continue para
#ifdef DEBUG
      printf("  continue para\n");
#endif

      if(lcnt && left){
        ++left;
      }
      cnt += para(str + i, j-i, 0, left);
      lcnt = j-i;
    }else{  // new para
#ifdef DEBUG
      printf("  new para\n");
#endif
      if(st==2 && lcnt==0){
        vec.pb(++cnt); cnt = 0;
      }else{
        if(left) ++cnt, left = 0;
        if(cnt) vec.pb(cnt), cnt = 0;
      }

      cnt += para(str + i, j-i, 0, left);
      st = 1; lcnt = j-i;
    }
  }

  if(st==2 && lcnt==0){
    vec.pb(++cnt); cnt = 0;
  }else{
    if(left) ++cnt, left = 0;
    if(cnt) vec.pb(cnt), cnt = 0;
  }

  int ans = 0;
  if(!vec.empty()){
#ifdef DEBUG
    for(int x : vec) printf("  %d\n",x);
#endif
    ans = vec[0];
    FOR(i,1,vec.size()) ans += vec[i] + 1;
  }
  printf("%d\n",ans);

  return 0;
}
