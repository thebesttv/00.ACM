#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct Ind{
  int x,y;
}temp;
queue<Ind> q;

int main(void){
  int k;
  while(scanf("%d",&k)==1){
    for(int y=k+1;y<=2*k;y++){
      int x = k*y/(y-k);
      if(x*y == k*(x+y)){
        temp.x=x; temp.y=y;
        q.push(temp);
      }
    }
    printf("%d\n",q.size());
    while(!q.empty()){
      temp=q.front(); q.pop();
      printf("1/%d = 1/%d + 1/%d\n",k,temp.x,temp.y);
    }
  }

  return 0;
}
