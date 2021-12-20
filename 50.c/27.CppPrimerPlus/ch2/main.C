// 使用 main 函数递归
#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define CE() clear()
typedef long long LL;
typedef long long unsigned LLU;

int line=0;

int main(void){
  line++;
  if(line==8) return 0;
  FOR(i,0,abs(4-line)) putchar(' ');
  int t;
  switch(line){
    case 1: case 7: t=1; break;
    case 2: case 6: t=3; break;
    case 3: case 5: t=5; break;
    case 4: t=7;
  }
  FOR(i,0,t) putchar('*');
  putchar('\n');
  main();

  return 0;
}
