// UVa10717 Mint
// Rujia Liu
// ���⣺��һ���������ӣ�ÿ�������ȶ�����һ�ֲ�ͬ��Ӳ����������ɵġ��ĸ������ȱ���ȸߡ�
// ����4<=n<=50��Ӳ�ҵĸ߶ȣ��Լ�t������������ȸ߶ȣ�����ÿ������߶�h������ڿ��ܴﵽ�������ȸ߶��У�<=h�����߶Ⱥ�>=h����С�߶ȡ�
// �㷨��ö����������Ӳ�ң�����С����������һ������Ԥ��������ظ����㣩��Ȼ�����������
#include<iostream>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
using namespace std;

const int maxn = 50 + 5;
int coin[maxn], minh[maxn][maxn][maxn][maxn]; // Ԥ������

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

int ans1, ans2;
void update_ans(int h, int h0) {
  if(h % h0 == 0) { ans1 = ans2 = h; }
  else {
    int d = h / h0;
    if(ans1 < 0 || d * h0 > ans1) ans1 = d * h0;
    if(ans2 < 0 || (d+1) * h0 < ans2) ans2 = (d+1) * h0;
  }
}

int main() {
  int n, t, h;
  while(cin >> n >> t && n) {
    FOR(i,0,n) cin >> coin[i];
    FOR(a,0,n) FOR(b,a+1,n) FOR(c,b+1,n) FOR(d,c+1,n) {
      minh[a][b][c][d] = lcm(coin[a], lcm(coin[b], lcm(coin[c], coin[d])));
    }
    while(t--) {
      cin >> h;
      ans1 = -1, ans2 = -1;
      FOR(a,0,n) FOR(b,a+1,n) FOR(c,b+1,n) FOR(d,c+1,n)
        update_ans(h, minh[a][b][c][d]);
      cout << ans1 << " " << ans2 << "\n";
    }
  }
  return 0;
}
