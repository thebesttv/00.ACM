#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[20],n;
bool book[20],check[50];

inline bool is_prime(int n){
  return check[n]==0;
}
void dfs(int cur){
  if(cur==n){
    if(is_prime(a[n-1]+a[0])){
      for(int i=0;i<n;i++){
        if(i) printf(" ");
        printf("%d",a[i]);
      }
      printf("\n");
    }
    return;
  }
  for(int i=1;i<=n;i++) if(!book[i]) if(!cur || is_prime(i+a[cur-1])){
    a[cur]=i;
    book[i]=1;
    dfs(cur+1);
    book[i]=0;
  }
}

int main(void){
  check[0]=1; check[1]=1;
  for(int i=2;i<10;i++) if(!check[i])
    for(int j=i*i;j<=50;j+=i) check[j]=1;
#ifdef DEBUG
  for(int i=1;i<=50;i++) if(is_prime(i)) printf("%d ",i);
  printf("\n");
#endif

  int kase=0;
  while(scanf("%d",&n)==1){
    memset(book,0,sizeof(book));
    if(kase) printf("\n");
    printf("Case %d:\n",++kase);
    a[0]=1; book[1]=1;
    dfs(1);
  }

  return 0;
}
