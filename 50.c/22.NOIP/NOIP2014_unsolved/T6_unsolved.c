/*
描述
已知多项式方程：
  a0 + a1*x + a2*x^2 + a3*x^3 + ... + an*x^n=0
求这个方程在[1, m]内的整数解（n 和 m 均为正整数）。

格式
输入格式
输入共 n+2 行。
第一行包含 2 个整数 n、m，每两个整数之间用一个空格隔开。
接下来的 n+1 行每行包含一个整数，依次为a0, a1, ..., an

输出格式
第一行输出方程在[1, m]内的整数解的个数。
接下来每行一个整数，按照从小到大的顺序依次输出方程在[1, m]内的一个整数解。

样例1
样例输入1
2 10
1
-2
1

样例输出1
1
1

样例2
样例输入2
2 10
2
-3
1

样例输出2
2
1
2

样例3
样例输入3
2 10
1
3
2

样例输出3
0

限制
对于30%的数据，0<n≤2, |ai|<=100, ai!=0, m<=100
对于50%的数据，0<n≤100, |ai|<=10^100, ai!=0, m<=100
对于70%的数据，0<n≤100, |ai|<=10^10000, ai!=0, m<=10000
对于100%的数据，0<n≤100, |ai|<=10^10000, ai!=0, m<=1000000

来源
NOIP2014 提高组 Day2
*/

/*
  得分：10(30)
  解题报告：
    尴尬。。。最后提交的时候忘了把n<=2的情况取消注释，然后光荣地得了10分。。。不过本来最多也只能得30。。。

  正解：
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

const int MOD=2000002679;
const int MAX=120;
int a[MAX],power[MAX],n,m;
char t1[10020];

int main(void){
  scanf("%d%d",&n,&m);

  if(n<=2){
    FORR(i,0,n) scanf("%d",&a[i]);
    int cnt=0; VR<int> v;
    FORR(x,1,m){
      int d=1,ans=0;
      FORR(i,0,n){
        ans+=d*a[i];
        d*=x;
      }
      if(!ans) {cnt++; v.push_back(x);}
    }
    printf("%d\n",cnt);
    FOR(i,0,cnt) printf("%d\n",v[i]);
  }else{
    FORR(i,0,n){
      int ans=0;
      scanf("%s",t1); int len=strlen(t1);
      if(t1[0]=='-'){
        FOR(i,1,len) ans=(1LL*ans+t1[i]-'0')%MOD;
        ans*=-1;
      }else FOR(i,0,len) ans=(1LL*ans+t1[i]-'0')%MOD;
      a[i]=ans;
    }
    int cnt=0; VR<int> v;
    FORR(x,1,m){
      int d=1,ans=0;
      FORR(i,0,n){
        ans=(1LL*d*a[i]+ans)%MOD;
        d=(1LL*d*x)%MOD;
      }
      if(!ans) {cnt++; v.push_back(x);}
    }
    printf("%d\n",cnt);
    FOR(i,0,cnt) printf("%d\n",v[i]);
  }

  return 0;
}
