#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

long k,m,begin;

int get(long remain){
  long result=(begin+m-1)%remain;
  begin=result;
  return result;
}

int main(void){
  long i, find=0;
  scanf("%ld%ld",&k,&m);
  m++;
  FOR(i,0,k) printf("%d ",get(2*k-i));
  printf("\n");
  return 0;
}

/*
long k,m,begin;

int check(long remain){
  long result = (begin+m-1)%remain;
  if(result>=k) {begin=result; return 1;}
  return 0;
}

int main(void){
  long i, find=0;
  scanf("%ld",&k);
  for(m=k;!find;m++){
    find=true; begin=0;
    FOR(i,0,k) if(!check(2*k-i)){
      find=false; break;
    }
  }
  printf("%ld\n",m-1);
  return 0;
}
*/
