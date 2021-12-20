/*
描述
本题中，我们将用符号⌊c⌋表示对c向下取整，例如：⌊3.0⌋=⌊3.l⌋=⌊3.9⌋=3。
蛐蛐国最近蚯蚓成灾了！隔壁跳蚤国的跳蚤也拿蚯蚓们没办法，蛐蛐国王只好去请神刀手来帮他们消灭蚯蚓。
蛐蛐国里现在共有n只蚯蚓（n为正整数）。每只蚯蚓拥有长度，我们设第i只蚯蚓的长度为ai(i=1, 2, ..., n)，并保证所有的长度都是非负整数（即：可能存在长度为0的蚯蚓）。
每一秒，神刀手会在所有的蚯蚓中，准确地找到最长的那一只（如有多个则任选一个）将其切成两半。神刀手切开蚯蚓的位置由常数p （是满足0<p<l的有理数）决定，设这只蚯蚓长度为x，神刀手会将其切成两只长度分别为⌊px⌋和x - ⌊px⌋的蚯蚓。特殊地，如果这两个数的其中一个等于0，则这个长度为0的蚯蚓也会被保留。此外，除了刚刚产生的两只新蚯蚓，其余蚯蚓的长度都会增加q （是一个非负整常数）。
蛐蛐国王知道这样不是长久之计，因为蚯蚓不仅会越来越多，还会越来越长。蛐蛐国王决定求助于一位有着洪荒之力的神秘人物，但是救兵还需要m秒才能到来...... （m为非负整数）
蛐蛐国王希望知道这m秒内的战况。具体来说，他希望知道：
m秒内，每一秒被切断的蚯蚓被切断前的长度（有m个数）
m秒后，所有蚯蚓的长度（有n + m个数）。
蛐蛐国王当然知道怎么做啦！但是他想考考你......

格式
输入格式
第一行包含六个整数n,m,q,u,v,t，其中：n,m,q的意义见问题描述；u,v,t均为正整数；你需要自己计算p = u/v (保证0<u<v) t是输出参数，其含义将会在输出格式中解释。
第二行包含n个非负整数，为a1, a2, ..., an，即初始时n只蚯蚓的长度。
同一行中相邻的两个数之间，恰好用一个空格隔开。
保证 1<=n<=10^5，0 <= m <= 7 x 10^6， 0 < u < v <= 10^9，0 <= q <= 200， 1 <= t <= 71， 0 <= ai <= 10^8。

输出格式
第一行输出⌊m/t⌋个整数，按时间顺序，依次输出第t秒，第2t秒，第3t秒，……被切断蚯蚓（在被切断前）的长度。
第二行输出⌊(n+m)/t⌋个整数，输出m秒后蚯蚓的长度；需要按从大到小的顺序，依次输出排名第t，第2t，第3t，... 的长度。
同一行中相邻的两个数之间，恰好用一个空格隔开。即使某一行没有任何数需要输出，你也应输出一个空行。
请阅读样例来更好地理解这个格式。

样例1
样例输入1
3 7 1 1 3 1
3 3 2

样例输出1
3 4 4 4 5 5 6
6 6 6 5 5 4 4 3 2 2

样例2
样例输入2
3 7 1 1 3 2
3 3 2

样例输出2
4 4 5
6 5 4 3 2

样例3
样例输入3
3 7 1 1 3 9
3 3 2

样例输出3
      //空一行
2

限制
子任务
测试点1~3满足 m=0。
测试点4~7满足 n,m<=1,000。
测试点8~14满足 q=0，其中测试点8~9还满足 m<=10^5。
测试点15~18满足 m<=3x10^5。
测试点19~20没有特殊的约定，参见原始的数据范围。
测试点1~12，15~16还满足 v<=2，这意味着u,v的唯一可能的取值是 u=1,v=2，即 p=0.5 。这可能会对解决问题有特殊的帮助。

提示
样例1说明
在神刀手到来前：3只蚯蚓的长度为3, 3, 2。
1秒后：一只长度为3的蚯蚓被切成了两只长度分别为1和2的蚯蚓，其余蚯蚓的长度增加了1。最终4只蚯蚓的长度分别为(1, 2), 4, 3。括号表示这个位置刚刚有一只蚯蚓被切断。
2秒后：一只长度为4的蚯蚓被切成了1和3。5只蚯蚓的长度分别为：2, 3, (1, 3), 4。
3秒后：一只长度为4的蚯蚓被切断。6只蚯蚓的长度分别为：      3, 4, 2, 4, (1, 3)。
4秒后：一只长度为4的蚯蚓被切断。7只蚯蚓的长度分别为：      4, (1, 3), 3, 5, 2, 4。
5秒后：一只长度为5的蚯蚓被切断。8只蚯蚓的长度分别为：      5, 2, 4, 4, (1, 4), 3, 5。
6秒后：一只长度为5的蚯蚓被切断。9只蚯蚓的长度分别为：      (1, 4), 3, 5, 5, 2, 5, 4, 6。
7秒后：一只长度为6的蚯蚓被切断。10只蚯蚓的长度分别为：2, 5, 4, 6, 6, 3, 6, 5, (2, 4)。
所以，7秒内被切断的蚯蚓的长度依次为3, 4, 4, 4, 5, 5, 6。7秒后，所有蚯蚓长度从大到小排序为 6, 6, 6, 5, 5, 4, 4, 3, 2, 2。

样例2说明
这个数据中只有t = 2与上个数据不同。只需在每行都改为每两个数输出一个数即可。
虽然第一行最后有一个6没有被输出，但是第二行仍然要重新从第二个数再开始输出。

样例3说明
这个数据中只有t = 9与上个数据不同。
注意第一行没有数要输出，但也要输出一个空行。

来源
NOIP 2016 提高组 Day 2 第二题
*/

