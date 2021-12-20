/*
描述
小南有一套可爱的玩具小人，它们各有不同的职业。
有一天，这些玩具小人把小南的眼镜藏了起来。小南发现玩具小人们围成了一个圈，它们有的面朝圈内，有的面朝圈外。如下图：

图片（T1-1.png）在目录中

这时singer告诉小南一个谜题：“眼镜藏在我左数第3个玩具小人的右数第1个玩 具小人的左数第2个玩具小人那里。”
小南发现，这个谜题中玩具小人的朝向非常关键，因为朝内和朝外的玩具小人的左右方向是相反的：面朝圈内的玩具小人，它的左边是顺时针方向，右边是逆时针方向；而面向圈外的玩具小人，它的左边是逆时针方向，右边是顺时针方向。
小南一边艰难地辨认着玩具小人，一边数着：
“singer朝内，左数第3个是archer。
“archer朝外，右数第1个是thinker。
“thinker朝外，左数第2个是writer。
“所以眼镜藏在writer这里！”
虽然成功找回了眼镜，但小南并没有放心。如果下次有更多的玩具小人藏他的眼镜，或是谜题的长度更长，他可能就无法找到眼镜了。所以小南希望你写程序帮他解决类似的谜题。这样的谜题具体可以描述为：
有n个玩具小人围成一圈，已知它们的职业和朝向。现在第1个玩具小人告诉小南一个包含m条指令的谜题，其中第i条指令形如“左数/右数第S_i个玩具小人”。你需要输出依次数完这些指令后，到达的玩具小人的职业。

格式
输入格式
输入的第一行包含两个正整数n, m，表示玩具小人的个数和指令的条数。
接下来n行，每行包含一个整数和一个字符串，以 逆时针 为顺序给出每个玩具小人的朝向和职业。其中0表示朝向圈内，1表示朝向圈外。保证不会出现其他的数。字符串长度不超过10且仅由小写字母构成，字符串不为空，并且字符串两两不同。整数和字符串之间用一个空格隔开。
接下来m行，其中第i行包含两个整数a_i, s_i，表示第i条指令。若a_i=0，表示向左数Si个人；若a_i=1，表示向右数si个人。保证ai不会出现其他的数，1<=Si<n。

输出格式
输出一个字符串，表示从第一个读入的小人开始，依次数完m条指令后到达的小人的职业。

样例1
样例输入1
7 3
0 singer
0 reader
0 mengbier
1 thinker
1 archer
0 writer
1 mogician
0 3
1 1
0 2

样例输出1
writer

样例2
样例输入2
10 10
1 c
0 r
0 p
1 d
1 e
1 m
1 t
1 y
1 u
0 v
1 7
1 1
1 4
0 5
0 3
0 1
1 6
1 2
0 8
0 4

样例输出2
y

限制
子任务
子任务会给出部分测试数据的特点。如果你在解决题目中遇到了困难，可以尝试只解决一部分测试数据。
每个测试点的数据规模及特点如下表：

  测试点   n   m   全朝内  全左数  si=1  职业长度为1
     1    20  10^3    V      V      V         V     
     2    20  10^3    X      V      V         V     
     3    20  10^3    V      X      V         V     
     4    20  10^3    X      X      V         V     
     5    20  10^3    V      V      X         V     
     6    20  10^3    X      V      X         V     
     7    20  10^3    V      X      X         V     
     8    20  10^3    X      X      X         V     
     9    20  10^3    V      V      V         X     
    10    20  10^3    X      V      V         X     
    11    20  10^3    V      X      V         X     
    12    20  10^3    X      X      V         X     
    13    20  10^3    V      V      X         X     
    14    20  10^3    X      V      X         X     
    15    20  10^3    V      X      X         X     
    16    20  10^3    X      X      X         X     
    17  10^5  10^5    V      V      X         X     
    18  10^5  10^5    X      V      X         X     
    19  10^5  10^5    V      X      X         X     
    20  10^3  10^5    X      X      X         X     

其中一些简写的列意义如下：
全朝内：若为"V"，表示该测试点保证所有的玩具小人都朝向圈内；
全左数：若为"V"，表示该测试点保证所有的指令都向左数，即对任意的 1 <= i <= m， ai = 0 ；
Si = 1：若为"V"，表示该测试点保证所有的指令都只数1个，即对任意的 1 <= i <= m， Si = 1；
职业长度为1：若为"V"，表示该测试点保证所有玩具小人的职业一定是一个长度为1的字符串。

来源
NOIP 2016 提高组 Day 1 第一题
*/

/*
  得分：100
  解题报告：
    前16个点直接暴力模拟即可，后面四个点可以对每个命令计算，O(m)完成。
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

const int MAX=100020;
struct Ind{
  char s[20];
  int opt;
}ind[MAX];
int n,m;

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n){
    scanf("%d%s",&ind[i].opt,ind[i].s);
    ind[i].opt = ind[i].opt==0 ? 1 : -1;  //内1，外-1
  }
  int ans=0,a,b;
  FOR(i,0,m){
    scanf("%d%d",&a,&b);
    if(a==0) b=-b;  //左负右正
    ans = (ans + ind[ans].opt*b + n)%n;
  }
  printf("%s\n",ind[ans].s);

  return 0;
}
