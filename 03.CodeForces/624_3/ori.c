#include <bits/stdc++.h>

using namespace std;

long long get(vector<long long> &f, int pos) {
	long long res = 0;
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res;
}

void upd(vector<long long> &f, int pos, int val) {
	for (; pos < int(f.size()); pos |= pos + 1) {
		f[pos] += val;
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (auto &pnt : p) cin >> pnt.first;
	for (auto &pnt : p) cin >> pnt.second;
	sort(p.begin(), p.end());

	vector<int> vs;
	for (auto &pnt : p) vs.push_back(pnt.second);
	sort(vs.begin(), vs.end());
	vs.resize(unique(vs.begin(), vs.end()) - vs.begin());

	long long ans = 0;
	vector<long long> cnt(vs.size()), xs(vs.size());
	for (auto &pnt : p) {
		int pos = lower_bound(vs.begin(), vs.end(), pnt.second) - vs.begin();
		ans += get(cnt, pos) * 1ll * pnt.first - get(xs, pos);
		upd(cnt, pos, 1);
		upd(xs, pos, pnt.first);
	}

	cout << ans << endl;

	return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

int x[100000],v[100000];

int main(void){
  int n;
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&x[i]);
  FOR(i,0,n) scanf("%d",&v[i]);
  LL ans = 0;
  FOR(i,0,n) FOR(j,0,n) if(x[i]<x[j])
    if(v[i]<=v[j]) ans += x[j]-x[i];
  printf("%lld\n",ans);

  return 0;
}
*/
