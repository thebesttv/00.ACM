#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 20;
int n, k, a[MAX], s[MAX];
// f[i] = a[i] < 2 * a[i+1], s[i] = f[0:i]

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    s[0] = a[0] < 2 * a[1];
    for (int i = 1; i < n-1; i++)
      s[i] = s[i-1] + (a[i] < 2 * a[i+1]);

    int ans = (s[k-1] == k);
    for (int i = 1; i+k-1 < n-1; i++) {
      ans += (s[i+k-1] - s[i-1] == k);
    }
    printf("%d\n", ans);
  }
}
