/*
  ϰ��2-8. �����еĺͣ�subsequence��
  �����

  ����������ǣ����д��sum += 1.0/(i*i)�Ļ������ڼ���i*i��ʱ�����
*/

#include<stdio.h>
int main() {
  int i, n, m;
  scanf("%d%d", &n, &m);  
  
  double sum = 0;
  for(i = n; i <= m; i++) {
    sum += 1.0 / i / i;
  }
  printf("%.5lf\n", sum);
  return 0;
}
