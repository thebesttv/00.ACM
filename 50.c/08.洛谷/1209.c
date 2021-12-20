/*
题目描述
在一个夜黑风高,下着暴风雨的夜晚,farmer John的牛棚的屋顶、门被吹飞了。 好在许多牛正在度假，所以牛棚没有住满。 牛棚一个紧挨着另一个被排成一行，牛就住在里面过夜。 有些牛棚里有牛，有些没有。 所有的牛棚有相同的宽度。 自门遗失以后,farmer John必须尽快在牛棚之前竖立起新的木板。 他的新木材供应商将会供应他任何他想要的长度,但是吝啬的供应商只能提供有限数目的木板。 farmer John想将他购买的木板总长度减到最少。
给出:可能买到的木板最大的数目M(1<= M<=50);牛棚的总数S(1<= S<=200); 牛棚里牛的总数C(1 <= C <=S);和牛所在的牛棚的编号stall_number(1 <= stall_number <= S),计算拦住所有有牛的牛棚所需木板的最小总长度。 输出所需木板的最小总长度作为答案。

输入输出格式
输入格式：
第 1 行: 木板最大的数目M ,牛棚的总数S 和 牛的总数C(用空格分开)
第 2 到 C+1 行: 每行包含一个整数，表示牛所占的牛棚的编号。

输出格式：
单独的一行包含一个整数表示所需木板的最小总长度。

输入输出样例
输入样例#1：
4 50 18
3 
4 
6 
8 
14
15 
16 
17 
21
25 
26 
27 
30 
31 
40 
41 
42 
43

输出样例#1：
25
*/

/*
  解题报告：
    存储相邻两头牛的间距并升序排列。
    先假设所有有牛的棚上都放一块木板，那么此时木板总数tot=c，总长度ans=c。
    然后遍历所有间距，每次都将两块木板并成一块，那么长度增加 间距-1，总数减少1，直到正好有m块木板。
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
int m,s,c,pos[MAX];
PQ<int,VR<int>,greater<int> > q;

int main(void){
  scanf("%d%d%d",&m,&s,&c);
  FOR(i,0,c) scanf("%d",&pos[i]);
  sort(pos,pos+c);
  FOR(i,1,c) q.push(pos[i]-pos[i-1]+1);
  int tot=c,ans=c;  //共tot张板，总长ans
  while(tot>m && !q.empty()){
    ans+=q.top()-2; q.pop(); tot--;
  }
  printf("%d\n",ans);

  return 0;
}
