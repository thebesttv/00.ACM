// Tag: 后缀数组
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 4e5 + 20;
struct SA{
  int n, p[MAX], c[MAX]; char s[MAX];

  struct Node{
    int idx, a, b;
    bool operator < (const Node &c) const {
      return a != c.a ? a < c.a : b < c.b;
    }
    bool operator == (const Node &c) const {
      return a == c.a && b == c.b;
    }
  }node[MAX];

  int cnt[MAX], pos[MAX], p2[MAX], c2[MAX];
  void count_sort(){
    MST(cnt, 0);
    FOR(i,0,n) ++cnt[c[p[i]]];
    pos[0] = 0;
    FOR(i,1,n) pos[i] = pos[i-1] + cnt[i-1];
    FOR(i,0,n) p2[pos[c[p[i]]]++] = p[i];
    memcpy(p,p2,sizeof(p));
  }

  int process(){
    scanf("%s",s); n = strlen(s);
    s[n++] = '$'; s[n] = 0;

    FOR(i,0,n) node[i] = {i, s[i], 0};
    sort(node, node+n);
    p[0] = node[0].idx; c[p[0]] = 0;
    FOR(i,1,n){
      p[i] = node[i].idx;
      if(node[i] == node[i-1])
        c[p[i]] = c[p[i-1]];
      else
        c[p[i]] = c[p[i-1]] + 1;
    }

    for(int k=0; (1<<k) < n; ++k){
      FOR(i,0,n) p[i] = (p[i] - (1<<k) + n)%n;
      count_sort();

      c2[p[0]] = 0;
      FOR(i,1,n){
        pii cur = {c[p[i]], c[(p[i] + (1<<k))%n]};
        pii prev = {c[p[i-1]], c[(p[i-1] + (1<<k))%n]};
        if(cur == prev)
          c2[p[i]] = c2[p[i-1]];
        else
          c2[p[i]] = c2[p[i-1]] + 1;
      }
      memcpy(c,c2,sizeof(c));
    }

    //FOR(i,0,n) printf("%d ",p[i]); putchar('\n');
    s[--n] = 0;
    return p[n];
  }
}sa,sb;

int main(void){
  int la = sa.process();
  int lb = sb.process();
#ifdef DEBUG
  printf("a: %s\n",sa.s+la);
  printf("b: %s\n",sb.s+lb);
#endif
  string s; s += sa.s[la];

  char ch = sb.s[lb];
  FOR(i,la+1,sa.n)
    if(sa.s[i] >= ch){
      s += sa.s[i];
    } else break;

  s += string(sb.s + lb);
  printf("%s\n",s.c_str());

  return 0;
}

