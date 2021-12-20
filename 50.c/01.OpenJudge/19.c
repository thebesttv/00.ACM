/*
描述
一个工厂制造的产品形状都是长方体，它们的高度都是h，长和宽都相等，一共有六个型号，他们的长宽分别为1*1, 2*2, 3*3, 4*4, 5*5, 6*6。这些产品通常使用一个 6*6*h 的长方体包裹包装然后邮寄给客户。因为邮费很贵，所以工厂要想方设法的减小每个订单运送时的包裹数量。他们很需要有一个好的程序帮他们解决这个问题从而节省费用。现在这个程序由你来设计。

输入
输入文件包括几行，每一行代表一个订单。每个订单里的一行包括六个整数，中间用空格隔开，分别为1*1至6*6这六种产品的数量。输入文件将以6个0组成的一行结尾。

输出
除了输入的最后一行6个0以外，输入文件里每一行对应着输出文件的一行，每一行输出一个整数代表对应的订单所需的最小包裹数。

样例输入
0 0 4 0 0 1 
7 5 1 0 0 0 
0 0 0 0 0 0 

样例输出
2 
1 

来源
Central Europe 1996
*/

/*
一开始只想到搜索（可能是一个暑假结束，码力下降了吧），结果复杂度太大，直接TLE。而且弄了一整个晚二。。。 
然后浏览了一下两篇题解，一出文德楼就想到了好几个剪枝（虽然对AC没有什么帮助吧。。。）

正解：
  可以证明，只要每个包裹被使用的面积比最大，答案即为最优。其他解无论怎样都不可能更优。
  那么就可以贪心解决。
  按长度从6到1依次贪心。 
  对于长6的，一定只能放在一个包裹中。
  对于长5的，一定还能放11个长1的。
  对于长4的，有如下几种可能：
  长度 1 2 3 4
  个数 0 5 0 1
       4 4 0 1
       8 3 0 1
      12 2 0 1
      16 1 0 1
      20 0 0 1
  可以看出，只要分a[2]是否>=5讨论即可。
  对于长3的，类似。
  对于长2的，每个包裹中一定能放9个，剩下的和长1的一起放。
  对于长1的，填满包裹即可。 
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

int a[10];

int main(void){
  while(scanf("%d",&a[1])==1){
    FORR(i,2,6) scanf("%d",&a[i]);
    bool flag=0; FORR(i,1,6) if(a[i]) {flag=1; break;}
    if(!flag) break;
    int ans=0;

    //倒序考虑
    ans+=a[6]; a[6]=0;
    ans+=a[5]; a[1]-=11*a[5]; a[5]=0;

    while(a[4]>0){
      a[1]-=20-4*min(max(a[2],0),5); a[2]-=5; //两种写法等效，第一种注意max(a[2],0)，因为a[2]可能为负数
      //if(a[2]>=5) a[2]-=5;
      //else {a[1]-=20-a[2]*4; a[2]=0;}
      a[4]--; ans++;
    }

    ans+=a[3]/4; a[3]%=4;
    if(a[3]>0){
      if(a[3]==3){
        a[1]-=9-4*min(max(a[2],0),1); a[2]--;
        //if(a[2]>=1) {a[2]--; a[1]-=5;}
        //else a[1]-=9;
      }else if(a[3]==2){
        a[1]-=18-4*min(max(a[2],0),3); a[2]-=3;
        //if(a[2]>=3) {a[2]-=3; a[1]-=6;}
        //else {a[1]-=18-4*a[2]; a[2]=0;}
      }else{
        a[1]-=27-4*min(max(a[2],0),5); a[2]-=5;
        //if(a[2]>=5) {a[2]-=5; a[1]-=7;}
        //else {a[1]-=27-4*a[2]; a[2]=0;}
      }
      a[3]=0; ans++;
    }

    if(a[2]>0) {ans+=a[2]/9; a[2]%=9;}
    if(a[2]>0) {ans++; a[1]-=36-a[2]*4;}
    if(a[1]>0) ans+=ceil(a[1]/36.0);

    printf("%d\n",ans);
  }

  return 0;
}

/*
const int MAX=10;
int a[MAX],tans,ansMin;
const int w3=13,w4=6;
const int d3[13][MAX]={
  {0,0,0,4},
  {0,5,1,3},
  {0,9,0,3},
  {0,6,3,2},
  {0,10,2,2},
  {0,14,1,2},
  {0,18,0,2},
  {0,7,5,1},
  {0,11,4,1},
  {0,15,3,1},
  {0,19,2,1},
  {0,23,1,1},
  {0,27,0,1},
};
int d4[6][MAX]={
  {0,0,5,0,1},
  {0,4,4,0,1},
  {0,8,3,0,1},
  {0,12,2,0,1},
  {0,16,1,0,1},
  {0,20,0,0,1},
};

void dfs(int m){
  if(m>=ansMin) return;
  if(a[4]>0){
    FOR(i,0,w4){
      FORR(j,1,4) a[j]-=d4[i][j];
      dfs(m+1);
      FORR(j,1,4) a[j]+=d4[i][j];
    }
  }else if(a[3]>0){
    FOR(i,0,w3){
      FORR(j,1,3) a[j]-=d3[i][j];
      dfs(m+1);
      FORR(j,1,3) a[j]+=d3[i][j];
    }
  }else{
    int s=0;
    if(a[1]>0) s+=a[1];
    if(a[2]>0) s+=4*a[2];
    m+=ceil(1.00*s/36);
    ansMin=min(ansMin,m);
  }
}

int main(void){
#ifdef LOCAL
  freopen("1000_in.txt","r",stdin);
  freopen("out.txt","w",stdout);
#endif
  while(scanf("%d",&a[1])==1){
    FORR(i,2,6) scanf("%d",&a[i]);
    bool flag=0; FORR(i,1,6) if(a[i]) {flag=1; break;}
    if(!flag) break;
    tans=0; ansMin=1<<30;
    //6,5(,1,2,3)
    tans+=a[6]; a[6]=0;
    tans+=a[5]; a[1]-=11*a[5]; a[5]=0; if(a[1]<0) a[1]=0;
    tans+=a[1]/36; a[1]%=36;
    tans+=a[2]/9; a[2]%=9;
    tans+=a[3]/4; a[3]%=4;

    dfs(0);
    printf("%d\n",ansMin+tans);
  }

  return 0;
}
*/
