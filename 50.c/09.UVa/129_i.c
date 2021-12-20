#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char a[200];
int n,l,tot;
bool flag;

bool dfs(int cur){
  if(cur) tot++;
  if(tot==n){
    flag=1;
    for(int i=0;i<cur;i++){
      printf("%c",a[i]+'A');
      if(i!=cur-1){
        if((i+1)%64==0) printf("\n");
        else if((i+1)%4==0) printf(" ");
      }
    }
    printf("\n%d\n",cur);
    return 1;
  }
  for(int i=0;i<l;i++){
    a[cur]=i;
    bool ok=1;
    for(int j=1;j*2<=(cur+1);j++){
      bool same=1;
      for(int k=0;k<j;k++) if(a[cur-k]!=a[cur-j-k]) {same=0; break;}
      if(same) {ok=0; break;}
    }
    if(ok){
      if(dfs(cur+1)) return 1;
    }
  }
  return 0;
}

int main(void){
  while(scanf("%d%d",&n,&l)==2 && n){
    memset(a,0,sizeof(a));
    tot=0; flag=0;
    dfs(0);
  }

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char a[200],save[200];
int n,l,tot,len;
bool flag;

void dfs(int cur){
  if(cur) tot++;
#ifdef DEBUG
  printf("  in dfs(%d), tot: %d, a:",cur,tot);
  for(int i=0;i<cur;i++) printf(" %c",a[i]+'A');
  printf("\n");
#endif
  if(tot==n){
    flag=1; len=cur;
#ifdef DEBUG
    printf("  find, len: %d\n",len);
#endif
    memcpy(save,a,sizeof(char)*cur);
    return;
  }
  for(int i=0;i<l;i++){
    a[cur]=i;
    bool ok=1;
    for(int j=1;j*2<=(cur+1);j++){
      bool same=1;
      for(int k=0;k<j;k++) if(a[cur-k]!=a[cur-j-k]) {same=0; break;}
      if(same) {ok=0; break;}
    }
    if(ok){
      if(flag) return;
      dfs(cur+1);
    }
  }
}

int main(void){
  while(scanf("%d%d",&n,&l)==2 && n){
    memset(a,0,sizeof(a)); memset(save,0,sizeof(save));
    tot=0; flag=0; len=0;
    dfs(0);
//  printf("  len: %d\n",len);
    for(int i=0;i<len;i++){
      printf("%c",save[i]+'A');
      if(i!=len-1){
        if((i+1)%64==0) printf("\n");
        else if((i+1)%4==0) printf(" ");
      }
    }
    printf("\n%d\n",len);
  }

  return 0;
}
*/
