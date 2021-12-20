#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=4010;
int A[MAX],B[MAX],C[MAX],D[MAX];
int sum[MAX*MAX];

int main(void){
  int T; scanf("%d",&T);
  for(int kase=0;kase<T;kase++){
    if(kase) printf("\n");
    int n,ans=0; scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
    int tail=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
      sum[tail++]=C[i]+D[j];
    sort(sum,sum+tail);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
      int t=A[i]+B[j]; t=-t;
      int i,pos=lower_bound(sum,sum+tail,t)-sum;
      if(sum[pos]==t){
        i=pos;
        while(i<tail && sum[i+1]==t) i++;
        ans+=i-pos+1;
      }
    }
    printf("%d\n",ans);
  }

  return 0;
}
