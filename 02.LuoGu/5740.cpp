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

struct Node {
    string s;
    int a,b,c,n;
    Node() {
        n = 0;
    }
    Node(istream &is) {
        is >> s >> a >> b >> c;
        n = a + b + c;
    }
    bool operator < (const Node &b) const {
        return n > b.n;
    }
};
VR<Node> v;

int main() {
    int n; scanf("%d", &n);
    while(n--) v.pb(Node(cin));
    stable_sort(ALL(v));
    Node &p = v.front();
    printf("%s %d %d %d\n",
           p.s.c_str(), p.a, p.b, p.c);
}
