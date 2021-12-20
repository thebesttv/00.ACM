/*
描述
牛牛最近迷上了一种叫斗地主的扑克游戏。斗地主是一种使用黑桃、红心、梅花、 方片的 A 到 K 加上大小王的共 54 张牌来进行的扑克牌游戏。在斗地主中，牌的大小关系根据*牌的数码*表示如下：3<4<5<6<7<8<9<10<J<Q<K<A<2<小王<大王，而**花色并不对牌的大小产生影响**。每一局游戏中，一副*手牌*由 n 张牌组成。游戏者每次可以根据规定的*牌型*进行出牌，首先打光自己的手牌一方取得游戏的胜利。
现在，牛牛只想知道，对于自己的若干组*手牌*，分别最少需要多少次出牌可以将它们打光。请你帮他解决这个问题。
需要注意的是，本题中游戏者每次可以出手的*牌型*与一般的斗地主相似而略有不同。
具体规则如下：
图片

格式
输入格式
第一行包含用空格隔开的 2 个正整数 T, n ，表示手牌的组数以及每组手牌的张数。
接下来 T 组数据，每组数据 n 行，每行一个非负整数对 ai, bi，表示一张牌，其中 ai 表示牌的数码，bi 表示牌的花色，中间用空格隔开。特别的，我们用 1 来表示数码 A，11 表示数码 J，12 表示数码 Q，13 表示数码 K；黑桃、红心、梅花、方片分别用 1-4 来表示；小王的表示方法为 0 1，大王的表示方法为 0 2。

输出格式
共 T 行，每行一个整数，表示打光第 i 组手牌的最少次数。

样例1
样例输入1
1 8
7 4
8 4
9 1
10 4
11 1
5 1
1 4
1 1

样例输出1
3

样例2
样例输入2
1 17
12 3
4 3
2 3
5 4
10 2
3 3
12 2
0 1
1 3
10 1
6 2
12 1
11 3
5 2
12 4
2 2
7 2

样例输出2
6

限制
对于不同的测试点，我们约定手牌组数 T 与张数 n 的规模如下：
编号    T    n    编号   T    n
  1    100   2     11   100  14
  2    100   2     12   100  15
  3    100   3     13    10  16
  4    100   3     14    10  17
  5    100   4     15    10  18
  6    100   4     16    10  19
  7    100  10     17    10  20
  8    100  11     18    10  21
  9    100  12     19    10  22
 10    100  13     20    10  23
数据保证：所有的手牌都是随机生成的。

提示
输入输出样例 1 说明
共有 1 组手牌，包含 8 张牌：方片 7，方片 8，黑桃 9，方片 10，黑桃 J，黑桃 5，方片 A 以及黑桃 A。可以通过打单顺子（方片 7，方片 8，黑桃 9，方片 10，黑桃 J），单张牌（黑桃 5）以及对子牌（黑桃 A 以及方片 A）在 3 次内打光。

来源
NOIP 2015 提高组 Day 1 第三题
数据由 AHdoc 生成。
同时感谢 QQ用户 879×××461。
*/

