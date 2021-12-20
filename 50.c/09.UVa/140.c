#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=26;
bool G[MAX][MAX],isNode[MAX];
int v[MAX],save[MAX];
int n,ansMin;

bool read();

int main(void){
  while(read()){
    ansMin=1<<30;
    int P[MAX],tail=0;
    for(int i=0;i<MAX;i++) if(isNode[i]) P[tail++]=i;
    do{
      int bw=0;
      for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(G[P[i]][P[j]])
        bw=max(bw,j-i);
      if(bw<ansMin){
        ansMin=bw;
        memcpy(save,P,sizeof(P));
      }
    }while(next_permutation(P,P+n));
    for(int i=0;i<n;i++) printf("%c ",save[i]+'A');
    printf("-> %d\n",ansMin);
  }
  return 0;
}

bool read(){
  memset(G,0,sizeof(G)); n=0;
  for(int i=0;i<MAX;i++) {isNode[i] = v[i] = save[i] = 0;}
  int c,cur;
  bool stop=0;
  while(!stop){
    cur=getchar();
    if(cur=='#') return 0;
    cur-='A';
    isNode[cur]=1;
    while(1){
      c=getchar();
      if(isalpha(c)){
        c-='A'; isNode[c]=1;
        if(!G[cur][c]){
          G[cur][c] = G[c][cur] = 1;
        }
      }else if(c==';') break;
      else if(c=='\n') {stop=1; break;}
    }
  }
  for(int i=0;i<MAX;i++) if(isNode[i]) n++;
#ifdef DEBUG_1
  printf("  total nodes: %d\n",n);
  for(int i=0;i<MAX;i++) if(isNode[i]){
    printf("    %c: deg: %d, connected to:",i+'A',deg[i]);
    for(int j=0;j<MAX;j++) if(G[i][j]) printf(" %c",j+'A');
    printf("\n");
  }
#endif
  return 1;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=26;
bool G[MAX][MAX],vis[MAX],isNode[MAX];
int v[MAX],save[MAX],deg[MAX];
int n,ansMin;

bool read();
void dfs(int cur, int bw);

int main(void){
  while(read()){
    ansMin=1<<30;
    dfs(0,0);
    for(int i=0;i<n;i++) printf("%c ",save[i]+'A');
    printf("-> %d\n",ansMin);
  }
  return 0;
}

void dfs(int cur, int bw){
  if(cur==n){
    if(bw<ansMin){
      ansMin=bw;
      memcpy(save,v,sizeof(v));
    }
    return;
  }
  for(int i=0;i<MAX;i++) if(isNode[i] && !vis[i]){
//    int tot=0;                                                  //剪枝：当进入一个节点i时，令还未访问的与i相连节点数为n，组成集合S
//    for(int j=0;j<cur;j++) if(!vis[j] && G[i][v[j]]) tot++;     //      则只有当S中的n个节点都顺次排列时，其组成的部分 bandwidth 最小，为n
//    if(tot>=ansMin) continue;                                   //好像并没有什么用。。。
#ifdef DEBUG
    printf("  in dfs(%d,%d), trying node %c\n",cur,bw,i+'A');
#endif
    int t=0;
    for(int j=0;j<cur;j++) if(G[v[j]][i]) t=max(t,cur-j);
//    for(int j=0;j<cur;j++)
//      for(int k=j+1;k<cur;k++) if(G[v[j]][v[k]]) t=max(t,k-j);
    v[cur]=i;
    vis[i]=1;
    dfs(cur+1,max(bw,t));
    vis[i]=0;
  }
}
bool read(){
  memset(G,0,sizeof(G)); n=0;
  for(int i=0;i<MAX;i++) {vis[i] = isNode[i] = v[i] = save[i] = deg[i] = 0;}
  int c,cur;
  bool stop=0;
  while(!stop){
    cur=getchar();
    if(cur=='#') return 0;
    cur-='A';
    isNode[cur]=1;
    while(1){
      c=getchar();
      if(isalpha(c)){
        c-='A'; isNode[c]=1;
        if(!G[cur][c]){
          G[cur][c] = G[c][cur] = 1;
          deg[cur]++; deg[c]++;
        }
      }else if(c==';') break;
      else if(c=='\n') {stop=1; break;}
    }
  }
  for(int i=0;i<MAX;i++) if(isNode[i]) n++;
#ifdef DEBUG_1
  printf("  total nodes: %d\n",n);
  for(int i=0;i<MAX;i++) if(isNode[i]){
    printf("    %c: deg: %d, connected to:",i+'A',deg[i]);
    for(int j=0;j<MAX;j++) if(G[i][j]) printf(" %c",j+'A');
    printf("\n");
  }
#endif
  return 1;
}
*/
