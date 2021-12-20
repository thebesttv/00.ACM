#include <iostream>
using namespace std;
const int ArSize = 6;

int main(void){
  float naaq[ArSize];
  cout << "Enter the NAAQs (New Age Awareness Quotients) "
       << "of\nyour neighbors. Program terminates "
       << "when you make\n" << ArSize << " entries "
       << "or enter a negative value.\n";
  int i=0; float tmp;
  cout << "FIrst value: ";
  cin >> tmp;
  while (i < ArSize && tmp >= 0){
    naaq[i] = tmp;
    ++i;
    if (i < ArSize){
      cout << "Next value: ";
      cin >> tmp;
    }
  }
  if (i == 0)
    cout << "No data -- bye\n";
  else{
    cout << "Enter your NAAQ: ";
    float you; cin >> you;
    int cnt=0;
    for (int j = 0; j < i; j++)
      if (naaq[i] > you)
        ++cnt;
    cout << cnt << " of youer neighbors have greater awareness of\n"
         << "the New Age than you do.\n";
  }
  return 0;
}
