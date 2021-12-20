/*
描述
在一个非降序列中，查找与给定值最接近的元素。

输入
第一行包含一个整数n，为非降序列长度。1 <= n <= 100000。
第二行包含n个整数，为非降序列各元素。所有元素的大小均在0-1,000,000,000之间。
第三行包含一个整数m，为要询问的给定值个数。1 <= m <= 10000。
接下来m行，每行一个整数，为要询问最接近元素的给定值。所有给定值的大小均在0-1,000,000,000之间。

输出
m行，每行一个整数，为最接近相应给定值的元素值，保持输入顺序。若有多个值满足条件，输出最小的一个。
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int a[100000],n,m;

int main(void){
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  scanf("%d",&m); int t;
  for(int i=0;i<m;i++){
    scanf("%d",&t);
    int *p=lower_bound(a,a+n,t);
    if(p-a==n) printf("%d\n",*(p-1));
    else{
      if(p-a>0 && abs(*(p-1)-t)<=abs(*p-t)) p--;
      printf("%d\n",*p);
    }
  }
  return 0;
}
