/*
There is an apple tree outside of kaka's house. Every autumn, a lot of apples will grow in the tree. Kaka likes apple very much, so he has been carefully nurturing the big apple tree.

The tree has N forks which are connected by branches. Kaka numbers the forks by 1 to N and the root is always numbered by 1. Apples will grow on the forks and two apple won't grow on the same fork. kaka wants to know how many apples are there in a sub-tree, for his study of the produce ability of the apple tree.

The trouble is that a new apple may grow on an empty fork some time and kaka may pick an apple from the tree for his dessert. Can you help kaka?

Input
The first line contains an integer N (N ≤ 100,000) , which is the number of the forks in the tree.
The following N - 1 lines each contain two integers u and v, which means fork u and fork v are connected by a branch.
The next line contains an integer M (M ≤ 100,000).
The following M lines each contain a message which is either
"C x" which means the existence of the apple on fork x has been changed. i.e. if there is an apple on the fork, then Kaka pick it; otherwise a new apple has grown on the empty fork.
or
"Q x" which means an inquiry for the number of apples in the sub-tree above the fork x, including the apple (if exists) on the fork x
Note the tree is full of apples at the beginning

Output
For every inquiry, output the correspond answer per line.

Sample Input
3
1 2
1 3
3
Q 1
C 2
Q 1

Sample Output
3
2
*/

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

const int MAX=100020;
int n,m;
struct Edge{
  int u,v,next;
}edge[MAX<<1];
int se[MAX],tailE=1;
int ts=0; //dfs计数
bool ava[MAX];  //ava[i]: 节点i是否有果子
struct Node{
  int l,r;  //两次dfs序
}node[MAX];
struct ST{  //树状数组
  int n,s[MAX<<1];
  
  void init(int n_) {n=n_;}
  void add(int x, int v){
    while(x<=n){
      s[x]+=v; x+=x&-x;
    }
  }
  int sum(int x){
    int ans=0;
    while(x){
      ans+=s[x]; x-=x&-x;
    }
    return ans;
  }
  int sum(int l, int r){  //求区间[l,r]和
    return sum(r)-sum(l-1);
  }
}st;

inline void addEdge(int u, int v){
  edge[tailE]=(Edge){u,v,se[u]}; se[u]=tailE++;
}
void dfs(int u){
  Node &t=node[u];
  t.l=++ts;
  for(int i=se[u];i;i=edge[i].next){
    Edge &e=edge[i];
    if(node[e.v].l) continue;
    dfs(e.v);
  }
  t.r=++ts;
}

int main(void){
  scanf("%d",&n);
  int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    addEdge(u,v); addEdge(v,u);
  }
  dfs(1);

  st.init(node[1].r);
  FORR(i,1,n){
    st.add(node[i].l,1);
    ava[i]=1;
  }

  scanf("%d",&m);
  int ch,x;
  FOR(i,0,m){
    do ch=getchar(); while(ch!='Q' && ch!='C');
    scanf("%d",&x);
    if(ch=='Q') printf("%d\n",st.sum(node[x].l,node[x].r));
    else{
      if(ava[x]){
        ava[x]=0; st.add(node[x].l,-1); //<b> 对dfs序修改 </b>
      }else{
        ava[x]=1; st.add(node[x].l,1);
      }
    }
  }

  return 0;
}
