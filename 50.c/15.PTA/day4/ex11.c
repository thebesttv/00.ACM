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

void print(VR<int> v, char *s){
  printf("int[] %s = new int[]{",s);
  printf("%d",v[0]);
  FOR(i,1,v.size()) printf(",%d",v[i]);
  printf("};\n");
}

int main(void){
  string s; cin >> s;
  set<int> st;
  for(char c : s) st.insert(c-'0');
  VR<int> v;
  for(int x : st) v.push_back(x);
  reverse(ALL(v));

  VR<int> ans;
  for(char c : s){
    int pos=0, ch=c-'0';
    while(v[pos]!=ch) pos++;
    ans.push_back(pos);
  }
  print(v,"arr");
  print(ans,"index");

  return 0;
}
