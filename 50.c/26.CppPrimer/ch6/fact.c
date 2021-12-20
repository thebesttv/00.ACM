#include "Chapter6.h"

int fact(int n){
  long long int s=1;
  while(n > 1) s *= n--;
  return s;
}
