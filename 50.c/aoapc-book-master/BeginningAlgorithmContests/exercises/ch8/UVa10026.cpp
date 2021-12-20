// UVa10026 Shoemaker's Problem
// Rujia Liu
// ���⣺Ь����������ඩ������ЩЬ����һ�����������ޣ�������������޾ͻᷣ���������������ķ���������ж����ͬ�ģ��밴�����˳���С���������
// �㷨������fine/time�Ӵ�С��
#include<cstdio>
#include<algorithm>
using namespace std;

struct Job {
  int idx, time, cost;
  Job(int idx=0, int time=0, int cost=0):idx(idx),time(time),cost(cost){}
  bool operator < (const Job& rhs) const {
    return rhs.cost*time < rhs.time*cost || (rhs.cost*time == rhs.time*cost && idx < rhs.idx);
  }
};

const int maxn = 1000 + 5;
Job jobs[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
   int n, time, cost;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d%d", &time, &cost); 
      jobs[i] = Job(i+1, time, cost);
    }
    sort(jobs, jobs+n);
    for(int i = 0; i < n-1; i++) printf("%d ", jobs[i].idx);
    printf("%d\n", jobs[n-1].idx);
    if(T) printf("\n");
  }
  return 0;
}
