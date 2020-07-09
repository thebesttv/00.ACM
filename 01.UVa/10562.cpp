// Tag: 坑
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

const int MAX = 220;
int n; char s[MAX][MAX];

bool isName(int ch){
  return ch && ch != '-' && ch != '|' && ch != ' ';
}

void print(int i, int j){
  printf("%c(",s[i][j]);
  if(i+1 <= n && s[i+1][j] == '|'){
    int l = j;
    while(l && s[i+2][l-1] == '-') --l;
    while(s[i+2][l] == '-' && s[i+3][l]){
      if(isName(s[i+3][l])) print(i+3,l);
      ++l;
    }
  }
  putchar(')');
}

int main(void){
  int T; scanf("%d",&T); getchar();
  while(T--){
    n = 0;
    while(FGETS(s[n+1]) && strcmp(s[n+1],"#\n")){
      ++n; int len = strlen(s[n]);
      s[n][--len] = 0;
    }

    putchar('(');
    if(n) FOR(i,0,MAX) if(s[1][i] != ' '){
      print(1,i); break;
    }
    printf(")\n");
  }

  return 0;
}
