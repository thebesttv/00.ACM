#include<iostream>
#include<cstdio>
using namespace std;

int gcd(int a, int b){
  return b==0 ? a : gcd(b,a%b);
}
/* gcd(a,b) = 2*gcd(a/2,b/2), !(a&1) && !(b&1)
            = gcd(a/2,b), !(a&1) && (b&1)
            = gcd(a,b/2), (a&1) && !(b&1)
            = gcd(abs(a-b)/2,b), (a&1) && (b&1)
  -> 令 a=x*2^i, b=y*2^j
     则 gcd(a,b) = gcd(x,y)*2^min(i,j)
 
 */
int binary_gcd(int a, int b){ //若不开O2，速度与gcd差距不大
  if(!a || !b) return a^b;
  int i=0,j=0;
  while(!(a&1)) a>>=1,i++;
  while(!(b&1)) b>>=1,j++;
  while(a!=b){
    if(a<b) a^=b,b^=a,a^=b;
    a-=b; //辗转相减
    while(!(a&1)) a>>=1;
  }
  return a<<min(i,j);
}
void gcd(int a, int b, int & d, int &x, int & y);

int main(void){
#ifdef LOCAL
  freopen("in","r",stdin);
#endif
  int a,b;
  while(scanf("%d%d",&a,&b)==2){
    gcd(a,b);
  }

  return 0;
}
