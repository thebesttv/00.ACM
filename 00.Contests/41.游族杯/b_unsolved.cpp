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

const int MAX = 1020;
int n, lMax, v[MAX];

bool ask(const string &s){
  printf("? %s\n",s.c_str()); fflush(stdout);
  char str[4]; scanf("%s",str);
  return str[0]=='1';
}

void answer(const string &s){
  printf("! %s\n",s.c_str());
}

int check(const string &pre, const string &suf, int n, char ch){
  int l = 0, r = n;
  while(l<r){
    int m = (l+r+1)/2;
    if(ask(pre + string(m, ch) + suf))
      l = m;
    else
      r = m-1;
  }
  return l;
}

int main(void){
  scanf("%d",&n); lMax = (n/2)+1;
  int cnt0, cnt1;
  if(!ask("1")){  // all zero
    answer(string(n, '0'));
    return 0;
  }else if(!ask(string(lMax,'1'))){ // 1 <= cnt1 < lMax
    cnt1 = check("", "", lMax, '1');
    cnt0 = n - cnt1;

    // 1 fewer
    int cntOk = 0;
    FORR(i,0,cnt1){
      v[i] = check(string(i,'1'), string(cnt1-i,'1'), lMax - cnt1, '0');
      if(v[i]) ++cntOk;
    }

    if(cntOk == 1){
      string ans;
      FORR(i,0,cnt1) if(v[i])
        ans = string(i,'1') + string(cnt0,'0') + string(cht1-i,'1');
      answer(ans); return 0;
    }

    FORR(i,0,cnt1) if(v[i]) {
    }
  }else{
  }


  int l = 1, r = n;
  while(l<r){
    int m = (l+r+1)/2;
    if(ask(string(m, '1')))
      l = m;
    else
      r = m - 1;
  }

  return 0;
}

/*
int n;

bool ask(const string &s){
  printf("? %s\n",s.c_str()); fflush(stdout);
  char str[4]; scanf("%s",str);
  return str[0]=='1';
}

void answer(const string &s){
  printf("! %s\n",s.c_str());
}

int check(const string &prefix, int left1, int left0){
  int l = 0, r = left0;
  string str1(left1, '1');
  while(l<r){
    int m = (l+r+1)/2;
    if(ask(prefix + string(m, '0') + str1))
      l = m;
    else
      r = m-1;
  }
#ifdef DEBUG
  printf("  prefix: %s, 0: %d\n",prefix.c_str(), l);
#endif
  return l;
}

int main(void){
  scanf("%d",&n);
  if(!ask("1")){  // all zero
    answer(string(n, '0'));
    return 0;
  }
  int l = 1, r = n;
  while(l<r){
    int m = (l+r+1)/2;
    if(ask(string(m, '1')))
      l = m;
    else
      r = m - 1;
  }

  int cnt1 = l, cnt0 = n-l;
#ifdef DEBUG
  printf("  cnt1: %d, cnt0: %d\n",cnt1,cnt0);
#endif
  string prefix;
  ROR(i,cnt1, 0){
    int t = check(prefix, i, cnt0);
    cnt0 -= t;
    prefix += string(t, '0');
    if(i) prefix += '1';
  }

  answer(prefix.c_str());

  return 0;
}
*/
