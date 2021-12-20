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

/*
  令 f(i,S1,S2) 表示考虑前i个人时、只有一个老师教的科目集合为S1、有两个及以上老师教的科目集合为S2时的最小花费。
  也因为对于i，无法求出i-1时的S2，则
    f(i,S1,S2) = min{ f(i+1,S1,S2), f(i+1,S1',S2')+c[i] }, 其中 S1',S2' 表示考虑i后的新集合。
*/

const int MAX=140;
const int INF=0x3f3f3f3f;
int s,m,n;
int check[MAX][1<<8][1<<8];
int st[MAX],c[MAX];
char t1[200];

void read(int i); //读取函数
int f(int i, int S0, int S1, int S2);

int main(void){
  while(scanf("%d%d%d",&s,&m,&n)==3 && s){ getchar();
    MST(check,-1); MST(st,0);
    FOR(i,0,m+n) read(i);
    printf("%d\n",f(0,(1<<s)-1,0,0));
  }

  return 0;
}

void read(int i){ //读取函数
  FGETS(t1);
  char * p=strtok(t1," \n\r"); c[i]=atoi(p);
  p=strtok(NULL," \n\r");
  while(p){
    int t=atoi(p)-1;  //题目中标号为1:s，改为0:s-1
    st[i]|=1<<t;
    p=strtok(NULL," \n\r");
  }
}
int f(int i, int S0, int S1, int S2){
  if(i==m+n) return !S0 && S1==0 && S2==(1<<s)-1 ? 0 : INF;
  int & a=check[i][S1][S2];
  if(a!=-1) return a;
  a=INF;
  if(i>=m) a=f(i+1,S0,S1,S2);
  int m0=st[i]&S0,m1=st[i]&S1;
  S0^=m0; S1=(S1^m1)|m0; S2|=m1;
  return a=min(a,f(i+1,S0,S1,S2)+c[i]);
}

/*
  将所有教师放在一个数组中，在职教师为0:m-1，求职者为m:m+n-1
  令 f(i,S) 表示当考虑前i个教师、课程的状态为S时的最小花费
    在S中，对每个课程使用一个三进制数表示，0: 没有人教, 1: 有一个人教, 2: 至少有两个人教
  但因为在递推时不能根据当前S算出i-1时的S（因为当S中的一个课程为2时，不知道是只有两人教还是有大于两人教），因此只能向后递推，得
    f(i,S) = min{ f(i+1,S), f(i+1,S+{st[i]} + c[i] }
    当i=m+n时，只有当S中每个课程都有人教时才返回0，否则返回INF。
*/

/*
const int MAX=140;
const int INF=0x3f3f3f3f;
int s,m,n,std_;
int st[MAX],c[MAX],check[MAX][1<<16];
char t1[200];

void read(int i); //读取函数
int f(int i, int S);
void PRINT(int n);

int main(void){
  while(scanf("%d%d%d",&s,&m,&n)==3 && s){ getchar();
    MST(check,-1); MST(st,0);
    FOR(i,0,m+n) read(i);
    std_=0; for(int i=1;i<(s<<1);i+=2) std_|=1<<i;  //std_即为每个课程都有至少两个老师教的状态
    printf("%d\n",f(0,0));
  }

  return 0;
}

void read(int i){ //读取函数
  FGETS(t1);
  char * p=strtok(t1," \n\r"); c[i]=atoi(p);
  p=strtok(NULL," \n\r");
  while(p){
    int t=atoi(p)-1;  //题目中标号为1:s，改为0:s-1
    st[i]|=1<<t;
    p=strtok(NULL," \n\r");
  }
}
int f(int i, int S){
  if(i==n+m) return S==std_ ? 0 : INF;  //边界条件
  int & a=check[i][S];
  if(a!=-1) return a;
  a=INF;  //<b></b>
  if(i>=m) a=f(i+1,S);

  //假设要雇佣i
  FOR(j,0,s) if(st[i]&(1<<j)){  //根据st[i]更新S
    int t=((S>>(j<<1))&1) + ((S>>(j<<1|1))&1)<<1;
    if(t<2) t++;
    S&=~(3<<(j*2)); S|=(t&1)<<(j*2); S|=((t>>1)&1)<<(j*2+1);
  }
  return a=min(a,f(i+1,S)+c[i]);
}
void PRINT(int n){
  printf("***");
  FOR(i,0,(s<<1)) printf("%d",1&(n>>i));
  printf("***");
}
*/
