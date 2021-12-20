/*
新壳栈
小 Z 设计了一种新的数据结构“新壳栈”。首先,它和传统的栈一样支持压入、弹出操作。此外,其栈顶的前 c 个元素是它的壳,支持翻转操作。其中,c > 2是一个固定的正整数,表示壳的厚度。小 Z 还希望,每次操作,无论是压入、弹出还是翻转,都仅用与 c 无关的常数时间完成。聪明的你能帮助她编程实现“新壳栈”吗?
程序期望的实现效果如以下两表所示。其中,输入的第一行是正整数 c,之后每行输入都是一条指令。另外,如遇弹出操作时栈为空,或翻转操作时栈中元素不足 c 个,应当输出相应的错误信息。

  指令  含义
  1 e   在栈顶压入元素 e
    2   弹出(并输出)栈顶元素
    3   翻转栈顶的前 c 个元素
    0   退出

  输入  输出  栈中的元素  解释(左为栈底,右为栈顶)
     3        无          输入正整数 c
   1 1        1           压入元素 1
   1 2        1 2         压入元素 2
   1 3        1 2 3       压入元素 3
   1 4        1 2 3 4     压入元素 4
   3 1        4 3 2       翻转栈顶的前 c 个元素
   1 5        1 4 3 2 5   压入元素 5
     3        1 4 5 2 3   翻转栈顶的前 c 个元素
     2     3  1 4 5 2     弹出栈顶元素 3
     2     2  1 4 5       弹出栈顶元素 2
     2     5  1 4         弹出栈顶元素 5
     3  错误  1 4         由于栈中元素不足 c 个,无法翻转,故操作失败,输出错误信息
     2     4  1           弹出栈顶元素 4
    2      1  空          弹出栈顶元素 1
    2   错误  空          由于栈为空,无法弹出栈顶元素,故操作失败,输出错误信息
    0         空          退出
*/

/*
  解题报告：
    说实话这是我第一次见这么帅的数据结构合并，它的大致结构是这样的：

                              prev next          
                             <---- ---->         
       +-----------------  --------------        
       |      stack     <-->    deque    <- input
       +-----------------  --------------        
                       ^    ^         ^          
                      top  tail      head        

    。。。嗯这就是一个栈插上了一个双端队列 XD，不过我一开始还是不明觉历啊！
    stack + deque 就是题目的所谓的O(1)新壳栈了，其中deque是“壳”部分，stack是非壳部分，具体实现见代码注释。
    不过题目里是手打栈和队列（变成了循环队列），还是比较搞的。
    代码的具体实现原理我还不清楚，但差不多就行了吧 XD
*/

#include <iostream>
using namespace std;
const int NSIZE = 100000, CSIZE = 1000;
int n, c, r, tail, head, s[NSIZE], q[CSIZE];
//数组 s 模拟一个栈,n 为栈的元素个数
//数组 q 模拟一个循环队列,tail 为队尾的下标,head 为队头的下标
//<b> q的优先级永远比s大</b>
bool direction, empty;

int previous(int k){  //k的前驱节点
  if(direction) return ((k+c-2)%c)+1;
  else return (k%c)+1;
}
int next(int k){  //k的后继节点
  if(direction) return (k%c)+1;
  else return ((k+c-2)%c)+1;
}

void push(){
  /*
   * 读入elem后，首先查看队列是否满了，如果满了，则出队一个到栈中。
   * 然后再将elem入队（壳）
   */
  int element;
  cin >> element;
  if(next(head)==tail){ //if full
    n++;
    s[n]=q[tail];
    tail=next(tail);
  }
  if(empty) empty=false;
  else head=next(head);
  q[head]=element;
}
void pop(){
  /*
   * 进行非法判断后，直接输出壳上的第一个元素，然后进行empty的判断，如果还剩下元素，则将栈出栈到队列中
   */
  if(empty) {cout<<"Error: the stack is empty!"<<endl; return;}
  cout << q[head] << endl;
  if(tail==head) empty=true;
  else{
    head=previous(head);
    if(n>0){
      tail=previous(tail);
      q[tail]=s[n];
      n--;
    }
  }
}
void reverse(){
  /*
   * 用全局变量direction判断是否revers过
   */
  if(naxt(head)==tail){
    direction = !direction;
    swap(head,tail);
  }else cout << "Error: less than " << c << " elements in the stack!" << endl;
}

int main(){
  cin>>c;
  n=0; tail=1; head=1; empty=true;
  direction=true; //directhon 为1，表示正序；为0，表示逆序

  do{
    cin>>r;
    switch(r){
      case 1: push(); break;
      case 2: pop(); break;
      case 3: reverse(); break;
    }
  }while(r!=0);

  return 0;
}
