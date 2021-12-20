// UVa10050 Hartals
// Rujia Liu
// ���⣺����n��p������H[i]������H[i]��ʾÿH[i]�����һ�λ���������������⣩�����ǰn�����ж������л��ģ������տ�ʼ��
#include<cstdio>
#include<cstring>
const int maxn = 4000;
int vis[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, p;
    scanf("%d%d", &n, &p);
    memset(vis, 0, sizeof(vis));
    while(p--) {
      int H;
      scanf("%d", &H);
      for(int i = H; i <= n; i += H)
        if(i % 7 != 0 && i % 7 != 6) vis[i] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += vis[i];
    printf("%d\n", cnt);
  }
  return 0;
}

