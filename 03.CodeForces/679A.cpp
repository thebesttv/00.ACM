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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

int square[] = {4, 9, 25, 49};
int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

bool ask(int n){
  printf("%d\n",n); fflush(stdout);
  char s[10]; scanf("%s",s);
  return s[0] == 'y';
}

int main(void){
  for(int i : square) if(ask(i)){
    printf("composite\n"); return 0;
  }

  int cnt = 0;
  for(int i : prime) if(ask(i)){
    ++cnt;
  }
  printf("%s\n", cnt<=1 ? "prime" : "composite");

  return 0;
}

/*
int v[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
bool vis[100];
int cnt = 0;

bool ask(int n){
  if(vis[n]) return false;
  vis[n] = 1;

  char s[10];
  printf("%d\n",n); fflush(stdout);
  scanf("%s",s);
  return s[0] == 'y';
}

int main(void){
  FOR(i,0,4){
    if(!ask(v[i])) continue;
    ++cnt;
    if(cnt>=2) break;

    if(ask(v[i]*v[i])) ++cnt;
    if(cnt>=2) break;

    FOR(j,4,25) if(v[i]*v[j]<=100){
      if(ask(v[j])) ++cnt;
      if(cnt>=2) break;
    }
    if(cnt>=2) break;
  }
  printf("%s\n", cnt<=1 ? "prime" : "composite");

  return 0;
}
*/
