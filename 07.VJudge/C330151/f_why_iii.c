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

int n;
deque<int> t,k;

int main(void){
  while(scanf("%d",&n)==1 && n){
    int s;
    FOR(i,0,n) { scanf("%d",&s); t.push_back(s); }
    FOR(i,0,n) { scanf("%d",&s); k.push_back(s); }

    sort(t.begin(),t.end(),greater<int>());
    sort(k.begin(),k.end(),greater<int>());
    int ans=0;
    while(!t.empty()){
      if(t.front()>k.front()){
        ans++; t.pop_front(); k.pop_front();
      }else if(t.front()<k.front()){
        ans--; t.pop_back(); k.pop_front();
      }else{
        if(t.back() > k.back()){
          ans++; t.pop_back(); k.pop_back();
        }else{
          if(t.back() < k.front()) ans--;
          t.pop_back(); k.pop_front();
        }
      }
    }
    /*
    sort(t.begin(),t.end()); sort(k.begin(),k.end());
    int ans=0;
    while(!t.empty()){
      if(t.front() <= k.front()){
        if(t.front() < k.back()) ans--;
        t.pop_front(); k.pop_back();
      }else{
        ans++;
        t.pop_front(); k.pop_front();
      }
    }
    */
    printf("%d\n",ans*200);
  }

  return 0;
}

/*
const int MAX=102000;
int n,a[MAX],b[MAX];
bool va[MAX];

int main(void){
  while(scanf("%d",&n)==1 && n){
    MST(va,0);
    FORR(i,1,n) scanf("%d",&a[i]);
    FORR(i,1,n) scanf("%d",&b[i]);
    sort(a+1,a+1+n,greater<int>());
    sort(b+1,b+1+n,greater<int>());

    int ans=0,j=1;
    FORR(i,1,n){
      while(j<=n){
        if(a[i]<b[j]) { j++; continue; }
        va[i]=1; if(a[i]>b[j]) ans++;
        j++; break;
      }
      if(!va[i]) ans--;
    }
    printf("%d\n",ans*200);
  }

  return 0;
}
*/
