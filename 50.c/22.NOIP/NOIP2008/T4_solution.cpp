
注意到并没有说基于二分图匹配,因为这个算法和二分图匹配无关.这个算法只是用到了给一个图着色成二分图.


第一步需要解决的问题是,判断是否有解.

考虑对于任意两个数q1[i]和q1[j]来说,它们<b>不能</b>压入同一个栈中的充要条件是什么(注意没有必要使它们同时存在于同一个栈中,只是压入了同一个栈).实际上,这个条件p是:<b>存在一个k,使得i<j<k且q1[k]<q[i]<q[j] </b>.

首先证明充分性,即如果满足条件p,那么这两个数一定不能压入同一个栈.这个结论很显然,使用反证法可证.
假设这两个数压入了同一个栈,那么在压入q1[k]的时候栈内情况如下:
…q[i]…q[j]…
因为q1[k]比q1[i]和q1[j]都小,所以很显然,当q1[k]没有被弹出的时候,另外两个数也都不能被弹出(否则q2中的数字顺序就不是1,2,3,…,n了).
而之后,无论其它的数字在什么时候被弹出,q[j]总是会在q1[i]之前弹出.而q1[j]>q[i],这显然是不正确的.

接下来证明必要性.也就是,如果两个数不可以压入同一个栈,那么它们一定满足条件p.这里我们来证明它的逆否命题,也就是"如果不满足条件p,那么这两个数一定可以压入同一个栈."
不满足条件p有两种情况:一种是对于任意i<j<k且 q[i]<q[j], q[k]>q[i]; 另一种是对于任意i<j,q[i]>q[j].
第一种情况下,很显然,在q1[k]被压入栈的时候,q[i]已经被弹出栈.那么,q[k]不会对q[j]产生任何影响(这里可能有点乱,因为看起来,当q[j]<q[k]的时候,是会有影响的,但实际上,这还需要另一个数r,满足j<k<r且q1[r]<q[j]<q[k] ,也就是证明充分性的时候所说的情况…而事实上我们现在并不考虑这个r,所以说q[k]对q[j]没有影响).
第二种情况下,我们可以发现这其实就是一个降序序列,所以所有数字都可以压入同一个栈.
这样,原命题的逆否命题得证,所以原命题得证.

此时,条件p为q1[i]和q1[j]不能压入同一个栈的充要条件也得证.

这样,我们对所有的数对(i,j)满足1<=i<j<=n,检查是否存在i<j<k满足p1[k]<p1[i]<p1[j].如果存在,那么在点i和点j之间连一条无向边,表示p1[i]和p1[j]不能压入同一个栈.此时想到了什么?那就是二分图~
二分图的两部分看作两个栈,因为二分图的同一部分内不会出现任何连边,也就相当于不能压入同一个栈的所有结点都分到了两个栈中.
此时我们只考虑检查是否有解,所以只要O(n)检查出这个图是不是二分图,就可以得知是否有解.

此时,检查有解的问题已经解决.接下来的问题是,如何找到字典序最小的解.
实际上,可以发现,如果把二分图染成1和2两种颜色,那么结点染色为1对应当前结点被压入s1,为2对应被压入s2.为了字典序尽量小,我们希望让编号小的结点优先压入s1.
又发现二分图的不同连通分量之间的染色是互不影响的,所以可以每次选取一个未染色的编号最小的结点,将它染色为1并从它开始DFS染色,直到所有结点都被染色为止.这样,我们就得到了每个结点应该压入哪个栈中.接下来要做的,只不过是模拟之后输出序列啦~

还有一点小问题,就是如果对于数对(i,j),都去枚举检查是否存在k使得p1[k]<p1[i]<p1[j]的话,那么复杂度就升到了O(n^3).解决方法就是,首先预处理出数组b,b[i]表示从p1[i]到p1[n]中的最小值.接下来,只需要枚举所有数对(i,j),检查b[j+1]是否小于p1[i]且p1[i]是否小于p1[j]就可以了.

附代码(除去注释不到100行),带注释.代码中的a数组对应文中的队列p1.
已经过掉所有标准数据,以及5 7 2 4 1 6 3这组让很多贪心程序挂掉的数据~

xpycc  November 29th, 2008 at 09:24

这位大牛不妨试试以下数据：
1000
2 3 4 5 ... 1000 1
对于这组数据 MS 您的程序崩溃了……

原因是这组数据中无向边的条数为 999*999 ，而您的内存只申请了 1002*2 。

sqybi  November 29th, 2008 at 11:29

@xpycc
嗯...程序貌似是有bug的...
而且判无解的地方貌似也有问题...

#include
 
using namespace std;
 
const int nn = 1002, mm = nn * 2, inf = 1000000000;
int n, tot, now;
int a[nn], b[nn], head[nn], color[nn];
int adj[mm], next[mm];
int stack[3][nn];
bool result;
 
void addEdge(int x, int y) //加边
{
    ++ tot;
    adj[tot] = y;
    next[tot] = head[x];
    head[x] = tot;
}
 
bool dfs(int i) //DFS染色,检查图是否是二分图的经典算法
{
    int temp = head[i];
    while (temp) //邻接表,检查每一条边
    {
        if (! color[adj[temp]]) //如果与当前结点的结点还未染色
        {
            color[adj[temp]] = 3 - color[i]; //进行染色
            dfs(adj[temp]); //DFS
        }
        if (color[adj[temp]] == color[i]) return false;
            //如果两个相邻结点染色相同,说明此图不是二分图,返回无解
        temp = next[temp];
    }
    return true;
}
 
int main()
{
    freopen("twostack.in", "r", stdin);
    freopen("twostack.out", "w", stdout);
 
    //输入
    scanf("%d", &amp;n);
    for (int i = 1; i &lt;= n; ++ i) scanf("%d", &amp;a[i]);
 
    //预处理b数组
    b[n + 1] = inf;
    for (int i = n; i &gt;= 1; -- i) b[i] = min(b[i + 1], a[i]); //"min" in STL
 
    //枚举数对(i,j)并加边
    tot = 0;
    for (int i = 1; i &lt;= n; ++ i)
        for (int j = i + 1; j &lt;= n; ++ j)
            if (b[j + 1] &lt; a[i] &amp;&amp; a[i] &lt; a[j])
            {
                addEdge(i, j);
                addEdge(j, i);
            }
 
    //DFS染色
    memset(color, 0, sizeof(color));
    result = true;
    for (int i = 1; i &lt;= n; ++ i) //每次找当前未染色的编号最小的结点,并染颜色1
        if (! color[i]) //当前位置尚未被染色
        {
            color[i] = 1;
            if (! dfs(i)) //染色时出现矛盾,此时图不是一个二分图,即无法分配到两个栈中
            {
                result = false; //记录无解
                break;
            }
        }
 
    if (! result) //无解
        printf("0");
    else //有解
    {
        //模拟求解
        now = 1;
        for (int i = 1; i &lt;= n; ++ i)
        {
            //将当前数字压入对应的栈
            if (color[i] == 1)
                printf("a ");
            else
                printf("c ");
            stack[color[i]][0] ++;
            stack[color[i]][stack[color[i]][0]] = a[i]; //this will work even if stack[1][0] = 0
 
            //循环检查,如果可以的话就从栈顶弹出元素
            while (stack[1][stack[1][0]] == now || stack[2][stack[2][0]] == now)
            {
                if (stack[1][stack[1][0]] == now)
                {
                    printf("b ");
                    stack[1][0] --;
                }
                else if (stack[2][stack[2][0]] == now)
                {
                    printf("d ");
                    stack[2][0] --;
                }
                now ++;
            }
        }
    }
}