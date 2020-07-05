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

const int MAX=100020;
int n,q; char s[MAX];
set<int> st[26];

int main(void){
  scanf("%s%d",s+1,&q);
  n = strlen(s+1);
  FORR(i,1,n) st[s[i]-'a'].insert(i);

  int op,pos,l,r,ch;
  while(q--){
    scanf("%d",&op);
    if(op==1){
      scanf("%d",&pos);
      do ch=getchar(); while(!isalpha(ch));
      st[s[pos]-'a'].erase(pos);
      st[ch-'a'].insert(pos);
      s[pos]=ch;
    }else{
      scanf("%d%d",&l,&r);
      int cnt=0;
      FOR(i,0,26){
        set<int>::iterator it = st[i].lower_bound(l);
        if(it!=st[i].end() && *it <= r) cnt++;
      }
      printf("%d\n",cnt);
    }
  }

  return 0;
}


/*
const int MAX=100020;
int n,q; char s[MAX];
int v[26][MAX]; // v[c-'a'][i]: 字母 c 在 i 是否出现

struct ST{
  int v[MAX];
  void add(int x, int a){
    while(x<=n){
      v[x]+=a; x += -x&x;
    }
  }
  int sum(int x){
    int s=0;
    while(x){
      s+=v[x]; x -= -x&x;
    }
    return s;
  }
}st[26];

int main(void){
  scanf("%s%d",s+1,&q);
  n = strlen(s+1);
  FORR(i,1,n) st[s[i]-'a'].add(i,1);

  int op,pos,l,r,ch;
  while(q--){
    scanf("%d",&op);
    if(op==1){
      scanf("%d",&pos);
      do ch=getchar(); while(!isalpha(ch));
      st[s[pos]-'a'].add(pos,-1);
      st[ch-'a'].add(pos,1);
      s[pos]=ch;
    }else{
      scanf("%d%d",&l,&r);
      int cnt=0;
      FOR(i,0,26)
        if( st[i].sum(r) - st[i].sum(l-1) > 0)
          cnt++;
      printf("%d\n",cnt);
    }
  }

  return 0;
}
*/
