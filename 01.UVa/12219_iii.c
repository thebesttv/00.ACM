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
struct Node{
  char s[5];
  int lc, rc;

  bool operator < (const Node &b) const {
    if(!strcmp(s,b.s))
      return lc!=b.lc ? lc<b.lc : rc<b.rc;
    else
      return strcmp(s,b.s)<0;
  }
}node[MAX];
char s[MAX*10];
map<Node,int> mp;
bool flag[MAX];

void getName(int &l, char *dst){
  int tail=0;
  while(isalpha(s[l])){
    dst[tail++]=s[l];
    l++;
  }
  dst[tail]=0;
}

int ncnt=0,pos;
int dfs(){
  int u=++ncnt;
  getName(pos,node[u].s);
  if(s[pos]=='('){  // 不能用遍历的方法，否则复杂度爆炸……
    pos++; node[u].lc=dfs();
    pos++; node[u].rc=dfs();
    pos++;
  }else{
    node[u].lc=node[u].rc=0;
  }

  if(mp.count(node[u])){
    u=mp[node[u]], ncnt--;
  }else{
    mp[node[u]]=u;
  }
  return u;
}

void print(int u){
  if(flag[u]){
    printf("%d",u); return;
  }
  printf("%s",node[u].s);
  flag[u]=1;
  if(node[u].lc){
    putchar('(');
    print(node[u].lc);
    putchar(',');
    print(node[u].rc);
    putchar(')');
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    mp.clear(); MST(flag,0); ncnt=0;
    scanf("%s",s);
    pos=0; int u=dfs();
    print(u); putchar('\n');
  }

  return 0;
}

/*
const int MAX=50020;
struct Node{
  string root;
  int lc, rc;

  bool operator < (const Node &b) const {
    if(root==b.root){
      return lc!=b.lc ? lc<b.lc : rc<b.rc;
    }else{
      return root<b.root;
    }
  }
}node[MAX];
int ncnt;
char s[MAX*10];
map<Node,int> mp;

string getName(int &l){
  char name[6],tail=0;
  while(isalpha(s[l])){
    name[tail++]=s[l]; l++;
  }
  name[tail]=0;
  return string(name);
}

int dfs(int l, int r){
  int u=++ncnt;
  node[u].root = getName(l);
  int m=-1,p=0;
  FOR(i,l,r) switch(s[i]){
    case '(': p++; break;
    case ')': p--; break;
    case ',': if(p==1) m=i;
  }
  if(m<0){  // leaf
    node[u].lc = node[u].rc = 0;
  }else{
    node[u].lc=dfs(l+1,m);
    node[u].rc=dfs(m+1,r-1);
  }

  if(!mp.count(node[u])){
    mp[node[u]]=u;
#ifdef DEBUG
  printf("node[%d]: ",u); cout << node[u].root << ", ";
  printf("%d, %d, %d\n",node[u].lc,node[u].rc,node[u].no);
#endif
  }else{
    u=mp[node[u]];
    ncnt--;
  }
  return u;
}

bool flag[MAX];
void print(int u){
  if(flag[u]){
    printf("%d",u); return;
  }
  cout << node[u].root;
  flag[u]=1;
  if(node[u].lc){
    putchar('(');
    print(node[u].lc);
    putchar(',');
    print(node[u].rc);
    putchar(')');
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    ncnt=0; mp.clear(); MST(flag,0);
    scanf("%s",s); int len=strlen(s);
    int u=dfs(0,len);

    print(u);
    putchar('\n');
  }

  return 0;
}
*/

/*
const int MAX=50020;
struct Node{
  string root;
  int lc, rc;
  int no;

  Node() { }
  Node(string s, int l, int r):
    root(s), lc(l), rc(r) { }
  bool operator < (const Node &b) const {
    if(root==b.root){
      return lc!=b.lc ? lc<b.lc : rc<b.rc;
    }else{
      return root<b.root;
    }
  }
}node[MAX];
int ncnt;
char s[MAX];

string getName(int &l){
  char name[6],tail=0;
  while(isalpha(s[l])){
    name[tail++]=s[l]; l++;
  }
  name[tail]=0;
  return string(name);
}

map<Node,int> mp;

int dfs(int l, int r){
  int u=++ncnt;
  node[u].root = getName(l);
  int m=-1,p=0;
  FOR(i,l,r) switch(s[i]){
    case '(': p++; break;
    case ')': p--; break;
    case ',': if(p==1) m=i;
  }
  if(m<0){  // leaf
    node[u].lc = node[u].rc = 0;
  }else{
    node[u].lc=dfs(l+1,m);
    node[u].rc=dfs(m+1,r-1);
  }

  if(!mp.count(node[u]))
    mp[node[u]]=u;

  node[u].no=mp[node[u]];
#ifdef DEBUG
  printf("node[%d]: ",u); cout << node[u].root << ", ";
  printf("%d, %d, %d\n",node[u].lc,node[u].rc,node[u].no);
#endif

  return node[u].no;
}

bool flag[MAX];
void print(int u){
  u=node[u].no;
  if(flag[u]){
    printf("%d",u); return;
  }
  cout << node[u].root;
  flag[u]=1;
  if(node[u].lc){
    putchar('(');
    print(node[u].lc);
    putchar(',');
    print(node[u].rc);
    putchar(')');
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    ncnt=0; mp.clear(); MST(flag,0);
    scanf("%s",s); int len=strlen(s);
    int u=dfs(0,len);

    print(u);
    putchar('\n');
  }

  return 0;
}
*/
