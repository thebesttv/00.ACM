/*
题目描述
John的农场在给奶牛挤奶前有很多杂务要完成，每一项杂务都需要一定的时间来完成它。比如：他们要将奶牛集合起来，将他们赶进牛棚，为奶牛清洗乳房以及一些其它工作。尽早将所有杂务完成是必要的，因为这样才有更多时间挤出更多的牛奶。当然，有些杂务必须在另一些杂务完成的情况下才能进行。比如：只有将奶牛赶进牛棚才能开始为它清洗乳房，还有在未给奶牛清洗乳房之前不能挤奶。我们把这些工作称为完成本项工作的准备工作。至少有一项杂务不要求有准备工作，这个可以最早着手完成的工作，标记为杂务1。John有需要完成的n个杂务的清单，并且这份清单是有一定顺序的，杂务k(k>1)的准备工作只可能在杂务1..k-1中。
写一个程序从1到n读入每个杂务的工作说明。计算出所有杂务都被完成的最短时间。当然互相没有关系的杂务可以同时工作，并且，你可以假定John的农场有足够多的工人来同时完成任意多项任务。

输入输出格式
输入格式：
第1行：一个整数n，必须完成的杂务的数目(3<=n<=10,000)；
第2 ~ n+1行： 共有n行，每行有一些用1个空格隔开的整数，分别表示：
工作序号(1..n,在输入文件中是有序的)；
完成工作所需要的时间len（1<=len<=100）；
一些必须完成的准备工作，总数不超过100个，由一个数字0结束。有些杂务没有需要准备的工作只描述一个单独的0，整个输入文件中不会出现多余的空格。

输出格式：
一个整数，表示完成所有杂务所需的最短时间。

输入输出样例
输入样例#1：
7
1 5 0
2 2 1 0
3 3 2 0
4 6 1 0
5 1 2 4 0
6 8 2 4 0
7 4 3 5 6 0

输出样例#1：
23
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
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

const int MAX=10020;
int a[MAX];

int main(void){
  int n; scanf("%d",&n);
  int t,p;
  int ansMax=0;
  FORR(i,1,n){
    scanf("%d",&t); scanf("%d",&t);
    while(scanf("%d",&p)==1 && p){
      a[i]=max(a[i],a[p]);
    }
    a[i]+=t; ansMax=max(ansMax,a[i]);
  }
  printf("%d\n",ansMax);

  return 0;
}
