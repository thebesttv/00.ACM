/*
题目描述
小明正在学习一种新的编程语言 A++，刚学会循环语句的他激动地写了好多程序并 给出了他自己算出的时间复杂度，可他的编程老师实在不想一个一个检查小明的程序， 于是你的机会来啦！下面请你编写程序来判断小明对他的每个程序给出的时间复杂度是否正确。

A++语言的循环结构如下：
  F i x y
    循环体
  E

其中F i x y表示新建变量 i（变量 i 不可与未被销毁的变量重名）并初始化为 x， 然后判断 i 和 y 的大小关系，若 i 小于等于 y 则进入循环，否则不进入。每次循环结束后 i 都会被修改成 i+1，一旦 i 大于 y 终止循环。
x 和 y 可以是正整数（x 和 y 的大小关系不定）或变量 n。n 是一个表示数据规模的变量，在时间复杂度计算中需保留该变量而不能将其视为常数，该数远大于 100。
“E”表示循环体结束。循环体结束时，这个循环体新建的变量也被销毁。
注：本题中为了书写方便，在描述复杂度时，使用大写英文字母“O”表示通常意义下“Θ”的概念。

输入输出格式
输入格式：
输入文件第一行一个正整数 t，表示有 t（t≤10）个程序需要计算时间复杂度。 每个程序我们只需抽取其中 F i x y和E即可计算时间复杂度。注意：循环结构 允许嵌套。
接下来每个程序的第一行包含一个正整数 L 和一个字符串，L 代表程序行数，字符 串表示这个程序的复杂度，O(1)表示常数复杂度，O(n^w)表示复杂度为nw，其 中w是一个小于100的正整数（输入中不包含引号），输入保证复杂度只有O(1)和O(n^w) 两种类型。
接下来 L 行代表程序中循环结构中的F i x y或者 E。 程序行若以F开头，表示进入一个循环，之后有空格分离的三个字符（串）i x y， 其中 i 是一个小写字母（保证不为n），表示新建的变量名，x 和 y 可能是正整数或 n，已知若为正整数则一定小于 100。
程序行若以E开头，则表示循环体结束。

输出格式：
输出文件共 t 行，对应输入的 t 个程序，每行输出Yes或No或者ERR（输出中不包含引号），若程序实际复杂度与输入给出的复杂度一致则输出Yes，不一致则输出No，若程序有语法错误（其中语法错误只有: ① F 和 E 不匹配 ②新建的变量与已经存在但未被销毁的变量重复两种情况），则输出ERR 。
注意：即使在程序不会执行的循环体中出现了语法错误也会编译错误，要输出 ERR。

输入输出样例
输入样例#1：
8 
2 O(1) 
F i 1 1 
E 
2 O(n^1) 
F x 1 n 
E 
1 O(1) 
F x 1 n 
4 O(n^2) 
F x 5 n 
F y 10 n 
E 
E 
4 O(n^2) 
F x 9 n 
E 
F y 2 n 
E 
4 O(n^1) 
F x 9 n 
F y n 4 
E 
E 
4 O(1) 
F y n 4 
F x 9 n 
E 
E 
4 O(n^2) 
F x 1 n 
F x 1 10 
E 
E

输出样例#1：
Yes
Yes 
ERR 
Yes 
No 
Yes 
Yes 
ERR

样例解释1
第一个程序 i 从 1 到 1 是常数复杂度。
第二个程序 x 从 1 到 n 是 n 的一次方的复杂度。
第三个程序有一个 F 开启循环却没有 E 结束，语法错误。
第四个程序二重循环，n 的平方的复杂度。
第五个程序两个一重循环，n 的一次方的复杂度。
第六个程序第一重循环正常，但第二重循环开始即终止（因为n远大于100，100大于4）。
第七个程序第一重循环无法进入，故为常数复杂度。
第八个程序第二重循环中的变量 x 与第一重循环中的变量重复，出现语法错误②，输出 ERR。

数据规模与约定
对于 30%的数据：不存在语法错误，数据保证小明给出的每个程序的前 L/2 行一定为以 F 开头的语句，第 L/2+1 行至第 L 行一定为以 E 开头的语句，L≤10，若 x、y 均 为整数，x 一定小于 y，且只有 y 有可能为 n。
对于50%的数据：不存在语法错误，L≤100，且若 x、y 均为整数，x 一定小于 y， 且只有 y 有可能为 n。
对于70%的数据：不存在语法错误，L≤100。
对于100%的数据：L≤100。
*/

