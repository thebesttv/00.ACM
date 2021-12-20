// UVa10099 The Tourist Guide
// Rujia Liu
// ���⣺����һ�������Ȩͼ����T���ο�Ҫ��S�㵽D�㡣ÿ��·���������ƣ�����ÿ�ζ�Ҫ�е��δ���������Ҫ�߼��ˡ�����û���رߡ�
// �㷨�����ε�floyd�������S��D�����ƿ��·Ȩֵv����Ҫ(T-1)/(v-1)+1�Ρ�
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100 + 5;
int d[maxn][maxn];

int main() {
  int n, m, u, v, w, kase = 0;
  while(scanf("%d%d", &n, &m) == 2 && n) {
    // ��ʼ����ֱ�ӿ�����ȫͼ�������ڵı߿��ɳ���Ϊ0�������������
    memset(d, 0, sizeof(d));
    for(int i = 0; i < m; i++) {
      scanf("%d%d%d", &u, &v, &w); u--; v--;
      d[u][v] = d[v][u] = w;
    }
    // ���㷨
    for(int k = 0; k < n; k++)
      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
          d[i][j] = max(d[i][j], min(d[i][k], d[k][j]));

    int S, D, T;
    scanf("%d%d%d", &S, &D, &T);
    int v = d[S-1][D-1];
    printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", ++kase, (T-1)/(v-1)+1);
  }
  return 0;
}
