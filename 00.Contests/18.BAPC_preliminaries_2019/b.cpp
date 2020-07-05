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

const int MOD = 1e9 + 7;
const int MAX = 3e5 + 20;
int n; char s[20];
stack<int> sn;
stack<char> so;

void eval(){
  LL x2 = sn.top(); sn.pop();
  LL x1 = sn.top(); sn.pop();
  char ch = so.top(); so.pop();
  if(ch == '+') sn.push((x1+x2)%MOD);
  else          sn.push((x1*x2)%MOD);
}

void cal(int lev){
  bool first = 1;
  while(n--){
    scanf("%s",s);
#ifdef DEBUG
    printf("  get %s\n",s);
#endif
    if(s[0]=='('){
      if(first){
        first = 0;
      }else if(lev&1){ // *
        so.push('*');
      }else{  // +
        while(!so.empty() && so.top() == '*'){
          eval();
        }
        so.push('+');
      }
      so.push('(');
      cal(lev+1);
    }else if(s[0]==')'){
      while(so.top() != '('){
        eval();
      }
      so.pop();
      return;
    }else{
      if(first){
        first = 0;
      }else if(lev&1){  // *
        so.push('*');
      }else{  // +
        while(!so.empty() && so.top() == '*'){
          eval();
        }
        so.push('+');
      }
      int n; sscanf(s,"%d",&n);
      sn.push(n);
    }
  }
}

int main(void){
  scanf("%d",&n);
  int cnt = 0;
  cal(0);
  while(!so.empty()) eval();
  printf("%d\n",sn.top());

  return 0;
}

