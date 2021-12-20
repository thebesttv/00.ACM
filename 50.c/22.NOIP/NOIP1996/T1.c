/*
问题描述
设有2^n（n<=6）个球队进行单循环比赛，计划在(2^n)–1天内完成，每个队每天进行一场比赛。设计一个比赛的安排，使在(2^n)–1天内每个队都与不同的对手比赛。
例如n=2时的比赛安排：
队   1 2 3 4
比赛 1==2 3==4 一天
1==3 2==4 二天
1==4 2==3 三天

输入格式
输入的第一行包含以个整数n。

输出格式
输出(2^n)-1行，每行开头为一对尖括号，里面输出天数序号。随后写出这天的安排。详细格式见样例。有多个方案则输出字典序最小的方案。

样例输入
2

样例输出
<1>1-2,3-4
<2>1-3,2-4
<3>1-4,2-3

数据规模和约定
n<=6
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=(1<<7);
bool G[MAX][MAX],book[MAX];

int main(void){
  int n; scanf("%d",&n);
  int tot_days=(1<<n)-1,tot_players=(1<<n),daily_rounds=(1<<(n-1));
  for(int day=1;day<=tot_days;day++){
    printf("<%d>",day);
    memset(book,0,sizeof(book));
    for(int round=0;round<daily_rounds;round++){
      int p1,p2;
      for(p1=1;p1<=tot_players;p1++) if(!book[p1]) break;
      for(p2=1;p2<=tot_players;p2++) if(!book[p2] && !G[p1][p2] && p1!=p2) break;
      book[p1] = book[p2] = G[p1][p2] = G[p2][p1] = 1;
      printf("%d-%d",p1,p2); if(round!=daily_rounds-1) printf(",");
    }
    printf("\n");
  }

  return 0;
}

/*
//网络
#include<cstdio>  
#include<cstring>  
using namespace std;  

#define maxn 100  
bool a[maxn],b[maxn][maxn];  
int main(){  
  int n,i,j,k,s,sum;
  scanf("%d",&n);
  s=1<<n;
  for(i=1;i<s;i++){  
    memset(a,0,sizeof(a));
    printf("<%d>",i);
    sum=0;
    for(j=1;j<s;j++) for(k=j+1;k<=s;k++)
      if(!a[j] && !a[k] && !b[j][k] && !b[k][j]){  
        a[j]=a[k]=1;
        b[j][k]=b[k][j]=1,sum++;
        printf("%d-%d",j,k);
        if(sum<(s>>1))printf(" ");
      }
    printf("\n");
  }  

  return 0;  
}  
*/
