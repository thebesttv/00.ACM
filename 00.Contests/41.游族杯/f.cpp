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
int n, ans; char s[MAX];
string str[MAX];

struct Node{
  string s;
  map<string, Node*> mp;
} root;

bool ok(const string &s){
  if(s.size()<5) return false;
  int n = s.size();
  return s[n-1] == 'j' && s[n-2] == 'o' && s[n-3] == 'e' && s[n-4] == '.';
}

void dfs(Node &u, char *p){
#ifdef DEBUG
  printf("  %s\n",u.s.c_str());
#endif
  if((*p)==0) return;
  string s;
  FOR(i,1,MAX)
    if(isalpha(p[i]) || p[i]=='.'){
      s += p[i];
    }else{
      p = p+i; break;
    }

  if(u.mp.count(s))
    dfs(*(u.mp[s]), p);
  else{
    Node *v = new Node;
    v->s = s; u.mp[s] = v;
    dfs(*v, p);
  }
}

void dfs2(Node *u){
  if(u->mp.empty() && ok(u->s)){
    ++ans;
  }
  for(auto v : u->mp)
    dfs2(v.SE);
}

int main(void){
  root.s = "root";
  scanf("%d",&n);
  FOR(i,0,n){
    scanf("%s",s);
    dfs(root, s);
  }

  dfs2(&root);
  printf("%d\n",ans);

  return 0;
}


/*
const int MAX = 1e6 + 20;
int n; char s[MAX];
VR<int> G[MAX];
map<pair<int, string>, bool> isDir, isFile;
VR<pair<int,string>> v;

bool ok(const string &s){
  if(s.size()<5) return false;
  int n = s.size();
  return s[n-1] == 'j' && s[n-2] == 'o' && s[n-3] == 'e' && s[n-4] == '.';
}

int main(void){
  scanf("%d",&n); int len;
  while(n--){
    scanf("%s",s); len = strlen(s);
    string str; VR<string> vec;

    FOR(i,0,len)
      if(s[i]=='/'){
        if(str.size()){
          vec.push_back(str);
          str.clear();
        }
      }else{
        str += s[i];
      }
    if(str.size())
      vec.push_back(str);

    if(vec.empty())
      continue;

    FOR(i,0,vec.size()-1){
#ifdef DEBUG
      printf("  isDir(%d, %s)\n",i,vec[i].c_str());
#endif
      isDir[{i,vec[i]}] = 1;
    }

    v.push_back({vec.size()-1, vec.back()});
  }

  for(auto p : v) if(!isDir[p] && ok(p.SE)){
    isFile[p] = 1;
  }
  printf("%d\n",(int)isFile.size());

  return 0;
}
*/
