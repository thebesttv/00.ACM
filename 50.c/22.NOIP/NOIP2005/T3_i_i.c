/*
描述
佳佳刚进高中，在军训的时候，由于佳佳吃苦耐劳，很快得到了教官的赏识，成为了“小教官”。在军训结束的那天晚上，佳佳被命令组织同学们进行篝火晚会。一共有n个同学，编号从1到n。一开始，同学们按照1，2，……，n的顺序坐成一圈，而实际上每个人都有两个最希望相邻的同学。如何下命令调整同学的次序，形成新的一个圈，使之符合同学们的意愿，成为摆在佳佳面前的一大难题。
佳佳可向同学们下达命令，每一个命令的形式如下：

(b1, b2,... bm -1, bm) （注：bi的值任意，如：3,1,4,5）

这里m的值是由佳佳决定的，每次命令m的值都可以不同。这个命令的作用是移动编号是b1，b2，…… bm –1，bm的这m个同学的位置。要求b1换到b2的位置上，b2换到b3的位置上，……，要求bm换到b1的位置上。
执行每个命令都需要一些代价。我们假定如果一个命令要移动m个人的位置，那么这个命令的代价就是m。我们需要佳佳用最少的总代价实现同学们的意愿，你能帮助佳佳吗?

对于30%的数据，n <= 1000；
对于全部的数据，n <= 50000。

格式
输入格式
输入的第一行是一个整数n（3 <= n <= 50000），表示一共有n个同学。其后n行每行包括两个不同的正整数，以一个空格隔开，分别表示编号是1的同学最希望相邻的两个同学的编号，编号是2的同学最希望相邻的两个同学的编号，……，编号是n的同学最希望相邻的两个同学的编号。

输出格式
输出包括一行，这一行只包含一个整数，为最小的总代价。如果无论怎么调整都不能符合每个同学的愿望，则输出-1。

样例1
样例输入1
4
3 4
4 3
1 2
1 2

样例输出1
2

限制
1s

来源
NOIp2005 第三题
*/

