#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORR(i,a,b) for(int i = (a); i <= (b); ++i)
#define ALL(x) x.begin(), x.end()
#define pb push_back
using LL = long long;
using LLU = long long unsigned;

int main() {
    LLU s = 0, x, n = 0;
    while(cin >> x) {
        s += x;
        ++n;
    }
    s *= 1ll << (n-1);
    printf("%llu\n", s);
}
