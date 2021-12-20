#include<iostream>
using namespace std;

int main(void){
  int &i = *(new int{10240});
  cout << i << endl;

  return 0;
}
