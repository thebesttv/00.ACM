// Tag: 
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<string,string> pii;

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

int nread(){
  int s = 0, ch, neg = 0;
  do ch = getchar(), neg |= (ch == '-'); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return neg ? -s : s;
}

struct Node{
  string fi, se; bool male, foreign;
  Node() { }
  Node(string fi, string se, bool male, bool foreign):
    fi(fi), se(se), male(male), foreign(foreign) { }
};
map<string, Node> mp;

char s1[100], s2[100], s3[100], s4[100];

int main(void){
  int n = read();
  while(n--){
    scanf("%s%s",s1,s2);
    int n = strlen(s2);
    if(s2[n-1] == 'm'){
      s2[n-1] = 0;
      mp[s1] = Node(s1, s2, true, true);
    }else if(s2[n-1] == 'f'){
      s2[n-1] = 0;
      mp[s1] = Node(s1, s2, false, true);
    }else if(s2[n-1] == 'n'){ // son
      s2[n-4] = 0;
      mp[s1] = Node(s1, s2, true, false);
    }else{  // dottir
      s2[n-7] = 0;
      mp[s1] = Node(s1, s2, false, false);
    }
  }
  n = read();

  while(n--){
    scanf("%s%s%s%s",s1,s2,s3,s4);
    if(mp.find(s1) == mp.end() || mp[s1].se != s2
        || mp.find(s3) == mp.end() || mp[s3].se != s4){
      printf("NA\n"); continue;
    }

    if(mp[s1].male == mp[s3].male){
      printf("Whatever\n");
    }else if(mp[s1].foreign || mp[s3].foreign){
      printf("Yes\n");
    }else{
      Node *p = &mp[s1]; set<string> st;
      for(int i = 0; i < 4; ++i, p = &mp[p->se]){
        st.insert(p->fi);
        if(mp.find(p->se) == mp.end()) break;
      }

      bool bad = 0; p = &mp[s3];
      for(int i = 0; i < 4; ++i, p = &mp[p->se]){
        if(st.find(p->fi) != st.end()){
          bad = 1; break;
        }
        if(mp.find(p->se) == mp.end()) break;
      }
      printf("%s\n", bad ? "No" : "Yes");
    }
  }

  return 0;
}

