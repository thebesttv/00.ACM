#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORR(i,a,b) for(int i = (a); i <= (b); ++i)
#define ALL(x) x.begin(),x.end()
#define VR vector
#define pb push_back
using LL = long long;
using LLU = long long unsigned;

const int MAX = 10020;
bool prime[MAX];
VR<int> p;

int f(int x){
    for (int p : ::p) {
        if (p >= x) return -1;
        if (prime[x-p] == 0)
            return p;
    }
    return -1;
}

int main() {
    for (int i = 2; i < MAX; ++i) if(!prime[i])
        for (int j = i * 2; j < MAX; j += i)
            prime[j] = 1;
    FOR(i,2,MAX) if(!prime[i])
        p.pb(i);

    int n; scanf("%d",&n);
    for(int i = 4; i <= n; i += 2) {
        int x = f(i);
        if (x < 0) continue;
        printf("%d=%d+%d\n", i, x, i-x);
    }
}
