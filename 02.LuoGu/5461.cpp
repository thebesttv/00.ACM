#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORR(i,a,b) for(int i = (a); i <= (b); ++i)
#define ALL(x) x.begin(), x.end()
#define pb push_back
using LL = long long;
using LLU = long long unsigned;

const int MAX = 2000;

int n;
bool v[MAX][MAX];

void f(int x1, int y1, int x2, int y2) {
    if (x1+1 >= x2 || y1+1 >= y2)
        return;
    int xm = (x1 + x2) / 2;
    int ym = (y1 + y2) / 2;
    FOR(i,x1,xm) FOR(j,y1,ym)
        v[i][j] = 0;
    f(x1, ym, xm, y2);
    f(xm, y1, x2, ym);
    f(xm, ym, x2, y2);
}

int main() {
    scanf("%d", &n);
    n = 1 << n;
    FOR(i,0,n) FOR(j,0,n) v[i][j] = 1;

    f(0, 0, n, n);

    FOR(i,0,n) {
        FOR(j,0,n) printf("%d ", v[i][j]);
        putchar('\n');
    }
}
