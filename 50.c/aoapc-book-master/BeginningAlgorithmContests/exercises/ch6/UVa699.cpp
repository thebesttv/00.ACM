// UVa699 The Falling Leaves
// Rujia Liu
// ���⣺��һ�ö�������ÿ���ڵ㶼��һ��ˮƽλ�ã�������������1����λ���Ҷ������ұ�1����λ�������������ÿ��ˮƽλ�õ����н���Ȩֵ֮�͡����յݹ鷽ʽ���룬-1��ʾ����
// �㷨���ڡ���������ͬʱ���㣬���������İ�����������

#include<cstring>
#include<iostream>
using namespace std;

const int maxn = 200;
int sum[maxn];

// ���벢ͳ��һ������������ˮƽλ��Ϊp
void build(int p) {
  int v;
  cin >> v;
  if(v == -1) return; // ����
  sum[p] += v;
  build(p - 1);
  build(p + 1);
}

// �߶����ͳ��
bool init() {
  int v;
  cin >> v;
  if(v == -1) return false;

  memset(sum, 0, sizeof(sum));
  int pos = maxn/2; // ������ˮƽλ��
  sum[pos] = v;
  build(pos - 1); // ������
  build(pos + 1); // ������
}

int main() {
  int kase = 0;
  while(init()) {
    int p = 0;
    while(sum[p] == 0) p++; // ������ߵ�Ҷ��

    // ��ʼ�������ΪҪ������ĩ����ո�������΢�鷳һ��
    cout << "Case " << ++kase << ":\n" << sum[p++];
    while(sum[p] != 0) {
      cout << " " << sum[p];
      p++;
    }
    cout << "\n\n";
  }
  return 0;
}
