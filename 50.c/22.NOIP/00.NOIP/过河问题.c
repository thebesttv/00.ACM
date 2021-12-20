#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define INFINITY 10000
#define LEFT 1
#define RIGHT 0
#define LEFT_TO_RIGHT 1
#define RIGHT_TO_LEFT 0

int n,time[SIZE],pos[SIZE];
int max(int a,int b) {
  if(a>b)
    return a;
  else
    return b;
}
int go(int stage) {
  int i,j,num,tmp,ans;
  if(stage == RIGHT_TO_LEFT) {
    num = 0;
    ans = 0;
    for(i = 1; i <= n; i ++)
      if(pos[i] == RIGHT) {
        num++;
        if(time[i] > ans)
          ans=time[i];
      }
    if(num<=2) return ans;
    ans = INFINITY;
    for(i = 1; i <= n-1; i ++)
      if(pos[i] == RIGHT)
        for(j = i+1; j <= n; j++)
          if(pos[j] == RIGHT) {
            pos[i] = LEFT;
            pos[j] = LEFT;
            tmp=max(time[i],time[j])+go(LEFT_TO_RIGHT);
            if(tmp < ans)
              ans = tmp;
            pos[i]=RIGHT;
            pos[j]=RIGHT;
          }
    return ans;
  }
  if(stage == LEFT_TO_RIGHT) {
    ans = INFINITY;
    for(i = 1; i <= n ; i++)
      if(pos[i]==LEFT) {
        pos[i] = RIGHT;
        tmp = time[i]+go(RIGHT_TO_LEFT);
        if(tmp < ans) ans = tmp;
        pos[i]=LEFT;
      }
    return ans;
  }
  return 0;
}
int main() {
  int i;
  scanf("%d",&n);
  for(i = 1; i <= n; i ++) {
    scanf("%d",&time[i]);
    pos[i] = RIGHT;
  }
  printf("%d\n",go(RIGHT_TO_LEFT));
  return 0;
}