/*
双向链表实现
*/
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
#define PB push_back
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=30;
int n, a, b;
struct Block{   // block 编号 1:n
  int fa, son;  // fa=0表示上面无方块，son=0表示下面无方块（即在地上）
}block[MAX];
char cmd1[10], cmd2[10];

void clear(int a){  // clear & put back any block that is above a (not including a)
  /*
  //!!!WRONG!!!
  // 假设 a 上、下分别有方块 fa, sa。则 v 中最先存放 a ，导致 block[a].son = 0
  // 那么在调用 move(a,b) 时，函数会认为 a 已经在地上，不用修改 block[sa].fa 的值
  // 于是在之后的操作中，系统会认为 sa 和 b 的上面都为 a ，导致错误
    VR<int> v; int fa=a;
    while(block[fa].fa){
      v.PB(fa); fa = block[fa].fa;
    }
  */
  // find & store all blocks above a (not including a)
  VR<int> v; int fa=block[a].fa;
  while(fa){
    v.PB(fa); fa = block[fa].fa;
  }
  // clear & put back
  if(v.size()) for(int i : v){
    block[i].fa = block[i].son = 0;
  }

  block[a].fa=0;
}

int top(int a){   //return the topmost block above a
  while(block[a].fa) a = block[a].fa;
  return a;
}

void move(int a, int b){  // pile a onto block b
  if(block[a].son){
    block[ block[a].son ].fa = 0;
  }
  block[a].son = b;
  block[b].fa = a;
}

int main(void){
  scanf("%d",&n);

  while(scanf("%s",cmd1)==1){
    if(cmd1[0]=='q') break;
    scanf("%d %s %d",&a,cmd2,&b);
    a++, b++;
    if(top(a)==top(b)) continue;
    if(cmd1[0]=='m'){
      if(cmd2[1]=='n'){ // move a onto b
        clear(a), clear(b);
        move(a,b);
      }else{  // move a over b
        clear(a);
        move(a,top(b));
      }
    }else{
      if(cmd2[1]=='n'){ // pile a onto b
        clear(b);
        move(a,b);
      }else{  // pile a over b
        move(a,top(b));
      }
    }
  }

  //print
  FORR(i,1,n){
    printf("%d:",i-1);
    if(!block[i].son){  // block i on the ground
      int fa=i;
      while(fa){
        printf(" %d",fa-1);
        fa = block[fa].fa;
      }
    }
    printf("\n");
  }

  return 0;
}


/*
const int MAX=30;
int n, a, b;
int p[MAX]; // p[a] = b: a's father is b, b is on top of a
int base[MAX];  // base[a] = b: number a stack's father is a, a is just above the b's stack' base
char cmd1[10], cmd2[10];

void clear(int a);  // clear & put back any block that is above a
int top(int a);   //return the topmost block above a
void move(int a, int b);  // move block a onto block b

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) base[i]=i;
  while(scanf("s",&cmd1)==1){
    if(cmd1[0]=='q') break;
    scanf("%d%s%d",&a,cmd2,&b);
    a++, b++;
    if(cmd1[0]=='m'){
      if(cmd2[1]=='n'){ // move a onto b
      }else{  // move a over b
      }
    }else{
      if(cmd2[1]=='n'){ // pile a onto b
      }else{  // pile a over b
      }
    }
  }

  //print
  FORR(i,1,n){
    printf("%d:",i-1);
    int fa=base[i];
    while(fa){
      printf(" %d",fa-1);
      fa=p[fa];
    }
    printf("\n");
  }

  return 0;
}

void clear(int a){  //clear & put back any block that is above a
  if(!p[a]) return;
  int fa=p[a]; p[a]=0;  // record what's just above a, & clear a of its parent

  VR<int> v; v.push_back(fa);
  while(fa) v.push_back(fa), fa=p[fa];  // find all blocks above a
  for(i : v) p[i]=0, base[i]=i;         // clear & replace each block
}
int top(int a){   //return the topmost block above a
  int fa=a;
  while(p[fa]) fa=p[fa];
  return fa;
}
void move(int a, int b){  // move block a onto block b (not involving changing base)
  p[b]=a;
}
*/
