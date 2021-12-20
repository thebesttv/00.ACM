/*
描述
怀表是由一个表链和一个表盘连接而成的。同时，表链又是由多个长度为1的表链组件连接而成的。小明现有一个表盘和多个长度为1的表链组件。他希望组合成一个完整的怀表当做生日礼物送给爸爸。
表盘和表链组件的两端都有表扣可以和其它的表链组件或者表盘相连。 一共有两种表扣设计，分别是“L” 和“V”。表链组件和表盘的左右两端可以使用相同的或者不同的表扣设计，因此我们有以下四种不同的表链组件和表盘设计方式，“LL”, “LV”, “VL”, “VV”，如“LV”表示左端的表扣设计是“L”, 右端的表扣设计是“V”。另，表盘和表链是不允许上下左右翻转的。如果把两个表链组件或者一个表链组件和表盘相连接，那么相连部分的表扣设计必须一致。此外，还必须确保表盘可以连接到表链的任意一端。
例子1：表盘是“LV”，共有5个表链组件分别是，“LL”, “LL”, “LV”, “VL”, “VL” 。现在希望组合成长度为4的怀表（表链长度是4）。 有两种正确的表链组合方式：“VLLLLVVL” 和“VLLVVLLL”。而且，对于每一种表链的组合方式，表盘都可以连接到表链的左右两端 （表盘放到表链左端使用V相连，表盘放到表链右端使用L相连）。
例子2:  表盘是“LL”，共有4个表链组件分别是，“LL”, “LV”, “VL”, “VV”。现在希望组合成长度为3的怀表（表链长度是3）。有三种正确的表链组合方式：“LLLVVL”, “LVVLLL”和“LVVVVL”。而且，对于每一种表链的组合方式，表盘都可以接到表链的任一端。
注意怀表的组合方式可能不唯一。每一种表链的组合方式都可以当做是一个由“L”和“V”组成的字符串。如果两种表链对应的字符串是不匹配的， 那么表链也是不相同的。

输入
标准的输入包含若干组测试数据。每组数据第一行是整数N (0 < N ≤ 40)和K (0 < K ≤ N) 。
N 代表表链组件的个数，K代表要组合成的怀表长度(表链组件的个数)。
接着的N+ 1 行描述表盘（第二行）和表链组件的表扣设计。有四种可能输入： “LV”, “LL”, “VV” 和“VL”。

输出
对于每组测试数据，输出一行。 输出“YES”, 如果可能按照要求组合成怀表，并输出可能的组合方式的数目。如果不能，则输出”NO”.

样例输入
4 4
LV
LL
LV
VL
VL
4 4
VL
LL
LV
VL
VL

样例输出
YES
2
NO

提示
提示: 本题需要使用 long long 数据类型。 
*/

#include<iostream>
#include<cstdio>
using namespace std;

#define CODE(ch) ((ch[0]=='L')<<1 | (ch[1]=='L'))
#define LINK(a, b) ((a&1) == (b>>1))
//VV: 00, VL: 01, LV: 10, LL: 11

const int MAX = 41 * 41 * 41 * 41 + 1;
const int c41p3 = 68921; //41^3
const int c41p2 = 1681;  //41^2
int tot[4],k,n,p;
long long check[MAX];
char kase[MAX];
char curKase=0; //范围：[1,254]

long long dfs(int code, int cur, int l){ //code为tot的编码，cur为当前表链头
  if(l==k) return LINK(cur,p);
  if(kase[code]==curKase) return check[code];
  long long & a = check[code] = 0; kase[code]=curKase;
  if(code / c41p3 && LINK(cur,0))
    a += dfs(code - c41p3, 0, l+1);
  if(code / c41p2 % 41 && LINK(cur,1))
    a += dfs(code - c41p2, 1, l+1);
  if(code / 41 % 41 && LINK(cur,2))
    a += dfs(code - 41, 2, l+1);
  if(code % 41 && LINK(cur,3))
    a += dfs(code-1, 3, l+1);
  return a;
}

int main(void){
  while(scanf("%d%d",&n,&k)==2){
    char ch[3];
    tot[0]=tot[1]=tot[2]=tot[3]=0;
    curKase = curKase==254 ? 1 : curKase+1;
    scanf("%s",ch); p=CODE(ch);
    for(int i=0;i<n;i++){
      scanf("%s",ch); tot[CODE(ch)]++;
    }
#ifdef DEBUG
    printf("  p: %d\n  ",p);
    for(int i=0;i<4;i++) printf("tot[%d]: %d, ",i,tot[i]);
    printf("\n");
#endif
    int code = tot[0]*c41p3 + tot[1]*c41p2 + tot[2]*41 + tot[3];
    long long ans=dfs(code,p,0);
    ans ? printf("YES\n%lld\n",ans) : printf("NO\n");
  }

  return 0;
}


































