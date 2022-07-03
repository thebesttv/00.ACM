#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 20;
int n, s, v[MAX];
// l[i]: starting from left, the min num of elements to remove to get i 1's
int l[MAX], r[MAX];

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &s);
    int c = 0; l[0] = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
      if (v[i]) {
        ++c;
        l[c] = i + 1;
      }
    }

    c = 0; r[0] = 0;
    for (int i = n-1; i >= 0; i--)
      if (v[i]) {
        ++c;
        r[c] = n - i;
      }
#ifdef DEBUG
    for (int i = 0; i <= c; i++) {
      printf("l[%2d]: %2d, r[%2d]: %2d\n", i, l[i], i, r[i]);
    }
#endif

    if (s >= c) {
      printf("%d\n", s == c ? 0 : -1); continue;
    }

    int ans = INT_MAX, d = c - s;
    for (int i = 0; i <= d; i++) {
      ans = min(ans, l[i] + r[d-i]);
    }
    printf("%d\n", ans);
  }
}
