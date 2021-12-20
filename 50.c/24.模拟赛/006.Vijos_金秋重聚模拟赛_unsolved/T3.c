/*
描述
我们称一个整数是奇偶等和数，是说它的数位个数是偶数（比如二位数，四位数，六位数等，且特殊说明 0 是一位数字），且其中所有奇数位数字之和恰好等于所有偶数位数字之和。
我们称一个整数是几乎奇偶等和数，是说在恰好修改其中一位数字后，得到的新数字是一个奇偶等和数。这里说恰好修改一位数字，要求必须发生了实质性修改，也就是说修改后的数字必须与之前的数字不同（例如将1234修改为1234就是不合法的，因为修改后的数字和之前是一样的）；同时要求不能将最高位修改为 0。
现在给定整数 A 和 B，问有多少几乎奇偶等和数 x 满足 A≤x≤B。

格式
输入格式
输入只有一行，是两个整数 A 和 B，满足 0≤A≤B≤10^9 。

输出格式
输出一个正整数，表示有多少几乎奇偶等和数。

样例1
样例输入1
1 33

样例输出1
21

样例2
样例输入2
51 78

样例输出2
25

限制
对于 30% 的数据，0<=a<=b<=130000
对于所有数据，0<=A<=B<=10^9
存在额外的 10\%10% 的数据，B-A<=10^7；还有另外的额外 10% 的数据，B-A<=5*10^7 。
每一组数据的时限为 0.3 秒。
*/

/*
  得分：0
  解题报告：
    无奈。。。
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
