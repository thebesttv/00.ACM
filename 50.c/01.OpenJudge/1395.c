/*
描述
The cows have purchased a yogurt factory that makes world-famous Yucky Yogurt.
Over the next N (1 <= N <= 10,000) weeks, the price of milk and labor will fluctuate weekly such that it will cost the company Ci (1 <= Ci <= 5,000) cents to produce one unit of yogurt in week i. Yucky's factory, being well-designed, can produce arbitrarily many units of yogurt each week.
Yucky Yogurt owns a warehouse that can store unused yogurt at a constant fee of S (1 <= S <= 100) cents per unit of yogurt per week. Fortuitously, yogurt does not spoil. Yucky Yogurt's warehouse is enormous, so it can hold arbitrarily many units of yogurt.
Yucky wants to find a way to make weekly deliveries of Yi (0 <= Yi <= 10,000) units of yogurt to its clientele (Yi is the delivery quantity in week i). Help Yucky minimize its costs over the entire N-week period. Yogurt produced in week i, as well as any yogurt already in storage, can be used to meet Yucky's demand for that week.

输入
Line 1: Two space-separated integers, N and S.
Lines 2..N+1: Line i+1 contains two space-separated integers: Ci and Yi.

输出
Line 1: Line 1 contains a single integer: the minimum total cost to satisfy the yogurt schedule. Note that the total might be too large for a 32-bit integer.

样例输入
4 5
88 200
89 400
97 300
91 500

样例输出
126900

提示
OUTPUT DETAILS:
In week 1, produce 200 units of yogurt and deliver all of it. In week 2, produce 700 units: deliver 400 units while storing 300 units. In week 3, deliver the 300 units that were stored. In week 4, produce and deliver 500 units.
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX=10020;
int c[MAX],y[MAX];
int n,s;

int extra(int cur);

int main(void){
  scanf("%d%d",&n,&s);
  for(int i=0;i<n;i++) scanf("%d%d",&c[i],&y[i]);
  int left=0; long long cost=0;
  for(int i=0;i<n;i++){
    cost+=left*s;
    if(left){
      if(left>=y[i]) {left-=y[i]; y[i]=0;}  //<b>注意顺序，left要在y之前减</b>
      else {y[i]-=left; left=0;}
    }
    cost+=c[i]*y[i];
    int produce=extra(i);
    cost+=c[i]*produce;
    left+=produce;  //<b> </b>
#ifdef DEBUG
    printf("  in week %d, produce %d necessary and %d extra, left %d, current cost: %lld\n",i,y[i],produce,left,cost);
#endif
  }
  printf("%lld\n",cost);

  return 0;
}

int extra(int cur){
  int cost=c[cur],sum=0;
  for(int i=cur+1;i<n;i++){
    cost+=s;
    if(cost<c[i]) sum+=y[i];
    else break;
  }
  return sum;
}
