// UVa729 The Hamming Distance Problem
// Rujia Liu
// ���⣺
// ������������N, H�������ֵ���������г���ΪN��ǡ�ð���H��1��01��
// ��ģ��1<=H<=N<=16
// �㷨B��2^Nö�٣����1�ĸ���ΪH�ģ�����ֱ��ö���Ӽ�
#include <cstdio>
#include <cstring>
int N, H;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &N, &H);
    for(int i = 0; i < (1<<N); i++) {
      int cnt = 0;
      for(int j = 0; j < N; j++) if(i & (1<<j)) cnt++;
      if(cnt == H) {
        for(int j = N-1; j >= 0; j--) printf("%d", (i & (1<<j)) ? 1 : 0); 
        printf("\n");
      }
    }
    if(T) printf("\n");
  }
  return 0;
}
