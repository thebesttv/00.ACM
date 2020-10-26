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
typedef pair<int,int> pii;

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

void read(VR<string> &v){
  char s[20];
  while(true){
    scanf("%s",s); int n = strlen(s);
    if(!isalpha(s[n-1])){
      s[n-1] = 0; v.pb(s); return;
    }else v.pb(s);
  }
}

bool ok(VR<string> &v){
  const string &s = v.back();
  int n = s.size();
  return n >= 3 && s[n-3] == 'o' && s[n-2] == 'n' && s[n-1] == 'g';
}

void print(VR<string> &v, const char *str){
  bool first = true;
  for(auto &s : v){
    if(first) first = false;
    else putchar(' ');
    printf("%s",s.c_str());
  }
  printf("%s",str);
}

int main(void){
  int n = read();
  while(n--){
    VR<string> v1, v2;
    read(v1), read(v2);
    if(ok(v1) && ok(v2)){
      print(v1, ", ");
      v2[v2.size()-3] = "qiao";
      v2[v2.size()-2] = "ben";
      v2[v2.size()-1] = "zhong";
      print(v2, ".\n");
    }else printf("Skipped\n");
  }

  return 0;
}

