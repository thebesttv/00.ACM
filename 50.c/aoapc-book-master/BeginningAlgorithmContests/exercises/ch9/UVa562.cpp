// UVa562 Dividing coins
// Rujia Liu
// ���⣺��m<=100��Ӳ�ң�ÿ����ֵ<=500��Ҫ��ֳ����飬��ֵ֮�;����ӽ��������ֵ֮�͵Ĳ�
// �㷨���������⡣��������Ϊfloor(sum/2)����ֵ��������ȡ�d[i][j]
#include<cstdio>
#include<cstring>
const int maxm = 100 + 5;
const int maxv = 500;
int m, a[maxm], d[maxm*maxv];

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &m);
    int sum = 0;
    for(int i = 0; i < m; i++) { scanf("%d", &a[i]); sum += a[i]; }
    int V = sum / 2;

    memset(d, 0, sizeof(d));
    d[0] = 1;
    for(int i = 0; i < m; i++)
      for(int j = V-1; j >= 0; j--)
        if(d[j] && j + a[i] <= V) d[j + a[i]] = 1;

    int ans = V;
    while(!d[ans]) ans--;
    printf("%d\n", sum-ans*2);
  }
  return 0;
}
