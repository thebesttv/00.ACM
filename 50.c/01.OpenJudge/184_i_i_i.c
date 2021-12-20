/*
描述
动物王国中有三类动物A,B,C，这三类动物的食物链构成了有趣的环形。A吃B， B吃C，C吃A。
现有N个动物，以1－N编号。每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。
有人用两种说法对这N个动物所构成的食物链关系进行描述：
第一种说法是"1 X Y"，表示X和Y是同类。
第二种说法是"2 X Y"，表示X吃Y。
此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，否则就是真话。
  1. 当前的话与前面的某些真的话冲突，就是假话；
  2. 当前的话中X或Y比N大，就是假话；
  3. 当前的话表示X吃X，就是假话。
你的任务是根据给定的N（1 <= N <= 50,000）和K句话（0 <= K <= 100,000），输出假话的总数。

输入
第一行是两个整数N和K，以一个空格分隔。
以下K行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中D表示说法的种类。
若D=1，则表示X和Y是同类。
若D=2，则表示X吃Y。

输出
只有一个整数，表示假话的数目。

样例输入
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5

样例输出
3
*/

/*
  解题报告（从洛谷同题搬运）：
    我的天，终于AC了。
    使用图来表示 A,B,C 之间的关系，若 x->y，表示x吃y，则有图
      -> A -> B -> C -> （前后两个箭头表示循环）
    依旧是使用并查集，又因为x在A,B,C是相对不确定的，那么令 x, x+n, x+2n 组成一个与 A,B,C 相同的食物链，即
      -> x -> x+n -> x+2n ->
    在个体x的基础上再引进个体 y，可根据 x与y,y+n,y+2n 的关系构建三张关系图：
      1. -> x, y -> x+n, y+n -> x+2n, y+2n -> // p[x]=p[y]
      2. -> x, y+n -> x+n, y+2n -> x+2n, y -> // p[x]=p[y+n]
      3. -> x, y+2n -> x+n, y -> x+2n, y+n -> // p[x]=p[y+2n]
    那么就可根据这三个相对关系来解题了。
    而在判断时，因为x和y之间的关系可能还没确定，不能简单根据x,y是否满足指定关系判断，而是要判断x,y是否<b>不满足其他任意关系</b>。
    对两种断言：
      断言x与y是同类，即关系1
        反着判断，即x不能吃y且y不能吃x。因为x吃y是关系3、y吃x是关系2，那么就只要从关系2,3中每个任取一个判断即可。
        即只需判断 (1) p[x]!=p[y+n] 或 p[x+n]!=p[y+2n] 或 p[x+2n]!=p[y]；
                   (2) p[x]!=p[y+2n] 或 p[x+n]!=p[y] 或 p[x+2n]!=p[y+n]。
        其实也就是判断x,y是否满足：两者并非关系2且并非关系3。
      断言x吃y，即关系3
        反着判断，即x不能与y是同类（即非关系1）且y不能吃x（即非关系2）。有了之前的经验，只需判断
          (1) p[x]!=p[y] 或 ... 或 ...
          (2) p[x]!=p[y+n] 或 ... 或 ...
      如果不能判断断言为假，则断言必须为正，那么只要更具断言指示的某个关系进行三次merge即可。
      注：判断只需一个关系的三分之一，但merge一定要一个关系的全部三个。
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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=50020;
int n,m,p[MAX*3];

inline int find(int x){
  return p[x]<0 ? x : p[x]=find(p[x]);
}
inline bool same(int x, int y){
  return find(x)==find(y);
}
void merge(int x, int y){
  x=find(x),y=find(y);
  if(x==y) return;
  if(p[x]<p[y]){
    p[x]+=p[y]; p[y]=x;
  }else{
    p[y]+=p[x]; p[x]=y;
  }
}

int main(void){
  MST(p,-1);
  scanf("%d%d",&n,&m);
  int cnt=0;
  int d,x,y;
  FOR(i,0,m){
    scanf("%d%d%d",&d,&x,&y);
    if(x<1 || x>n || y<1 || y>n) {cnt++; continue;}
    if(d==2 && x==y) {cnt++; continue;}
    if(d==1){
      if(same(x,y+n) || same(x+n,y)) cnt++;
      else {merge(x,y); merge(x+n,y+n); merge(x+2*n,y+2*n);}
    }else{  //x吃y
      if(same(x,y) || same(x,y+n)) cnt++;
      else {merge(x,y+2*n); merge(x+n,y); merge(x+2*n,y+n);}
    }
  }
  printf("%d\n",cnt);

  return 0;
}
/*
const int MAX=50000+10;
int p[MAX],r[MAX],tot=0;

int getParent(int n);
void merge(int d, int x, int y);

int main(void){
  memset(p,-1,sizeof(p)); memset(r,0,sizeof(r));
    //r[i]表示i和i的父节点（即pi）之间的关系
    //r[i]==0:i和pi同类
    //r[i]==1:i被pi吃
    //r[i]==2:i吃pi
  int n,k; scanf("%d%d",&n,&k);
  int d,x,y;
  for(int i=0;i<k;i++){
    scanf("%d%d%d",&d,&x,&y);
    if(x>n || y>n || (d==2 && x==y)) tot++;
    else{
      int px=getParent(x),py=getParent(y);
      if(px==py){ //即x、y之间有确定关系
        if(d==1 && r[x]!=r[y]) tot++;
        else if(d==2 && r[y]!=(r[x]+1)%3) tot++;
        //r[x]==0 -> r[y]==1
        //r[x]==1 -> r[y]==2
        //r[x]==2 -> r[y]==0
      }else{
        merge(d,x,y);
      }
    }
  }
  printf("%d\n",tot);

  return 0;
}

int getParent(int x){
  if(p[x]<0) return x;
  else{
    int t=p[x];
    p[x]=getParent(p[x]); //顺序不能反
    r[x]=(r[x]+r[t])%3;   //先更新r[p[x]]，再根据r[p[x]]更新r[x]
    return p[x];
  }
}
void merge(int d, int x, int y){
  int px=getParent(x),py=getParent(y);
  p[py]=px; //将y的树接到x的树上
  r[py]=(3-r[y] + d-1 + r[x])%3;
    //py--(3-r[y])%3-->y
    // y--(d-1)-->x
    // x--r[x]-->px
}
*/
