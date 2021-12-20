#include <iostream>
//#include <stdexcept>

double Div(int a, int b){
  if(b == 0)
    throw std::runtime_error("Divided by zero!");
  return static_cast<double>(a) / b;
}

int main(void){
  int a, b; double res;
  std::cin >> a >> b;
  try{
    res = Div(a, b);
  }catch (std::runtime_error err){
    std::cout << "Encounter an error: " << err.what() << std::endl;
    std::cout << "Program terminates." << std::endl;
    return -1;
  }
  std::cout << res << std::endl;
  std::cout << "Program ends successfully." << std::endl;

  return 0;
}
