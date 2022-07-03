#include <bits/stdc++.h>
using namespace std;

char s[20];

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    int x = -1, y = -1; bool ok = false;
    for (int i = 1; i <= 8; i++) {
      scanf("%s", s+1);
      if (x != -1) continue;
      int c = 0, first = -1;
      for (int j = 1; j <= 8; j++) if (s[j] == '#') {
          if (first == -1) first = j;
          c++;
      }
      if (c == 2) ok = true;
      if (ok && c == 1) x = i, y = first;
    }
    printf("%d %d\n", x, y);
  }
}
