#include<iostream>
#include<cstdio>
using namespace std

int gcd(int a, int b){
  return b==0 ? a : gcd(b,a%b);
}
void gcd(int a, int b, int & d, int & x, int & y){  //扩展欧几里得，求出x,y，使得 ax+by=d，其中d=gcd(a,b)
                                                    //可用于求逆元 ax同余1 mod n，当且仅当d=1时有唯一解x
  if(!b) {d=a; x=1; y=0;}
  else {gcd(b,a%b,d,y,x); y-=x*(a/b);}
}

int main(void){


  return 0;
}
