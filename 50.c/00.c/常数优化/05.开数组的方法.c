#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

const int D1=10;
const int D2=100000;
clock_t start,stop;

//[1] time: 9.545515s
//int a[D1][D2];

//[2] time: 9.491248s （快不到哪儿去）
int a[D2][D1];

int main(void){
  start=clock();
  for(int k=0;k<100;k++){
    for(int i=0;i<D1;i++) for(int j=0;j<D2;j++) a[i][j]=sqrt(i*10+j)*sqrt(i*10+j);
  }
  stop=clock();
  printf("time: %lf\n",(double)(stop-start)/CLOCKS_PER_SEC);

  return 0;
}
