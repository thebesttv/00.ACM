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

char cmd[1024], s[1024];

struct Dir;

struct File{
  string name;
  Dir *fa;

  File(string name, Dir *fa): name(name), fa(fa) { }
};

struct Dir{
  string name;
  set<Dir*> subDir;
  set<File*> subFile;
  Dir *fa;

  Dir(string name, Dir *fa): name(name), fa(fa) { }
}*pwd, *root;

string getPathName(Dir *p){
  stack<Dir*> st;
  while(p){
    st.push(p);
    p = p->fa;
  }
  string s;
  while(!st.empty()){
    s += "/" + st.top()->name;
    st.pop();
  }
  return s;
}

void split(char *s, VR<string> &v){
  string ts;
  while(*s){
    if(*s == '/'){
      v.push_back(ts);
      ts.clear();
    }else{
      ts += *s;
    }
    ++s;
  }
  v.push_back(ts);
}

Dir *getDir(Dir *pwd, const string &name){
  for(auto p : pwd->subDir)
    if(p->name == name)
      return p;
  return nullptr;
}

void cd(char *path){
  VR<string> v; split(path,v);
#ifdef DEBUG
  printf("cd ");
  for(auto p : v) printf("%s ",p.c_str());
  putchar('\n');
#endif

  for(auto p : v){
    if(p == ".."){
      pwd = pwd->fa;
    }else{
      pwd = getDir(pwd, p);
    }
  }
}

void ls(Dir *pwd){
#ifdef DEBUG
  printf("ls dir %s\n",pwd->name.c_str());
#endif
  printf("Listing for %s:\n",getPathName(pwd).c_str());
  VR<string> v;
  for(auto p : pwd->subDir)
    v.push_back(p->name);
  for(auto p : pwd->subFile)
    v.push_back(p->name);
  if(v.empty()){
    printf("There are no files/directories.\n\n");
    return;
  }
  sort(ALL(v));
  for(auto p : v)
    printf("%s\n",p.c_str());
  putchar('\n');
}

int main(void){
  int kase = 0;
  while(true){
    scanf("%s",cmd);
    if(cmd[0] == 'i'){  // init
      printf("File system #%d:\n\n",++kase);
      root = new Dir("home", nullptr);
      pwd = root;
    }else if(cmd[0] == 'e'){  // end
      break;
    }else if(cmd[0] == 'c'){  // cd
      scanf("%s",s); cd(s);
    }else if(cmd[0] == 'l'){
      ls(pwd);
    }else if(cmd[2] == 'f'){  // mkfile
      scanf("%s",s);
      pwd->subFile.insert(new File(s, pwd));
    }else{  // mkdir
      scanf("%s",s);
      pwd->subDir.insert(new Dir(s, pwd));
    }
  }

  return 0;
}
