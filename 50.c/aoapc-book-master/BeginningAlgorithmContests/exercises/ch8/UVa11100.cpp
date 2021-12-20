// UVa11100 The Trip, 2007
// Rujia Liu
// ���⣺������һϵ�еİ�������״����һ���ģ�����С���������ڴ�������棬������������һ��������һϵ�д�С��ͬ�İ���Ҫ�����һ�ֻ����������ķ�����ʹ������µ�piece���١��ڴ�ǰ����piece����������ֵӦ����С 
// �㷨��ע���С��ͬ�İ������໥�ף������СΪs�İ���cnt[s]������max{cnt[s]}���Ǵ𰸡���������Ҳ���ѣ������Ժ�ѭ����piece 1, 2, 3, ..., k
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

const int maxn = 10000 + 5;
int s[maxn];

int main() {
  int n, kase = 0;
  while(scanf("%d", &n) == 1 && n) {
    int ans = 1, cnt = 1;
    for(int i = 0; i < n; i++) scanf("%d", &s[i]);
    sort(s, s+n);
    for(int i = 1; i < n; i++) {
      if(s[i] != s[i-1]) cnt = 1;
      else ans = max(ans, ++cnt);
    }

    if(kase++ > 0) printf("\n");
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++) {
      for(int j = i; j < n; j += ans) {
        if(j > i) printf(" ");
        printf("%d", s[j]);
      }
      printf("\n");
    }
  }
  return 0;
}
