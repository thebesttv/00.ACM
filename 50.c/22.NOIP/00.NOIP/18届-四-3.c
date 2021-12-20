/*
输入1
8

输出1
7

输入2
2012

输出2
2004
*/

/*
  解题报告：
    这其中最有趣的是merge函数，由于while中的判断，它把两个相同的data加到左边的那个中，有点类似于游戏2048的一维版。
    而稍作模拟，可以发现，对于每个n，其一次次的合并实质上是一个由多棵满二叉树组成的森林。
      比如对于n=10，是一个有两棵树的森林：

                    8
                /       \
            4              4
          /   \          /   \
        2       2      2       2      2
       / \     / \    / \     / \    / \
      1   1   1   1  1   1   1   1  1   1
    而答案就是这个森林的度为2的节点数。
    又因为n2=n0-1，因此答案即为 n-k, k 为森林中树的棵树。
    再仔细观察森林中每棵树的叶子节点，可以发现，这k棵树将n分解为 2^a1 + 2^a2 + 2^a3 + ... + 2^ak，其中 a1>a2>a3?...>ak，可以看作每棵树的层数（从0算起）。
    显然，这实质上是将n分解成了二进制。
    那么答案就更容易得出了。
    只要将n转化为二进制n'，令n'中“1”的数目为k，则答案即为n-k。
*/

#include <iostream>
using namespace std;

const int SIZE = 20;
int data[SIZE];
int n, i, h, ans;

void merge(){
  data[h-1] = data[h-1] + data[h];
  h--;
  ans++;
}

int main(){
  cin>>n;
  h = 1;
  data[h] = 1;
  ans = 0;
  for (i = 2; i <= n; i++){
    h++; data[h] = 1;
    while (h > 1 && data[h] == data[h-1])
      merge();
  }
  cout<<ans<<endl;

  return 0;
}
