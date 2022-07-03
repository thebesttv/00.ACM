#include <bits/stdc++.h>

int v[4];

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    int c = 0;
    for (int i = 0; i < 4; i++) {
      scanf("%d", &v[i]);
      if (i) c += v[i] > v[0];
    }
    printf("%d\n", c);
  }
}
