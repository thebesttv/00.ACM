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

int v[3]; char s[3][10];

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    FOR(i,0,3) scanf("%s",s[i]);

    int idx[3]={-1,-1,-1};
    FOR(i,0,3){
      v[i] = 0;
      FOR(j,0,3)
        if(s[i][j]!='-') v[i] = v[i]*10 + s[i][j]-'0';
        else v[i] = v[i]*10, idx[i] = j;
    }
    int pow[3] = {100,10,1};

    bool done = 0;
    for(int i=0;i<=9 && !done; ++i)
      for(int j=0;j<=9 && !done; ++j)
        for(int k=0;k<=9 && !done; ++k){
          int vv[3];
          FOR(h,0,3){
            vv[h] = v[h];
            if(idx[h]!=-1) switch(h){
              case 0: vv[h] += pow[idx[h]]*i; break;
              case 1: vv[h] += pow[idx[h]]*j; break;
              case 2: vv[h] += pow[idx[h]]*k; break;
            }
          }

          if(200<=vv[0] && vv[0]<vv[1] && vv[1]<vv[2] && vv[2]<=500){
            printf("Gas Station #%d:\n",kase);
            printf("   Input:  %s %s %s\n",s[0],s[1],s[2]);
            printf("   Output: %d %d %d\n",vv[0],vv[1],vv[2]);
            putchar('\n');
            done = 1;
          }
        }
  }

  return 0;
}
