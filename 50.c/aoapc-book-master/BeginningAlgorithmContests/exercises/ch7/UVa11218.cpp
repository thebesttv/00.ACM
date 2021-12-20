// UVa11218 KTV
// Rujia Liu
// ���⣺����n����Ȩ���ϣ�ÿ�����ϰ���1~9�е������������ҳ������������ϣ�ʹ��1~9ǡ�ø�����һ�Σ���Ȩ�����
// �㷨������n^2ö��ǰ�������ϣ�ֱ�Ӽ�������������ϡ���λ�����ô�����򵥣��ٶ�Ҳ����

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10;
const int ALL = (1<<9)-1;
int mask[maxn], v[ALL+1];

int main() {
  int kase = 0, n;
  while(scanf("%d", &n) == 1 && n) {
    memset(v, 0, sizeof(v));
    for(int i = 0; i < n; i++) {
      int a, b, c, s;
      scanf("%d%d%d%d", &a, &b, &c, &s); a--; b--; c--;
      mask[i] = (1<<a) + (1<<b) + (1<<c);
      v[mask[i]] = max(v[mask[i]], s);
    }

    int ans = -1;
    for(int i = 0; i < n; i++)
      for(int j = i+1; j < n; j++) if((mask[i] & mask[j]) == 0) {
        int last_mask = ALL ^ mask[i] ^ mask[j]; // ���һ����ϵ�mask
        if(v[last_mask]) ans = max(ans, v[mask[i]] + v[mask[j]] + v[last_mask]);
      }
    printf("Case %d: %d\n", ++kase, ans);
  }
  return 0;
}
