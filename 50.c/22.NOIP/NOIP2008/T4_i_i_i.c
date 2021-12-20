/*
描述
Tom最近在研究一个有趣的排序问题。通过2个栈S1和S2，Tom希望借助以下4种操作实现将输入序列升序排序。
  操作a 如果输入序列不为空，将第一个元素压入栈S1
  操作b 如果栈S1不为空，将S1栈顶元素弹出至输出序列
  操作c 如果输入序列不为空，将第一个元素压入栈S2
  操作d 如果栈S2不为空，将S2栈顶元素弹出至输出序列
如果一个1~n的排列P可以通过一系列操作使得输出序列为1，2，…，(n-1)，n，Tom就称P是一个“可双栈排序排列”。例如(1,3,2,4)就是一个“可双栈排序序列”，而(2,3,4,1)不是。
将(1,3,2,4)排序的操作序列：<a,c,c,b,a,d,d,b>
当然，这样的操作序列有可能有几个，对于上例(1,3,2,4)，<a,c,c,b,a,d,d,b>是另外一个可行的操作序列。
Tom希望知道其中字典序最小的操作序列是什么。

格式
输入格式
第一行是一个整数n。
第二行有n个用空格隔开的正整数，构成一个1~n的排列。

输出格式
输出文件共一行，如果输入的排列不是“可双栈排序排列”，输出数字0；
否则输出字典序最小的操作序列，每两个操作之间用空格隔开，行尾没有空格。

样例1
样例输入1
4
1 3 2 4

样例输出1
a b a a b b a b

限制
1s

提示
30%的数据满足： n<=10
50%的数据满足： n<=50
100%的数据满足： n<=1000

来源
NOIP2008 提高组第4题
*/

/*
  得分：40
  解题报告：（考后）
    考试时只会暴力，再加上分点，多骗到了10分 XD
    首先，要判断给定序列a[1:n]是否有解：
      对于两个数a[i],a[j] (i<j)，它们不能压入同一个栈的充要条件p为：
        存在k，使得i<j<k，且a[k]<a[i]<a[j]
      证明：
        1.充分性，即如果满足条件p，a[i]和a[j]一定不能压入同一个栈。使用反证法证明。
          若a[i]和a[j]满足条件p且在同一个栈中，因为a[k]比a[i]和a[j]都小，所以在弹出a[k]前，a[i]和a[j]都不能弹出。
          此时从栈底到栈顶依次为 a[i],a[j],a[k]。
          将来当a[k]弹出后，a[j]先于a[i]弹出，但a[i]<a[j]，理应a[i]先于a[j]弹出，因此错误。
        2.必要性，即如果a[i]和a[j]不能压入同一个栈，那么一定满足条件p。证明其逆反命题，即如果不满足条件p那么a[i]和a[j]一定可以压入同一个栈。
          有两种情况不满足p，分别为：(1).对于任意i<j<k，满足a[i]<a[j]且a[k]>a[i]；(2).对于任意i<j,总存在a[i]>a[j]
          (1).因为a[k]>a[i]，所以a[i]一定先于a[k]出栈，a[i]也先于a[j]出栈，成立。
          (2).此时的序列是降序序列，所有数都能压入同一个栈中，成立。
      因此，条件p为a[i]和a[j]不能压入同一个栈中的充要条件得证。
    对于每个(i,j)判断完成后，就可以判断有无可行解了。
    因为一共只有两个栈，a[i]要么在一个栈里，要么在另一个栈里，就想到二分图或并查集。
    这里使用二分图判断。
    对于每个不能放在一个栈中的无序对(i,j)，建立一条连接i和j的无向边，然后通过染色判断二分图（每个节点染色为1或-1，总是先将没有被染色的点染为1）。如果是二分图则有解，不是则无解。
    若有解，染完色后每个a[i]的相对位置也就确定了。
    因为题目要求最小字典序，那么可以贪心地将颜色为1的节点压入st1，颜色为2的节点压入st2，并且在每个节点被压栈后，<b>循环判断（因为有时栈中有多个有序元素）</b>两个栈是否能弹出元素。（终于有点贪心了 XD）
    在判断i,j是否可以在同一个栈中时，可以令b[i]表示a[i:n]中的最小值，那么只要当b[j+1]<a[i]<a[j]时，i,j就不能在同一个栈中。

  BTW:好高兴这一年总分破了04年的记录 XD
*/

