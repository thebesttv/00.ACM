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

const int MAX=50020;
char s[MAX*10];
struct Node{
  string s; int op,lc,rc;
  bool operator < (const Node &b) const {
    if(op!=b.op) return op<b.op;
    return lc!=b.lc ? lc<b.lc : rc<b.rc;
  }
};

map<Node, int> mp;
VR<Node> v;
int ID(const Node &t){
  if(mp.count(t)) return mp[t];
  v.push_back(t);
  return mp[t]=v.size()-1;
}

int x=0;
int build_tree(){
  Node u; u.op=0;
  while(islower(s[x])){
    u.s+=s[x];
    u.op = u.op*27 + s[x]-'a'+1;  // <b> 要 27 位,而且 a 是 1!!!!!! </b>
    ++x;
  }
  if(s[x]=='('){
    ++x; u.lc=build_tree();
    ++x; u.rc=build_tree();
    ++x;
  }else{
    u.lc = u.rc = -1;
  }
  return ID(u);
}

int vis[MAX],cnt=0;
void print(int x){
  Node &u = v[x];
  int &a=vis[x];
  if(!a){
    a=++cnt;
    cout << u.s;
    if(u.lc!=-1){
      cout << "(";
      print(u.lc);
      cout << ",";
      print(u.rc);
      cout << ")";
    }
  }else{
    cout << a;
  }
}

int main(void){
  int T; scanf("%d",&T); getchar();
  while(T--){
    cnt=x=0; mp.clear(); v.clear(); MST(vis,0);
    scanf("%s",s);
    int u=build_tree();
    print(u); putchar('\n');
  }
  return 0;
}

/*
const int MAX=50020;
char s[MAX*10];
struct Node{
  string s; int op,lc,rc;
  bool operator < (const Node &b) const {
    if(op!=b.op) return op < b.op;
    return lc!=b.lc ? lc<b.lc : rc<b.rc;
  }
};

map<Node, int> mp;
VR<Node> v;
int ID(const Node &t){
  if(mp.count(t)) return mp[t];
  v.push_back(t);
  return mp[t]=v.size()-1;
}

int build_tree(int x, int y){
  Node u; u.op=0;
  while(islower(s[x])){
    u.s+=s[x]; u.op = u.op*27 + s[x]-'a';
    ++x;
  }

  if(x==y){
    u.lc = u.rc = -1;
    return ID(u);
  }

  int p=0,c=x;
  while(c<y){
    if(s[c]=='(') ++p;
    else if(s[c]==')') --p;
    else if(s[c]==',' && p==1) break;
    ++c;
  }
  u.lc = build_tree(x+1,c);
  u.rc = build_tree(c+1,y-1);
  return ID(u);
}

int vis[MAX],cnt=0;
void print(int x){
  Node &u = v[x];
  int &a=vis[x];
  if(!a){
    a=++cnt;
    cout << u.s;
    if(u.lc!=-1){
      cout << "(";
      print(u.lc);
      cout << ",";
      print(u.rc);
      cout << ")";
    }
  }else{
    cout << a;
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    cnt=0; mp.clear(); v.clear(); MST(vis,0);
    scanf("%s",s); int len=strlen(s);
    int root = build_tree(0,len);
    print(root); putchar('\n');
  }
  return 0;
}
*/
