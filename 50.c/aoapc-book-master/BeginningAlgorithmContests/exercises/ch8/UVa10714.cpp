// UVa10714 Ants
// Rujia Liu
// ���⣺�����ڡ�ѵ��ָ�ϡ��е��������⣬����ľ�峤��L�����ϸ���n���Լ��������ϵ�ľ����˵��λ�á������ٶ�Ϊ1�������ʱ����ʱ��
// �㷨��
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
  int T, L, n, x;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &L, &n);
    int mint = 0, maxt = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &x);
      mint = max(mint, min(x, L-x));
      maxt = max(maxt, max(x, L-x));
    }
    printf("%d %d\n", mint, maxt);
  }
  return 0;
}
