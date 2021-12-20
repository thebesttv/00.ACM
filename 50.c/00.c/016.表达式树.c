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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

bool isOperator(char ch){
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')';
}

struct Node{
  int val;
  Node *lc, *rc;  // if lc == rc == NULL, then val is operand, else val is operator

  bool isOperator(){
    return lc || rc;
  }
  bool isOperand(){
    return lc == NULL && rc == NULL;
  }
}oFlag;

Node *buildTree(VR<Node> &v, int x, int y){
  int c1 = -1, c2 = -1, p = 0;
  if(y-x == 1){
    Node *u = new Node{v[x].val, NULL, NULL};
    return u;
  }
  FOR(i,x,y) if(v[i].isOperator()){
    switch(v[i].val){
      case '(': p++; break;
      case ')': p--; break;
      case '+': case '-': if(!p) c1=i; break;
      case '*': case '/': if(!p) c2=i; break;
    }
  }
  if(c1 < 0) c1 = c2;
  if(c1 < 0) return buildTree(v,x+1,y-1);
  Node *u = new Node;
  u->lc = buildTree(v,x,c1);
  u->rc = buildTree(v,c1+1,y);
  u->val = v[c1].val;
  return u;
}

double cal(Node *u){
  if(u->isOperand()) return u->val;
  double l = cal(u->lc);
  double r = cal(u->rc);
  double ans;
  switch(u->val){
    case '+': ans = l + r; break;
    case '-': ans = l - r; break;
    case '*': ans = l * r; break;
    case '/': ans = l / r; break;
  }
  return ans;
}

int main(void){
  string s; getline(cin,s);
  VR<Node> exp;
  int i = 0;
  while(i < s.size()){
    if(isdigit(s[i])){
      int v = 0;
      while(i<s.size() && isdigit(s[i])){
        v = v*10 + s[i]-'0'; i++;
      }
      exp.push_back(Node{v,NULL,NULL});
      continue;
    }else if(isOperator(s[i])){
      exp.push_back(Node{s[i],&oFlag,&oFlag});
    }
    i++;
  }
#ifdef DEBUG
  for(Node t : exp){
    if(t.isOperand()) printf("%d",t.val);
    else printf("%c",t.val);
    putchar(' ');
  }
  putchar('\n');
#endif
  Node *root = buildTree(exp, 0, exp.size());

  printf("%lf\n",cal(root));

  return 0;
}
