#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=100000000;
bool a[MAX];
int b[10000];

int main(void){
  int n; scanf("%d",&n);
  int p=0;
  for(int i=2;i<=n;i++){
    if(a[i]==0) b[p++]=i; //如果a[i]没有被标记，入表
    for(int j=0;j<p && i*b[j]<=n;j++){  //枚举表中所有素数b[j]，并保证i*b[j]<=n
      a[i*b[j]]=1;
      if(i%b[j]==0) break;  //如果i能被b[j]整除，则停止枚举
    }
  }
  for(int i=0;i<p;i++) printf("%d ",b[i]); printf("\n");

  return 0;
}
