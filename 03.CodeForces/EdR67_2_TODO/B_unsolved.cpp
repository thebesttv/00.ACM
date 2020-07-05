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

const int MAX = 200000 + 10;
int n,m,len;
char s[MAX], a[MAX];
int rec['z'+1], cnt['z'+1], t['z'+1];

bool ok(int m){
  FORR(i,'a','z') if(cnt[i]>rec[i]){
    return false;
  }
  return true;
}

int main(void){
  scanf("%d%s",&n,s+1);

  scanf("%d",&m);
  while(m--){
    scanf("%s",a+1); len = strlen(a+1);
    MST(cnt,0); FORR(i,1,len) cnt[a[i]]++;

    /*
    MST(rec,0);
    FORR(i,1,n){
      rec[s[i]]++;
      if(ok(i)){
        printf("%d\n",i);
        break;
      }
    }
    */

    int l=len, r=n; //[l,r]
    int mid=(l+r)>>1;
    MST(rec,0); FORR(i,1,mid) rec[s[i]]++;
    while(l<r){
      mid=(l+r)>>1;
      //printf("  for F:%d, l: %d, r: %d, m: %d",m,l,r,mid);
      if(ok(mid)){
        int tm=(l+mid)>>1;
        FORR(i,tm+1,mid) rec[s[i]]--;
        r = mid;
        //printf("  ok\n");
      }else{
        int tm=(mid+1+r)>>1;
        FORR(i,mid+1,tm) rec[s[i]]++;
        l = mid+1;
        //printf("  bad\n");
      }
    }
    printf("%d\n",l);
  }

  return 0;
}
