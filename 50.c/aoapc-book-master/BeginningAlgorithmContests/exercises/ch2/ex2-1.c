/*
  ϰ��2-1. λ����digit��
  �����
*/

#include<stdio.h>
int main() {
  int n, d = 0;
  scanf("%d", &n);
  do {
    n /= 10;
    d++;
  } while(n > 0);
  printf("%d\n", d);
  return 0;
}
