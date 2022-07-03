#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 20;
map<int, vector<int>> mp;
int n;

struct Record {
  int l, r, a;
} rec;

int solve(const vector<int> &p, int &l, int &r) {
  int gMin = INT_MAX, gr = -1;
  int ansMax = INT_MIN, al = -1, ar = -1;
  for (int i = 0; i < p.size(); i++) {
    const int g = 2 * i - p[i];
    if (g < gMin) gMin = g, gr = p[i];
    if (g - gMin + 1 > ansMax) {
#ifdef DEBUG
      printf("i: %d, g: %d, gmin: %d\n", i, g, gMin);
#endif
      ansMax = g - gMin + 1, al = gr, ar = p[i];
    }
  }
  l = al, r = ar;
  return ansMax;
}

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    mp.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int x; scanf("%d", &x);
      mp[x].push_back(i);
    }

    int ans = -1;
    for (const auto &p : mp) {
      int l, r;
      int t = solve(p.second, l, r);
      if (t > ans) {
        ans = t;
        rec = {l, r, p.first};
      }
    }
    printf("%d %d %d\n", rec.a, rec.l, rec.r);
  }
}
