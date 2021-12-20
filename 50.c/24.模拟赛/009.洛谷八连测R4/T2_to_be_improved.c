/*
题目描述
给定一个长度为偶数的排列 p，你每次可以选取 p 排列中相邻的两个元素，假如分别是 x 和 y，那 么把 x 和 y 加入一个序列 q 的末尾，并将 x 和 y 从排列 p 中删除。重复上述过程，直到 p 中没有元素， 显然最终 q 序列也是一个排列。例如 p = (1, 3, 2, 4)，第一次可以选取 3, 2 这两个元素加入 q，并且从 p 中删除，此时 p = (1, 4)，第二次可以选取 1, 4 这两个元素加入 q，此时 p 为空，q = (3, 2, 1, 4)。观察上 述过程，最终 q 序列可能会有很多方案，请你输出所有可能方案中，q 的字典序最大的。
字典序的比较方式如下，假设有两个长度同为 n 的序列 a, b。我们找到最大的 t，使得对于 ∀i ≤ t， ai = bi。之后比较 a[t+1] 与 b[t+1]，如果 a[t+1] < b[t+1]，我们就认为 a 的字典序比 b 小，反之亦然。

输入输出格式
输入格式：
第一行包含一个正整数 n。第二行 n 个数，表示排列 p。

输出格式：
一行 n 个数，表示字典序最大的序列 q。

输入输出样例
输入样例#1：
4 
3 1 4 2

输出样例#1：
4 2 3 1

输入样例#2：
6 
6 5 4 1 3 2

输出样例#2：
6 5 4 1 3 2

说明
测试点编号   限制与约束
1,2          n<=10
3,4,5,6      n<=10^3
7,8,9,10     n<=10^5
*/

/*
  得分：100
  解题报告：
    没想到贪心竟然对了。（不过好像正确性很显然的样子。。。）
    每次在剩下的数组中找到字典序最大的一对，取出并输出即可。
    但维护这个数据结构不容易。我用了一个数组和一个同步更新的优先队列写了几遍才写得差不多。数组用的是类似双向链表的存储方法，同时使用ill数组判断数组中序号为i的节点是否无效。
    突然发现，我这个方法用了7.09MB的内存，题目规定最大8MB，好险啊。
  正解：
    因为p是一个排列，所有没有重复的数字，贪心时只需每次寻找最大的数（不在末尾）即可。
    那么数据结构需要支持的操作有两个：
      1.查找区间中最大的数的位置
      2.删除两个数
    [1]线段树
    [2]链表 O(n)
      因为n<=10^5，可以通过记录每个数的位置，从而用O(1)的时间找到最大数的位置
      用wh[i]表示数字i在排列中的位置，vis[i]表示i是否被删除过
      每次寻找vis[i]=0的最大i（i不能在可行排列的末尾），输出i以及i右边的元素，并在链表中将两个都删除即可。
      发现整个寻找其实是一次n:1的遍历，因此可以在遍历vis[n:1]的同时计算出答案，复杂度即为O(n)。
      如果n<=10^9则还需要离散化。
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



/*
//链表
const int MAX=100020;
int n,pos[MAX]; //pos[i]: 数字i在链表中的位置
bool vis[MAX];  //vis[i]: 数字i是否被访问过
struct Node{
  int n;
  int l,r;
}node[MAX];
bool first=1;

bool print(int l){
  int r=node[l].r; if(r==-1) return false;

  if(!first) putchar(' ');
  else first=0;
  printf("%d %d",node[l].n,node[r].n);
  vis[node[l].n]=1; vis[node[r].n]=1;

  if(node[l].l!=-1) node[node[l].l].r=node[r].r;
  node[node[r].r].l=node[l].l;
  return true;
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n){
    int t; scanf("%d",&t);
    node[i].n=t; pos[t]=i;
    node[i].l=i-1; node[i].r=i+1;
    if(i==0) node[i].l=-1; else if(i==n-1) node[i].r=-1;
  }
  int p=n+1,t=n>>1;
  FOR(i,0,t){
    do{
      p--;
      while(vis[p]) p--;
    }while(!print(pos[p]));
  }
  printf("\n");

  return 0;
}
*/

/*
const int MAX=100020;
struct Node{
  int l,r;
  int n,ln,rn;
  bool operator < (const Node & b) const {return l!=b.l ? l<b.l : r<b.r;}
}rec[MAX<<1];
PQ<Node> q;
int n,tail,a[MAX];
bool ill[MAX<<1];

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&a[i]);
  FOR(i,1,n){
    Node t; t.l=a[i-1]; t.r=a[i];
    t.n=tail++; t.ln=t.n-1; t.rn=t.n+1;
    if(i==1) t.ln=-1; else if(i==n-1) t.rn=-1;
    rec[t.n]=t; q.push(t);
  }

  bool first=1; int cnt=0;
  while(!q.empty()){
    Node t=q.top(); q.pop();
    if(ill[t.n]) continue;
    if(!first) printf(" %d %d",t.l,t.r);
    else {printf("%d %d",t.l,t.r); first=0;}
    //cnt+=2; if(cnt==n) break;

    int n=t.n;
    ill[n]=1;
#ifdef DEBUG
    printf(" ***l: %d, r: %d, n: %d, ln: %d, rn: %d ***\n",rec[n].l,rec[n].r,n,rec[n].ln,rec[n].rn);
#endif

    //t.n=tail++;
    //ill[rec[n].ln]=1; ill[rec[n].rn]=1;
    //t.l=rec[rec[n].ln].l; t.r=rec[rec[n].rn].r;
    //t.ln=rec[rec[n].ln].ln;
    //t.rn=rec[rec[n].rn].rn;
    //rec[t.ln].rn=t.n; rec[t.rn].ln=t.n;
    //rec[t.n]=t; q.push(t);

    if(rec[n].ln==-1 || rec[n].rn==-1) t.n=-1;
    else t.n=tail++;

    if(rec[n].ln!=-1){
      ill[rec[n].ln]=1;
      t.l=rec[rec[n].ln].l;
      t.ln=rec[rec[n].ln].ln;
      if(t.ln!=-1){
        rec[t.ln].rn=t.n;
      }
    }
    if(rec[n].rn!=-1){
      ill[rec[n].rn]=1;
      t.r=rec[rec[n].rn].r;
      t.rn=rec[rec[n].rn].rn;
      if(t.rn!=-1){
        rec[t.rn].ln=t.n;
      }
    }
    if(t.n!=-1){
      rec[t.n]=t; q.push(t);
#ifdef DEBUG
    printf("create ***l: %d, r: %d, n: %d, ln: %d, rn: %d ***\n",t.l,t.r,t.n,t.ln,t.rn);
#endif
    }
  }
  putchar('\n');

  return 0;
}
*/