/*
  得分：85
  解题报告：
    若直接模拟，则O(m*(n+m)/2)，直接TLE。
    因为每次都选择最大的，想到使用优先队列，但因为每秒中其他蚯蚓都在变长，不可能每次都对所有蚯蚓进行操作。
    因此想到使用全局变量delta记录每只蚯蚓从一开始到第i秒长度的增长量，但要注意每次被切的蚯蚓不会变长。
      首先对测试数据1进行模拟：
        0. 3, 3, 2
        1. (1, 2), 4, 3
        2. 2, 3, (1, 3), 4
        3. 3, 4, 2, 4, (1, 3)
      然后改为带delta的（直接对每个减去delta即可）：
                                delta
        0. 3, 3, 2                0
        1. (0, 1), 3, 2           1
        2. 0, 1, (-1, 1), 2       2
        3. 0, 1, -1, 1, (-2, 0)   3
      可以看出，除了被切断的蚯蚓，其他蚯蚓长度都不改变。而对于被切断的蚯蚓，设其长度为l，切断后长度为l1,l2，在当前秒有delta，在上一秒有delta'则
        l1 = (l+delta')*p
        l2 = l+delta' - l1
      而进入队列后，
        l1 = l1-delta
        l2 = l2-delta
      因此可以写出代码：
        l=que.top(); que.pop();
        l+=delta; delta+=q;
        l1=l*p; l2=l-l1;
        que.push(l1-delta); que.push(l2-delta);
    但复杂度还是大了。而要优化，只能再优化优先队列。
    想到使用O(1)的单调队列。
    得出结论：若令长为 x 的蚯蚓，其被切所得为 x1,x2；长为 y (y<x) 的蚯蚓被切所得为 y1,y2 ，那么，x1>y1, x2>y2 恒成立
      证明：
        x刚被切时，x1 = x*p, x2 = x-x*p
        因为x>y，所以x先于y被切。那么设x被切后，过了t秒y被切。
        则在x被切后的第t秒，
          x1 = x*p + t*q, x2 = x - x*p + t*q
          y1 = y*p, y2 = y - y*p
        则
          x1 - y1 = (x-y)*p + t*q
          x2 - y2 = (x-y) + (x-y)*p + t*q
        因为 x-y>0，所以 x1>y1, x2>y2
        又因为以后 x1,x2,y1,y2 增长量相同，所以 x1>y1, x2>y2 恒成立。
        得证。
    那么就可以为所有还没被切的蚯蚓建立一个队列q1，为x1建立一个队列q2，再为x2建立一个队列q3。
    根据刚刚的证明，得到：q2和q3一定是单调的。而只要在输入后排一次序，q1也是单调的，那么就可以使用单调队列了。
    只要在每次取蚯蚓时，依次判断q1,q2,q3的队头，取最大值，再将切下的x1放入q2，x2放入q3，即可。
    具体实践时，还可以在模拟时同时输出第一行的答案。
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

//STL队列配getMax函数
const int MAX=7000020;
int n,m,q,u,v,t;
queue<int> q1,q2,q3;
int a[MAX];

inline int getMax(){
  int tmp;
  if(!q1.empty() && (q2.empty() || q1.front()>=q2.front()) && (q3.empty() || q1.front()>=q3.front())){  //大于或大于等于都可以
    tmp=q1.front(); q1.pop();
  }else if(!q2.empty() && (q3.empty() || q2.front()>=q3.front())){
    tmp=q2.front(); q2.pop();
  }else{
    tmp=q3.front(); q3.pop();
  }
  return tmp;
}

int main(void){
  scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
  FOR(i,0,n) scanf("%d",&a[i]);
  sort(a,a+n,greater<int>());
  FOR(i,0,n) q1.push(a[i]);

  bool first=0;
  int delta=0;
  for(int i=1,tmp;i<=m;i++){
    tmp=getMax(); tmp+=delta;
    if(i%t==0){
      if(first) putchar(' ');
      else first=1;
      printf("%d",tmp);
    }
    int l1=1LL*tmp*u/v; int l2=tmp-l1;
    delta+=q;
    q2.push(l1-delta); q3.push(l2-delta);
  }
  putchar('\n');

  first=0;
  int tot=m+n;
  for(int i=1,tmp;i<=tot;i++){
    tmp=getMax();
    if(i%t==0){
      if(first) putchar(' ');
      else first=1;
      printf("%d",tmp+delta);
    }
  }
  putchar('\n');

  return 0;
}

/*
//手打队列
const int MAX=7000020;
int n,m,q,u,v,t;
int q1[MAX],q2[MAX],q3[MAX];
int h1,t1,h2,t2,h3,t3;
int a[MAX];

int main(void){
  scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
  FOR(i,0,n) scanf("%d",&a[i]);
  sort(a,a+n,greater<int>());
  FOR(i,0,n) q1[t1++]=a[i];

  bool first=0;
  int delta=0;
  for(int i=1,tmp;i<=m;i++){
    if(h1<t1 && (h2>=t2 || q1[h1]>=q2[h2]) && (h3>=t3 || q1[h1]>=q3[h3])){
      tmp=q1[h1++];
    }else if(h2<t2 && (h3>=t3 || q2[h2]>=q3[h3])){
      tmp=q2[h2++];
    }else{
      tmp=q3[h3++];
    }
    tmp+=delta;
    if(i%t==0){
      if(first) putchar(' ');
      else first=1;
      printf("%d",tmp);
    }
    int l1=1LL*tmp*u/v; int l2=tmp-l1;
    delta+=q;
    q2[t2++]=l1-delta; q3[t3++]=l2-delta;
  }
  putchar('\n');

  first=0;
  int tot=m+n;
  for(int i=1,tmp;i<=tot;i++){
    if(h1<t1 && (h2>=t2 || q1[h1]>=q2[h2]) && (h3>=t3 || q1[h1]>=q3[h3])){
      tmp=q1[h1++];
    }else if(h2<t2 && (h3>=t3 || q2[h2]>=q3[h3])){
      tmp=q2[h2++];
    }else{
      tmp=q3[h3++];
    }
    if(i%t==0){
      if(first) putchar(' ');
      else first=1;
      printf("%d",tmp+delta);
    }
  }
  putchar('\n');

  return 0;
}
*/

