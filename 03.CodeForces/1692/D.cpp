#include <bits/stdc++.h>
using namespace std;

const int tMAX = 24 * 60;
bool ok[tMAX];

int go(int h, int m, int x) {
  int ori = h * 60 + m;
  int v = (ori + x) % tMAX;
  int ans = ok[ori];
  while (v != ori) {
    ans += ok[v];
    v = (v + x) % tMAX;
  }
  return ans;
}

int main() {
  for (int i = 0; i < tMAX; i++) {
    int h = i / 60, m = i % 60;
    bool res = (h / 10) == (m % 10) && (h % 10) == (m / 10);
#ifdef DEBUG
    if (res) printf("%02d:%02d\n", h, m);
#endif
    ok[i] = res;
  }

  int T; scanf("%d", &T);
  while (T--) {
    int h, m, x;
    scanf("%d:%d %d\n", &h, &m, &x);
    printf("%d\n", go(h, m, x));
  }
}
