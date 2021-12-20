/*
描述
海滩上有一堆桃子，N只猴子来分。第一只猴子把这堆桃子平均分为N份，多了一个，这只猴子把多的一个扔入海中，拿走了一份。第二只猴子接着把剩下的桃子平均分成N份，又多了一个，它同样把多的一个扔入海中，拿走了一份。第三、第四、……，第N只猴子仍是最终剩下的桃子分成N份，扔掉多了的一个，并拿走一份。
编写程序，输入猴子的数量N，输出海滩上最少的桃子数，使得每只猴子都可吃到桃子。

输入
一个整数N。

输出
输出当猴子数量为N时海滩上最少的桃子数。结果保证在int型范围内。

样例输入
2

样例输出
7
*/

#include<iostream>
#include<cstdio>
using namespace std;

int check[30];

int isRight(unsigned int cur, unsigned int n){
  unsigned int t;
  for(int i=0;i<n;i++){
    t=n*cur;
    if(t%(n-1)==0) cur=t/(n-1)+1;
    else return 0;
  }
  return cur;
}

int main(void){
  unsigned int n,t; check[2]=7; check[3]=25;
  while(scanf("%u",&n)==1){
    if(check[n]) printf("%u\n",check[n]);
    else for(int i=n*n*2;;i+=2) if(t=isRight(i,n)){
#ifdef DEBUG
      printf("  i: %d, ",i);
#endif
      printf("%u\n",check[n]=t); break;
    }
  }

  return 0;
}

/*
#include<iostream>
#include<cstdio>
using namespace std;

int check[30];

bool isRight(int cur, int n){
  for(int i=0;i<n;i++){
    if((cur-1)%n==0 && cur){
      cur-=1+(cur-1)/n;
    }else return false;
  }
  return true;
}

int main(void){
#ifdef LOCAL
  freopen("in","r",stdin);
#endif
  int n; check[2]=7; check[3]=25;
  while(scanf("%d",&n)==1){
    if(check[n]) {printf("%d\n",check[n]); continue;}
    int t=n*n*n;
    for(int i=(t&1 ? t : t+1);;i+=2) if(isRight(i,n)){
      printf("%d\n",check[n]=i); break;
    }
  }

  return 0;
}
*/
