// UVa10718 Bit Mask
// Rujia Liu
// ���⣺����һ��32λ�ķǸ�����N���ҳ�һ����M������L<=M<=U����N or M��ֵ��󡣱���˵��N=100��L=50��U=60����ôM=59ʱ��N or M = 127�������м���Mͬʱ���������������С��һ��M�� 
// �㷨��̰�ģ����32λ������߿�ʼ����ÿһλ����Ψһ��̰�������֤or NΪmax��ͬʱ��ʹ��Ĵ���L,U ��Χ�ڼ��ɡ� 
#include<iostream>
using namespace std;

// ��������[left, right], [L, U]�Ƿ��н���
inline bool overlap(long long left, long long right, long long L, long long U) {
  return !(right < L || U < left);
}

int main() {
  long long N, L, U, M;
  while(cin >> N >> L >> U) {
    M = 0;
    for(int i = 31; i >= 0; i--) {
      long long bit = 1LL << i;
      bool ok0 = overlap(M, M + bit - 1, L, U); // �Ƿ������0
      bool ok1 = overlap(M + bit, M + bit * 2 - 1, L, U); // �Ƿ������1
      if((!ok0 && ok1) || (ok0 && ok1 && !(N & bit))) M ^= bit; // (1) ֻ����1���� (2)01���е�N�Ķ�ӦλΪ0���������1
    }
    cout << M << "\n";
  }
  return 0;
}
