/*
题目描述
在大学期间，经常需要租借教室。大到院系举办活动，小到学习小组自习讨论，都需要向学校申请借教室。教室的大小功能不同，借教室人的身份不同，借教室的手续也不一样。
面对海量租借教室的信息，我们自然希望编程解决这个问题。
我们需要处理接下来n天的借教室信息，其中第i天学校有ri个教室可供租借。共有m份订单，每份订单用三个正整数描述，分别为dj,sj,tj，表示某租借者需要从第sj天到第tj天租借教室（包括第sj天和第tj天），每天需要租借dj个教室。
我们假定，租借者对教室的大小、地点没有要求。即对于每份订单，我们只需要每天提供dj个教室，而它们具体是哪些教室，每天是否是相同的教室则不用考虑。
借教室的原则是先到先得，也就是说我们要按照订单的先后顺序依次为每份订单分配教室。如果在分配的过程中遇到一份订单无法完全满足，则需要停止教室的分配，通知当前申请人修改订单。这里的无法满足指从第sj天到第tj天中有至少一天剩余的教室数量不足dj个。
现在我们需要知道，是否会有订单无法完全满足。如果有，需要通知哪一个申请人修改订单。

输入输出格式
输入格式：
第一行包含两个正整数n,m，表示天数和订单的数量。
第二行包含n个正整数，其中第i个数为ri，表示第i天可用于租借的教室数量。
接下来有m行，每行包含三个正整数dj,sj,tj，表示租借的数量，租借开始、结束分别在第几天。
每行相邻的两个数之间均用一个空格隔开。天数与订单均用从1开始的整数编号。

输出格式：
如果所有订单均可满足，则输出只有一行，包含一个整数 0。否则（订单无法完全满足）
输出两行，第一行输出一个负整数-1，第二行输出需要修改订单的申请人编号。

输入输出样例
输入样例#1：
4 3 
2 5 4 3 
2 1 3 
3 2 4 
4 2 4

输出样例#1：
-1 
2

输入输出样例说明
第 1 份订单满足后，4 天剩余的教室数分别为 0，3，2，3。第 2 份订单要求第 2 天到第 4 天每天提供 3 个教室，而第 3 天剩余的教室数为 2，因此无法满足。分配停止，通知第 2 个申请人修改订单。

数据范围
对于10%的数据，有1≤ n,m≤ 10；
对于30%的数据，有1≤ n,m≤1000；
对于 70%的数据，有1 ≤ n,m ≤ 10^5；
对于 100%的数据，有1 ≤ n,m ≤ 10^6,0 ≤ ri,dj≤ 10^9,1 ≤ sj≤ tj≤ n。
NOIP 2012 提高组 第二天 第二题
*/

/*
  得分：100
  解题报告：
    如果使用暴力，一定会TLE。即使使用差分优化后，也还是太慢。
    那么我们需要更好的优化策略。
    考虑到每天教室的个数是随着订单的增加一单单减少的，可是说是“单调的”，并且一个订单能不能被满足与之后的订单无关。因此想到可以枚举第一个不被满足的订单并判断。而最好的枚举方法便是二分。
    对于枚举的订单m，模拟[1,m]中的所有订单的情况，然后判断其中是否有一个或多个不被满足（不必考虑是具体哪个），那么只要二分找到第一个符合要求的订单即为答案。
    当然，可以在二分之前先判断是否有解，再进行二分。也可以在二分之后，根据答案是否为m，如果是m再判断是否有解（因为可能正好第m个订单不能被满足，也可能所有订单都能被满足，但二分会停止在m处）。不过两个是差不多的。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long unsigned LLU;
const int MAX=1000020;
struct Quest{
  int d,l,r;
}quest[MAX];
LLU tl[MAX];
int ori[MAX];
int n,m;

bool check(int day){  //模拟从第1到第day天的租借情况，如果有不足则返回true，否则返回false
  memset(tl,0,sizeof(tl));
  for(int i=1;i<=day;i++){
    tl[quest[i].l]+=quest[i].d;
    tl[quest[i].r+1]-=quest[i].d;
  }
  LLU delta=0;
  for(int i=1;i<=n;i++){
    delta+=tl[i];
    if(delta>ori[i]) return true;
  }
  return false;
}

int main(void){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",&ori[i]);
  for(int i=1;i<=m;i++) scanf("%d%d%d",&quest[i].d,&quest[i].l,&quest[i].r);

  if(!check(m)) printf("%d\n",0);
  else{
    int L=1,R=m+1;
    while(L<R){
      int M=L+(R-L)/2;
      if(check(M)) R=M;
      else L=M+1;
    }
    printf("%d\n%d\n",-1,L);
  }
  return 0;
}

/*
//O(mn) 45分
#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=1000020;
int a[MAX],n,m;

int read(){
  register int ch,sum=0;
  do ch=getchar(); while(!(ch>='0' && ch<='9'));
  do{
    sum=sum*10+ch-'0';
    ch=getchar();
  }while(ch>='0' && ch<='9');
  return sum;
}

int main(void){
  scanf("%d%d",&n,&m);
  n-=3; register int i;
  for(i=1;i<=n;i+=4){
    //scanf("%d",&a[i]);
    a[i]=read();
    a[i+1]=read();
    a[i+2]=read();
    a[i+3]=read();
  }
  n+=3; for(;i<=n;i++) a[i]=read();
  bool flag=1;
  register int d,s,t;
  for(i=1;i<=m && flag;i++){
    //scanf("%d%d%d",&d,&s,&t);
    d=read(); s=read(); t=read();
    for(int j=s;j<=t;j++)
      if(a[j]>=d) a[j]-=d;
      else if(flag){
        flag=0;
        printf("-1\n%d\n",i);
        break;
      }
  }
  if(flag) printf("0\n");

  return 0;
}
*/
