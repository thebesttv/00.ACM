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
  char ch = 'M';
  int i = ch;
  cout << "The ASCII code for " << ch << " is " << i << endl;

  cout << "Add one to the character code:" << endl;
  ch++; i = ch;
  cout << "The ASCII code for " << ch << " is " << i << endl;

  cout << "Display char ch using cout.put(ch): ";
  cout.put(ch);
  cout.put('!');
  cout << endl
       << "Done"
       << endl;

  return 0;
}
