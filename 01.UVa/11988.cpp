// Tag: 链表 高效率
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

// deque
const int MAX = 100020;
int n; char s[MAX];
deque<string> q;

void push(string &str, int cur){
  if(str.empty()) return;
  if(cur) q.push_back(str);
  else q.push_front(str);
  str.clear();
}

int main(void){
  while(scanf("%s",s)==1){
    n = strlen(s); q.clear();
    string str;
    int cur = 1;  // 1: back, 0: front
    FOR(i,0,n){
      if(s[i] == '['){
        push(str, cur); cur = 0;
      }else if(s[i] == ']'){
        push(str, cur); cur = 1;
      }else{
        str += s[i];
      }
    }
    push(str, cur);
    for(string &s : q) printf("%s",s.c_str());
    putchar('\n');
  }

  return 0;
}

/*
// 链表
const int MAX = 100020;
int n; char s[MAX];
struct Node{
  char ch; Node *next;
}node[MAX];

int main(void){
  while(scanf("%s",s)==1){
    n = strlen(s); int cnt = 1;
    Node *head = node, *tail = node, *cur = node;
    node[0].next = nullptr;
    FOR(i,0,n){
      if(s[i] == '[') cur = head;
      else if(s[i] == ']') cur = tail;
      else{
        Node *p = node + (cnt++);
        p->ch = s[i];
        p->next = cur->next;
        cur->next = p;
        if(cur == tail) tail = p;
        cur = p;
      }
    }
    cur = head->next;
    while(cur) putchar(cur->ch), cur = cur->next;
    putchar('\n');
  }

  return 0;
}
*/

/*
// 数组链表
const int MAX = 100020;
int n,nxt[MAX]; char s[MAX];

int main(void){
  while(scanf("%s",s+1)==1){
    n = strlen(s+1); int cnt = 1;
    int head = 0, tail = 0, cur = 0; nxt[0] = 0;
    FORR(i,1,n){
      if(s[i] == '[') cur = head;
      else if(s[i] == ']') cur = tail;
      else{
        nxt[i] = nxt[cur];
        nxt[cur] = i;
        if(cur == tail) tail = i;
        cur = i;
      }
    }
    cur = nxt[0];
    while(cur) putchar(s[cur]), cur = nxt[cur];
    putchar('\n');
  }

  return 0;
}
*/
