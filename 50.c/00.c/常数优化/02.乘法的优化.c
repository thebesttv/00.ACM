#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;

const int MAX=10000000;
clock_t start,stop;
double tstart=0,tstop=0;

int main(void){
  for(int i=0;i<MAX;i++){
    int a,b=rand();
    start=clock();
    //[1] time: 10.314965
    //a=b*10;
    //a=b*10;

    //[2] time: 10.527899 （无卵用）
    //a=(b<<1)+(b<<3);
    //a=(b<<1)+(b<<3);

    //[1] time: 10.410155
    //a=b*2;
    //a=b*2;

    //[2] time: 10.454581 （???）
    a=b<<1;
    a=b<<1;

    stop=clock();
    tstart+=(double)start; tstop+=double(stop);
  }
  printf("time: %lf\n",(tstop-tstart)/CLOCKS_PER_SEC);

  return 0;
}