/*
  得分：100
  解题报告：
    很变态的模拟，不过也算是D1的签到题了……
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

const int MAX=220;
const int TAG=10000;  //n
int L,w,ansMax;
char t1[MAX];
struct Node{
  bool isEnd;
  char ch;
  int l,r;
  int toEnd;
}node[MAX],cEnd;
int tail=0;
int st[MAX],top;
bool visN[MAX],visC[256];

inline void init(){
  tail=1; ansMax=0; top=0;
  MST(visN,0); MST(visC,0);
}
void read(){
  scanf("%d%s",&L,t1);
  if(!strchr(t1,'n')) w=0;
  else{
    char *p = strtok(t1,"O(n^)");
    w = atoi(p);
  }

  int type,ch,l,r;
  FOR(i,0,L){
    do type=getchar(); while(!isalpha(type));
    if(type=='E') node[tail++]=cEnd;
    else{ //F
      do ch=getchar(); while(!isalpha(ch));
      scanf("%s",t1);
      if(t1[0]=='n') l=TAG;
      else l=atoi(t1);
      scanf("%s",t1);
      if(t1[0]=='n') r=TAG;
      else r=atoi(t1);
      node[tail++] = (Node){0,ch,l,r,0};
    }
  }
}
bool check(){
  FOR(i,1,tail){
    const Node & t=node[i];
    if(t.isEnd){  //E
      if(!top) return false;  //<b> </b>
      int u=st[--top];
      node[u].toEnd=i;
      visC[node[u].ch]=0; //销毁变量
    }else{  //F
      if(visC[t.ch]) return false;
      visC[t.ch]=1; st[top++]=i;
    }
  }
  return top==0;  //判断 F 和 E 是否匹配
}
void dfs(int cur, int cnt){
#ifdef DEBUG
  printf("  dfs(%d,%d)\n",cur,cnt);
#endif
  visN[cur]=1;
  Node & t=node[cur];
  ansMax=max(ansMax,cnt);

  if(t.isEnd) return;
  FORR(i,cur+1,t.toEnd) if(!visN[i]){
    Node & tt=node[i];
    if(tt.l<TAG && tt.r<TAG){ //[l:r] or end
      if(tt.l<=tt.r) dfs(i,cnt);
      else FORR(j,i,tt.toEnd) visN[j]=1;  //<b><b> </b></b>
    }else if(tt.l<TAG && tt.r==TAG){  //[l:n]
      dfs(i,cnt+1);
    }else if(tt.l==TAG && tt.r==TAG){ //[n:n]
      dfs(i,cnt);
    }else{  //[n:r], don't enter
      FORR(j,i,tt.toEnd) visN[j]=1;  //<b> </b>
    }
  }
}

int main(void){
  cEnd.isEnd=1;
  int T; scanf("%d",&T);
  while(T--){
    init(); read();

    if(!check()) {printf("ERR\n"); continue;}
#ifdef DEBUG
    FOR(i,1,tail){
      Node & t=node[i];
      printf("  node[%d]: {%d,%c,%d,%d,%d}\n",i,t.isEnd,t.ch,t.l,t.r,t.toEnd);
    }
#endif

    node[0].toEnd=tail-1;
    dfs(0,0);

    printf("%s\n", ansMax==w ? "Yes" : "No" );
  }

  return 0;
}
