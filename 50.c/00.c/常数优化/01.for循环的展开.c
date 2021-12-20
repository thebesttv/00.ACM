#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;

const int MAX=100000;
int a[MAX];
clock_t start,stop;

int main(void){
  srand(time(NULL));
  double tot=0;
  for(int kase=0;kase<1000;kase++){
    for(int i=0;i<MAX;i++) a[i]=rand();
    int sum=0;
    start=clock();
    //[1]
    //for(int i=0;i<MAX;i++){
    //  sum+=a[i];
    //}

    //[2]
    //for(int i=0;i<MAX;i+=2){
    //  sum+=a[i];
    //  sum+=a[i+1];
    //}

    //[3]
    //for(int i=0;i<MAX;i+=4){
    //  sum+=a[i];
    //  sum+=a[i+1];
    //  sum+=a[i+2];
    //  sum+=a[i+3];
    //}

    //[4]
    //for(int i=0;i<MAX;i+=8){
    //  sum+=a[i];
    //  sum+=a[i+1];
    //  sum+=a[i+2];
    //  sum+=a[i+3];
    //  sum+=a[i+4];
    //  sum+=a[i+5];
    //  sum+=a[i+6];
    //  sum+=a[i+7];
    //}

    //[5]
    for(int i=0;i<MAX;i+=5){
      sum+=a[i];
      sum+=a[i+1];
      sum+=a[i+2];
      sum+=a[i+3];
      sum+=a[i+4];
    }

    stop=clock();
    tot+=(double)(stop-start)/CLOCKS_PER_SEC;
  }
  printf("total: %lf\n",tot);

  return 0;
}
