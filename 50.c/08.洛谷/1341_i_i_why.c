/*
题目描述
给定n个各不相同的无序字母对（区分大小写，无序即字母对中的两个字母可以位置颠倒）。请构造一个有n+1个字母的字符串使得每个字母对都在这个字符串中出现。

输入输出格式
输入格式：
第一行输入一个正整数n。
以下n行每行两个字母，表示这两个字母需要相邻。

输出格式：
输出满足要求的字符串。
如果没有满足要求的字符串，请输出“No Solution”。
如果有多种方案，请输出前面的字母的ASCII编码尽可能小的（字典序最小）的方案

输入输出样例
输入样例#1：
4
aZ
tZ
Xt
aX

输出样例#1：
XaZtX
 
说明
数据规模
不同的无序字母对个数有限，n的规模可以通过计算得到。
*/

/*
  解题报告：
    实质上就是判断有没有欧拉回路再输出，但搜索欧拉回路的函数我给写炸了。。。
    到现在还没搞懂搜欧拉回路的函数。。。
      在函数中不要break是因为欧拉图的性质使得从点u递归后要么停止要么还会回到点u，那么就不用break，但如果用了会有什么影响？不知道。。。
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

const int MAX=128;
int n,out[MAX],cnt[MAX];
bool G[MAX][MAX],vis[MAX][MAX];
char t1[3];
VR<char> res;

/*
//错误
void euler(int u){
  res.push_back(u);
  FOR(i,0,MAX) if(G[u][i] && !vis[u][i]){
    vis[u][i]=vis[i][u]=1; cnt[u]++; cnt[i]++;
    euler(i); break;  //不能break //???
  }
}
*/

void euler(int u){
  FOR(i,0,MAX) if(G[u][i] && !vis[u][i]){
    vis[u][i]=vis[i][u]=1; cnt[u]++; cnt[i]++;
    euler(i);
  }
  res.push_back(u);
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n){
    scanf("%s",t1);
    char c1=t1[0],c2=t1[1];
    out[c1]++; out[c2]++;
    G[c1][c2]=G[c2][c1]=1;
  }

  int s=-1,t=-1,cntJi=0; bool flag=1;
  FOR(i,0,MAX) if(out[i]&1){
    if(cntJi==0) s=i;
    else if(cntJi==1) t=i;
    else {flag=0; break;}
    cntJi++;
  }
  if(!flag || cntJi&1) printf("No Solution\n");
  else{
    if(s!=-1) euler(s);
    FOR(i,0,MAX) if(out[i] && cnt[i]<out[i]) euler(i);
    if(res.size()!=n+1) printf("No Solution");
    else ROR(i,res.size()-1,0) putchar(res[i]);
    putchar('\n');
  }

  return 0;
}
