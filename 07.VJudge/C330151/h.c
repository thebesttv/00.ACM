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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=3020;
int n; string rk[MAX];
VR<int> v;

int main(void){
  while(scanf("%d",&n)==1 && n){
    v.clear();
    FOR(i,0,n){
      char s[40]; scanf("%s",s);
      int j=0; while(s[j]=='0') j++;
      rk[i]=string(s+j);
    }
    sort(rk,rk+n,greater<string>());
    v.push_back(1);
    FOR(i,1,n){
      string &s1=rk[i];
      string &s0=rk[i-1];
      if(s1.compare(s0)==0){
        v[v.size()-1]++;
      }else v.push_back(1);
    }

    int ans=0;
    FOR(i,0,v.size()) if(v[i]){
      int c=v[i]; ans+=c; v[i]=0;
      FOR(j,i+1,v.size()) if(v[j]){
        if(c<=v[j]){
          v[j]-=c;
        }else{
          v[j]=0;
        }
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
