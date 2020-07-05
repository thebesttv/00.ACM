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

const int MAX = 120;
int n; char s[MAX];
string pre, suf, mid;
deque<char> v[MAX];

bool okPre(){
  pre.clear();
  while(true){
    int ch = '*';
    FOR(i,0,n) if(v[i].front() != '*'){
      if(ch == '*')
        ch = v[i].front();
      else if(ch != v[i].front())
        return false;
      v[i].pop_front();
    }
    if(ch == '*') break;
    pre.push_back(ch);
  }
#ifdef DEBUG
  printf("  pre: %s\n",pre.c_str());
#endif
  return true;
}

bool okSuf(){
  suf.clear();
  while(true){
    int ch = '*';
    FOR(i,0,n) if(v[i].back() != '*'){
      if(ch == '*')
        ch = v[i].back();
      else if(ch != v[i].back())
        return false;
      v[i].pop_back();
    }
    if(ch == '*') break;
    suf.push_back(ch);
  }
  reverse(ALL(suf));
#ifdef DEBUG
  printf("  suf: %s\n",suf.c_str());
#endif
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    FOR(i,0,n){
      v[i].clear();
      scanf("%s",s); int len = strlen(s);
      FOR(j,0,len) v[i].push_back(s[j]);
    }

    printf("Case #%d: ",kase);
    if(!okPre() || !okSuf()){
      printf("*\n");
    }else{
      mid.clear();
      FOR(i,0,n) while(!v[i].empty()){
        if(v[i].front() != '*') mid.push_back(v[i].front());
        v[i].pop_front();
      }
      string ans = pre + mid + suf;
      printf("%s\n",ans.c_str());
    }
  }

  return 0;
}

/*
const int MAX = 120;
int n; char s[MAX];
string pre[MAX], suf[MAX];
deque<string> mid[MAX];

auto cmp = [](string &a, string &b){
  return a.size() != b.size() ? a.size() > b.size() : a > b;
};

bool okPre(){
  sort(pre,pre+n,cmp);
  FOR(i,1,n) FOR(j,0,pre[i].size())
    if(pre[i][j] != pre[0][j])
      return false;
  return true;
}

bool okSuf(){
  sort(suf,suf+n,cmp);
  int len = suf[0].size();
  FOR(i,1,n){
    int d = suf[0].size() - suf[i].size();
    FOR(j,0,suf[i].size())
      if(suf[i][j] != suf[0][j+d])
        return false;
  }
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    FOR(k,0,n){
      mid[k].clear(); pre[k]=suf[k]="";
      scanf("%s",s); int len = strlen(s);
      int i=0, j;
      while(i<len){
        while(i<len && s[i]=='*') ++i;
        j = i; string t;
        while(j<len && s[j]!='*') t += s[j++];
        if(!t.empty()) mid[k].push_back(t);
        i = j;
      }
      if(s[0]!='*')
        pre[k] = mid[k].front(), mid[k].pop_front();
      if(s[len-1]!='*')
        suf[k] = mid[k].back(), mid[k].pop_back();
#ifdef DEBUG
      printf("for string %s, get:\n  pre: %s\n  mid:",s,pre[k].c_str());
      for(string &s : mid[k]) printf(" %s",s.c_str());
      printf("\n  suf: %s\n",suf[k].c_str());
#endif
    }

    printf("Case #%d: ",kase);
    if(!okPre() || !okSuf()){
      printf("*\n"); continue;
    }
    printf("%s",pre[0].c_str());
    FOR(i,0,n) for(string &s : mid[i])
      printf("%s",s.c_str());
    printf("%s\n",suf[0].c_str());
  }

  return 0;
}
*/

/*
const int MAX = 120;
int n; char s[MAX], rPre[MAX], rSuf[MAX];
string pre[60], suf[60];
VR<string> mid[60];

void cal(char *s, int idx){
  int len = strlen(s);
  int i = 0;
  string prefix, suffix, cur;
  VR<string> v;
  // pre
  while(i<len && s[i]!='*') prefix += s[i++];

  // mid + suf
  while(i<len){
    while(i<len && s[i]=='*') ++i;
    int j = i;
    cur.clear();
    while(j<len && s[j]!='*') cur += s[j++];
    i = j;
    if(cur.size())
      v.push_back(cur);
  }
  // has suffix
  if(s[len-1]!='*' && v.size()){
    suffix = v.back();
    if(v.size()>1) FOR(i,0,v.size()-1)
      mid[idx].push_back(v[i]);
  }else{ // has no suffix
    for(string &x : v) mid[idx].push_back(x);
  }

  pre[idx] = prefix;
  suf[idx] = suffix;
#ifdef DEBUG
  cout << "get from: " << s << endl;
  cout << "  pre: " << prefix << endl;
  cout << "  mid:";
  for(string x : mid[idx]) cout << " " << x;
  cout << endl;
  cout << "  suf: " << suffix << endl;
#endif
}

bool okPre(){
  MST(rPre,0);
  sort(pre, pre+n, [](const string &a, const string &b){
        return a.size() != b.size() ? a.size() > b.size() : a > b;
      });

  int len = pre[0].size();
  FOR(i,0,len) rPre[i] = pre[0][i];

  // for(string &s : pre){
  FOR(i,0,n){
    string &s = pre[i];
#ifdef DEBUG
    printf("  okPre: trying: %s\n",s.c_str());
#endif
    FOR(i,0,s.size()) if(s[i] != rPre[i])
      return false;
  }
  return true;
}

bool okSuf(){
  MST(rSuf,0);
  sort(suf, suf+n, [](const string &a, const string &b){
        return a.size() != b.size() ? a.size() > b.size() : a > b;
      });

  int len = suf[0].size();
  FOR(i,0,len) rSuf[i] = suf[0][i];

  // for(string &s : suf){
  FOR(i,0,n){
    string &s = suf[i];
#ifdef DEBUG
    printf("  okSuf: trying: %s\n",s.c_str());
#endif
    int d = len - s.size();
    FOR(i,0,s.size()) if(s[i] != rSuf[i+d])
      return false;
  }
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    FOR(i,0,n){
      mid[i].clear();
      scanf("%s",s);
      cal(s, i);
    }

    printf("Case #%d: ",kase);
    // pre
    if(!okPre()){
      printf("*\n"); continue;
    }

    // suf
    if(!okSuf()){
      printf("*\n"); continue;
    }

    printf("%s",rPre);
    FOR(i,0,n) for(string &s : mid[i])
      printf("%s",s.c_str());
    printf("%s",rSuf);
    putchar('\n');
  }

  return 0;
}
*/
