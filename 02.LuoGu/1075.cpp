#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a); i < (b); ++i)
#define FORR(i,a,b) for(int i=(a); i <= (b); ++i)
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define PQ priority_queue
#define VR vector
#define FI first
#define SE second
#define pb push_back
using LL = long long;
using LLU = long long unsigned;

const int MAX = sqrt(2e9)+20;
LL n;
bool vis[MAX];
VR<int> primes;

bool isPrime(LL x) {
    if (x <= 3) return x >= 2;
    LL n = sqrt(x+0.5);
    FORR(i,2,n) if(x%i == 0)
        return false;
    return true;
}

int main() {
    for(LL i = 2; i < MAX; ++i) if(!vis[i])
        for(LL j = i*i; j < MAX; j += i)
            vis[j] = 1;
    FOR(i,2,MAX) if(!vis[i])
        primes.pb(i);

#ifdef DEBUG
    FOR(i,0,10) printf("%d ", primes[i]);
#endif

    scanf("%lld", &n);
    for (int p : primes) if(n % p == 0 && isPrime(n/p)) {
        printf("%lld\n", n/p);
        break;
    }
}
