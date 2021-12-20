#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int MAX=210;
int ans[MAX],cap[3],d;
bool vis[MAX][MAX];
struct Node{
  int v[3],amount;

  bool operator < (const Node & b) const{
//    return amount<b.amount;
    return amount > b.amount; //pq中第一个元素优先级最高，与set和sort后的数组相反
  }
}temp;
priority_queue<Node> q;

void update(Node a){
  for(int i=0;i<3;i++){
    if(ans[a.v[i]]==-1 || ans[a.v[i]]>a.amount) ans[a.v[i]]=a.amount;
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    while(!q.empty()) q.pop();
    memset(ans,-1,sizeof(ans)); memset(vis,0,sizeof(vis));
    scanf("%d%d%d%d",&cap[0],&cap[1],&cap[2],&d);
    temp.v[0]=temp.v[1]=0; temp.v[2]=cap[2]; temp.amount=0;
    q.push(temp);
    //update(temp);
    while(!q.empty()){
      Node a=q.top(); q.pop();
      update(a);
      if(ans[d]>=0) break;
      for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(i!=j){
        if(!a.v[i] || a.v[j]==cap[j]) continue;
        int amount = min(a.v[i],cap[j]-a.v[j]);
        temp=a;
        temp.v[i]-=amount; temp.v[j]+=amount; temp.amount+=amount;
        if(!vis[temp.v[0]][temp.v[1]]){
          vis[temp.v[0]][temp.v[1]]=1;
          //update(temp);
          q.push(temp);
        }
      }
    }
    for(int i=d;i>=0;i--) if(ans[i]!=-1){
      printf("%d %d\n",ans[i],i);
      break;
    }
  }

  return 0;
}
