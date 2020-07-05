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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 60;
int n;
char ori[MAX][120];

map<string, int> ID;

struct Fun{
  char name[12];
  int beg, end; // [beg, end)
  bool running;
  Fun() { running = 0; }
  int read(int l, int no);
  void run();
};
VR<Fun> fun;

struct Var{
  char name[12];
  string sname;
  int v;
  set<int> st; // 依赖函数

  void update(int newV){
    if(newV == v) return;
    v = newV;
    printf("update %s %d\n",name,newV);
    for(int i : st) fun[i].run();
  }
};
VR<Var> var;

int getVal(char *s, int &p){
  int v = 0;
  if(isdigit(s[p])){
    while(isdigit(s[p])){
      v = v*10 + s[p] - '0';
      ++p;
    }
  }else{
    int tail = 0;
    char name[12];
    while(isalpha(s[p])){
      name[tail++] = s[p];
      ++p;
    }
    name[tail] = 0;
    v = var[ ID[string(name)] ].v;
  }
  return v;
}

void parse(char *s){
  int l = 0, r = 0;
  char name[12];
  while(isalpha(s[r])){
    name[r] = s[r]; ++r;
  }
  name[r] = 0;
  l = r;
  Var &v = var[ ID[string(name)] ];
  while(!isalnum(s[l])) ++l;
  
  int rVal = getVal(s,l);
  int isDe = 0; r = l;
  while(s[r]){
    if(s[r] == '+'){
      isDe = 1; break;
    }else if(s[r] == '-'){
      isDe = -1; break;
    }
    ++r;
  }

  if(isDe){
    while(!isalnum(s[l])) ++l;
    rVal += isDe * getVal(s,l);
  }
  v.update(rVal);
}

int Fun::read(int l, int no){
  sscanf(ori[l] + 8, "%s", name);
  beg = ++l;
  while(strncmp(ori[l], "end", 3)){
    char *s = ori[l++];
#ifdef DEBUG
    printf("  reading line: %s\n",s);
#endif

    int tl = 0, tr;
    while(s[tl] != '=') ++tl;
    while(s[tl] && !isalpha(s[tl])) ++tl;
    if(!isalpha(s[tl])) continue;

    char vname[12];
    tr = tl+1; while(isalpha(s[tr])) ++tr;
    strncpy(vname, s + tl, tr - tl);
    vname[tr - tl] = 0;
    var[ID[string(vname)]].st.insert(no);
#ifdef DEBUG
    printf("  fun %s depends on var %s (%s)\n", name,var[ID[string(vname)]].name, vname);
#endif

    tl = tr;
    while(s[tl] && !isalpha(s[tl])) ++tl;
    if(!isalpha(s[tl])) continue;
    tr = tl+1; while(isalpha(s[tr])) ++tr;
    strncpy(vname, s + tl, tr - tl);
    vname[tr - tl] = 0;
    var[ID[string(vname)]].st.insert(no);
#ifdef DEBUG
    printf("  fun %s depends on var %s (%s)\n", name,var[ID[string(vname)]].name, vname);
#endif
  }
  return end = l;
}

void Fun::run(){
  if(running) return;
  running = 1;
  printf("enter %s\n",name);
  FOR(i,beg,end) parse(ori[i]);
  printf("leave %s\n",name);
  running = 0;
}

int main(void){
  scanf("%d",&n); FGETS(ori[0]);
  FOR(i,0,n) FGETS(ori[i]);

  FOR(i,0,n){
    if(strncmp(ori[i], "observable", 10)==0){
      Var t;
      int l = 11, r;
      while(ori[i][l]==' ') ++l;
      r = l+1;
      while(isalpha(ori[i][r])) ++r;
      strncpy(t.name, ori[i] + l, r-l);
      t.name[r-l] = 0;
      t.sname = string(t.name);
      ID[t.sname] = var.size();

      l = r;
      while(!isalnum(ori[i][l])) ++l; // rval 非负

      if(isdigit(ori[i][l])){
        sscanf(ori[i] + l, "%d", &t.v);
      }else{
        char tName[12];
        sscanf(ori[i] + l, "%s", tName);
        t.v = var[ID[string(tName)]].v;
      }

      var.push_back(t);
      printf("observable %s %d\n",t.name,t.v);
    }else if(strncmp(ori[i], "observe", strlen("observe"))==0){
      Fun f;
      i = f.read(i, fun.size());
      fun.push_back(f);
      fun[fun.size()-1].run();
    }else{  // change value
#ifdef DEBUG
      printf("  normal line to parse: %s\n",ori[i]);
#endif
      parse(ori[i]);
    }
  }

  return 0;
}
