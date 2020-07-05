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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

typedef set<int> Set;
int n; char s[100];
struct Idx{
  map<Set,int> mp;
  VR<Set> v;
  void clear(){
    mp.clear(); v.clear();
  }
  int ID(const Set &s){
    if(mp.count(s)) return mp[s];
    v.push_back(s);
    return mp[s] = v.size()-1;
  }
  Set get(int x){
    return v[x];
  }
}idx;
stack<int> st;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    idx.clear();
    while(!st.empty()) st.pop();
    scanf("%d",&n);
    FOR(i,0,n){
      scanf("%s",s);
      if(s[0]=='P'){
        st.push(idx.ID(Set()));
      }else if(s[0]=='D'){
        st.push(st.top());
      }else{
        Set s1=idx.get(st.top()); st.pop();
        Set s2=idx.get(st.top()); st.pop();
        Set s3;
        if(s[0]=='U') set_union(ALL(s1),ALL(s2),INS(s3));
        else if(s[0]=='I') set_intersection(ALL(s1),ALL(s2),INS(s3));
        else { s2.insert(idx.ID(s1)); s3=s2; }
        st.push(idx.ID(s3));
      }
      printf("%lu\n",idx.get(st.top()).size());
    }
    printf("***\n");
  }
  return 0;
}
