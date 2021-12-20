/*
描述
在一个果园里，多多已经将所有的果子打了下来，而且按果子的不同种类分成了不同的堆。多多决定把所有的果子合成一堆。
每一次合并，多多可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。可以看出，所有的果子经过n-1次合并之后，就只剩下一堆了。多多在合并果子时总共消耗的体力等于每次合并所耗体力之和。
因为还要花大力气把这些果子搬回家，所以多多在合并果子时要尽可能地节省体力。假定每个果子重量都为1，并且已知果子的种类数和每种果子的数目，你的任务是设计出合并的次序方案，使多多耗费的体力最少，并输出这个最小的体力耗费值。
例如有3种果子，数目依次为1，2，9。可以先将1、2堆合并，新堆数目为3，耗费体力为3。接着，将新堆与原先的第三堆合并，又得到新的堆，数目为12，耗费体力为12。所以多多总共耗费体力=3+12=15。可以证明15为最小的体力耗费值。

格式
输入格式
输入包括两行，第一行是一个整数n(1<＝n<=10000)，表示果子的种类数。第二行包含n个整数，用空格分隔，第i个整数ai(1<＝ai<=20000)是第i种果子的数目。

输出格式
输出包括一行，这一行只包含一个整数，也就是最小的体力耗费值。输入数据保证这个值小于2^31。

样例1
样例输入1
3 
1 2 9

样例输出1
15 

限制
每个测试点1s

来源
NOIp 2004
*/

/*
  得分：100
  解题报告
    贪心。
    可以看出，任意合并树都为正则二叉树，即每个节点要么有两个子树，要么没有子树。
    对于每棵合并树，其总体力消耗 S
      = 所有非叶子节点之和
      = 所有非根节点之和
      = sum{ ai*d8 | i为叶节点，ai为其值，di为其到根节点距离 }
    
  贪心证明：
    1.在最优合并树中，最小的两个叶子节点一定是最深且在一起的。
      设ax,ay为最小的两个叶子，ai,aj为其他任意两个在一起的叶子，d1和d2分别为ax,ay和ai,aj到根节点的距离，则
        s1=d1*(ax+ay) + d2*(ai+aj)
        s2=d2*(ax+ay) + d1*(ai+aj)
        s1-s2=(d1-d2)(ax+ay-ai-aj)
        因为d1>=d2，ax+ay<=ai+aj
        所以s1<=s2
        得证。
    2.将最小的两个叶子去掉后还是最优合并树
      反证法：
        令 T 为 n 个叶子节点的最优合并树
           T' 为 T 去掉两个最小叶子的有 n-1 个叶子节点的树
           T* 为有 n-1 个叶子节点的最优合并树
        所以
          WT=WT'+a1+a2
          WT*<WT' -> WT*+a1+a2 < WT'+a1+a2
        即
          WT*+a1+a2 < WT
        而因为T为最优合并树，所以矛盾，原命题成立。
*/

//一种机智的做法：插入负值
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

priority_queue<int> q;

int main(void){
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++){
    int t; scanf("%d",&t);
    q.push(-t);
  }
  int ans=0;
  while(!q.empty()){
    int t=q.top(); q.pop();
    if(q.empty()) break;
    t+=q.top(); q.pop();
    ans+=-t; q.push(t); //s=所有非根节点之和
  }
  printf("%d\n",ans);

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct Node{
  int n;

  Node();
  Node(int n_): n(n_) { }
  bool operator < (const Node & b) const {
    return n>b.n;
  }
};
priority_queue<Node> q;

int main(void){
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++){
    int t; scanf("%d",&t);
    q.push(Node(t));
  }
  int ans=0;
  while(!q.empty()){
    Node t=q.top(); q.pop();
    if(q.empty()) break;
    t.n+=q.top().n; q.pop();
    ans+=t.n; q.push(t);
  }
  printf("%d\n",ans);

  return 0;
}
*/
