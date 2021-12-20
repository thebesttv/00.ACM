// UVa10670 Work Reduction
// Rujia Liu
// ���⣺����������M <= N����Ҫ��N���M��ÿ�ο��Լ�1������Ϊa�����߳���2������ȡ��������Ϊb��������С������
// ÿ��������L�ֲ�ͬ��(a,b)��Ҫ���տ�����С��������
// �㷨��̰�ģ�ÿ�μ��ٵþ����࣬����ע�ⲻҪ��С�ñ�M��С��
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Agency {
  int cost;
  string name;
  bool operator < (const Agency& rhs) const {
    return cost < rhs.cost || (cost == rhs.cost && name < rhs.name);
  }
};

const int maxn = 100 + 5;
Agency agencies[maxn];

int solve(int N, int M, int A, int B) {
  int cost = 0;
  while(N/2 >= M && B < A*(N-N/2)) {
    cost += B;
    N /= 2;
  }
//  printf("%d %d %d %d=>%d", M, N, A, B, cost + A*(N-M));
  return cost + A*(N-M);
}

int main() {
  int T;
  cin >> T;
  for(int kase = 1; kase <= T; kase++) {
    int M, N, L, A, B;
    printf("Case %d\n", kase);
    cin >> N >> M >> L;
    for(int i = 0; i < L; i++) {
      string s;
      cin >> s;
      int p = s.find(':');
      agencies[i].name = s.substr(0, p);
      sscanf(s.substr(p+1).c_str(), "%d,%d", &A, &B);
      agencies[i].cost = solve(N, M, A, B);
    }
    sort(agencies, agencies+L);
    for(int i = 0; i < L; i++)
      printf("%s %d\n", agencies[i].name.c_str(), agencies[i].cost);
  }
  return 0;
}