/*
  得分：34
  解题报告：
    一开始以为只是暴搜，没想到最后一堆TLE和WA。。。
    可以忽略花色，只看点数。
  正解：
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

int a[16],n,ansMin=1<<30;

void dfs(int step, int left);

int main(void){
  int T; scanf("%d%d",&T,&n);
  while(T--){
    ansMin=n; MST(a,0);
    for(int i=0,j,k;i<n;i++){
      scanf("%d%d",&j,&k);
      if(!j) a[k==1 ? 14 : 15]++;
      else a[j]++;
    }
    dfs(0,n);
    printf("%d\n",ansMin);
  }

  return 0;
}

void dfs(int step, int left){
#ifdef DEBUG
  printf("  in dfs(%d,%d)\n",step,left);
#endif
  if(step>=ansMin) return;
  if(!left) {ansMin=step; return;}
  //3
  ansMin=min(ansMin,step+left);

  //1 大小王可以直接删
#ifdef DEBUG
  printf("    in 1\n");
#endif
  if(a[14] && a[15]){
    a[14]--; a[15]--;
    dfs(step+1,left-2);
    a[14]++; a[15]++;
  }else{
    VR<int> s2,s3,s4;
    if(left>=2) FORR(i,1,13){
      if(a[i]>=2) s2.push_back(i);
      if(a[i]>=3) s3.push_back(i);
      if(a[i]>=4) s4.push_back(i);
    }

    //2,11
#ifdef DEBUG
    printf("    in 2,11\n");
#endif
    if(s4.size()) ROR(k,s4.size()-1,0){
      int t=s4[k];
      a[t]-=4;
      ROR(i,s2.size()-1,0) if(s2[i]!=t) RORR(j,i-1,0) if(s2[j]!=t && i!=j){
        int ta=s2[i],tb=s2[j];
        a[ta]-=2; a[tb]-=2;
        dfs(step+1,left-8);
        a[ta]+=2; a[tb]+=2;
      }
      FORR(i,1,13) FORR(j,i+1,13) if(a[i] && a[j] && i!=j){
        a[i]--; a[j]--;
        dfs(step+1,left-6);
        a[i]++; a[j]++;
      }
      dfs(step+1,left-4);
      a[t]+=4;
    }
    //5,6,7
#ifdef DEBUG
    printf("    in 5,6,7\n");
#endif
    if(s3.size()) ROR(i,s3.size()-1,0){
      int t=s3[i];
      a[t]-=3;
      //1对
      ROR(j,s2.size()-1,0) if(s2[j]!=t){
        int ta=s2[j];
        a[ta]-=2;
        dfs(step+1,left-5);
        a[ta]+=2;
      }
      //1单
      FORR(i,1,15) if(a[i] && i!=t){
        a[i]--;
        dfs(step+1,left-4);
        a[i]++;
      }
      //无
      dfs(step+1,left-3);
      a[t]+=3;
    }
    //4
#ifdef DEBUG
    printf("    in 4\n");
#endif
    if(s2.size()) ROR(i,s2.size()-1,0){
      int t=s2[i];
      a[t]-=2;
      dfs(step+1,left-2);
      a[t]+=2;
    }
    //8
#ifdef DEBUG
    printf("    in 8\n");
#endif
    FORR(i,3,9) if(a[i] && a[i+1] && a[i+2] && a[i+3] && a[i+4]){
      int j=i+5;
      for(;j<=13;j++) if(!a[j]) break;
      j-=i;
      FORR(len,5,j){
        FOR(k,0,len) a[i+k]--;
        dfs(step+1,left-len);
        FOR(k,0,len) a[i+k]++;
      }
    }
    //9
#ifdef DEBUG
    printf("    in 9\n");
#endif
    int siz2=s2.size();
    if(siz2>2) FOR(i,0,siz2-2){ //???
      //printf("      in loop %d, siz2: %d\n",i,siz2);
      int t1=s2[i],t2=s2[i+1],t3=s2[i+2];
      if(t1==2 || t2==2 || t3==2) continue;
      if(t1+1!=t2 || t2+1!=t3) continue;
      int j=i;  //记录最大连续个数
      for(;j<siz2;j++) if(s2[j]!=t1+(j-i)) break;
      j-=i;
      FORR(len,3,j){
        FOR(k,0,len) a[t1+k]-=2;
        dfs(step+1,left-len*2);
        FOR(k,0,len) a[t1+k]+=2;
      }
    }
    //10
#ifdef DEBUG
    printf("    in 10\n");
#endif
    int siz3=s3.size();
    if(siz3>3) FOR(i,0,siz3-1){
      int t1=s3[i],t2=s3[i+1];
      if(t1==2 || t2==2) continue;
      if(t1+1!=t2) continue;
      int j=i;  //记录最大连续个数
      for(;j<siz3;j++) if(s3[j]!=t1+(j-i)) break;
      j-=i;
      FORR(len,2,j){
        FOR(k,0,len) a[t1+k]-=3;
        dfs(step+1,left-len*3);
        FOR(k,0,len) a[t1+k]+=3;
      }
    }
  }
}
