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

// 动态数组实现
struct Stack{
  int *v,t,capacity;

  Stack(){
    v=new int[1]; t=0;
    capacity=1;
  }
  void expand(){
    int *p = new int[capacity*2]; // allocate new space
    capacity*=2;
    memcpy(p,v,capacity*sizeof(int)); // copy
    delete [] v; v=p;
  }
  bool isFull(){
    return t==capacity;
  }
  bool isEmpty(){
    return !t;
  }
  void push(int n){
    if(isFull()) expand();
    v[t++]=n;
  }
  int top(){
    if(isEmpty()){
      cerr << "Stack empty\n";
      return -1;
    }
    return v[t-1];
  }
  void pop(){
    if(isEmpty()){
      cerr << "Stack empty\n";
    }else{
      t--;
    }
  }
};

/*
// 数组实现
const int MAX_SIZE=1000;
struct Stack{
  int v[MAX_SIZE],t;

  bool isFull(){
    return t==MAX_SIZE;
  }
  bool isEmpty(){
    return !t;
  }
  void push(int n){
    v[t++]=n;
  }
  int top(){
    return v[t-1];
  }
  void pop(){
    t--;
  }
};
*/

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
    cout << "capacity: " << st.capacity << ",";
    FOR(i,0,st.t) cout << " " << st.v[i];
    cout << endl;
  }

  return 0;
}
