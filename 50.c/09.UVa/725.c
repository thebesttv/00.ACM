#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool vis[10];
bool flag;

void solve(int n){
  for(int b=1234;b<=98765;b++){
    memset(vis,0,sizeof(vis));
    int a=b*n; if(a>98765) return;
    int ta=a,tb=b;
    if(b<10000 || a<10000) vis[0]=1;
    while(ta>0) {vis[ta%10]=1; ta/=10;}
    while(tb>0) {vis[tb%10]=1; tb/=10;}
    bool ok=1;
    for(int i=0;i<10;i++) if(!vis[i]) {ok=0; break;}
    if(ok){
      flag=1;
      printf("%05d / %05d = %d\n",a,b,n);
    }
  }
}

int main(void){
  int n,kase=0;
  while(scanf("%d",&n)==1 && n){
    flag=0;
    if(kase++) printf("\n");
    solve(n);
    if(!flag) printf("There are no solutions for %d.\n",n);
  }

  return 0;
}
