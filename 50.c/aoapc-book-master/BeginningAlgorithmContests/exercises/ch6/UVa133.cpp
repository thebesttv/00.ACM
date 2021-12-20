// UVa133 The Dole Queue
// Rujia Liu
/*
  ���⣺
  n<20����վ��һȦ����ʱ����Ϊ1~n��
  ��������Ա��A��1��ʼ��ʱ������B��n��ʼ˳ʱ������
  ��ÿһ���У���ԱA��k����ͣ������B��m����ͣ������ע���п���������Աͣ��ͬһ�����ϣ���
  ����������Աѡ�е��ˣ�1������2�����뿪����

  ����n, k, m, ���ÿ���ﱻѡ�е��˵ı�ţ�����������ˣ��������Aѡ�еģ�

  �㷨����Ϊ��ģС��ֱ��ģ�⼴�ɡ���0��ʾ�뿪������ˣ�������ʱ������
*/
#include<cstdio>
const int maxn = 25;
int n, k, m, a[maxn];

// ��ʱ����t����������d��-1��ʾ˳ʱ���ߣ�
void go(int& p, int d, int t) {
  while(t--) {
    do { p = (p+d+n-1) % n + 1; } while(a[p] == 0); // �ߵ���һ����0����
  }
}

int main() {
  while(scanf("%d%d%d", &n, &k, &m) == 3 && n) {
    for(int i = 1; i <= n; i++) a[i] = i;
    int left = n; // ��ʣ�µ�����
    int p1 = n, p2 = 1;
    while(left) {
      go(p1, 1, k);
      go(p2, -1, m);
      printf("%3d", p1); left--;
      if(p2 != p1) { printf("%3d", p2); left--; }
      a[p1] = a[p2] = 0;
      if(left) printf(",");
    }
    printf("\n");
  }  
  return 0;
}
