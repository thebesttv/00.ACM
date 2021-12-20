// UVa270 Lining Up
// Rujia Liu
// ���⣺����ƽ����n����ͬ�㣬�ж�����м�������ͬһ��ֱ����
// �㷨��ö����㣬���������е㵽����б�ʣ���������ɨ�裬���ж��ٸ���ͬ
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 700;
const double eps = 1e-6;
int x[maxn], y[maxn];
double ang[maxn];

int main() {
  int T;
  scanf("%d\n", &T);
  while(T--) {
    int n = 0;
    char buf[100];
    for(;;) {
      if(fgets(buf, maxn, stdin) == NULL) break;
      if(sscanf(buf, "%d%d", &x[n], &y[n]) != 2) break;
      n++;
    }

    int ans = 1;
    for(int i = 0; i < n; i++) {
      int k = 0;
      for(int j = 0; j < n; j++)
        if(i != j) ang[k++] = atan2(y[j]-y[i], x[j]-x[i]);
      sort(ang, ang+k);
      int cnt = 1;
      for(int j = 1; j < k; j++) {
        if(fabs(ang[j] - ang[j-1]) < eps) cnt++; else cnt = 1;
        ans = max(ans, cnt+1);
      }
    }
    printf("%d\n", ans);
    if(T) printf("\n");
  }
  return 0;
}
