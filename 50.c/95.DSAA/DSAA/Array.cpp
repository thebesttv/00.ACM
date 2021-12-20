#include "Array.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <cstdio>
using namespace std;

//*****创建一个len长度的整形数组，返回数组的首地址*****
int * cyf_CreateArray(int len)
{
  if(len <= 0)
    return NULL;

  int * pnew = new int[len];
  memset(pnew, 0, sizeof(int)*len); //数组初始化为0

  return pnew;
}

//*****为数组赋n个随机数初值，初值范围1~1000*****
void  cyf_InitArray(int * a, int len, int n)
{
  if(a == NULL || n <= 0)
  {
    return;
  }
  
  srand(time(NULL));  //产生随机数种子;
  
  n = (len >= n)?n:len; //判断n是否超出数组长度
  
  for(int i=0;i<n;i++)
    a[i] = rand()%1000 + 1;
}

//*****显示数组中有效数字*****
void  cyf_ShowArray(int * a, int len, int n)
{
  if(a == NULL || n <= 0)
  {
    return;
  }

    n = (len >= n)?n:len; //判断n是否超出数组长度

  cout<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
}


//*****对数组n个数进行排序--冒泡升序排序*****
void  cyf_SortArray_Maopao(int * a, int len, int n)
{
  if(a == NULL || n <= 0)
  {
    return;
  }
  
    n = (len >= n)?n:len; //判断n是否超出数组长度

  int i,j;
  int tmp;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(a[j] > a[j+1])
      {
        tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
      }
    }
  }
}

//*****样例：计算冒泡排序的时间复杂度*********
int  cyf_SortArray_Maopao_TimeComplex(int * a, int len, int n)
{
    int count = 0;
  if(a == NULL || n <= 0)
  {
    return 0;
  }
  
    n = (len >= n)?n:len; //判断n是否超出数组长度
  
  int i,j;
  int tmp;
  for(i=0;i<n;i++)
  {
    count += 2; //i<n;i++ 两次运算
    for(j=0;j<n-i-1;j++)
    {
      count += 4;
      if(a[j] > a[j+1])
      {
        tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
        count += 5;//3次赋值运算 2次+运算
      }
      count += 2; //a[j] > a[j+1] 比较和+运算
    }
  }
  return count;
}

//*****作业1：在一个len长度 n个有效数的有序数组中a[0]~a[n-1]数组中删除指定的元素，要求删除后，数组依然有序*********
//len: 数组长度    n: 有效数字个数   m:要删除的数字
//return: 返回删除后的数组有效数字个数  如1 2 3 4 4 5 6 0 0 0 0  删除4 结果:1 2 3 5 6 0 0 0 0 0 0
int cyf_DeleteElement(int * a, int len, int n, int m)
{
  //add your code here
  if(a == NULL || n <= 0)
    return 0;
    n = (len >= n)?n:len; //判断n是否超出数组长度

  len=0;
  for(int i=0;i<n;++i) if(a[i]!=m)
    a[len++] = a[i];
  return len;
}

//*****作业2：将一个元素添加进数组
//len: 数组长度    n: 有效数字个数   m:要添加的数字
//return: 返回添加后的数组有效数字个数  如1 2 3 5 6 0 0 0 0  添加4 结果:1 2 3 4 5 6 0 0 0 0 0 
int cyf_AddElement(int * a, int len, int n, int m)
{
  //add your code here
  if(a == NULL) return 0;
  if(n>=len) return n;
  if(n<0) n=0;

  int i=0;
  while(i<n && a[i]<m) ++i;
  for(int j=n-1;j>=i;--j)
    a[j+1]=a[j];
  a[i]=m;
  ++n;

  return n;
}

//*****作业3：将一组元素添加进数组
//len: 数组长度    n: 有效数字个数   m:要添加的数字
//return: 返回添加后的数组首地址  
//如a: 1 2 3 5 6 0 0 0 0  b: 3 7 0 0 0 0  添加后: a: 1 2 3 3 4 5 6 7 0
//如a: 1 2 3 5 6 0 0 0 0  b: 3 7 8 9 9 9 9 0 0 0  添加后: a: 1 2 3 3 4 5 6 7 8 9 9 9 9
void cyf_AddElement(int * & a, int & lena, int & na, int * b, int lenb, int nb){
  //add your code here
  if(b==NULL || nb<=0) return;
  int *p = new int [na+nb], tail=0,i=0,j=0;
  while(i<na || j<nb){
    if(j>=nb || (i<na && a[i]<b[j]))
      p[tail++] = a[i++];
    else
      p[tail++] = b[j++];
  }
  delete [] a;
  a = p, lena = na = na + nb;
}
