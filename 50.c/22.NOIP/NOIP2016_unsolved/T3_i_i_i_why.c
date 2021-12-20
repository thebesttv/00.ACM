/*
描述
对于刚上大学的牛牛来说，他面临的第一个问题是如何根据实际情况申请合适的课程。
在可以选择的课程中，有2n节课程安排在n个时间段上。在第i (1 <= i <= n)个时间段上，两节内容相同的课程同时在不同的地点进行，其中，牛牛预先被安排在教室ci上课，而另一节课程在教室di进行。
在不提交任何申请的情况下，学生们需要按时间段的顺序依次完成所有的n节安排好的课程。如果学生想更换第i节课程的教室，则需要提出申请。若申请通过，学生就可以在第i个时间段去教室di上课，否则仍然在教室ci上课。
由于更换教室的需求太多，申请不一定能获得通过。通过计算，牛牛发现申请更换第i节课程的教室时，申请被通过的概率是一个已知的实数ki，并且对于不同课程的申请，被通过的概率是互相独立的。
学校规定，所有的申请只能在学期开始前一次性提交，并且每个人只能选择至多m节课程进行申请。这意味着牛牛必须一次性决定是否申请更换每节课的教室，而不能根据某些课程的申请结果来决定其他课程是否申请；牛牛可以申请自己最希望更换教室的m门课程，也可以 不用完 这m个申请的机会，甚至可以一门课程都不申请。
因为不同的课程可能会被安排在不同的教室进行，所以牛牛需要利用课间时间从一间教室赶到另一间教室。
牛牛所在的大学有v个教室，有e条道路。每条道路连接两间教室，并且是可以 双向通行 的。由于道路的长度和拥堵程度不同，通过不同的道路耗费的体力可能会有所不同。当第i (1<= i <= n-1)节课结束后，牛牛就会从这节课的教室出发，选择一条耗费体力最少的 路径 前往下一节课的教室。
现在牛牛想知道，申请哪几门课程可以使他因在教室间移动耗费的体力值的总和的 期望值 最小，请你帮他求出这个最小值。

格式
输入格式
第一行四个整数n, m, v, e。n表示这个学期内的时间段的数量；m表示牛牛最多可以申请更换多少节课程的教室；v表示牛牛学校里教室的数量；e表示牛牛的学校里道路的数量。
第二行n个正整数，第i (1 <= i<= n)个正整数表示ci，即第i个时间段牛牛被安排上课的教室；保证1 <= Ci <= v。
第三行n个正整数，第i (1<=i<=n)个正整数表示di，即第i个时间段另一间上同样课程的教室；保证1<=di<=v。
第四行n个实数，第i (1<=i<=n)个实数表示ki，即牛牛申请在第i个时间段更换教室获得通过的概率。保证0 <= ki <= 1。
接下来e行，每行三个正整数aj，bj，wj，表示有一条双向道路连接教室aj，bj，通过这条道路需要耗费的体力值是wj；保证1 <= aj, bj <= v, 1 <= wj <= 100。
保证 1<=n<=2000，0<=m<=2000，1<=v<=300，0<=e<=90000。
保证通过学校里的道路，从任何一间教室出发，都能到达其他所有的教室。
保证输入的实数最多包含3位小数。

输出格式
输出一行，包含一个实数，四舍五入精确到小数点后 恰好2位 ，表示答案。你的输出必须和标准输出 完全一样 才算正确。
测试数据保证四舍五入后的答案和准确答案的差的绝对值不大于4 x 10^-3。（如果你不知道什么是浮点误差，这段话可以理解为：对于大多数的算法，你可以正常地使用浮点数类型而不用对它进行特殊的处理）

样例1
样例输入1
3 2 3 3
2 1 2
1 2 1
0.8 0.2 0.5
1 2 5
1 3 3
2 3 1

样例输出1
2.80

限制
子任务

  测试点    n      m    v    特殊性质1  特殊性质2
     1      1      1   300      X          X     
     2      2      0    20      X          X     
     3      2      1   100      X          X     
     4      2      2   300      X          X     
     5      3      0    20      V          V     
     6      3      1   100      V          X     
     7      3      2   300      X          X     
     8     10      0   300      V          V     
     9     10      1    20      V          X     
    10     10      2   100      X          X     
    11     10     10   300      X          V     
    12     20      0    20      V          X     
    13     20      1   100      X          X     
    14     20      2   300      V          X     
    15     20     20   300      X          V     
    16    300      0    20      X          X     
    17    300      1   100      X          X     
    18    300      2   300      V          V     
    19    300    300   300      X          V     
    20   2000      0    20      X          X     
    21   2000      1    20      X          X     
    22   2000      2   100      X          X     
    23   2000   2000   100      X          X     
    24   2000   2000   300      X          X     
    25   2000   2000   300      X          X     

特殊性质1：图上任意两点ai , bi , ai ≠ bi间，存在一条耗费体力最少的路径只包含一条道路。
特殊性质2：对于所有的1 <= i <= n，ki = 1。

提示
样例1说明
所有可行的申请方案和期望收益如下表：

  申请更换教室  申请通过的  出现的概率  耗费的体力值    耗费的体力值
    的时间段      时间段                                   的期望
       无           无         1.0           8              8.0
                                                               
        1            1         0.8           4              4.8
                    无         0.2           8                 
                                                               
        2            2         0.2           0              6.4
                    无         0.8           8                 
                                                               
        3            3         0.5           4              6.0
                    无         0.5           8                 
                                                               
      1,2          1,2         0.16          4             4.48
                     1         0.64          4                 
                     2         0.04          0                 
                    无         0.16          8                 
                                                               
      1,3          1,3         0.4           0              2.8
                     1         0.4           4                 
                     3         0.1           4                 
                    无         0.1           8                 
                                                               
      2,3          2,3         0.1           4              5.2
                     2         0.1           0                 
                     3         0.4           4                 
                    无         0.4           8                 


提示
道路中可能会有多条双向道路连接相同的两间教室。也有可能有道路两端连接的是同一间教室。
请注意区分n,m,v,e的意义，n 不是教室的数量，m 不是道路的数量。

来源
NOIP 2016 提高组 Day 1 第三题
*/

