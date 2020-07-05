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

const int MAX=10020;
int a,b,c,d,mid;
char s[MAX];
bool isOp[MAX];
string varName;

struct Node{
  string s;
  bool isOp;
}node[MAX],_plus;

int getNum(string s){
  int len=s.length();
  int sum=0, op=1, l=0;
  if(s[0]=='-'){
    op=-1; l++;
  }
  FOR(i,l,len){
    sum = sum*10 + s[i]-'0';
  }
  return sum*op;
}
int getXNum(string s){
  int len=s.length();
  int op=1, l=0;
  if(s[0]=='-'){
    op=-1; l++;
  }
  if(isalpha(s[l])) return op;  // 省略系数

  string s2;
  while(l<len && isdigit(s[l]))
    s2.push_back(s[l++]);
  return op*getNum(s2);
}
bool isVar(string s){
  for(char ch : s)
    if(isalpha(ch)) return true;
  return false;
}

void get(char *s, int len, int &a, int &b){
  a=b=0; MST(isOp,0);
  queue<Node> q; q.push(_plus);

  FOR(i,1,len)  // find out all operators
    if(isalnum(s[i-1]) && (s[i]=='+' || s[i]=='-')) isOp[i]=1;

  FOR(i,0,len){ // 将运算符和算子分开，放入队列
    Node tn;
    if(isOp[i]){
      tn.s.push_back(s[i]);
      tn.isOp=1;
    }else{
      while(i<len && !isOp[i]) tn.s.push_back(s[i++]);
      i--;  // <b> </b>
      tn.isOp=0;
    }
    q.push(tn);
  }

#ifdef DEBUG
  queue<Node> tq=q;
  while(!tq.empty()){
    Node t=tq.front(); tq.pop();
    cout << t.s << " ";
  }
  printf("\n");
#endif

  while(!q.empty()){
    Node n1=q.front(); q.pop(); // 运算符
    Node n2=q.front(); q.pop(); // 算子
    int op = n1.s[0]=='+' ? 1 : -1;
    if(isVar(n2.s)){
      a += op*getXNum(n2.s);
      if(varName.empty()){
        for(char ch : n2.s) if(isalpha(ch))
          varName.push_back(ch);
      }
    }else{
      b += op*getNum(n2.s);
    }
  }
}

int main(void){
  _plus.s="+"; _plus.isOp=1;

  scanf("%s",s);
  for(mid=0;s[mid]!='=';mid++);
  s[mid]=0;

  char *l=s, *r=s+mid+1;
  get(l,strlen(l),a,b);
  get(r,strlen(r),c,d);
#ifdef DEBUG
  printf("  get a: %d, b: %d\n",a,b);
  printf("  get c: %d, d: %d\n",c,d);
  printf("  x = %d / %d\n",d-b,a-c);
#endif

  double x = 1.0 * (d-b) / (a-c);
  if(fabs(x)<1e-4) x=0; // 对 -0.000 的特判
  cout << varName << "=";
  printf("%.3lf\n",x);

  return 0;
}

/*
const int MAX=10020;
int a,b,c,d,mid;
char s[MAX];
bool isOp[MAX];

struct Node{
  string s;
  int lc, rc;
  bool isOp;
}node[MAX];

int getNum(int &l, char *s){
  int sum=0, op=1;
  if(s[l]=='-'){
    op=-1; l++;
  }
  while(isdigit(s[l])){
    sum = sum*10 + s[l]-'0';
    l++;
  }
  return sum*op;
}

int dfs(char *s, int l, int r){
  int u=++nc;
  int pos=-1;
  ROR(i,r-1,l) if(isOp[i]) pos=i;
  if(pos==-1){
    char tch=s[r]; s[r]=0;
    node[u].s=string(s+l);
    node[u].isOp=0;
    node[u].lc=node[u].rc=0;
    return u;
  }
  node[u].s=string( s[pos]=='+' ? "+" : "-");
  node[u].isOp=1;
  node[u].lc=dfs(s,l,pos);
  node[u].rc=dfs(s,pos+1,r);
}

void get(char *s, int len, int &a, int &b){
  MST(isOp,0); nc=0;
  FOR(i,1,len) if(isalnum(s[i-1]) && (s[i]=='+' || s[i]=='-'))
      isOp[i]=1;

  char x[100],tail;
  FOR(i,0,len) if(isalpha(s[i])){
    int l=i, r=i;
    while(l && !isOp[l-1]) l--;
    while(r<len && !isOp[r]) r++;

    FOR(j,l,r){
      x[tail++]=s[j];
      s[j]=' ';
    }
    break;
  }

  if(tail){
    if(hasNum){
      int t=0; a=getNum(t,x);
    }else{
      a = x[0]=='-' ? -1 : 1;
    }
  }else a=0;

  int u=dfs(s,0,len);

  b=cal(u);
}

int main(void){
  scanf("%s",s);
  for(mid=0;s[mid]!='=';mid++);
  s[mid]=0;
  char *l=s, *r=s+mid+1;
  get(l,strlen(l),a,b);
  get(r,strlen(r),c,d);
  double x = 1.0 * (d-b) / (a-c);
  printf("%.3lf\n",x);

  return 0;
}
*/
