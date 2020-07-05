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

const int MAX = 40;
int n; char s[MAX];

bool bad(const VR<char> &v){
  int c = 0;
  for(char ch : v)
    if(ch == '('){
      ++c;
    }else{
      --c;
      if(c<0) return true;
    }
  return c != 0;
}

int dep[MAX];
int dfs(int l, int r, const VR<char> &v){
  int c = 0, d = 1, rec = -1;
  FORR(i,l,r){
    if(v[i] == '('){
      ++c;
      if(c == 2){
        rec = i;
      }
    }else{
      if(c == 2){
        d = max(d, dfs(rec, i, v) + 1);
      }
      --c;
    }
  }
  return dep[l] = dep[r] = d;
}

void proc(const VR<char> &v){
  MST(dep,0);
  //dfs(0, v.size()-1, v);
  int c = 0, rec = -1;
  FOR(i,0,v.size()){
    if(v[i] == '('){
      ++c;
      if(c == 1){
        rec = i;
      }
    }else{
      if(c == 1){
        dfs(rec, i, v) + 1;
      }
      --c;
    }
  }

#ifdef DEBUG
  FOR(i,0,n) printf("%d ",dep[i]); putchar('\n');
#endif

  FORR(lev,1,100){
    int r = -1;
    FOR(i,0,n) if(dep[i] >= lev)
      r = i;
    if(r == -1) break;

    int l = -1;
    FORR(i,0,r){
      if(dep[i] > lev){
        putchar('|');
        if(i!=r) putchar(' ');
      }else if(dep[i] == lev){
        if(l == -1){
          printf("|_"), l = i;
        }else{
          putchar('|'), l = -1;
          if(i!=r) putchar(' ');
        }
      }else{
        if(l!=-1)
          printf("__");
        else
          printf("  ");
      }
    }
    putchar('\n');
  }
}

int main(void){
  int T; scanf("%d",&T); getchar();
  FORR(kase,1,T){
    FGETS(s); n = strlen(s);
    VR<char> v;
    FOR(i,0,n) if(s[i]=='(' || s[i]==')')
      v.push_back(s[i]);

    n = v.size();
    printf("Data set #%d:\n",kase);
    bool first = 1;
    for(char ch : v){
      if(first) first = 0;
      else putchar(' ');
      putchar(ch);
    }
    putchar('\n');

    if(bad(v)){
      printf("Parentheses do not match!\n");
    }else{
      proc(v);
    }
    putchar('\n');
  }

  return 0;
}
