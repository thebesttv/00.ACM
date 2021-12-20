// UVa729 The Hamming Distance Problem
// Rujia Liu
// ���⣺
// ������������N, H�������ֵ���������г���ΪN��ǡ�ð���H��1��01��
// ��ģ��1<=H<=N<=16
// �㷨A��2^Nö�٣����1�ĸ���ΪH�ġ����õݹ�ö��
#include <cstdio>
#include <cstring>
const int maxn = 20;
int N, H, bits[maxn];

// ��bits[d]��ʼȷ�����Ѿ�����c0��0��c1��1
void gen(int d, int c0, int c1) {
  if(d == N) {
    if(c1 != H) return;
    for(int i = 0; i < N; i++) printf("%d", bits[i]);
    printf("\n");
  } else {
     bits[d] = 0; gen(d+1, c0+1, c1);
     bits[d] = 1; gen(d+1, c0, c1+1);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &N, &H);
    gen(0, 0, 0);
    if(T) printf("\n");
  }
  return 0;
}
