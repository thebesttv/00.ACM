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

const int MAX=1<<11;
int n;
char res[MAX][MAX];

void fill(int i, int j, int cnt){
  if(cnt==1){
    if(i+j==(1<<n)+1){
      FOR(k,0,j) res[i][k]=' ';
      FORR(k,0,j) res[i-1][k]=' ';
    }
    res[i][j]='/'; res[i][j+1]=res[i][j+2]='_'; res[i][j+3]='\\';
    res[i-1][j+1]='/'; res[i-1][j+2]='\\';
    return;
  }
  int len=1<<cnt,h=1<<(cnt-1);
  fill(i-h,j+h,cnt-1);
  fill(i,j,cnt-1);
  fill(i,j+len,cnt-1);
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,1<<n){
    int t=(1<<n)+i;
    FORR(j,0,t) res[i][j]=' ';
  }
  fill(1<<n,1,n);
  FORR(i,1,1<<n) printf("%s\n",res[i]+1);

  return 0;
}
