/*
描述
欧拉函数 phi(n) 统计了 1 到 n 中与 n 互素的数字个数，例如 phi(9)=6。
现在给定正整数 A 和 B，请找出最小的正整数 n 满足 phi(n)/(n-1) < A/B 。

格式
输入格式
输入只有一行，是两个正整数 A 和 B，满足 1≤A<B≤10^6 。

输出格式
输出一个正整数，表示最小满足条件的 n。

样例1
样例输入1
1 2

样例输出1
6

样例2
样例输入2
2 5

样例输出2
12

限制
对于 20% 的数据，保证答案不超过 10^7
对于 30% 的数据，保证答案不超过 2.5 * 10^8
对于 40% 的数据，保证答案不超过 7 * 10^9
对于 50% 的数据，保证答案不超过 2.5 * 10^11
对于 60% 的数据，保证答案不超过 3.5 * 10^14
对于 70% 的数据，保证答案不超过 1.5 * 10^16
对于 80% 的数据，保证答案不超过 7 * 10^17
对于 90% 的数据，保证答案不超过 3.5 * 10^30
对于 100% 的数据，保证答案不超过 10^200
每一组数据的时限为 1 秒。
*/

/*
  得分：20
  解题报告：
    无奈只能暴力，phi table的生成还是抄的。。。
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

typedef long long unsigned LLU;
const int MAX=10000000;
int phi[MAX+20];

void phi_table(){
  phi[1]=1;
  FORR(i,2,MAX) if(!phi[i])
    for(int j=i;j<=MAX;j+=i){
      if(!phi[j]) phi[j]=j;
      phi[j]=phi[j]/i*(i-1);
    }
}

int main(void){
  phi_table();
  LLU A,B; scanf("%llu%llu",&A,&B);
#ifdef DEBUG
  printf(" done\n");
  FORR(i,1,20) printf("  phi(%d): %d\n",i,phi[i]);
#endif
  FORR(i,2,MAX) if(B*phi[i]<A*(i-1)){
    printf("%d\n",i); break;
  }

  return 0;
}






















/*
int gcd(int a, int b){
  return !b ? a : gcd(b,a%b);
}

int phi(int n){
  int cnt=0;
  FOR(i,1,n) if(gcd(i,n)==1) cnt++;
  return cnt;
}

int main(void){
  FORR(i,1,10000000) printf("phi(%d): %d\n",i,phi(i));


  return 0;
}
*/
