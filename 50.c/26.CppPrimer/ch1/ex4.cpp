#include <iostream>
#include "Sales_item.h"

int main(void){
  Sales_item tot;
  if(std::cin >> tot){
    Sales_item trans;
    while(std::cin >> trans){
      if(tot.isbn()==trans.isbn()){
        tot += trans;
      }else{
        std::cout << tot << std::endl;
        tot = trans;
      }
    }
    std::cout << tot << std::endl;
    return 0;
  }else{
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
}
