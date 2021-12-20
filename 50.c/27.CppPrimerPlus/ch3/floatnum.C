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
  cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
  float tub = 10.0 / 3.0;
  double mint = 10.0 / 3.0;
  const float million = 1.0e6;

  cout << "tub = " << tub;
  cout << ", a million tubs = " << million * tub;
  cout << ", \nand ten million tubs = ";
  cout << 10 * million * tub << endl;

  cout << "mint = " << mint << " and a million mints = ";
  cout << million * mint << endl;

  return 0;
}
