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

int main(void){
  int a=1;
  cout << "sizeof(int): " << sizeof(int) << endl;
  cout << "sizeof(a): " << sizeof(a) << ", a: " << a << endl;
  cout << "sizeof(a++): " << sizeof(a++) << ", a: " << a << endl;

  cout << "sizeof(printf(\"lalala\\n\")): " << sizeof(printf("lalala\n")) << endl;

  int *p = (int*)malloc(100);
  cout << sizeof(p) << endl;

  p = new int[10];
  cout << sizeof(p) << endl;

  return 0;
}
