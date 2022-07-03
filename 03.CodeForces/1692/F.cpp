#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 20;
int n, c[10];

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    memset(c, 0, sizeof(c));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int x; scanf("%d", &x);
      c[x%10]++;
    }
    bool ok = false;
    for (int i = 0; i <= 9 && !ok; i++) if (c[i]) {
      c[i]--;
      for (int j = i; j <= 9 && !ok; j++) if (c[j]) {
        c[j]--;
        for (int k = j; k <= 9 && !ok; k++) if ((i+j+k)%10 == 3 && c[k]) {
          ok = 1;
        }
        c[j]++;
      }
      c[i]++;
    }
    printf("%s\n", ok ? "YES" : "NO");
  }
}
