// UVa10098 Generating Fast, Sorted Permutation
// Rujia Liu
// ���⣺����һ���ַ��������ֵ��������������
// �㷨��ֱ����next_permutation
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
  int T;
  char s[100];
  scanf("%d", &T);
  while(T--) {
    scanf("%s", s);
    int n = strlen(s);
    sort(s, s+n);
    do { printf("%s\n", s); } while(next_permutation(s, s+n));
    printf("\n");
  }
  return 0;
}
