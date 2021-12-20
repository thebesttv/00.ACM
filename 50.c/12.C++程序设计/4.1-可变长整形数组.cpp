#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

class CArray{
  private:
    int * array;
    int size;
  public:
    CArray(int s=0);
    CArray(const CArray & b);
    ~CArray();
    void push_back(int n);
    int length() {return size;};

    CArray & operator = (const CArray & b);
    int & operator [] (int i) {return array[i];}
      //返回值应为<b> int 的引用</b>
      //如果只是 int ，则只能实现 n=a[4] ，不能实现 a[4]=n
};

CArray::CArray(int s): size(s){
  if(s==0) array=NULL;
  else array = new int[s];
}
CArray::CArray(const CArray & b){
//if(array) delete [] array;  //复制函数可能在初始化时调用，此时 array 指向不为 NULL ，但不能被 delete
  array=NULL; size=0;
  if(b.size){
    array = new int[b.size];
    memcpy(array,b.array,sizeof(int)*b.size);
    size=b.size;
  }
}
CArray::~CArray(){
  if(array) delete [] array;
}
CArray & CArray::operator = (const CArray & b){
  if(array==b.array) return *this;
  if(b.array==NULL){
    if(array) delete [] array;
    array=NULL; size=0;
  }else{
    if(size<b.size){
      if(array) delete [] array;
      array = new int[b.size];
    }
    memcpy(array,b.array,sizeof(int)*b.size);
  }
  return *this;
}
void CArray::push_back(int n){
  if(array){
    int *tempArray = new int [size+1];
    memcpy(tempArray,array,sizeof(int)*size);
    delete [] array;
    array = tempArray;
  }else{
    array = new int[1];
  }
  array[size++]=n;
}

int main(void){
  CArray a;
  for(int i=0;i<5;i++) a.push_back(i);
  CArray a2,a3;
  a2 = a; //重载 =
  for(int i=0;i<a.length();i++) printf("%d ",a2[i]); printf("\n");  //重载 []
  a2 = a3;
  for(int i=0;i<a2.length();i++) printf("%d ",a2[i]); printf("\n");
  a[3]=100;
  CArray a4(a);
  for(int i=0;i<a4.length();i++) printf("%d ",a4[i]); printf("\n");

  return 0;
}
