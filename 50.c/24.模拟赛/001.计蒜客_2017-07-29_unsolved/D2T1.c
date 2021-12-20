/*
蒜头君的小伙伴在 第一年 送给他一对 一岁 的兔子，并告诉他：这种兔子 刚生下来时算 0 岁，到了 2 岁时就可以繁殖了，它在 2−10 岁时，每年会生下来一对兔子，这些兔子到了 2 岁也可以繁殖，但这些兔子在 10 岁那年 生完仔后 不久就会死亡，蒜头君想知道，第 n 年兔子 产仔之后（第 n 年 10 岁的兔子此时已经死亡），他会有多少对兔子。结果对 1000000007 取模。

输入格式
共一行，一个正整数 n，表示蒜头君想知道第 n 年的兔子总对数。

输出格式
输出一个整数，表示第 n 年兔子总对数对 1000000007 取模的值。

数据规模
对于 30% 的数据，满足 1≤n≤10^3
对于 60% 的数据，满足 1≤n≤10^5
对于 100% 的数据，满足 1≤n≤10^9

样例输入1
10

样例输出1
88

样例输入2
88

样例输出2
352138150

样例输入3
10086

样例输出3
405567313
*/

/*
  得分：60
  解题报告：
  花了很久在电脑上模拟，发现可以使用数组递推，但只能过60%。
*/

#include<iostream>
#include<cstdio>
using namespace std;

const unsigned long long MOD=1000000007;
const int MAX=1000000;
unsigned long long a[MAX]={1,0,1,1,2,3,5,8,13,21,34};

int main(void){
  unsigned long long sum=54;
  for(int i=11;i<MAX;i++){
    a[i]=sum;
    sum=(sum+a[i-1]-a[i-10]+MOD)%MOD;
    if(a[i]<0) printf("in %d wrong\n",i);
  }
  int n; scanf("%d",&n);
  sum=0; for(int i=n;i>=n-9;i--) sum=(sum+a[i])%MOD;
  printf("%llu\n",sum);

  return 0;
}
