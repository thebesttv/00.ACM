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

const int MAX = 2520;
int n, m, cnt1[128], cnt2[128]; char s[MAX];

void cal(char *s, int *cnt){
  while(*s){
    int ch = *s++, t = 0;
    if(!isdigit(*s)) ++cnt[ch];
    else{
      while(isdigit(*s)){
        t = t*10 + *s-'0';
        ++s;
      }
      cnt[ch] += t;
    }
  }
#ifdef DEBUG
  FORR(i,'A','Z') if(cnt[i]) printf("%c: %d\n",i,cnt[i]);
#endif
}

int main(void){
  scanf("%s%d",s,&m);
  n = strlen(s);
  cal(s,cnt1);
  FORR(i,'A','Z') cnt1[i]*=m;

  scanf("%s",s); n = strlen(s);
  cal(s,cnt2);

  int ans = 0x3f3f3f3f;
  FORR(i,'A','Z') if(cnt2[i])
    ans = min(ans, cnt1[i]/cnt2[i]);
  printf("%d\n",ans);

  return 0;
}
