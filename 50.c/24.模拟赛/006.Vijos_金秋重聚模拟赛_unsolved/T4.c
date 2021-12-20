/*
描述
佳佳是一名出色的魔术师，现在他有一个初始长度为 n 的 01 字符串。他会对这个字符串进行一些操作和询问。
假设当前字符串的长度为 L，则有以下三种操作。
操作一、用 1 p c 来标记，其中 0<=p<=L 且 c 是0或1，表示在当前字符串第 p 个字符的后面插入一个新的字符 c；如果 p=0 表示在整个字符串的开头插入 c 。得到的新字符长度为比之前大一。
操作二、用 2 p 来标记，其中 1<=p<=L，表示删除当前的第 p 个字符，删除操作结束后，后面的字符会自动向前补齐，对应的新字符串长度会比之前小一。
操作三、用 3 s t 来表示，其中 1<=s<=t<=L，表示将字符串中第 s 个字符到第 t 个字符的一段整体翻转。反转后新的字符串长度不变。
佳佳还需要支持一种关于当前字符串的询问，用 4 s t 来表示，其中 1<=s<=t<=L，考虑从第 s 个到最后一个字符形成的子串，与从第 t 个到最后一个字符形成的字串，询问他们两个字符串的最长公共前缀长度。

格式
输入格式
输入的第一行是两个整数 n 和 m，n 是初始的字符串长度，m 是总的操作和询问的次数。
第二行输入一个长度为 n 的 01 字符串。
之后m行，每行给出一个操作或一个询问。

输出格式
对于每一次询问，输出一个正整数，表示最长公共前缀的长度。

样例1
样例输入1
12 9
000100001100
1 0 1
4 2 6
3 7 10
4 1 7
2 9
4 3 11
4 1 9
4 1 7
4 2 3

样例输出1
3
6
2
0
3
2

限制
对于 30% 的数据，n,m≤5000。
对于 60% 的数据，n,m≤300000。
对于 100% 的数据，n,m≤500000。
前三组数据的时限每一组为 1 秒，后面每一组数据的时限为 10 秒。
*/

/*
  得分：0（压根没做）
  解题报告：
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


