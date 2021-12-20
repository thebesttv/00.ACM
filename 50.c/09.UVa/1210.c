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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=1000000;
int n;
VR<int> prime,s;
bool vis[MAX+20];

int main(void){
  int sq=sqrt(MAX);
  FORR(i,2,sq) if(!vis[i])
    for(int j=i*i;j<=MAX;j+=i) vis[j]=1;
  FORR(i,2,MAX) if(!vis[i]) prime.push_back(i);
  s=prime; FOR(i,1,prime.size()) s[i]+=s[i-1];
  //FOR(i,0,20) printf("%d ",prime[i]); printf("\n");
  //FOR(i,0,20) printf("%d ",s[i]); printf("\n");

  int siz=s.size();
  while(scanf("%d",&n)==1 && n){
    int cnt=0;
    FOR(j,0,siz) if(s[j]==n) cnt++;
    FOR(i,1,siz) FOR(j,i,siz)
      if(s[j]-s[i-1]==n) cnt++;
      else if(s[j]-s[i-1]>n) break;
    printf("%d\n",cnt);
  }

  return 0;
}
