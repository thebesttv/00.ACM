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

struct Node{
  int a, e;
  bool operator < (const Node &b) const {
    return e > b.e;
  }
  Node(int a, int e): a(a), e(e) { }
};
VR<Node> f1,f2,f3,f4;

void print(const VR<Node> &f){
  if(f.size()==0) { printf("0 0\n"); return; }
  bool first=1;
  for(const Node &t : f){
    if(first) first=0;
    else putchar(' ');
    printf("%d %d",t.a,t.e);
  }
  putchar('\n');
}

void add(VR<Node> &f1, VR<Node> &f2, VR<Node> &f3){
  int n = f1.size(), m = f2.size();
  int i=0, j=0;
  while(i<n && j<m){
    if(f1[i].e == f2[j].e){
      int a = f1[i].a + f2[j].a;
      if(a) f3.push_back(Node(a,f1[i].e));
      i++, j++;
    }else if(f1[i].e > f2[j].e){
      f3.push_back(f1[i]);
      i++;
    }else{
      f3.push_back(f2[j]);
      j++;
    }
  }
  while(i<n) f3.push_back(f1[i++]);
  while(j<m) f3.push_back(f2[j++]);
}

void mul(VR<Node> &f1, VR<Node> &f2, VR<Node> &f3){
  VR<Node> tf;
  int n = f1.size(), m = f2.size();
  FOR(i,0,n) FOR(j,0,m){
    int a = f1[i].a * f2[j].a;
    int e = f1[i].e + f2[j].e;
    tf.push_back(Node(a,e));
  }
  sort(tf.begin(), tf.end());
#ifdef DEBUG
  printf("ori: "); print(tf);
#endif

  if(!tf.size()) return;  // <b> </b>
  int a = tf[0].a, e = tf[0].e;
  FOR(i,1,tf.size()){
    if(e == tf[i].e){
      a += tf[i].a;
    }else{
      if(a) f3.push_back(Node(a,e));
      a = tf[i].a, e = tf[i].e;
    }
  }
  if(a) f3.push_back(Node(a,e));
}

int main(void){
  int n,m,a,e;
  scanf("%d",&n);
  FOR(i,0,n){
    scanf("%d%d",&a,&e);
    if(a) f1.push_back(Node(a,e));
  }
  sort(f1.begin(),f1.end());

  scanf("%d",&m);
  FOR(i,0,m){
    scanf("%d%d",&a,&e);
    if(a) f2.push_back(Node(a,e));
  }
  sort(f2.begin(),f2.end());
#ifdef DEBUG
  print(f1); print(f2);
#endif

  mul(f1,f2,f3);
  print(f3);

  add(f1,f2,f4);
  print(f4);

  return 0;
}