/*
  得分：10
  解题报告：（考后）
    题目大意：给定一个目标序列，通过某种置换使得当前的有序序列转化为目标序列，并求出最少需要置换的人数。
    通过思考可以发现：因为bi的顺序和个数都是任意的，所有只要通过一次“精心策划”的置换即可达到目标状态。
    但因为目标状态是无序的，由顺序到无序不容易，可以反过来，考虑另一种等价的转换：从目标状态到当前状态，即从无序到有序。
    那么就可以确定一个“零点”，正序扫描所有人，统计目标状态中共有多少人不在他们应该在的位置上，即为答案。
    但因为这是一个环，是可以任意旋转的，在基准点（零点）确定之前，每个人都没有“绝对位置”一说，所有要尝试所有的基准点，复杂度即为O(n^2)，而这样的复杂度对于高达5*10^4的n是无能为力的。
    因此考虑降低复杂度。
    我们引入“相对有序”的概念，对于任意i,j，如果pos[i]-pos[j]=i-j（pos[i]为目标状态中i的位置（因为通常是开数组来解的，i也就有了一个“数组位置”）），即当目标状态i和j的间距与当前状态i和j的间距相等时，称i和j是相对有序的。
    因为两种状态下i和j的间距相等，那么就可以旋转整个环，使得i和j变得真正有序，也即，一定存在一个不会置换i,j的最优置换。
    那么，只要求出在某一特定基准点下，最多的相对有序的人数T，答案即为n-T。
    令 t = c[i]-i, c[i]>=i  ，t即为目标状态到当前状态需要走的步数。
           c[i]-i+n, c[i]<i
    那么t相同的人即为相对有序的。
    对每个i，使cnt[t][0]++，记录基准t下相对有序的人数，然后将目标序列反向排列，再求一次cnt[t][1]，答案即为 n-max{cnt}。
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=50020;
int n,G[MAX][2];
int a[MAX];
int cnt[MAX][2];  //cnt[i][0]: 在正方向上，走i步能到正确位置的人数
                  //cnt[i][1]: 在负方向上，走i步能到正确位置的人数
bool vis[MAX];

bool build(){
  a[0]=0; a[1]=G[0][0]; vis[a[0]]=vis[a[1]]=1;
  for(int i=1;i<n-1;i++){
    if(a[i-1]==G[a[i]][0] && !vis[G[a[i]][1]]) a[i+1]=G[a[i]][1];
    else if(a[i-1]==G[a[i]][1] && !vis[G[a[i]][0]]) a[i+1]=G[a[i]][0];
    else return false;
    vis[a[i+1]]=1;
  }
  if(a[n-1]!=G[a[0]][1] || (a[0]!=G[a[n-1]][0] && a[0]!=G[a[n-1]][1])) return false;
  for(int i=0;i<n;i++) if(!vis[i]) return false;
  return true;
}

int main(void){
  scanf("%d",&n);
  for(int i=0;i<n;i++) {scanf("%d%d",&G[i][0],&G[i][1]); G[i][0]--; G[i][1]--;};

  int ans=0;
  if(!build()) ans=-1;
  else{
    for(int i=0;i<n;i++){
      cnt[(a[i]-i+n)%n][0]++; //i顺时针走到a[i]所需的步数
      cnt[(a[n-i-1]-i+n)%n][1]++;
    }
    for(int i=0;i<n;i++)
      ans=max(ans,max(cnt[i][0],cnt[i][1]));
    ans=n-ans;
  }
  printf("%d\n",ans);

  return 0;
}

/*
//网络
//分析：学一个好思想：正难则反！由顺序到乱序我们很难快速找到，但是我们知道如何从乱序变为顺序！解决本题利用了组合数学中置换群的思想。
//从第一个人处断开，将圆环的问题转化为序列的问题。如果可以，求出目标序列。求出目标序列复杂度O(n).
//求出目标序列右移0至n-1位置时，不需要移动的人数。将目标序列反转，再求出目标序列右移0至n-1位置时，不需要移动的人数。求不需要移动的人数最大等价于求需要移动的人数最小。复杂度O(n)。
//更详细的说：
//引进“相对有序”这个概念，当两个人满足C[j]-C[i]==j-i时，两个相对有序。
//题目要求最小的总代价，但是我们可以考虑倒过来想，要求最小的总代价亦即求最多有多少人不用移动，亦即相对有序。
//然后我们引进一个辅助变量T=C-I,{C-I>=0},T=C[i]-I+N,{C[i]-I<0},那么这个T[i]有什么意义呢？我们知道初始状态的编号是1-N，而目标状态是C[1]-C[N],那么C-I便是从目标状态到初始状态顺时针所要移动的距离，那么如果那么T值相等的两个同学则是相对有序的，亦即不用移动，我们只要找出最大的T然后N-Max(T)就是得到的结果，但是这样还不够，因为刚刚那样只是顺时针所要移动的距离，我们还要计算逆时针的到的结果，从顺时针和逆时针中找到最大的T，然后N-Max(T) 才能够是正确结果.

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 50000 + 10;
int n, m;
int vis[maxn];
int G[maxn][2];
int B[maxn];

bool init () {
  memset(vis, 0, sizeof(vis));
  B[0] = 0; B[1] = G[0][0];
  vis[B[0]] = vis[B[1]] = 1;
  for (int i = 1; i < n-1; i++) {
    if (B[i-1] == G[B[i]][0]) B[i+1] = G[B[i]][1];
    else if (B[i-1] == G[B[i]][1]) B[i+1] = G[B[i]][0];
    else return false;
    vis[B[i+1]] = 1;
  }
  for (int i = 0; i < n; i++)
    if (!vis[i]) return false;
  return true;
}

int cnt[maxn][2];
int solve () {
  for (int i = 0; i < n; i++) {
    cnt[(B[i]-i+n)%n][0]++;       //令T[i]=(B[i]-i+n)%n，其意义为从目标状态到初始状态要走的距离
                                  //当T[i]==T[j]时，i和j是相对有序的，即可以通过将圈旋转T[i]个人使得i和j在正确的位置上
    cnt[(B[n-i-1]-i+n)%n][1]++;   //那么cnt[i]即T[j]=i的人数，即在i的状态下的相对有序人数
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, max(cnt[i][0], cnt[i][1]));

  return n-ans;
}

int main () {
  // freopen("in.txt", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &G[i][0], &G[i][1]);
    G[i][0]--; G[i][1]--;
  }

  if (init()) cout << solve() << "\n";
  else cout << "-1\n";

  return 0;
}
*/