#include<iostream>
#include<cstdio>
#include<stack>
#include<list>
using namespace std;

const int MAX=1020;
int n,a[MAX];
int b[MAX]; //b[i]: a[i:n-1]的最小值
int color[MAX];
stack<int> st1,st2;
list<int> e[MAX];
bool first=1;

bool dfs(int u, int c);
void print(char c);

int main(void){
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  b[n]=a[n];
  for(int i=n-1;i>0;i--) b[i]=min(b[i+1],a[i]);  //初始化最小值数组

  for(int i=1;i<n;i++) for(int j=i+1;j<n;j++) if(a[i]<a[j] && b[j+1]<a[i]){ //将不能放在一个栈中的元素连接
#ifdef DEBUG                                //<b> j 不能等于 n </b>
    printf("  (%d,%d)\n",i,j);
#endif
    e[i].push_back(j); e[j].push_back(i);
  }

  bool flag=1;
  for(int i=1;i<=n;i++) if(!color[i]){ //染色判断二分图
    if(!dfs(i,1)) {flag=0; break;}
  }
#ifdef DEBUG
  for(int i=1;i<=n;i++) printf("  color[%d]: %d\n",i,color[i]);
#endif

  if(!flag) printf("0\n");
  else{
    bool first=0;
    int cur=1;
    for(int i=1;i<=n;i++){
      if(color[i]==1){
        print('a');
        st1.push(a[i]);
      }else{
        print('c');
        st2.push(a[i]);
      }
      while((!st1.empty() && st1.top()==cur) || (!st2.empty() && st2.top()==cur)){  //<b></b>
        //while(!st1.empty() && st1.top()==cur) {st1.pop(); print('b'); cur++;}
        //while(!st2.empty() && st2.top()==cur) {st2.pop(); print('d'); cur++;}
        if(!st1.empty() && st1.top()==cur) {st1.pop(); print('b');}
        else {st2.pop(); print('d');}
        cur++;
      }
    }
    printf("\n");
  }

  return 0;
}

bool dfs(int u, int c){
  color[u]=c;
  list<int>::iterator it;
  for(it=e[u].begin();it!=e[u].end();it++)
    //if(color[*it] && color[*it]!=-c) return false;
    if(color[*it]==c) return false; //get
    else if(!color[*it] && !dfs(*it,-c)) return false;
  return true;
}
void print(char c){
  if(!first) printf(" ");
  else first=0;
  printf("%c",c);
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;

int a[1020],n;
char sw[2020],save[2020];
stack<int> st1,st2;
deque<int> q,res;

bool dfs(int cur);

int main(void){
  scanf("%d",&n);
  for(int i=0;i<n;i++) {scanf("%d",&a[i]); q.push_back(a[i]);}

  if(n<=10){
    st1.push(q.front()); q.pop_front();
    sw[0]='a';
    if(dfs(1)){
      for(int i=0;i<(n<<1);i++)
        if(!i) printf("%c",save[i]);
        else printf(" %c",save[i]);
      printf("\n");
    }else printf("0\n");
  }else{  //骗到了第4个点 XD
    printf("0\n");
  }
  return 0;
}

bool dfs(int cur){
  if(cur==(n<<1)) {memcpy(save,sw,sizeof(sw));; return true;}
  //a
  if(!q.empty()){
    int t=q.front(); q.pop_front();
    st1.push(t); sw[cur]='a';
    if(dfs(cur+1)) return true;
    st1.pop(); q.push_front(t);
  }

  //b
  if(!st1.empty() && ((res.empty() && st1.top()==1) || (!res.empty() && st1.top()==res.back()+1))){
    int t=st1.top(); st1.pop();
    res.push_back(t); sw[cur]='b';
    if(dfs(cur+1)) return true;
    res.pop_back(); st1.push(t);
  }

  //c
  if(!q.empty()){
    int t=q.front(); q.pop_front();
    st2.push(t); sw[cur]='c';
    if(dfs(cur+1)) return true;
    st2.pop(); q.push_front(t);
  }

  //d
  if(!st2.empty() && ((res.empty() && st2.top()==1) || (!res.empty() && st2.top()==res.back()+1))){
    int t=st2.top(); st2.pop();
    res.push_back(t); sw[cur]='d';
    if(dfs(cur+1)) return true;
    res.pop_back(); st2.push(t);
  }
  return false;
}
*/
