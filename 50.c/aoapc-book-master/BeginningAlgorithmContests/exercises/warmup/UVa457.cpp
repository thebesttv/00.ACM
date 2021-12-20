// UVa457 Linear Cellular Automata
// Rujia Liu
// ���⣺��һ������A[1~40]������A[20]=1������Ϊ0������һ������DNA[0~9]�������·���ģ��50�Σ�
// ͬʱ��ÿ����A[i]�滻ΪDNA[A[i-1]+A[i]+A[i+1]]������Խ��A[i]�İ�0��
#include<cstdio>
#include<cstring>
int A[50], oldA[50], DNA[10];
const char* s = " .xW";

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    for(int i = 0; i < 10; i++) scanf("%d", &DNA[i]);
    memset(A, 0, sizeof(A));
    memset(oldA, 0, sizeof(oldA));
    A[20] = 1;
    for(int day = 0; day < 50; day++) {
      for(int i = 1; i <= 40; i++) {
        oldA[i] = A[i];
        printf("%c", s[A[i]]);
      }
      printf("\n");
      for(int i = 1; i <= 40; i++)
        A[i] = DNA[oldA[i-1]+oldA[i]+oldA[i+1]];
    }
    if(T) printf("\n");
  }
  return 0;
}
