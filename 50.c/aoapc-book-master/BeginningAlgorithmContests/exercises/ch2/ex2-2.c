/*
  ϰ��2-2. ˮ�ɻ�����daffodil��
  �����
*/

#include<stdio.h>
int main() {
  int a, b, c;
  for(a = 1; a <= 9; a++)
    for(b = 0; b <= 9; b++)
      for(c = 0; c <= 9; c++)
        if(a*a*a+b*b*b+c*c*c == a*100+b*10+c) printf("%d%d%d\n", a, b, c);
  return 0;
}
