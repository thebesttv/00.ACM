#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,X[5][30],let[30],vis[30]={0},q[30]={0}; //vis[i]: 数i是否被使用
bool check(){
  int i,j,tmp[5][30]={0};
  for(i=1;i<=3;i++){
    for(j=0;j<n;j++){
      tmp[i][j]=let[X[i][j]];
    }

  }
  int k=0,re[30]={0};
  for(i=n-1;i>=0;i--){
    re[i]=tmp[1][i]+tmp[2][i]+k;k=0;
    k=re[i]/n;
    re[i]=re[i]%n;
  }
  if(memcmp(re,tmp[3],sizeof(re))==0 && k==0) return true;
  else return false;
}
bool checkcheck(){  //进行不进位的加法并判断（大多数情况下，因字母没有被全部枚举到，无法进行完整计算）
  int i;
  for(i=n-1;i>=0;i--){
    int x=X[1][i],y=X[2][i],z=X[3][i];
    if(let[x]!=-1&&let[y]!=-1&&let[z]!=-1){
      int flag=0;
      if((let[x]+let[y])%n==let[z]) flag=1;   //有无进位两种情况
      if((let[x]+let[y]+1)%n==let[z]) flag=1;
      if(!flag) return false;
    }
  }
  return true;
}
void dfs(int step){ //当前枚举的字母为p[step]
  int i;
  if(step==n){
    if(check()){
      for(i=0;i<n-1;i++){
        printf("%d ",let[i]);
      }
      printf("%d",let[n-1]);
      exit(0);
    }
  }
  if(!checkcheck()) return; //**剪枝2）**
  for(i=n-1;i>=0;i--){ //**剪枝3）**  //因最高位不能有进位，因此从地位到高位要从大到小枚举
    if(!vis[i]){
      let[q[step]]=i;
      vis[i]=1;
      dfs(step+1);
      vis[i]=0;
      let[q[step]]=-1;
    }
  }
}
int main(){
  freopen("in.txt","r",stdin);
  int i,j,book[30]={0};
  char ch;
  scanf("%d",&n);
  ch=getchar();
  for(i=1;i<=3;i++){
    for(j=0;j<n;j++){
      scanf("%c",&ch);
      X[i][j]=ch-'A';
    }
    ch=getchar();
  }
  int top=0;
  for(i=n-1;i>=0;i--){
    int x=X[1][i],y=X[2][i],z=X[3][i];
    if(!book[x]){
      q[top++]=x;book[x]=1;
    }
    if(!book[y]){
      q[top++]=y;book[y]=1;
    }
    if(!book[z]){
      q[top++]=z;book[z]=1;
    }
  } //**剪枝1）** //优先枚举低位字母
  memset(let,-1,sizeof(let));
  dfs(0);
  return 0;
}
