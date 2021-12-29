#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a%b);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = min(a, min(b, c)), y = max(a, max(b, c));
    int g = gcd(x, y);
    printf("%d/%d\n", x/g, y/g);
}
