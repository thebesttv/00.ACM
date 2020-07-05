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

const int MAX = 1e6 + 20;
int n; char s1[MAX],s2[MAX];
set<int> st[4][4];

int idx(int ch){
  switch(ch){
    case 'A': return 0;
    case 'C': return 1;
    case 'G': return 2;
    case 'T': return 3;
    default: return -1;
  }
}

int main(void){
  scanf("%s%s",s1+1,s2+1); n = strlen(s1+1);
  FORR(i,1,n) if(s1[i] != s2[i])
    st[idx(s1[i])][idx(s2[i])].insert(i);

  int ans = 0;
  FORR(i,1,n) if(s1[i] != s2[i]){
    st[idx(s1[i])][idx(s2[i])].erase(i);
    set<int> &t = st[idx(s2[i])][idx(s1[i])];
    if(!t.empty()){
      int j = *(t.begin());
      swap(s1[i], s1[j]);
      t.erase(t.begin());
#ifdef DEBUG
      printf("  swap(%d,%d): %s\n",i,j,s1+1);
#endif
    }else{
      int ch1 = -1, ch2 = -1;
      FOR(ch,0,4) if(!st[idx(s2[i])][ch].empty()){
        if(ch1!=-1) ch2 = ch;
        else ch1 = ch;
      }

      set<int> *t = nullptr;
      if(ch2==-1 || st[ch2][idx(s1[i])].size() < st[ch1][idx(s1[i])].size())
        t = &st[idx(s2[i])][ch1];
      else
        t = &st[idx(s2[i])][ch2];

      int j = *(t->begin());
      st[idx(s1[i])][idx(s2[j])].insert(j);
      swap(s1[i],s1[j]);
#ifdef DEBUG
      printf("  swap(%d,%d): %s\n",i,j,s1+1);
#endif
      t->erase(t->begin());

      /*
      FOR(ch,0,4) if(!st[idx(s2[i])][ch].empty()){
        set<int> &t = st[idx(s2[i])][ch];
        int j = *(t.begin());
        st[idx(s1[i])][idx(s2[j])].insert(j);
        swap(s1[i],s1[j]);
#ifdef DEBUG
        printf("  swap(%d,%d): %s\n",i,j,s1+1);
#endif
        t.erase(t.begin());
      }
      */
    }
    ++ans;
  }
#ifdef DEBUG
  printf("%s\n%s\n",s1+1,s2+1);
#endif
  printf("%d\n",ans);

  return 0;
}
