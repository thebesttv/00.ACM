/*
  ϰ��1-8 ����ֵ��abs��
  �����
*/

#include<stdio.h>
int main() {
  double x;
  scanf("%lf", &x);
  if(x < 0) x = -x;
  printf("%.2lf\n", x);
  return 0;
}
