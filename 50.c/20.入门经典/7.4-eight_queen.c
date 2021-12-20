#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=20;
int c[MAX];
int n,cnt=0;
int vis[3][2*MAX];  //<b>数组要开两倍</b>

void search(int cur);

int main(void){
  #ifdef LOCAL
  freopen("in","r",stdin);
  #endif
  scanf("%d",&n);
  search(0);
  printf("tot: %d\n",cnt);

  return 0;
}

/*
//original
void search(int cur){
  if(cur==n){
    printf("%d:",++cnt);
    for(int i=0;i<n;i++) printf(" %d",c[i]);
    printf("\n");
  }else for(int i=0;i<n;i++){
    bool ok=1; c[cur]=i;
    for(int j=0;j<cur;j++) if(c[j]==c[cur] || c[cur]-c[j]==cur-j || c[cur]-c[j]==j-cur){
      ok=0; break;
    }
    if(ok) search(cur+1);
  }
}
*/

//improved, 使用数组记录 i 是否可行
//速度：
//  当 n=13 时，original 用时 12.8s ，improved 用时 1.8s
void search(int cur){
  if(cur==n){
    cnt++;
    //printf("%d:",++cnt);
    //for(int i=0;i<n;i++) printf(" %d",c[i]);
    //printf("\n");
  }else for(int i=0;i<n;i++) if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]){
    vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1; c[cur]=i;
    search(cur+1);
    vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
  }
}
