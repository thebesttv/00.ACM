// UVa11205 The Broken Pedometer 
// Rujia Liu
// ���⣺��P��LED�ƣ��Լ�N���ַ���Ҫ��ѡ���������ٵ�LED�ƣ�ʹ�ü�ʹֻ����Щ������������Ҳ�����ֳ���N���ַ�
// �������������������P, N�Լ�N��P�е�01�������ٵ��У�������������
// ��ģ��P<=15, N<=100
// �㷨��2^Pö�١���ÿ�����Ϊ�������������Լ򻯴���
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;
int N, P, bits[maxn]; // bits[i]Ϊ��i��01��������ֵ

// �ж��Ӽ�S�Ƿ������������д�
bool judge(int S) {
  for(int i = 0; i < N; i++)
    for(int j = 0; j < i; j++)
      if((bits[i] & S) == (bits[j] & S)) return false;
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &P, &N);
    for(int i = 0; i < N; i++) {
      int x = 0, b;
      for(int j = 0; j < P; j++) { scanf("%d", &b); x = x * 2 + b; }
      bits[i] = x;
    }

    int ans = P;
    for(int i = 0; i < (1<<P); i++) if(judge(i)) {      
      int cnt = 0;
      for(int j = 0; j < P; j++) if(i & (1<<j)) cnt++;
      ans = min(ans, cnt);
    }
    printf("%d\n", ans);
  }
  return 0;
}
