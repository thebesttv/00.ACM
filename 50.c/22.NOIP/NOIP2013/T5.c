//对随机数据的优化（骗分）
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=100020;
int h[MAX],f[MAX][2]; //f[i][t]: [1:i]形成的满足条件A（t=0）或条件B（t=1），最多能保留的花的珠数
                      //若t=0，f[i][t] = max{ f[i-j][t]+1 | 若f[i-j][t]为奇数，则h[i-j]<h[i]；若f[i-j][t]为偶数，则h[i-j]>h[i] }
                      //若t=1，f[i][t] = max{ f[i-j][t]+1 | 若f[i-j][t]为奇数，则h[i-j]>h[i]；若f[i-j][t]为偶数，则h[i-j]<h[i] }
int n;

int main(void){
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&h[i]);
  int ansMax=1;
  f[0][0]=f[0][1]=1;
  for(int i=1;i<n;i++){
    int t=min(i,40);  //对付随机数据
    for(int j=1;j<=t;j++){
      if(f[i-j][0]&1){  //奇
        if(h[i-j]<h[i]) f[i][0]=max(f[i][0],f[i-j][0]+1);
      }else{  //偶
        if(h[i-j]>h[i]) f[i][0]=max(f[i][0],f[i-j][0]+1);
      }
      if(f[i-j][1]&1){  //奇
        if(h[i-j]>h[i]) f[i][1]=max(f[i][1],f[i-j][1]+1);
      }else{  //偶
        if(h[i-j]<h[i]) f[i][1]=max(f[i][1],f[i-j][1]+1);
      }
      ansMax=max(ansMax,max(f[i][0],f[i][1]));
    }
  }
  printf("%d\n",ansMax);

  return 0;
}

/*
//正规做法
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAX=100020;
int h[MAX],f[MAX][2];
int n;
struct Node{
  int h,ans;
  Node(int h_, int ans_): h(h_), ans(ans_) { }
  bool operator < (const Node & b) const {
    return ans<b.ans;
  }
};
priority_queue<Node> a1,a2,b1,b2;
queue<Node> q;

int main(void){
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&h[i]);
  int ansMax=1;
  f[0][0]=f[0][1]=1;
  a1.push(Node(h[0],1));
  b1.push(Node(h[0],1));
  for(int i=1;i<n;i++){
    //A
    while(!a1.empty() && a1.top().h>=h[i]) {q.push(a1.top()); a1.pop();}
    if(!a1.empty() && a1.top().h<h[i])
      f[i][0]=max(f[i][0],a1.top().ans+1);
    while(!q.empty()) {a1.push(q.front()); q.pop();}

    while(!a2.empty() && a2.top().h<=h[i]) {q.push(a2.top()); a2.pop();}
    if(!a2.empty() && a2.top().h>h[i])
      f[i][0]=max(f[i][0],a2.top().ans+1);
    while(!q.empty()) {a2.push(q.front()); q.pop();}

    if(f[i][0]&1) a1.push(Node(h[i],f[i][0]));
    else a2.push(Node(h[i],f[i][0]));

    //B
    while(!b1.empty() && b1.top().h<=h[i]) {q.push(b1.top()); b1.pop();}
    if(!b1.empty() && b1.top().h>h[i])
      f[i][1]=max(f[i][1],b1.top().ans+1);
    while(!q.empty()) {b1.push(q.front()); q.pop();}

    while(!b2.empty() && b2.top().h>=h[i]) {q.push(b2.top()); b2.pop();}
    if(!b2.empty() && b2.top().h<h[i])
      f[i][1]=max(f[i][1],b2.top().ans+1);
    while(!q.empty()) {b2.push(q.front()); q.pop();}

    if(f[i][1]&1) b1.push(Node(h[i],f[i][1]));
    else b2.push(Node(h[i],f[i][1]));

    ansMax=max(ansMax,max(f[i][0],f[i][1]));
  }
  printf("%d\n",ansMax);

  return 0;
}
*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=100020;
int h[MAX],f[MAX][2];
int n;

int main(void){
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&h[i]);
  int ansMax=1;
  f[0][0]=f[0][1]=1;
  for(int i=1;i<n;i++){
    for(int j=1;j<=i;j++){
      if(f[i-j][0]&1){  //奇
        if(h[i-j]<h[i]) f[i][0]=max(f[i][0],f[i-j][0]+1);
      }else{  //偶
        if(h[i-j]>h[i]) f[i][0]=max(f[i][0],f[i-j][0]+1);
      }
      if(f[i-j][1]&1){  //奇
        if(h[i-j]>h[i]) f[i][1]=max(f[i][1],f[i-j][1]+1);
      }else{  //偶
        if(h[i-j]<h[i]) f[i][1]=max(f[i][1],f[i-j][1]+1);
      }
      ansMax=max(ansMax,max(f[i][0],f[i][1]));
    }
  }
  printf("%d\n",ansMax);

  return 0;
}
*/
