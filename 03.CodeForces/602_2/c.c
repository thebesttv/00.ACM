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

const int MAX=2020;
int n,k; char s[MAX];
typedef pair<int,int> pii;
VR<pii> v;

void f(int l, int r, int k){
  if(k==1){
    if(l+1==r){
      if(s[l]==')'){
        v.push_back({l,r});
      }
    }else{
      if(s[l]=='(' && s[r]==')'){
        ;
      }else if(s[l]==')' && s[r]=='('){
        v.push_back({l,r});
        reverse(s+l,s+r+1);
      }else if(s[l]=='(' && s[r]=='('){
        ROR(i,r-1,l) if(s[i]==')'){
          v.push_back({i,r});
          reverse(s+i,s+r+1); break;
        }
      }else{  // ))
        FOR(i,l+1,r) if(s[i]=='('){
          v.push_back({l,i});
          reverse(s+l,s+i+1); break;
        }
      }
      f(l+1,r-1,k);
    }
  }else{
    if(s[r]==')'){
      if(s[r-1]==')'){  // ))
        ROR(i,r-2,l) if(s[i]=='('){
          v.push_back({i,r-1});
          reverse(s+i,s+r); break;
        }
      }
    }else{
      if(s[r-1]=='('){  // ((
        ROR(i,r-2,l) if(s[i]==')'){
          v.push_back({i,r-1});
          reverse(s+i,s+r); break;
        }
      }
    }
    f(l,r-2,k-1);
    f(r-1,r,1);
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    v.clear();
    scanf("%d%d%s",&n,&k,s+1);
    f(1,n,k);
    printf("%d\n",v.size());
    if(v.size()) for(auto p : v){
      printf("%d %d\n",p.FI,p.SE);
    }
  }

  return 0;
}

/*
void f(int l, int r, int k){
  if(l+1==r){
    if(s[l]==')') v.push_back({l,r});
    return;
  }
  if(k==1){
    if(s[l]=='('){
      if(s[r]==')'){
        f(l+1,r-1,1); break;
      }
      int cnt0 = 1, cnt1 = 0;
      FORR(i,l+1,r){
        if(s[i]=='(') cnt0++;
        else cnt1++;
        if(cnt0==cnt1 && s[i]==')'){
          f(l+1,i-1,1); break;
        }
      }
    }else{  // )
      int cnt0 = 0, cnt1 = 1;
      FORR(i,l+1,r){
        if(s[i]=='(') cnt0++;
        else cnt1++;
        if(cnt0==cnt1 && s[i]=='('){
          v.push_back({l,i}); reverse(s+l,s+i+1);
          f(l+1,i-1,1); break;
        }
      }
    }
    return;
  }

  if(s[r]==')'){
    if(s[r-1]==')') // ))
      ROR(i,r-2,l) if(s[i]=='('){
        reverse(s+i, s+r); v.push_back({i,r-1});
        break;
      }
    f(l,r-2,k-1);
  }else{
    if(s[r-1]=='(') // ((
      ROR(i,r-2,l) if(s[i]==')'){
        reverse(s+i, s+r); v.push_back({i,r-1});
        v.push_back({r-1,r});
        break;
      }
    f(l,r-2,k-1);
  }
}
*/
