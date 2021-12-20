#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAX=1000+10;
int c[MAX],a[MAX],s[MAX];
int n;

inline int lowbit(int i) {return i & (-i);}
int sum(int i){
  int tot=0;
  while(i>0){
    tot+=c[i]; i-=lowbit(i);
  }
  return tot;
}
void add(int i, int d){
  while(i<=n){
    c[i]+=d; i+=lowbit(i);
  }
}

int main(void){
  srand(time(NULL));
  scanf("%d",&n);
  for(int i=1;i<=n;i++) {a[i]=(double)rand()/RAND_MAX*100; printf("%3d ",a[i]);} printf("\n");
  for(int i=1;i<=n;i++) add(i,a[i]);
  for(int i=1;i<=n;i++) {s[i]=sum(i); printf("%3d ",s[i]);} printf("\n");
  int l,r;
  while(scanf("%d%d",&l,&r)==2){
    printf("%d\n",s[r]-s[l-1]);
  }

  return 0;
}
