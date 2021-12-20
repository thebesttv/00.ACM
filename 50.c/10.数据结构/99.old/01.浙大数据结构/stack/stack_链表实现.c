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

// 链表实现
struct Node{
  int n; Node *next;
};
struct Stack{
  Node *t; int size;

  Stack(){
    t=nullptr; size=0;
  }
  bool isEmpty(){
    return !t;
  }
  void push(int n){
    Node *p = new Node;
    p->n = n; p->next = t;
    t = p; size++;
  }
  int top(){
    if(isEmpty()){
      cerr << "Stack empty\n";
      return -1;
    }
    return t->n;
  }
  void pop(){
    if(isEmpty()){
      cerr << "Stack empty\n";
      return;
    }
    Node *p = t;
    t = t->next;
    delete p; size--;
  }
};

int main(void){
  Stack st;
  string cmd; int x;
  while(cin >> cmd){
    if(cmd=="quit") break;
    if(cmd=="push"){
      cin >> x; st.push(x);
    }else if(cmd=="top"){
      cout << "top element of s:" << st.top() << endl;
    }else if(cmd=="pop"){
      st.pop();
    }
    cout << "size: " << st.size << ",";
    Node *p = st.t;
    while(p) { cout << " " << p->n; p=p->next; }
    cout << endl;
  }

  return 0;
}
