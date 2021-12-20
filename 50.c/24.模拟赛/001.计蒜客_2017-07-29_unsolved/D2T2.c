/*
蒜头君是一个爱思考的好孩子，这一天他学习了冒泡排序，于是他就想，把一个乱序排列通过冒泡排序排至升序需要多少次交换，这当然难不倒他，于是他想来点刺激的，给定一个 1...n 的排列，每次从该排列中选择一个区间 [l,r]，问使用冒泡排序将该区间排至升序需要多少次交换操作。

输入格式
第一行一个整数 n，表示排列长度。
接下来一行 n 个整数，表示该排列。
接下来一行一个整数 m，表示询问次数。
接下来 m 行，每行 2 个整数 l,r，表示询问 [l,r] 区间。

输出格式
输出 m 行，每行 1 个整数，第 i 行表示第 i 个询问的答案。

数据规模
对于 30% 的数据，满足 1≤n,m≤300
对于 60% 的数据，满足 1≤n,m≤1000
对于 100% 的数据，满足 1≤n,m≤30000, l<r, ∑∣l[i]−l[i−1]∣ + ∑∣r[i]−r[i−1]∣≤ 7×10^6

样例输入
10
9 8 7 4 5 6 10 3 2 1
5
2 4
8 10
2 8
5 9
4 9

样例输出
3
3
13
7
9
*/

/*
  得分：60
  解题报告：
  回顾了以下冒泡排序，感觉到类似于逆序对，但没有往那方面想。
  开始想到对每个询问的区间[l,r]中的位于pos的元素n，遍历pos+1到r的所有元素，找比n小的即可。
  后来想到使用minPos优化，但提交前还是不确定。
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=30000+20;
int a[MAX],pos[MAX];
int maxPos[MAX];  //minPos[i]: pos[1:i]中的最大值

int main(void){
#ifdef LOCAL
  freopen("in","r",stdin);
#endif
  int n; scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    pos[a[i]]=i;
  }
  int tempMax=pos[1];
  for(int i=1;i<=n;i++){
    tempMax<pos[i] ? tempMax=pos[i] : 0 ;
    maxPos[i]=tempMax;
  }
  int m; scanf("%d",&m);
  int l,r;
  for(int i=0;i<m;i++){
    scanf("%d%d",&l,&r);
    int cnt=0;
    for(int i=l;i<r;i++){
      for(int j=a[i];j>=1;j--){
        if(maxPos[j]<i) break;  //不确定
        if(pos[j]>i && pos[j]<=r) cnt++;
      }
    }
    printf("%d\n",cnt);
  }

  return 0;
}
