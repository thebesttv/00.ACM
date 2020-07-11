// Tag: 模拟 fun
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

const int MAX = 100020;
char s[120], name[120], tmp[120];
int icnt; // install cnt
struct Node{
  string name;
  int inum;
  bool ept; // explicit
  // set<int> depend,support;
  VR<int> depend,support;

  void init(string s){
    depend.clear(); support.clear();
    name=s; inum = 0; ept = 0;
  }
}node[MAX];

int IDcnt;  // from 1
map<string,int> mp;
int ID(string name){
  if(mp.count(name)) return mp[name];
  node[++IDcnt].init(name);
  return mp[name] = IDcnt;
}

void setDep(int u, char *s){
  VR<string> vec; string str;
  int len = strlen(s), i=0;
  while(i<len){
    if(isalpha(s[i])) str += s[i];
    else if(!str.empty()) vec.push_back(str), str.clear();
    ++i;
  }
  if(!str.empty()) vec.push_back(str), str.clear();
  FOR(i,2,vec.size()){
    int v = ID(vec[i]);
#ifdef DEBUG
    printf("* %s depends on %s\n",node[u].name.c_str(), node[v].name.c_str());
#endif
    node[u].depend.push_back(v);
    node[v].support.push_back(u);
  }
}

void install(int u, bool ept){
  if(node[u].inum) return;
  for(auto v : node[u].depend)
    if(!node[v].inum) install(v, false);
  node[u].inum = ++icnt;
  node[u].ept = ept;
  printf("   Installing %s\n",node[u].name.c_str());
}

void remove(int u, bool must){
  bool needed = 0;
  for(auto v : node[u].support)
    if(node[v].inum) { needed = 1; break; }
  if(needed){
    if(!must) return;
    printf("   %s is still needed.\n",node[u].name.c_str());
    return;
  }
  printf("   Removing %s\n",node[u].name.c_str());
  node[u].inum = 0;
  for(auto v : node[u].depend)
    if(node[v].inum && !node[v].ept)
      remove(v, false);
}

int main(void){
  while(FGETS(s)){
    mp.clear(); IDcnt = icnt = 0;
    do{
      fputs(s, stdout);
      if(s[0] == 'E') break;
      if(s[0] == 'L'){
        VR<pii> v;
        FORR(i,1,IDcnt) if(node[i].inum)
          v.push_back({node[i].inum,i});
        sort(ALL(v));
        for(auto p : v) printf("   %s\n", node[p.SE].name.c_str());
      }else{
        sscanf(s,"%s%s",tmp,name);
        int u = ID(name);
        if(s[0] == 'D'){
          setDep(u,s);
        }else if(s[0] == 'I'){
          if(node[u].inum){
            printf("   %s is already installed.\n",node[u].name.c_str());
            continue;
          }
          install(u, true);
        }else if(s[0] == 'R'){
          if(!node[u].inum){
            printf("   %s is not installed.\n",node[u].name.c_str());
            continue;
          }
          remove(u, true);
        }
      }
    }while(FGETS(s));
  }

  return 0;
}
