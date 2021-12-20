/*
描述
The Lab Cup Table Tennis Competition is going to take place soon among laboratories in PKU. Students from the AI Lab are all extreme enthusiasts in table tennis and hold strong will to represent the lab in the competition. Limited by the quota, however, only one of them can be selected to play in the competition.
To make the selection fair, they agreed on a single round robin tournament, in which every pair of students played a match decided by best of 5 games. The one winning the most matches would become representative of the lab. Now Ava, head of the lab, has in hand a form containing the scores of all matches. Who should she decide on for the competition?

输入
The input contains exactly one test case. The test case starts with a line containing n (2 ≤ n ≤ 100), the number of students in the lab. Then follows an n × n matrix A. Each element in the matrix will be one of 0, 1, 2 and 3. The element at row i and column j, aij, is the number of games won by the ith student in his/her match with the jth student. Exactly one of aij and aji (i ≠ j) is 3 and the other one will be less than 3. All diagonal elements of the matrix are 0’s.

输出
Output the number of the student who won the most matches. In the case of a tie, choose the one numbered the smallest.

样例输入
4
0 0 3 2
3 0 3 1
2 2 0 2
3 3 3 0

样例输出
4

来源
PKU Local 2007 (POJ Monthly--2007.04.28), ideas from ava, text and test cases by frkstyc
*/

#include<iostream>
#include<cstdio>
using namespace std;

int a[120][120];
int tot[120];

int main(void){
  int n,Max=0,u; scanf("%d",&n);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
  }
  /*
  for(int i=1;i<=n;i++){
    int cnt=0;
    for(int j=1;j<=n;j++) if(a[i][j]>a[j][i]) cnt++;
    if(cnt>Max) Max=cnt,u=i;
  }
  */
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++)
      if(a[i][j]>a[j][i]) tot[i]++;
      else tot[j]++;
  }
  for(int i=1;i<=n;i++) if(tot[i]>Max) Max=tot[u=i];
  printf("%d\n",u);

  return 0;
}
