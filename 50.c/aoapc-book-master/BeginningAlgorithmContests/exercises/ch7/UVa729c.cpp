// UVa729 The Hamming Distance Problem
// Rujia Liu
// ���⣺
// ������������N, H�������ֵ���������г���ΪN��ǡ�ð���H��1��01��
// ��ģ��1<=H<=N<=16
// �㷨C��C(N,H)ö�٣�ö�ٵĶ���Ϊ0������ö��˳������ֵ���
#include <cstdio>
#include <cstring>
const int maxn = 20;
int N, H, zero[maxn]; // zero[i]Ϊ��iΪ�Ƿ�Ϊ0

// �ӵ�d��0��λ�ÿ�ʼȷ����ȡֵ��Χ��from~N-1
void gen(int d, int from) {
  if(d == N-H) {
    for(int i = 0; i < N; i++) printf("%d", zero[i] ? 0 : 1);
    printf("\n");
  } else {
     for(int i = from; i < N; i++) {
       zero[i] = 1;
       gen(d+1, i+1);
       zero[i] = 0;
     }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &N, &H);
    memset(zero, 0, sizeof(zero));
    gen(0, 0);
    if(T) printf("\n");
  }
  return 0;
}
