/*
  ϰ��2-5. ͳ�ƣ�stat��
  �����
*/

#include<stdio.h>
int main() {
  int i, n, a, m, count;
  FILE *fp;

  /* ��һ�δ��ļ�ֻ��Ϊ�˶�ȡm */
  fp = fopen("stat.in", "r");
  fscanf(fp, "%d", &n);
  for(i = 0; i < n; i++)
    fscanf(fp, "%d", &a);
  fscanf(fp, "%d", &m);
  fclose(fp);

  /* �ڶ��δ��ļ����ͳ�� */
  count = 0;
  fp = fopen("stat.in", "r");
  fscanf(fp, "%d", &n);
  for(i = 0; i < n; i++) {
    fscanf(fp, "%d", &a);
    if(a < m) count++;
  }
  fclose(fp);

  fp = fopen("stat.out", "w");
  fprintf(fp, "%d\n", count);
  fclose(fp);

  return 0;
}
