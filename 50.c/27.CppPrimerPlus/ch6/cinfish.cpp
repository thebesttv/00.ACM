#include <iostream>
using namespace std;
const int MAX = 5;

int main(void){
  double fish[MAX];
  cout << "Please enter the weights of your fish.\n";
  int i = 0;
  while (i < MAX && cin >> fish[i]){
    if (++i < MAX)
      cout << "fish #" << i+1 << ": ";
  }
  double tot = 0;
  for (int j = 0; j < i; j++)
    tot += fish[j];
  if (i==0) cout << "no fish\n";
  else cout << "average: " << tot/i;

  return 0;
}
