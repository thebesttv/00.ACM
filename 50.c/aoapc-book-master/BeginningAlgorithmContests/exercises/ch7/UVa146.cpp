// UVa146 ID Codes
// Rujia Liu
// ���⣺����һ��Сд�ַ��������ֵ�����������С����
// �㷨��ֱ����next_permutation
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
  char s[100];
  while(scanf("%s", s) == 1 && s[0] != '#') {
    if(!next_permutation(s, s+strlen(s))) printf("No Successor\n");
    else printf("%s\n", s);
  }
  return 0;
}
