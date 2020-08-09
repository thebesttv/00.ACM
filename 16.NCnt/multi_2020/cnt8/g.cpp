// Tag: 暴力 模拟
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

const int MAX = 300;
const string REC[4][4] = {
  "*", "one","two", "three",
  "*", "diamond", "squiggle", "oval",
  "*", "solid", "striped", "open",
  "*", "red", "green", "purple"
};

char str[MAX];
int n,f[4][4][4][4];
struct Card{
  int v[4];
}c[MAX];

void read(int idx){
  int j = 0,n,v[4]; string s;
  scanf("%s",str); n = strlen(str);
  FOR(i,0,4){
    s.clear();
    while(j < n && !(islower(str[j]) || str[j]=='*')) ++j;
    while(j < n &&  (islower(str[j]) || str[j]=='*')) s += str[j++];
#ifdef DEBUG
    //printf(" %s",s.c_str());
#endif
    FOR(j,0,4) if(s == REC[i][j]){
      v[i] = j; break;
    }
    c[idx].v[i] = v[i];
  }
  f[v[0]][v[1]][v[2]][v[3]] = idx;
#ifdef DEBUG
  //putchar('\n');
  printf("(%d, %d, %d, %d)\n",v[0],v[1],v[2],v[3]);
#endif
}

int get(int x, int y){
  if(x == y) return x;
  FORR(i,1,3) if(i!=x && i!=y)
    return i;
  return -1;
}

inline void gen(int x, int *v){
  FOR(i,0,4) v[i] = x%3+1, x/=3;
}
void cal(VR<int> &vec, int *v){
  FOR(st,0,16){
    int a = f[st&1 ? v[0] : 0]
             [st&2 ? v[1] : 0]
             [st&4 ? v[2] : 0]
             [st&8 ? v[3] : 0];
    if(a) vec.push_back(a);
  }
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    MST(f,0); scanf("%d",&n);
    FORR(i,1,n) read(i);

    int a1 = -1, a2, a3, v1[4],v2[4],v3[4];
    FOR(i,0,81){
      gen(i,v1); VR<int> st1; cal(st1,v1);
      if(st1.empty()) continue;
      FOR(j,i,81){
        gen(j,v2); VR<int> st2; cal(st2, v2);
        if(st2.empty()) continue;

        FOR(k,0,4) v3[k] = get(v1[k], v2[k]);
        VR<int> st3; cal(st3, v3);
        if(st3.empty()) continue;

        for(int x : st1) for(int y : st2) if(x != y)
          for(int z : st3) if(x != z && y != z){
            a1 = x, a2 = y, a3 = z;
            goto DONE;
          }
      }
    }
DONE:
    if(a1 == -1)
      printf("Case #%d: -1\n",kase);
    else
      printf("Case #%d: %d %d %d\n",kase,a1,a2,a3);
  }

  return 0;
}
