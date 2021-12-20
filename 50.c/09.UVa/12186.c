#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=100020;
int n,t;
vector<int> son[MAX];

int f(int u){
  if(!son[u].size()) return 1;
  int a=0;
  VR<int> v;
  FOR(i,0,son[u].size()) v.push_back(f(son[u][i]));
  sort(v.begin(),v.end());
  int tot=ceil(t*son[u].size()/100.0);
  FOR(i,0,tot) a+=v[i];
  return a;
}

int main(void){
  while(scanf("%d%d",&n,&t)==2 && n){
    FORR(i,0,n) son[i].clear();
    for(int i=1,tt;i<=n;i++){
      scanf("%d",&tt); son[tt].push_back(i);
    }
    printf("%d\n",f(0));
  }

  return 0;
}

/*
const int MAX=100020;
int p[MAX],check[MAX];
int n,t;

int f(int u){
  int & a=check[u];
  if(a!=-1) return a;
  a=0; int cnt=0;
  vector<int> v;
  FORR(i,1,n) if(p[i]==u){
    cnt++; v.push_back(f(i));
  }
  sort(v.begin(),v.end());
  int tot=ceil(t*cnt/100.0);
  //int tot=(t*cnt-1)/100+1;
  FOR(i,0,tot) a+=v[i];
  if(!cnt) a=1;
  return a;
}

int main(void){
  while(scanf("%d%d",&n,&t)==2 && n){
    FORR(i,1,n) scanf("%d",&p[i]);
    MST(check,-1);
    printf("%d\n",f(0));
  }

  return 0;
}
*/
