#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

const int MAX=40;
int a[MAX],t[MAX],n;
char temp[200];

void flip(int pos){
  if(pos==n) return;
  printf("%d ",pos);
  for(int i=pos;i<=n;i++) t[n+pos-i]=a[i];
  for(int i=pos;i<=n;i++) a[i]=t[i];
}

int main(void){
  while(fgets(temp,sizeof(temp),stdin)!=NULL){
    memset(a,0,sizeof(a));
    n=0;
    char *p=strtok(temp," \n");
    while(p!=NULL){
      a[++n]=atoi(p);
      p=strtok(NULL," \n");
    }
    for(int i=1;i<=n;i++) //输出原排列
      if(i!=1) printf(" %d",a[i]);
      else printf("%d",a[i]);
    printf("\n");

    for(int i=1;i<=n;i++) t[n+1-i]=a[i];  //将a倒置，使得a[1]为底，a[n]为顶
    for(int i=1;i<=n;i++) a[i]=t[i];
#ifdef DEBUG
    for(int i=1;i<=n;i++) printf("%d ",a[i]); printf("\n");
#endif
    for(int i=1;i<n;i++){ //采取插入排序的思想
      int u=i;
      for(int j=i+1;j<=n;j++) if(a[j]>a[u]) u=j;
      if(i!=u){
        flip(u); flip(i); //先将a[u]翻到顶上，在执行flip(i)，将a[u]翻到位置i
#ifdef DEBUG
        printf("flip: %d %d\n",u,i);
        for(int i=1;i<=n;i++) printf("%d ",a[i]); printf("\n");
#endif
      }
    }
    printf("0\n");
  }

  return 0;
}
