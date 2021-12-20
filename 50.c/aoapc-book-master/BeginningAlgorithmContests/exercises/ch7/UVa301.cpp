// UVa301 Transportation
// Rujia Liu
// ���⣺��һ��������n���˵Ļ𳵴�վ0����������ͣ��վ1, 2, ..., m��
// ��t������(from, to, num)�Ķ�������ʾ��num���˴�fromվ��toվ��Ʊ��Ϊ(to-from)*num����������һЩ������ʹ�����棨������Ʊ�ۣ����
// �㷨�����ݡ�ע�Ȿ����һ������Ч�������Լ�֦

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxm = 10;
const int maxt = 25;
int n, m, t, ans, from[maxt], to[maxt], num[maxt], cnt[maxm];

void dfs(int d, int tot) {
  // �����Լ�֦�����ʣ�����ж��������ܻ����޷�������ǰ�ҵ������Ž⣬���֦
  int extra = 0;
  for(int i = d; i < t; i++) extra += num[i] * (to[i] - from[i]);
  if(tot + extra <= ans) return;

  ans = max(ans, tot);
  if(d == t) return;
  dfs(d+1, tot);
  bool ok = true;
  for(int i = from[d]; i < to[d]; i++) {
    cnt[i] += num[d];
    if(cnt[i] > n) ok = false; // ������
  }
  if(ok) dfs(d+1, tot + num[d] * (to[d] - from[d]));
  for(int i = from[d]; i < to[d]; i++) {
    cnt[i] -= num[d];
  }
}

int main() {
  while(scanf("%d%d%d", &n, &m, &t) == 3 && n) {
    for(int i = 0; i < t; i++) scanf("%d%d%d", &from[i], &to[i], &num[i]);
    memset(cnt, 0, sizeof(cnt));
    ans = 0;
    dfs(0, 0);
    printf("%d\n", ans);
  }
  return 0;
}
