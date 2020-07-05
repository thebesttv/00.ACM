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

const int MAX = 5020;
int n,m; char s[MAX], c[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    deque<int> pos[26];
    scanf("%s%s",s,c);
    n = strlen(s);
    FOR(i,0,n) pos[s[i]-'A'].push_back(i);
    FOR(i,0,n){
      pos[s[i]-'A'].pop_front();
      bool done = 0;
      FOR(j,'A',s[i]) if(!pos[j-'A'].empty()){
        int p = pos[j-'A'].back();
        swap(s[i],s[p]);
        done = 1; break;
      }
      if(done) break;
    }
#ifdef DEBUG
    printf("  get s: %s\n",s);
#endif
    if(strcmp(s,c)<0) printf("%s\n",s);
    else printf("---\n");
  }

  return 0;
}

    /*
    int i=0, j=0;
    while(i<n && j<m){
      if(s[i] > c[j]){
        bool done = 0;
        FOR(k,i+1,n) if(s[k] < c[j]){
          done = 1;
          swap(s[i], s[k]);
          break;
        }

        if(!done) FOR(k,i+1,n)
          if(s[k] == c[j] && (k>=m || s[i] < c[k])){
            done = 1;
            swap(s[i], s[k]);
            break;
          }

        if(!done) FOR(k,i+1,n)
          if(s[k] == c[j] && (k>=m || s[i]==c[k])){
            done = 1;
            swap(s[i], s[k]);
            break;
          }

        if(!done) FOR(k,i+1,n)
          if(s[k] == c[j]){
            done = 1;
            swap(s[i], s[k]);
            break;
          }
        break;
      }
      i++, j++;
    }
    if(strcmp(s,c)<0) printf("%s\n",s);
    else printf("---\n");
    */
