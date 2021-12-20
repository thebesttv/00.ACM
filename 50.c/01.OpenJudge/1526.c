/*
描述
世界上有许多宗教，你感兴趣的是你学校里的同学信仰多少种宗教。
你的学校有n名学生（0 < n <= 50000），你不太可能询问每个人的宗教信仰，因为他们不太愿意透露。但是当你同时找到2名学生，他们却愿意告诉你他们是否信仰同一宗教，你可以通过很多这样的询问估算学校里的宗教数目的上限。你可以认为每名学生只会信仰最多一种宗教。

输入
输入包括多组数据。
每组数据的第一行包括n和m，0 <= m <= n(n-1)/2，其后m行每行包括两个数字i和j，表示学生i和学生j信仰同一宗教，学生被标号为1至n。输入以一行 n = m = 0 作为结束。

输出
对于每组数据，先输出它的编号（从1开始），接着输出学生信仰的不同宗教的数目上限。

样例输入
10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0

样例输出
Case 1: 1
Case 2: 7
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int p[50000+10];

int getParent(int n){
  if(p[n]<0) return n;
  else return p[n]=getParent(p[n]);
}
void merge(int a, int b){
  int pa=getParent(a),pb=getParent(b);
  if(pa==pb) return;
  int tot=p[pa]+p[pb];
  if(p[pa]<p[pb]){
    p[pb]=pa;
    p[pa]=tot;
  }else{
    p[pa]=pb;
    p[pb]=tot;
  }
}

int main(void){
  int n,m,kase=0;
  while(scanf("%d%d",&n,&m)==2 && n){
    memset(p,-1,sizeof(p));
    int a,b;
    for(int i=0;i<m;i++){
      scanf("%d%d",&a,&b);
      merge(a,b);
    }
    int cnt=0;
    for(int i=1;i<=n;i++) if(p[i]<0) cnt++;
    printf("Case %d: %d\n",++kase,cnt);
  }

  return 0;
}
