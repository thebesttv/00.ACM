#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=1000;
const int INF=0x3f3f3f3f;
char s[MAX];
int f[MAX][MAX];

//if(match(s[i],s[j]) f[i][j]=min(f[i][j],f[i+1][j-1]);
//f[i][j] = min{f[i][k],f[k+1][j]}

inline bool match(char a, char b){
  return (a=='(' && b==')') || (a=='[' && b==']');
}
void print(int l, int r){
  if(l==r){
    //putchar(s[l]); putchar(s[l]=='(' ? ')' : ']');  //如果s[l]为')'或']'则错误
    if(s[l]=='(' || s[l]==')') printf("()");
    else printf("[]");
  }else if(l<r){
    if(match(s[l],s[r]) && f[l][r]==f[l+1][r-1]){
      putchar(s[l]); print(l+1,r-1); putchar(s[r]);
    }else FOR(k,l,r) if(f[l][r]==f[l][k]+f[k+1][r]){
      print(l,k); print(k+1,r);
      return;
    }
  }
}

int main(void){
  int T; FGETS(s); T=atoi(s);
  while(T--){
    FGETS(s); FGETS(s); //两组数据中有一个空行
    int n=strlen(s); while(s[n-1]=='\n' || s[n-1]=='\r') s[--n]=0;
    //MST(f,0x3f);
    FOR(i,0,n) f[i][i]=1,f[i+1][i]=0; //<b></b>
    ROR(i,n-2,0) FOR(j,i+1,n){
      f[i][j]=n;  //不用memset而在每次更新开始时设置会快很多
      if(match(s[i],s[j])) f[i][j]=f[i+1][j-1]; //<b>当i+1=j时，会走到f[j][j-1] </b>
      FOR(k,i,j) f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
    }
    print(0,n-1); putchar('\n');
    if(T) putchar('\n');
  }

  return 0;
}
