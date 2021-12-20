/*(
题目描述
给一nXn的字母方阵，内可能蕴含多个“yizhong”单词。单词在方阵中是沿着同一方向连续摆放的。摆放可沿着8个方向的任一方向，同一单词摆放时不再改变方向，单词与单词之间[color=red]可以[/color]交叉,因此有可能共用字母。输出时，将不是单词的字母用“*”代替，以突出显示单词。

输入输出格式
输入格式：
第一行输入一个数n。(7<=n<=100)。
第二行开始输入n*n的字母矩阵。

输出格式：
突出显示单词的n*n矩阵。

输入输出样例
输入样例#1：
8
qyizhong
gydthkjy
nwidghji
orbzsfgz
hhgrhwth
zzzzzozo
iwdfrgng
yyyygggg

输出样例#1：
*yizhong
gy******
n*i*****
o**z****
h***h***
z****o**
i*****n*
y******g
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

const int MAX=120;
int n;
char G[MAX][MAX],ori[]="yizhong";
bool ans[MAX][MAX];
int to[8][2]={{1,1},{1,-1},{-1,1},{-1,-1},{1,0},{-1,0},{0,-1},{0,1}};

bool check(int x, int y, int dir){
  char t1[8];
  FOR(i,0,7){
    if(x<0 || x>=n || y<0 || y>=n) return false;
    t1[i]=G[x][y];
    x+=to[dir][0]; y+=to[dir][1];
  }
  return strcmp(ori,t1)==0;
}
void mark(int x, int y, int dir){
  FOR(i,0,7){
    ans[x][y]=1;
    x+=to[dir][0]; y+=to[dir][1];
  }
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%s",G[i]);
  FOR(i,0,n) FOR(j,0,n) FOR(dir,0,8) if(check(i,j,dir))
    mark(i,j,dir);
  FOR(i,0,n){
    FOR(j,0,n) putchar(ans[i][j] ? G[i][j] : '*');
    putchar('\n');
  }
  return 0;
}
