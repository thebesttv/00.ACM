#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;

const int MAX=4000000;
clock_t start,stop;
double tstart=0,tstop=0;

int main(void){
  for(int i=0;i<MAX;i++){
    int a,b=rand();
    start=clock();
    //[1] time: 4.135882s
    a=(signed int)b/123;
    a=(signed int)b/123;

    //[2] time: 4.080479s（区别不大）
    //a=(unsigned int)b/123;
    //a=(unsigned int)b/123;

    stop=clock();
    tstart+=(double)start; tstop+=double(stop);
  }
  printf("time: %lf\n",(tstop-tstart)/CLOCKS_PER_SEC);

  return 0;
}
