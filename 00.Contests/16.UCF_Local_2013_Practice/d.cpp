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

struct Node{
  VR<string> pn,ea;
};
map<pair<string,string>,Node*> mp;

bool isMail(string &s){
  for(char c : s) if(c=='@')
    return true;
  return false;
}

void insert(string fn, string ln, string pn, string ea){
#ifdef DEBUG
  cout << "insert " << fn +" " + ln + " " + pn + " " + ea + "\n";
#endif
  auto &p = mp[{ln,fn}];
  if(!p) p = new Node;
  if(pn.size()) p->pn.push_back(pn);
  if(ea.size()) p->ea.push_back(ea);
}

void printPN(string &s){
  printf("(%c%c%c)%c%c%c-%c%c%c%c\n",
      s[0],s[1],s[2],s[3],s[4],s[5],s[6],s[7],s[8],s[9]);
}

int main(void){
  int n,kase=0;
  while(scanf("%d",&n) && n){
    string fn,ln,s;
    mp.clear();
    while(n--){
      cin >> fn >> ln >> s;
      if(isMail(s)){
        insert(fn,ln,string(),s);
      }else{
        insert(fn,ln,s,string());
      }
    }
    printf("Contact list #%d:\n",++kase);
    for(auto p : mp){
      cout << p.FI.SE << " " << p.FI.FI << "\n";
      VR<string> &pn = p.SE->pn;
      VR<string> &ea = p.SE->ea;
      sort(ALL(pn)); sort(ALL(ea));
      cout << "Phone:\n";
      for(auto s : pn) printPN(s);
      cout << "E-Mail:\n";
      for(auto s : ea) cout << s << "\n";
      cout << "###\n";
    }
    printf("\n");
  }

  return 0;
}
