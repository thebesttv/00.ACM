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

const int MAX=120;
int n; char s[MAX];
int f[MAX][MAX],g[MAX][MAX],r[MAX][MAX];
struct Node{
  string s;
  int rep;
  Node() { }
  Node(string s, int rep): s(s), rep(rep) { }
  bool operator < (const Node &b) const {
    return rep!=b.rep ? rep<b.rep : s<b.s;
  }
};
int cnt=0;
map<Node,int> mp;
Node v[MAX*MAX];
int id(Node &t){
  if(mp.count(t)) return mp[t];
  mp[t]=++cnt; v[cnt]=t;
  return cnt;
}

int main(void){
  while(scanf("%s",s+1)==1){
    mp.clear(); MST(f,0x3f);
    n = strlen(s+1);
    FORR(i,1,n){
      char ts[2]={s[i],0};
      f[i][i]=1; r[i][i]=0;
      g[i][i]=id(Node(string(ts),1));
    }
    FORR(l,2,n) FORR(i,1,n-l+1){
      int j=i+l-1;
      int &a=f[i][j];
      FOR(k,i,j){
        if(v[g[i][k]].s == v[g[k+1][j]].s){
          if(a>f[i][k]){
            a = f[i][k]; r[i][j] = k;
            g[i][j] = id(Node(v[g[i][k]].s,
                  v[g[i][k]].rep + v[g[k+1][j]].rep));
          }
        }else{
          int t = f[i][k] + f[k+1][j];
          if(a>t){
            a = t; r[i][j]=k;
            g[i][j] = id(Node(v[g[i][k]].s + v[g[
        }
      }
    }
  }

  return 0;
}

















































/*
const int MAX=104;
int n; char s[MAX];
int f[MAX][MAX],g[MAX][MAX];
struct Node{
  string s; int rep;
  Node(string s, int rep): s(s), rep(rep) { }
  bool operator < (const Node &b) const {
    return s!=b.s ? s<b.s : rep<b.rep;
  }
};
map<Node,int> mp;

int cnt=0;
Node v[MAX*MAX];
int id(const string &s){
  if(mp.count(s)) return mp[s];
  else{
    mp[s]=++cnt; v[cnt]=s;
    return cnt;
  }
}

void print(int l, int r){
  if(l==r){
    cout << v[g[l][r]]; return;
  }
}

int main(void){
  while(scanf("%s",s)==1){
    MST(f,0x3f); mp.clear(); cnt=0;
    n = strlen(s+1);
    FORR(i,1,n){
      char ts[2]; ts[0]=s[i]; ts[1]=0;
      f[i][i]=1;
      g[i][i]=id(Node(string(ts),1));
    }
    FORR(l,2,n) FORR(i,1,n-l+1){
      int j=i+l-1;
      FOR(k,i,j){
        if(g[i][k]!=g[k+1][j]){
          int t = f[i][k]+f[k+1][j];
          if(f[i][j]>t){
            //string ts = v[g[i][k]].s + v[g[i
            f[i][j]=t; g[i][j]=id(v[g[i][k]] + v[g[k+1][j]]);
          }
        }else{
          if(f[i][j]>f[i][k]){
            f[i][j]=f[i][k]; g[i][j]=g[i][k];
          }
        }
      }
    }
    FORR(i,1,n) FORR(j,i,n){
      printf("f[%d][%d]: %d, g: ",i,j,f[i][j]);
      cout << v[g[i][j]] << endl;
    }
    //printf("%d\n",f[1][n]);
    //print(1,n);
  }

  return 0;
}
*/
