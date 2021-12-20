//bfs
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<stack>
using namespace std;

int fact[10];
struct Node{
  int v[9];
  int f,dir;
}q[362880],tar;
int to[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};  //r, l, u, d
char token[4] = {'r','l','u','d'};
bool vis[362880];

int getCode(int * a, int len);
bool try_to_insert(int n);
int bfs();
void print(int n);
int f(int n);

int main(void){
  for(int i=0;i<8;i++) tar.v[i]=i+1; tar.v[8]=0;
  fact[0]=1;
  for(int i=1;i<=8;i++) fact[i]=fact[i-1]*i;
  int T; scanf("%d",&T);
  while(T--){
    memset(vis,0,sizeof(vis)); memset(q,0,sizeof(q));
    int c;
    for(int i=0;i<9;i++){
      do c=getchar(); while(!isalnum(c));
      if(c=='x') q[0].v[i]=0;
      else q[0].v[i]=c-'0';
    }
    int y=0;
    for(int i=0;i<9;i++) y+=f(i);
#ifdef DEBUG
    printf("  y: %d\n",y);
#endif
    if(y&1) printf("unsolvable\n");
    else{
      int ans=bfs();
      if(ans!=-1) print(ans);
      else printf("unsolvable\n");
      if(T) printf("\n");
    }
  }

  return 0;
}

int bfs(){
  int head=0,tail=1;
  try_to_insert(0);
  while(head<tail){
    Node temp=q[head];
    if(!memcmp(temp.v,tar.v,sizeof(int)*9)) return head;
    int pos=0; while(temp.v[pos]) pos++;
    int x=pos/3,y=pos%3;
    for(int dir=0;dir<4;dir++){
      int tx=x+to[dir][0],ty=y+to[dir][1];
      if(tx>=0 && tx<=2 && ty>=0 && ty<=2){
        int z=tx*3+ty;
        memcpy(&q[tail],&temp,sizeof(Node));
        q[tail].v[z]=temp.v[pos];
        q[tail].v[pos]=temp.v[z];
        q[tail].f=head; q[tail].dir=dir;
        if(try_to_insert(tail)) tail++;
      }
    }
    head++;
  }
  return -1;
}
int getCode(int * a, int len){
  int code=0;
  for(int i=0;i<len;i++){
    int cnt=0;
    for(int j=i+1;j<len;j++) if(a[j]<a[i]) cnt++;
    code+=fact[len-i-1]*cnt;
  }
  return code;
}
bool try_to_insert(int n){
  int code=getCode(q[n].v,9);
  if(!vis[code]) return vis[code]=1;
  else return 0;
}
void print(int n){
  stack<char> st;
  while(n!=0){
    st.push(token[q[n].dir]);
    n=q[n].f;
  }
  while(!st.empty()) {printf("%c",st.top()); st.pop();}
  printf("\n");
}
int f(int n){
  int cnt=0;
  for(int i=0;i<n;i++) if(q[0].v[i]<q[0].v[n] && q[0].v[i]) cnt++;
  return cnt;
}
