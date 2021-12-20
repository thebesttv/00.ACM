#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[20];

int main(void){
  int n,kase=0;
  while(scanf("%d",&n)==1){
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    long long Max=0;
    for(int i=0;i<n;i++) for(int j=i;j<n;j++){
      long long sum=1;
      for(int k=i;k<=j;k++) sum*=a[k];
      Max=max(Max,sum);
    }
    printf("Case #%d: The maximum product is %lld.\n\n",++kase,Max);
  }

  return 0;
}
