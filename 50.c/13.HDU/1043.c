//dbfs
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

const int MAX=362880;
const int MAXQ=10000;
struct Node{
  int v[9];
  int f,dir,code;
}q0[MAXQ],q1[MAXQ];
int head0,head1,tail0,tail1,node0,node1;
bool vis0[MAX],vis1[MAX];
int pos0,pos1;
int to[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};  //r, l, u, d
char token1[4] = {'r','l','u','d'};
char token2[4] = {'l','r','d','u'};
int fact[9];

bool dbfs();
int expand(bool type);
int getCode(const Node & a);
void print();

int main(void){
#ifdef LOCAL
  freopen("in","r",stdin);
#endif
  fact[0]=1;
  for(int i=1;i<9;i++) fact[i]=fact[i-1]*i;
  while(1){
    pos0 = pos1 = 0;
    memset(q0,0,sizeof(q0)); memset(vis0,0,sizeof(vis0));
    memset(q1,0,sizeof(q1)); memset(vis1,0,sizeof(vis1));
    int c;
    for(int i=0;i<9;i++){
      do c=getchar(); while(!isalnum(c) && c!=EOF);
      if(c==EOF) return 0;
      else if(c=='x') q0[0].v[i]=0;
      else if(isdigit(c)) q0[0].v[i]=c-'0';
    }
    for(int i=0;i<8;i++) q1[0].v[i]=i+1; q1[0].v[8]=0;

    int y=0;
    for(int i=1;i<9;i++) for(int j=0;j<i;j++) if(q0[0].v[j]<q0[0].v[i] && q0[0].v[j]) y++;
    if(y&1) printf("unsolvable\n");
    else{
      if(dbfs()) print();
      else printf("unsolvable\n");
    }
  }

  return 0;
}

bool dbfs(){ //问题：若直接输入目标，因无输出，却输出 lr
  head0=head1=0; tail0=tail1=1; node0=node1=0;
  q0[0].code=getCode(q0[0]); vis0[q0[0].code]=1;  //问题原因：未记录最开始两个队列中的元素
  q1[0].code=getCode(q1[0]); vis1[q1[0].code]=1;
  int sw=0;
  while(head0<tail0 && head1<tail1){
#ifdef DEBUG
    printf("  in while of bdfs, q1(%d,%d,%d), q2(%d,%d,%d)\n",head0,tail0,node0,head1,tail1,node1);
#endif
    int ans;
    //    if(sw&1){   //好像两个 if 的效果差不多
    if(tail0-head0 < tail1-head1){
      ans=expand(0);
      if(ans!=-1){
        for(int i=tail1-1;i>=0;i--) if(q1[i].code==q0[ans].code) {pos1=i; break;}
        return true;
      }
    }else{
      ans=expand(1);
      if(ans!=-1){
        for(int i=tail0-1;i>=0;i--) if(q0[i].code==q1[ans].code) {pos0=i; break;}
        return true;
      }
    }
    sw++;
  }
  return false;
  }
  int expand(bool type){
    int *phead,*ptail,*pnode; Node * q;
    if(!type){phead=&head0; ptail=&tail0; pnode=&node0; q=q0;}
    else {phead=&head1; ptail=&tail1; pnode=&node1; q=q1;}
    int &head=*phead, &tail=*ptail, &node=*pnode;
    node=0;
    Node temp=q[head];
    if(!type){
      if(vis1[temp.code]) {pos0=head; return head;}
    }else{
      if(vis0[temp.code]) {pos1=head; return head;}
    }
    int pos=0; while(temp.v[pos]) pos++;
    int x=pos/3,y=pos%3;
    for(int dir=0;dir<4;dir++){
      int tx=x+to[dir][0],ty=y+to[dir][1];
      if(tx>=0 && tx<=2 && ty>=0 && ty<=2){
        int z=tx*3+ty;
        memcpy(q[tail].v,temp.v,sizeof(int)*9);
        q[tail].v[z]=temp.v[pos];
        q[tail].v[pos]=temp.v[z];
        q[tail].f=head; q[tail].dir=dir;
        int code=q[tail].code=getCode(q[tail]);
        if(!type){
          if(!vis0[code]) {vis0[code]=1; tail++; node++;}
        }else{
          if(!vis1[code]) {vis1[code]=1; tail++; node++;}
        }
      }
    }
    head++;
    return -1;
  }
  int getCode(const Node & a){
    int code=0;
    for(int i=0;i<9;i++){
      int cnt=0;
      for(int j=i+1;j<9;j++) if(a.v[j]<a.v[i]) cnt++;
      code+=fact[8-i]*cnt;
    }
    return code;
  }
  void print(){
    stack<char> st;
    int code=q0[pos0].code;
    while(pos0){
      st.push(token1[q0[pos0].dir]);
      pos0=q0[pos0].f;
    }
    while(!st.empty()){
      putchar(st.top()); st.pop();
    }
    while(pos1){
      putchar(token2[q1[pos1].dir]);
      pos1=q1[pos1].f;
    }
    printf("\n");
  }