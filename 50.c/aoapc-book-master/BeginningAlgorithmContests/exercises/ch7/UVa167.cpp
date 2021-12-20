// UVa167 The Sultan's Successors
// Rujia Liu
// ���⣺�˻ʺ��������չ��8*8������ÿ�����Ӷ���һ��������Ҫ��8���ʺ����ڸ��ӵ�����֮�����
// �㷨��ö��ȫ���У�Ȼ���ж��Ƿ��������ʺ���ͬһ���Խ�����

#include<cstdio>
#include<algorithm>
using namespace std;
int v[8][8], P[8];

bool judge() {
  bool ok = true;
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < i; j++)
     if(P[i]-i == P[j]-j || P[i]+i == P[j]+j) return false;
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    for(int i = 0; i < 8; i++) {
      P[i] = i;
      for(int j = 0; j < 8; j++)
        scanf("%d", &v[i][j]);
    }
    int ans = 0;
    do {
      if(!judge()) continue;
      int sum = 0;
      for(int i = 0; i < 8; i++) sum += v[i][P[i]];
      ans = max(ans, sum);
    } while(next_permutation(P, P+8));
    printf("%5d\n", ans);
  }
  return 0;
}
