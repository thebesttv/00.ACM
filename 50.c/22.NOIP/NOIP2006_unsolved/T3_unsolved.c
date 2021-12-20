/*
题目描述
我们现在要利用m台机器加工n个工件，每个工件都有m道工序，每道工序都在不同的指定的机器上完成。每个工件的每道工序都有指定的加工时间。
每个工件的每个工序称为一个操作，我们用记号j-k表示一个操作，其中j为1到n中的某个数字，为工件号；k为1到m中的某个数字，为工序号，例如2-4表示第2个工件第4道工序的这个操作。在本题中，我们还给定对于各操作的一个安排顺序。
例如，当n=3，m=2时，“1-1，1-2，2-1，3-1，3-2，2-2”就是一个给定的安排顺序，即先安排第1个工件的第1个工序，再安排第1个工件的第2个工序，然后再安排第2个工件的第1个工序，等等。
一方面，每个操作的安排都要满足以下的两个约束条件。
  (1) 对同一个工件，每道工序必须在它前面的工序完成后才能开始；
  (2) 同一时刻每一台机器至多只能加工一个工件。
另一方面，在安排后面的操作时，不能改动前面已安排的操作的工作状态。
由于同一工件都是按工序的顺序安排的，因此，只按原顺序给出工件号，仍可得到同样的安排顺序，于是，在输入数据中，我们将这个安排顺序简写为“1 1 2 3 3 2”。
还要注意，“安排顺序”只要求按照给定的顺序安排每个操作。不一定是各机器上的实际操作顺序。在具体实施时，有可能排在后面的某个操作比前面的某个操作先完成。
例如，取n=3,m=2，已知数据如下：
  工件号 机器号/加工时间
      工序1 工序2
   1  1/3   2/2
   2  1/2   2/5
   3  2/2   1/4
则对于安排顺序“1 1 2 3 3 2”，下图中的两个实施方案都是正确的。但所需要的总时间分别是10与12。

                  方案一                                            方案二
        +--------+-----+-----------+                    +--------+-----+     +-----------+
  机器1 |   1    |  2  |     3     |              机器1 |   1    |  2  |     |     3     |
        --------------------------------->              ----------------------------------------->
                 3     5           9                             3     5     7           11

        +-----+  +-----+--------------+                          +-----+-----+--------------+
  机器2 |  3  |  |  1  |       2      |           机器2          |  1  |  3  |      2       |
        --------------------------------->              ----------------------------------------->
              2  3     5              10                         3     5     7              12

当一个操作插入到某台机器的某个空档时（机器上最后的尚未安排操作的部分也可以看作一个空档），可以靠前插入，也可以靠后或居中插入。为了使问题简单一些，我们约定：在保证约束条件（1）（2）的条件下，尽量靠前插入。并且，我们还约定，如果有多个空档可以插入，就在保证约束条件（1）（2）的条件下，插入到最前面的一个空档。于是，在这些约定下，上例中的方案一是正确的，而方案二是不正确的。
显然，在这些约定下，对于给定的安排顺序，符合该安排顺序的实施方案是唯一的，请你计算出该方案完成全部任务所需的总时间。

输入输出格式
输入格式：
输入的第1行为两个正整数，用一个空格隔开： m n （其中m（<20）表示机器数，n（<20）表示工件数）
第2行：m*n个用空格隔开的数，为给定的安排顺序。
接下来的2n行，每行都是用空格隔开的m个正整数，每个数不超过20。
  其中前n行依次表示每个工件的每个工序所使用的机器号，第1个数为第1个工序的机器号，第2个数为第2个工序机器号，等等。
  后n行依次表示每个工件的每个工序的加工时间。
可以保证，以上各数据都是正确的，不必检验。

输出格式：
输出只有一个正整数，为最少的加工时间。

输入输出样例
输入样例#1：
2 3
1 1 2 3 3 2
1 2 
1 2 
2 1
3 2 
2 5 
2 4

输出样例#1：
10

说明
NOIP 2006 提高组 第三题
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX_TIME=100000;
const int MAX=22;
bool tl[MAX][MAX_TIME];
struct Pro{
  int num,time;
}pro[MAX][MAX];   //pro[i][j]: 工件号为i的工件，其第j个工序
int tmp_ord[MAX];     //暂时存储每个工件的工序号
int ord[MAX*MAX][2];  //ord[i][0]: 第i个操作的工件号
                      //ord[i][1]: 第i个操作对应工件的工序号
int cur_time[MAX];  //当前每个工件最后一道工序停止的时间

void ins(int n);

int main(void){
  int n,m; scanf("%d%d",&m,&n);
  int tot=n*m,tnum;
  for(int i=0;i<tot;i++){
    scanf("%d",&tnum);  //工件号
    ord[i][0]=tnum;     //工件号
    ord[i][1]=++tmp_ord[tnum];  //工序号
  }
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&pro[i][j].num);   //机器号
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&pro[i][j].time);  //时间

  //模拟
  for(int i=0;i<tot;i++){ //对每个ord
    ins(i);
  }
#ifdef DEBUG
  int tmax=0;
  for(int i=1;i<=m;i++){
    printf("  %d:",i); for(int j=0;j<=tail[i];j++) printf("%3d",tl[i][j]); printf("\n");
    tmax=max(tmax,tail[i]);
  }
  printf("   :"); for(int j=0;j<=tmax;j++) printf("%3d",j); printf("\n");
#endif
  int ans=0;
  for(int i=1;i<=m;i++) ans=max(ans,cur_time[i]);
  printf("%d\n",ans);

  return 0;
}

void ins(int n){
  int wnum=ord[n][0],pnum=ord[n][1];
  int mnum=pro[wnum][pnum].num;
  int time=pro[wnum][pnum].time;
  int pos=cur_time[wnum],last;
  bool done=0;
  while(!done){
    while(tl[mnum][pos]) pos++;
    last=pos;
    bool flag=1;
    for(int i=0;i<time;i++){  //???
      if(tl[mnum][pos]) {flag=0; break;}
      else pos++;
    }
    if(flag){
      done=true;
      for(int i=0;i<time;i++) tl[mnum][i+last]=1;
      //cur_time[wnum]=pos;
      cur_time[wnum]=max(cur_time[wnum],last+time);
    }
  }
}








































/*
  得分：30，7个点TLE
  解题报告：
    //考试时以为只是模拟，本来想用差分，但感觉复杂度还好，就没用。。。
    //不能正确估计时间复杂度。
*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX_TIME=10000;
const int MAX=22;
bool tl[MAX][MAX_TIME];
int head[MAX],tail[MAX];  //时间轴中第一个和最后一个空闲区间的第一格
struct Pro{
  int num,time;
}pro[MAX][MAX];   //pro[i][j]: 工件号为i的工件，其第j个工序
int tmp_ord[MAX];     //暂时存储每个工件的工序号
int ord[MAX*MAX][2];  //ord[i][0]: 第i个操作的工件号
                      //ord[i][1]: 第i个操作对应工件的工序号
int cur_time[MAX];

void ins(int ordnum);

int main(void){
  int n,m; scanf("%d%d",&m,&n);
  int tot=n*m,tnum;
  for(int i=0;i<tot;i++){
    scanf("%d",&tnum);  //工件号
    ord[i][0]=tnum;     //工件号
    ord[i][1]=++tmp_ord[tnum];  //工序号
  }
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&pro[i][j].num);   //机器号
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&pro[i][j].time);  //时间

  //模拟
  for(int i=0;i<tot;i++){ //对每个ord
    ins(i);
  }
#ifdef DEBUG
  int tmax=0;
  for(int i=1;i<=m;i++){
    printf("  %d:",i); for(int j=0;j<=tail[i];j++) printf("%3d",tl[i][j]); printf("\n");
    tmax=max(tmax,tail[i]);
  }
  printf("   :"); for(int j=0;j<=tmax;j++) printf("%3d",j); printf("\n");
#endif
  int ans=0;
  for(int i=1;i<=m;i++) ans=max(ans,tail[i]);
  printf("%d\n",ans);

  return 0;
}

void ins(int n){
  int wnum=ord[n][0],pnum=ord[n][1];  //工件号和工序号
  int mnum=pro[wnum][pnum].num;   //机器号
  int time=pro[wnum][pnum].time;  //时间
  int pos=max(head[mnum],cur_time[wnum]),last;
  bool done=0;
#ifdef DEBUG
  printf("  insert wnum: %d, pnum: %d, in machine: %d, time: %d, with head: %d, tail: %d\n",wnum,pnum,mnum,time,head[mnum],tail[mnum]);
#endif
  while(!done){ //XXX
    while(tl[mnum][pos]) pos++; //将pos放到第一个空闲区间的第一格
    last=pos;
    while(!tl[mnum][pos+1] && pos-last+1<time) pos++;  //走到第一个为1的格子或长度正好为time的格子
    if(pos-last+1>=time){ //找到第一个足够大的空闲区间
      done=true;
      for(int i=0;i<time;i++) tl[mnum][last+i]=1;
      cur_time[wnum]=pos+1;
    }
  }
  while(tl[mnum][head[mnum]]) head[mnum]++;
  tail[mnum] = max(tail[mnum], max(cur_time[wnum],head[mnum])); //??
  while(tl[mnum][tail[mnum]]) tail[mnum]++; //XXX
}
*/
