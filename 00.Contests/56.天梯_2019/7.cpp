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

const int st[2][2] = {{130, 27}, {129, 25}};
int s, h, m;

int main(void){
  int n = read();
  while(n--){
    s = read(), h = read(), m = read();
    const int *v;
    if(s == 1){ // boy
      v = st[0];
    }else{  // girl
      v = st[1];
    }

    if(h < v[0]){
      printf("duo chi yu!");
    }else if(h > v[0]){
      printf("ni li hai!");
    }else{
      printf("wan mei!");
    }
    putchar(' ');

    if(m < v[1]){
      printf("duo chi rou!\n");
    }else if(m > v[1]){
      printf("shao chi rou!\n");
    }else{
      printf("wan mei!\n");
    }
  }

  return 0;
}

