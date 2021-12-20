/*
Discription
对于给出的n个询问，每次求有多少个数对(x,y)，满足a≤x≤b，c≤y≤d，且gcd(x,y) = k，gcd(x,y)函数为x和y的最大公约数。

Input
第一行一个整数n，接下来n行每行五个整数，分别表示a、b、c、d、k

Output
共n行，每行一个整数表示满足要求的数对(x,y)的个数

Sample Input
2
2 5 1 5 1
1 5 1 5 2

Sample Output
14
3

HINT
100%的数据满足：1≤n≤50000，1≤a≤b≤50000，1≤c≤d≤50000，1≤k≤50000
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
#define RE register
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=50020;
int mu[MAX],prime[MAX]; bool check[MAX];
int s[MAX];
int n,a,b,c,d,k;

void init(int n){
  mu[1]=1; int tot=0;
  FORR(i,2,n){
    if(!check[i]){
      prime[tot++]=i;
      mu[i]=-1;
    }
    FOR(j,0,tot){
      if(i*prime[j]>n) break;
      check[i*prime[j]]=1;
      if(i%prime[j]==0){
        mu[i*prime[j]]=0; break;
      }else{
        mu[i*prime[j]]=-mu[i];
      }
    }
  }
  FORR(i,1,n) s[i]=s[i-1]+mu[i];
}
/*
int f(int n, int m){  //(x,y)=k, 1<=x<=n, 1<=y<=m
  if(n>m) swap(n,m);  //保证 n<=m
  int ans=0,j,j1,j2;
  for(int i=1;i<=n;i=j+1){
    //j1 = n / (k*(n/(k*i)));
    //j2 = m / (k*(m/(k*i)));
    j1 = k*(n/(k*i)); j2 = k*(m/(k*i));
    if(!j1 || !j2) break; //防止除零
    j1=n/j1; j2=m/j2;
    j=min(j1,j2);
    ans += (s[j]-s[i-1])*(n/(k*i))*(m/(k*i));
  }
  return ans;
}
*/
int f(int n, int m){  //(x,y)=1, 1<=x<=(n/k), 1<=y<=(m/k)
  n/=k; m/=k;
  if(n>m) swap(n,m);
  int ans=0,j;
  for(int i=1;i<=n;i=j+1){
    j = min( n/(n/i), m/(m/i) );
    ans += (s[j]-s[i-1])*(n/i)*(m/i);
  }
  return ans;
}

int main(void){
  init(50000);  //计算莫比乌斯函数前缀和
  scanf("%d",&n);
  while(n--){
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
    int ans=f(b,d)-f(a-1,d)-f(b,c-1)+f(a-1,c-1);  //容斥原理求解
    printf("%d\n",ans);
  }

  return 0;
}
