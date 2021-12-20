#include <iostream>

int main(void){
  int a, b;
  while(std::cin >> a >> b){
    try{
      if(b==0)
        throw std::runtime_error("divided by zero");
      std::cout << static_cast<double>(a) / b << std::endl;
    }catch(std::runtime_error err){
      std::cout << err.what() << std::endl;
      std::cout << "proceed ? (y/n) ";
      char ch; std::cin >> ch;
      if(ch != 'y' && ch!='Y')
        break;
    }
  }

  return 0;
}
