#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <algorithm>
#include "Sales_item.h"

int main(void){
  std::istream_iterator<Sales_item> inIt(std::cin), eof;
  std::ostream_iterator<Sales_item> outIt(std::cout, "\n");
  std::vector<Sales_item> v(inIt, eof);

  std::sort(v.begin(), v.end(),
      [](const Sales_item &a, const Sales_item &b){
        return a.isbn() < b.isbn();
      });

  auto l = v.begin();
  while(l != v.end()){
    auto r = std::find_if(l+1, v.end(),
        [l](const Sales_item &a){
          return a.isbn() != l->isbn();
        });
    *outIt++ = std::accumulate(l+1,r,*l);
    l = r;
  }

  return 0;
}