/*
//优先队列
typedef long long LL;
const int MAX=7000020;
int n,m,q,u,v,t;
double p;
PQ<int> que;
int cut[MAX];

int main(void){
  scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
  for(int i=0,tmp;i<n;i++) {scanf("%d",&tmp); que.push(tmp);}
  p=(double)u/v;

  int delta=0;
  FORR(i,1,m){
    int t=que.top()+delta; que.pop(); //<b> //t先加上之前的delta
    cut[i]=t; delta+=q; //delta进行更新
    //int l1=t*p; int l2=t-l1;
    int l1=1LL*t*u/v,l2; l2=t-l1;
    l1-=delta; l2-=delta; //再减去更新后的delta
    que.push(l1); que.push(l2);       //</b>
#ifdef DEBUG
    printf("  in %d:",i);
    VR<int> v;
    while(!que.empty()){
      int t=que.top(); que.pop();
      printf(" %d",t+delta);
      v.push_back(t);
    }
    printf("\n");
    FOR(i,0,v.size()) que.push(v[i]);
#endif
  }

  bool first=0;
  for(int i=t;i<=m;i+=t){
    if(!first) first=1;
    else putchar(' ');
    printf("%d",cut[i]);
  }
  putchar('\n');

  first=0;
  int tmp=m+n,ans;
  FORR(i,1,tmp){
    ans=que.top(); que.pop();
    if((i%t)==0){
      if(!first) first=1;
      else putchar(' ');
      printf("%d",ans+delta);
    }
  }
  putchar('\n');

  return 0;
}
*/
