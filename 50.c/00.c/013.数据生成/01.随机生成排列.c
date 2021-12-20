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
  方法：
    [1]调用STL中的random_shuffle函数
      random_shuffle(a,a+n);
      需要生成随机数种子
    [2]随机交换
      FOR(i,0,tot){
        int i=get(n),j=get(n);
        swap(a[i],a[j]);
      }
*/

const int MAX=10000;
int a[MAX];

int main(void){
  srand(time(NULL));
  int n; scanf("%d",&n);
  FOR(i,0,n) a[i]=i+1;

  FOR(i,0,10){
    random_shuffle(a,a+n);
    printf("%2d.",i); FOR(j,0,n) printf(" %d",a[j]); printf("\n");
  }


  return 0;
}
