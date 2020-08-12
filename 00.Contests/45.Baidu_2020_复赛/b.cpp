// Tag: 
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
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 1e5 + 20;
int n,sa1[MAX],sa0[MAX],sb1[MAX],sb0[MAX],d[MAX];
char a[MAX],b[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%s%s",&n,a+1,b+1);
    FORR(i,1,n){
      sa1[i] = sa1[i-1] + (a[i]=='1'),
      sa0[i] = sa0[i-1] + (a[i]=='0');
      sb1[i] = sb1[i-1] + (b[i]=='1'),
      sb0[i] = sb0[i-1] + (b[i]=='0');
    }
    d[n+1] = 0;
    ROR(i,n,1) d[i] = d[i+1] + (a[i]!=b[i]);

    int ansMin = d[1];
    FORR(i,2,n)
      if(a[i]=='0'){
        ansMin = min(ansMin, sa0[i-1] + 1 + sb1[i-1] + (b[i] == '0') + d[i+1]);
      }else{
        ansMin = min(ansMin, sa0[i-1] + 2 + sb1[i-1] + (b[i] == '0') + d[i+1]);
      }
    ansMin = min(ansMin, sa0[n] + 2 + sb1[n]);
    printf("%d\n",ansMin);
  }

  return 0;
}
