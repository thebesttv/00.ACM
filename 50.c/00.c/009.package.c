#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int V;

void zeroOnePackage(int cost, int weight){
  for(int j=V;j>=cost;j--)
    f[j]=max(f[j],f[j-cost]+weight);
}
void completePackate(int cost, int weight){
  for(int j=cost;j<=V;j++)
    f[j]=max(f[j],f[j-cost]+weight);
}
void multiplePackage(int cost, int weight, int amount){ //O(log amount)
  if(cost*amount>=V){
    complatePackage(cost,weight);
  }else{
    int k=1;
    while(k<amount){
      zeroOnePackage(cost*k,weight*k);
      amount-=k;
      k<<=1;
    }
    zeroOnePackage(cost*amount,weight*amount);
  }
}

int main(void){

  return 0;
}
