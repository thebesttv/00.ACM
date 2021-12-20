#include <iostream>
#include <map>
#include <string>
#include "Sales_item.h"

bool compareIsbn(const Sales_item &a, const Sales_item &b){
  return a.isbn() < b.isbn();
}

int main(void){
  std::map<Sales_item, decltype(compareIsbn)*> mp(compareIsbn);

  //std::map<Sales_item, int, bool (*)(const Sales_item &, const Sales_item &)> mp2(compareIsbn);

  //typedef bool (*pf)(const Sales_item &, const Sales_item &);
  using pf = bool (*)(const Sales_item &, const Sales_item &);
  std::map<Sales_item, int, pf> mp2(compareIsbn);

  return 0;
}
