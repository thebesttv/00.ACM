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
typedef pair<char,int> pci;

int bnd[128],n1,n2; char c1,c2;
void cal(pci p, set<pci> &st){
  FORR(i,1,bnd[p.FI]) if(i != p.SE){
    st.insert({p.FI, i});
  }

  int ch, n;
  ch = p.FI, n = p.SE;
  while(ch <= 'k'){
    if(ch < 'f') ++n;
    ++ch;
    if(n<1 || n > bnd[ch]) break;
    st.insert({ch,n});
  }

  ch = p.FI, n = p.SE;
  while(ch <= 'k'){
    if(ch >= 'f') --n;
    ++ch;
    if(n<1 || n > bnd[ch]) break;
    st.insert({ch,n});
  }

  ch = p.FI, n = p.SE;
  while(ch >= 'a'){
    if(ch > 'f') ++n;
    --ch;
    if(n<1 || n > bnd[ch]) break;
    st.insert({ch,n});
  }

  ch = p.FI, n = p.SE;
  while(ch >= 'a'){
    if(ch <= 'f') --n;
    --ch;
    if(n<1 || n > bnd[ch]) break;
    st.insert({ch,n});
  }

  /*
  FORR(ch,'a','k') if(bnd[ch]<=p.SE && ch != p.FI){
    st.insert({ch, p.SE});
  }
  FOR(k,1,11){
    char ch; int n;

    // minus
    ch = p.FI - k; n = p.SE - k;
    if(ch>='a' && n>=1)
      st.insert({ch,n});
    // plus
    ch = p.FI + k; n = p.SE - k;
    if(ch<='k' && n>=1)
      st.insert({ch,n});
  }
  */
#ifdef DEBUG
  printf("  for (%c,%d)\n",p.FI,p.SE);
  for(auto a : st) printf("    %c, %d\n",a.FI,a.SE);
#endif
}

int main(void){
  bnd['a'] = 6;
  bnd['b'] = 7;
  bnd['c'] = 8;
  bnd['d'] = 9;
  bnd['e'] = 10;
  bnd['f'] = 11;
  bnd['g'] = 10;
  bnd['h'] = 9;
  bnd['i'] = 8;
  bnd['j'] = 7;
  bnd['k'] = 6;
  scanf("%c%d %c%d",&c1,&n1,&c2,&n2);
#ifdef DEBUG
  printf("  get (%c,%d) (%c,%d)\n",c1,n1,c2,n2);
#endif
  set<pci> st1, st2, st3;
  cal({c1,n1}, st1);
  cal({c2,n2}, st2);
  set_intersection(ALL(st1), ALL(st2), INS(st3));
  printf("%d\n",st3.size());

  return 0;
}
