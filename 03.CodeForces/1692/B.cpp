#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    map<int, int> mp;
    scanf("%d", &n);
    while (n--) {
      int x; scanf("%d", &x);
      mp[x]++;
    }
    int odd = 0, even = 0;
    for (auto &p : mp)
      if (p.second & 1) ++odd;
      else ++even;
    int ans = odd + (even & (~1));
    printf("%d\n", ans);
  }
}
