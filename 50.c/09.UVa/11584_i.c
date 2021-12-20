/*
  DP + O(n^2)判断回文串
  令f[i]表示str[1:i]中的最少回文串数，则
    f[i] = min{ f[j]+1 | str[j+1:i]回文 }, O(n^2)
  那么要做到的就是O(n^2)判回文
  令huiwen[i][j]表示str[i:j]是否回文，则可以枚举“中点”，然后同时向左向右扩展，一旦不是回文就退出
    要判断两次：长度为奇数和偶数各一次
    如果只枚举一般意义上的“中点”，即g[i-j]和g[i+j]，则不能判断出回文串"bccb"。
  优化：
    判断回文串时同时记录结束于j的回文串的开始位置i，在DP时对每个j只考虑之前记录的i，可以将时间减少到0ms。
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

const int MAX=1020;
int f[MAX];
char t1[MAX];
vector<int> G[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%s",t1+1);
    int n=strlen(t1+1);

    FORR(i,1,n) G[i].clear();
    FORR(i,1,n) FOR(j,0,i)
      if(i+j<=n && t1[i-j]==t1[i+j]) G[i+j].push_back(i-j); //对结尾记录开头，而不是反过来
      else break;
    FORR(i,0,n) FOR(j,0,i)
      if(i+j+1<=n && t1[i-j]==t1[i+j+1]) G[i+j+1].push_back(i-j);
      else break;
    //FORR(i,1,n) sort(G[i].begin(),G[i].end());  //可以不用sort  why???
                                                  //递推时没有特别的顺序限制？

    MST(f,0x3f); f[0]=0;
    FORR(i,1,n) FOR(j,0,G[i].size())
      f[i]=min(f[i],f[G[i][j]-1]+1);  //<b>因为G[i][j]是回文串的开头，还是回文串的一部分，所以要将G[i][j]减去1 </b>
    printf("%d\n",f[n]);
  }

  return 0;
}

/*
const int MAX=1020;
int f[MAX];
bool huiwen[MAX][MAX];
char t1[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%s",t1+1);
    int n=strlen(t1+1);

    //判断回文
    MST(huiwen,0);
    FORR(i,1,n) FOR(j,0,i)
      if(i+j<=n && t1[i-j]==t1[i+j]) huiwen[i-j][i+j]=1;
      else break;
    FOR(i,1,n) FOR(j,0,i)
      if(i+j+1<=n && t1[i-j]==t1[i+j+1]) huiwen[i-j][i+j+1]=1;
      else break;
    
    MST(f,0x3f); f[0]=0;
    FORR(i,1,n) FOR(j,0,i) if(huiwen[j+1][i])
      f[i]=min(f[i],f[j]+1);
    printf("%d\n",f[n]);
  }
  return 0;
}
*/