/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=50;
long long check[MAX][MAX][4];
int v[MAX],n,k,p;
int to[4][2] = {{0,3},{0,3},{1,2},{1,2}};

int get(char * str);
long long f(int i, int j, int k){ //用前i个组件组成长为j的、最后一个为k的表链的种数
                                  //f(i,j,k) = 1, j==1 && k==p
                                  //         = f(i-1,j,k) + f(i-1,j-1,x), v[i]==k, x为所有能和k匹配的左组件
                                  //         = f(i-1,j,k), v[i]!=k
  long long & a = check[i][j][k];
  if(a!=-1) return a;
  if(j>i || j<=0) a = 0;
  else if(i==1){
    if(v[i]==k) a = 1;
    else a = 0;
  }else{
    if(v[i]==k) a = f(i-1,j,k) + f(i-1,j-1,to[k][0]) + f(i-1,j-1,to[k][1]);
    else a = f(i-1,j,k);
  }
#ifdef DEBUG
  printf("  f(%d,%d,%d): %lld\n",i,j,k,a);
#endif
  return a;
}

int main(void){
  char temp[3];
  while(scanf("%d%d",&n,&k)==2){
    memset(check,-1,sizeof(check)); memset(v,0,sizeof(v));
    for(int i=0;i<=n;i++){  //v[0], v[n+1]为表盘
      scanf("%s",temp);
      v[i]=get(temp);
    }
    v[n+1]=v[0];
    long long ans=f(n+2,k+2,v[0]);
#ifdef DEBUG
    printf("  debug:\n");
    for(int i=0;i<=n+2;i++) for(int j=0;j<=k+2;j++) for(int k=0;k<4;k++)
      printf("  f(%d,%d,%d): %lld\n",i,j,k,check[i][j][k]);
#endif
    if(ans) printf("YES\n%lld\n",ans);
    else printf("NO\n");
  }

  return 0;
}

int get(char * str){
  if(str[0]=='L'){
    if(str[1]=='L') return 0;
    else return 1;
  }else{
    if(str[1]=='V') return 2;
    else return 3;
  }
}
*/

/*
//网络
#include<stdio.h>

long long F[20000][4];//必须优化储存方式以防MLE 
int t[4];//VV:0,VL:1,LV:2,LL:3

inline int g(int x,int y,int z,int w)
{
  return (((x*(t[1]+1)+y)*(t[2]+1)+z)*(t[3]+1)+w);
}

long long f(int* num,int k,int goal)
{
  if (num[0]<0 || num[1]<0 || num[2]<0 || num[3]<0) return 0;
  if (F[g(num[0],num[1],num[2],num[3])][goal]!=-1)
    return F[g(num[0],num[1],num[2],num[3])][goal];
  if (k==1) return (num[goal]>0);
  int temp[4]={num[0],num[1],num[2],num[3]};
  int l=goal&2,r=goal&1;
  temp[l]--;
  F[g(num[0],num[1],num[2],num[3])][goal]=f(temp,k-1,r);
  temp[l]++;
  temp[l+1]--;
  F[g(num[0],num[1],num[2],num[3])][goal]+=f(temp,k-1,2+r);
  return F[g(num[0],num[1],num[2],num[3])][goal];
}

int main()
{
  int n,k,goal;
  char c1,c2;
  while (scanf("%d %d\n",&n,&k)!=EOF)
  {
    scanf("%c%c\n",&c1,&c2);
    for (int i=0;i<20000;i++)   
      F[i][0]=F[i][1]=F[i][2]=F[i][3]=-1;
    t[0]=t[1]=t[2]=t[3]=0;
    goal=((c2=='L')<<1)+(c1=='L');//要求适配 
    for (int i=1;i<=n;i++)
    {
      scanf("%c%c\n",&c1,&c2);
      t[((c1=='L')<<1)+(c2=='L')]++;
    }
    long long ans=f(t,k,goal);
    if (ans)
      printf("YES\n%lld\n",ans);
    else
      printf("NO\n");
  }
  return 0;
}
*/
