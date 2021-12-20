#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

int main(int artc, char *argv[]){
  std::ifstream in(argv[1]);
  std::istream_iterator<int> inIt(in), eof;
  std::ofstream outOdd(argv[2]), outEven(argv[3]);
  std::ostream_iterator<int> outOddIt(outOdd," "), outEvenIt(outEven,"\n");
  while(inIt != eof){
    auto x = *inIt++;
    if(x&1) *outOddIt++ = x;
    else    *outEvenIt++ = x;
  }
  outOdd.close(); outEven.close();

  return 0;
}
