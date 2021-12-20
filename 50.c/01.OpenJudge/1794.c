/*
描述
给出2个正整数集合A = {pi | 1 <= i <= a}，B = {qj | 1 <= j <= b}和一个正整数s。问题是：使得pi + qj = s的不同的(i, j)对有多少个。

输入
第1行是测试数据的组数n，后面跟着n组测试数据。
每组测试数据占5行，第1行是和s (1 <= s <= 10000)，第2行是一个正整数a (1 <= a <= 10000)，表示A中元素的数目。第3行是a个正整数，每个正整数不超过10000，表示A中的元素。第4行是一个正整数b (1 <= b <= 10000)，表示B中元素的数目。第5行是b个正整数，每个正整数不超过10000，表示B中的元素。
注意：这里的集合和数学书上定义的集合有一点点区别——集合内可能包含相等的正整数。

输出
n行，每行输出对应一个输入。输出应是一个非负整数。

样例输入
2
99
2
49 49
2
50 50
11
9
1 2 3 4 5 6 7 8 9
10
10 9 8 7 6 5 4 3 2 1

样例输出
4
9
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAX=10004;
int a[MAX],b[MAX],s,check[MAX];

int main(void){
#ifdef LOCAL
  freopen("in","r",stdin);
#endif
  int T; scanf("%d",&T);
  for(int kase=0;kase<T;kase++){
    memset(check,-1,sizeof(check)); memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
    int sum=0;
    scanf("%d",&s);
    int lena,lenb; scanf("%d",&lena);
    for(int i=0;i<lena;i++) scanf("%d",&a[i]);
    scanf("%d",&lenb);
    for(int i=0;i<lenb;i++) scanf("%d",&b[i]);
    sort(a,a+lena); sort(b,b+lenb);
    for(int i=0;i<lena;i++){
      if(a[i]>=s) break;
      int t=s-a[i],*p;
      if(check[a[i]]!=-1){sum+=check[a[i]]; continue;}
      p=lower_bound(b,b+lenb,t);
      if(*p!=t) check[a[i]]=0;
      else{
        check[a[i]]=0;
        for(;*p==t;p++) check[a[i]]++;
#ifdef DEBUG
        printf("  check[%d]: %d\n",a[i],check[a[i]]);
#endif
        sum+=check[a[i]];
      }
    }
    printf("%d\n",sum);
  }


  return 0;
}
