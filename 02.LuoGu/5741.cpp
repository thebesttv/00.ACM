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
using pii = pair<int,int>;

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
};
VR<Node> v;
VR<pii> res;

bool ok(int i, int j) {
    const Node &x = v[i], &y = v[j];
    return abs(x.a - y.a) <= 5 &&
        abs(x.b - y.b) <= 5 &&
        abs(x.c - y.c) <= 5 &&
        abs(x.n - y.n) <= 10;
}

int main() {
    int n; scanf("%d", &n);
    FOR(i,0,n) v.pb(Node(cin));

    FOR(i,0,n) FOR(j,i+1,n) if(ok(i,j))
        res.pb(v[i].s < v[j].s ? pii{i,j} : pii{j,i});
    sort(ALL(res), [](const pii x, const pii y) {
        const string x1 = v[x.FI].s, x2 = v[x.SE].s;
        const string y1 = v[y.FI].s, y2 = v[y.SE].s;
        if (x1 != y1)
            return x1 < y1;
        else
            return x2 < y2;
    });

    for(auto p : res)
        printf("%s %s\n", v[p.FI].s.c_str(), v[p.SE].s.c_str());
}