/*
  得分：80
  解题报告：
    一开始看到期望，就方了。。。事实证明的确挺绕。。。
    总之，可以枚举所有时间段的子集，然后对每个子集计算期望。
    期望的计算：
      每个子集S都有2^|S|个可能，每个可能Pi都有固定的体力和概率。
      枚举子集中每一个申请是否被通过，如果通过，则概率乘上通过的概率，否则乘上不通过的概率
        并且在枚举的同时计算出每一个Pi所造成的n个教室的位置，即可计算体力。
      概率乘上体力即为当前Pi的“期望”（因为我也说不清具体时什么。。。），每个Pi期望的和即为当前的子集S的期望。
    然而还是有4个点T了。。。
  正解：
    没想到是可以递推的。。。
    首先要了解期望的本质，本题中，期望是指：在已做出选择（选哪些时间段）的情况下，其会造成的所有可能的结果的可能性与那个结果的代价的加权平均数。即，对一种选择，若它会造成n中可能的结果R1,R2,...,Rn，且每个结果Ri的可能性为Pi，则期望为
      R1*P1 + R2*P2 + ... + Rn*Pn
    也就是说，只要选择一定，那么期望一定。
    而期望又是可以递推的。（Why???）
    又因为本题求的是最小期望那么就可以用类似DP的方法。
    令 f[i][j][0/1]表示：只考虑前i个时间段（只上前i段时间的课、且只申请前i段时间）、共申请j个时间段、是否申请第i个时间段，所得的最小期望
      f[i][j][1]表示申请第i段时间，f[i][j][0]表示不申请第i段时间。
    那么就可以分情况递推：
      对于f[i][j][0]，那么一定在c[i]上课
        1.前一个没申请
          f[i][j][0] = min(f[i][j][0], f[i-1][j][0] + G[c[i-1]][c[i]]);
        2.前一个申请了
          (1)申请成功，在d[i-1]上课
          (2)申请失败，在c[i-1]上课
          f[i][j][1] = min(f[i][j][1], f[i-1][j][1] + G[d[i-1]][c[i]]*p[i-1] + G[c[i-1]][c[i]]*(1-p[i-1]));
      对于f[i][j][0]，那么可能成功，也可能失败
        1.前一个没申请
          (1)当前申请成功
          (2)当前申请失败
        f[i][j][1] = min(f[i][j][1], f[i-1][j-1][0] + G[c[i-1]][d[i]]*p[i] + G[c[i-1]][c[i]]*(1-p[i]));
        2.前一个申请了
          (1)前一个申请成功
            ((1))当前申请成功
            ((2))当前申请失败
          (2)前一个申请失败
            ((1))当前申请成功
            ((2))当前申请失败
        f[i][j][1] = min(f[i][j][1], f[i-1][j-1][1]
          + G[d[i-1]][d[i]]*p[i-1]*p[i]           //1
          + G[d[i-1]][c[i]]*p[i-1]*(1-p[i])       //2
          + G[c[i-1]][d[i]]*(1-p[i-1])*p[i]       //3
          + G[c[i-1]][c[i]]*(1-p[i-1])*(1-p[i])); //4
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

const int MAX=2020;
const int MAXV=320;
const int INF=0x3f3f3f3f;
int n,m,v,e,c[MAX],d[MAX];
int G[MAXV][MAXV];
double p[MAX];
double f[MAX][MAX][2];
  //f[i][j][0]: 只上前i个时间段、共提交了j份申请（申请前i个中的某些）、且当前课不申请的最小期望
  //f[i][j][1]: 只上前i个时间段、共提交了j份申请（申请前i个中的某些）、且当前的课申请的最小期望

int main(void){
  scanf("%d%d%d%d",&n,&m,&v,&e);
  FORR(i,1,n) scanf("%d",&c[i]);
  FORR(i,1,n) scanf("%d",&d[i]);
  FORR(i,1,n) scanf("%lf",&p[i]);
  MST(G,0x3f); FORR(i,1,v) G[i][i]=0;
  for(int i=0,a,b,w;i<e;i++){
    scanf("%d%d%d",&a,&b,&w);
    if(w>=G[a][b]) continue;
    G[a][b]=G[b][a]=w;
  }

  FORR(k,1,v) FORR(i,1,v) if(G[i][k]<INF) FORR(j,1,v) if(G[k][j]<INF)
    G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
  FORR(i,1,n) FORR(j,0,m) f[i][j][0]=f[i][j][1]=INF;
  f[1][0][0]=f[1][1][1]=0;
  FORR(i,2,n) FORR(j,0,min(i,m)){
    f[i][j][0] = min( f[i-1][j][0] + G[c[i-1]][c[i]], f[i-1][j][1] + G[d[i-1]][c[i]]*p[i-1] + G[c[i-1]][c[i]]*(1-p[i-1]));
    if(j) f[i][j][1] = min( f[i-1][j-1][0] + G[c[i-1]][d[i]]*p[i] + G[c[i-1]][c[i]]*(1-p[i]),
                            f[i-1][j-1][1] + G[d[i-1]][d[i]]*p[i-1]*p[i]
                                           + G[d[i-1]][c[i]]*p[i-1]*(1-p[i])
                                           + G[c[i-1]][d[i]]*(1-p[i-1])*p[i]
                                           + G[c[i-1]][c[i]]*(1-p[i-1])*(1-p[i]));
  }
  double ansMin=INF;
  FORR(i,0,m) ansMin=min(ansMin,min(f[n][i][0],f[n][i][1]));
  printf("%.2lf\n",ansMin);

  return 0;
}

/*
const int MAXN=2020;
const int MAXV=320;
const int INF=0x3f3f3f3f;
int n,m,v,e;
int c[MAXN],d[MAXN];
double posi[MAXN];
int G[MAXV][MAXV];
int sset[MAXN];
double ansMin=1<<30;

double hope();
void sub_set(int last, int step){
  if(step==m) {ansMin=min(ansMin,hope()); return;}
  FORR(i,last+1,n){
    sset[step]=i; sub_set(i,step+1);
  }
  sset[step]=0; sub_set(last,m);
}

int main(void){
  MST(G,0x3f);
  scanf("%d%d%d%d",&n,&m,&v,&e);
  FORR(i,1,n) scanf("%d",&c[i]);
  FORR(i,1,n) scanf("%d",&d[i]);
  FORR(i,1,n) scanf("%lf",&posi[i]);
  FORR(i,1,v) G[i][i]=0;
  for(int i=0,a,b,w;i<e;i++){
    scanf("%d%d%d",&a,&b,&w);
    if(a==b || G[a][b]<w) continue; //<b></b>
    G[a][b]=G[b][a]=w;
  }

  FORR(k,1,v) FORR(i,1,v) if(G[i][k]<INF) FORR(j,1,v) if(G[k][j]<INF)
    G[i][j]=min(G[i][j],G[i][k]+G[k][j]);

  sub_set(0,0);

  printf("%.2lf\n",ansMin);

  return 0;
}

double hope(){
  int len=0;
  for(;len<m;len++) if(!sset[len]) break;
#ifdef DEBUG
  printf("  sub_set:");
  FOR(i,0,m) if(sset[i]) printf(" %d",sset[i]);
  printf("\n");
  //printf("    len: %d\n",len);
#endif
  double ans=0;
  FOR(i,0,1<<len){  //枚举是否通过

    //memcpy(final,c,SIZ(c));
    //for(register int j=0,t;j<len;j++) if((i>>j)&1){ //最终每堂课的位置
    //  t=sset[j];
    //  final[t]=d[t];
    //}
    //
    ////计算总体力
    //int sum=0;
    //FOR(j,1,n) sum+=G[final[j]][final[j+1]];
    //
    ////计算可能性
    //double tp=1;
    //FOR(j,0,len)
    //  if((i>>j)&1)  //通过
    //    tp*=posi[sset[j]];
    //  else          //不通过
    //    tp*=1.0-posi[sset[j]];

    int t; double tp=1.0;
    FOR(j,0,len){
      t=sset[j];
      if((i>>j)&1){
        swap(c[t],d[t]);
        tp*=posi[t];
      }else tp*=1.0-posi[t];
    }

    int sum=0;
    FOR(j,1,n) sum+=G[c[j]][c[j+1]];

    FOR(j,0,len) if((i>>j)&1){
      t=sset[j]; swap(c[t],d[t]);
    }

#ifdef DEBUG
    printf("    in one possible com, pos = %d * %.2lf = %.2lf\n",sum,tp,tp*sum);
#endif
    ans+=tp*sum;
  }
  return ans;
}
*/
