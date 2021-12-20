/*
题目描述
农民 John的农场里有很多牧区。有的路径连接一些特定的牧区。一片所有连通的牧区称为一个牧场。但是就目前而言，你能看到至少有两个牧区通过任何路径都不连通。这样，Farmer John就有多个牧场了。
John想在牧场里添加一条路径(注意，恰好一条)。对这条路径有以下限制：
一个牧场的直径就是牧场中最远的两个牧区的距离(本题中所提到的所有距离指的都是最短的距离)。考虑如下的有5个牧区的牧场，牧区用“*”表示，路径用直线表示。每一个牧区都有自己的坐标：

                (15,15) (20,15)
                 D       E
                 *-------*
                 |     _/|
                 |   _/  |
                 | _/    |
                 |/      |
        *--------*-------*
        A        B       C
     (10,10)  (15,10) (20,10)

这个牧场的直径大约是12.07106, 最远的两个牧区是A和E，它们之间的最短路径是A-B-E。
这里是另一个牧场：

                *F(30,15)
               / 
             _/  
           _/    
          /      
         *------*
         G      H
      (25,10)(30,10)

在目前的情景中，他刚好有两个牧场。John将会在两个牧场中各选一个牧区，然后用一条路径连起来，使得连通后这个新的更大的牧场有最小的直径。
注意，如果两条路径中途相交，我们不认为它们是连通的。只有两条路径在同一个牧区相交，我们才认为它们是连通的。
输入文件包括牧区、它们各自的坐标，还有一个如下的对称邻接矩阵：

　 A  B  C  D  E  F  G  H 
A  0  1  0  0  0  0  0  0
B  1  0  1  1  1  0  0  0
C  0  1  0  0  1  0  0  0
D  0  1  0  0  1  0  0  0
E  0  1  1  1  0  0  0  0
F  0  0  0  0  0  0  1  0
G  0  0  0  0  0  1  0  1
H  0  0  0  0  0  0  1  0

其他邻接表中可能直接使用行列而不使用字母来表示每一个牧区。输入数据中不包括牧区的名字。
输入文件至少包括两个不连通的牧区。
请编程找出一条连接两个不同牧场的路径，使得连上这条路径后，这个更大的新牧场有最小的直径。输出在所有牧场中最小的可能的直径。

输入输出格式
输入格式：
第1行: 一个整数N (1 <= N <= 150), 表示牧区数
第2到N+1行: 每行两个整数X,Y (0 <= X ,Y<= 100000), 表示N个牧区的坐标。注意每个 牧区的坐标都是不一样的。
第N+2行到第2*N+1行: 每行包括N个数字(0或1) 表示如上文描述的对称邻接矩阵。

输出格式：
只有一行，包括一个实数，表示所求直径。数字保留六位小数。
只需要打到小数点后六位即可，不要做任何特别的四舍五入处理。

输入输出样例
输入样例#1： 
8
10 10
15 10
20 10
15 15
20 15
30 15
25 10
30 10
01000000
10111000
01001000
01001000
01110000
00000010
00000101
00000010

输出样例#1： 
22.071068
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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
typedef long long LL;
typedef long long unsigned LLU;


