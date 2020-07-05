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

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef set<int> Set;
map<Set,int> SetID; // return ID of set
VR<Set> getSet; // 针对ID返回Set
stack<int> st;
char cmd[20];

int ID(Set s){
  if(SetID.count(s)) return SetID[s];
  getSet.push_back(s);
  return SetID[s] = getSet.size()-1;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    SetID.clear(); getSet.clear();
    while(!st.empty()) st.pop();
    int n; scanf("%d",&n);
    while(n--){
      scanf("%s",cmd);
      if(cmd[0]=='P') st.push(ID(Set()));
      else if(cmd[0]=='D') st.push(st.top());
      else{
        Set s1 = getSet[st.top()]; st.pop();
        Set s2 = getSet[st.top()]; st.pop();
        Set s;
        if(cmd[0]=='U')
          set_union(ALL(s1), ALL(s2), INS(s));
        else if(cmd[0]=='I')
          set_intersection(ALL(s1), ALL(s2), INS(s));
        else{
          s=s2; s.insert(ID(s1));
        }
        st.push(ID(s));
      }
      printf("%lu\n",getSet[st.top()].size());
    }
    printf("***\n");
  }


  return 0;
}

/*
int n; char cmd[20];
int get_id(const set<int>&);
struct Node{
  set<int> st;  // using id to represent different set
  int id;
  Node() { id=get_id(st); }
  Node(set<int> s) { st=s; id=get_id(st); }
};
stack<Node> st;
map<set<int>, int> mp;  // record the id of each different set
int cnt;  // record current id

int get_id(const set<int> &st){
  if(mp.count(st)) return mp[st];
  else return mp[st]=cnt++;
}

void Push() { st.push(Node()); }
void Dup() { st.push(st.top()); }

void Union(Node &n1, Node &n2){
  for(int i : n2.st) n1.st.insert(i);
  st.push(Node(n1.st));
}
void Inter(Node &n1, Node &n2){
  map<int, int> tmp;
  for(int i : n1.st) tmp[i]=1;
  n1.st.empty();
  for(int i : n2.st) if(tmp.count(i))
    n1.st.insert(i);
  st.push(Node(n1.st));
}
void Add(Node &n1, Node &n2){
  n2.st.insert(n1.id);
  st.push(Node(n2.st));
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    st.empty(); mp.clear(); cnt=0;

    scanf("%d",&n);
    while(n--){
      scanf("%s",cmd);
      if(cmd[0]=='P')       Push();
      else if(cmd[0]=='D')  Dup();
      else{
        Node n1=st.top(); st.pop();
        Node n2=st.top(); st.pop();
        if(cmd[0]=='U')  Union(n1, n2);
        else if(cmd[0]=='I')  Inter(n1, n2);
        else if(cmd[0]=='A')  Add(n1, n2);
      }
      printf("%lu\n",st.top().st.size());
    }
    printf("***\n");
  }

  return 0;
}
*/

/*
int n; char cmd[20];
int get_id(const set<int>&);
struct Node{
  set<int> st;  // using id to represent different set
  int id;
  Node(const set<int> &s) { st=s; id=get_id(st); }
};
stack<Node> st;
map<set<int>, int> mp;  // record the id of each different set
int cnt;  // record current id

int get_id(const set<int> &st){
  if(mp.count(st)) return mp[st];
  else return mp[st]=cnt++;
}
void Push() { set<int> s; st.push(Node(s)); }
void Dup() { st.push(st.top()); }
inline void Pop2(Node &n1, Node &n2){
  n1=st.top(); st.pop();
  n2=st.top(); st.pop();
}
void Union(){
  Node n1, n2; Pop2(n1, n2);
  for(int i : n2.st) n1.st.insert(i);
  st.push(Node(n1.st));
}
void Inter(){
  Node n1, n2; Pop2(n1, n2);
  map<int, int> mp;
  for(int i : n1.st) mp[i]=1;
  n1.st.empty();
  for(int i : n2.st) if(mp.count(i))
    n1.st.insert(i);
  st.push(Node(n1.st));
}
void Add(){
  Node n1, n2; Pop2(n1, n2);
  n2.st.insert(n1.id);
  st.push(Node(n2.st));
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    st.empty(); mp.clear(); cnt=0;

    scanf("%d",&n);
    while(n--){
      scanf("%s",cmd);
      if(cmd[0]=='P')       Push();
      else if(cmd[0]=='D')  Dup();
      else if(cmd[0]=='U')  Union();
      else if(cmd[0]=='I')  Inter();
      else if(cmd[0]=='A')  Add();
      printf("%lu\n",st.top().st.size());
    }
    printf("***\n");
  }

  return 0;
}
*/
