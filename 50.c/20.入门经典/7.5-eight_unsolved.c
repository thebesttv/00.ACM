#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

const int fact_of_9=362880;
int q[fact_of_9][9];
int dis[fact_of_9];
int fa[fact_of_9],save[fact_of_9];
int tar[9];
int to[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
char token[4] = {'r','l','u','d'};

void init_lookup_table();
bool try_to_insert(int n);
void print(int n);
int bfs();
//[1]
int fact[9];
bool vis[fact_of_9];

int main(void){
  for(int i=0;i<8;i++) tar[i]=i+1; tar[8]=0;
  int T; scanf("%d",&T);
  for(int kase=0;kase<T;kase++){
    memset(q,0,sizeof(q)); memset(dis,0,sizeof(dis)); memset(fa,0,sizeof(fa)); memset(save,0,sizeof(save));
    memset(vis,0,sizeof(vis));
//  for(int i=0;i<9;i++) scanf("%d",&q[0][i]);
//  for(int i=0;i<9;i++) scanf("%d",&tar[i]);
    char temp[3];
    for(int i=0;i<9;i++){
      scanf("%s",temp);
      if(temp[0]=='x') q[0][i]=0;
      else q[0][i]=temp[0]-'0';
    }
    int ans=bfs();
    if(ans==-1) printf("unsolvable\n");
    else{
      if(kase) printf("\n");
      print(ans);
//    printf("%d\n",dis[ans]);
    }
  }

  return 0;
}

int bfs(){
  init_lookup_table();
  try_to_insert(0);
  int pos=0;
  while(q[0][pos]) pos++;
  int x=pos/3, y=pos%3;
  int head=0, tail=1;
  while(head<tail){
#ifdef DEBUG
//    printf("  in bfs, q[%d],",head);
//    for(int i=0;i<9;i++) printf(" %d",q[head][i]);
//    printf("\n");
#endif
    if(!memcmp(q[head],tar,sizeof(tar))) return head;
    pos=0; while(q[head][pos]) pos++;
    x=pos/3; y=pos%3;
    for(int i=0;i<4;i++){
      int tx=x+to[i][0];
      int ty=y+to[i][1];
      if(tx>=0 && tx<=2 && ty>=0 && ty<=2){
        int z=tx*3+ty;
        memcpy(q[tail],q[head],sizeof(q[head]));
        q[tail][z]=q[head][pos];
        q[tail][pos]=q[head][z];
        save[tail]=i; fa[tail]=head;  //保存到达当前状态的方向和父节点
        dis[tail]=dis[head]+1;
        if(try_to_insert(tail)) tail++;
      }
    }
    head++;
  }
  return -1;
}

void print(int n){
  stack<char> st;
  while(n>0){
    st.push(token[save[n]]);
    n=fa[n];
  }
  while(!st.empty()){
    printf("%c",st.top()); st.pop();
  }
  printf("\n");
}

//[1]
void init_lookup_table(){
  fact[0]=1;
  for(int i=1;i<9;i++) fact[i]=fact[i-1]*i;
}
bool try_to_insert(int n){
  //encode
  int code=0;
  for(int i=0;i<9;i++){
    int cnt=0;
    for(int j=i+1;j<9;j++) if(q[n][j]<q[n][i]) cnt++;
    code+=fact[8-i]*cnt;
  }
  if(vis[code]) return 0;
  else return vis[code]=1;
}
