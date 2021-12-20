/*
描述
给出两个正整数以及四则运算操作符（+ - * /），求运算结果。

输入
第一行：正整数a，长度不超过100
第二行：四则运算符o，o是“+”，“-”，“*”，“/”中的某一个
第三行：正整数b，长度不超过100
保证输入不含多余的空格或其它字符

输出
一行：表达式“a o b”的值。

补充说明：
1. 减法结果有可能为负数
2. 除法结果向下取整
3. 输出符合日常书写习惯，不能有多余的0、空格或其它字符

样例输入
9876543210
+
9876543210

样例输出
19753086420
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int BASE=100000000;
const int WIDTH=8;
struct BigInteger;
typedef BigInteger BI;
struct BigInteger{
  vector<int> v;
  int len;
  bool isMinus;

  BigInteger(): len(0), isMinus(0) {}
};
char temp[2][200],op;

void create(BI & a, char * str);
BI add(BI a, BI b);
BI sub(BI a, BI b);
BI mul(BI a, BI b);
BI mul(BI a, int b);
BI div(BI a, BI b);
BI half(BI a);
int compare(const BI & a, const BI & b);
void print(const BI & a);

int main(void){
  scanf("%s",temp[0]);
  getchar(); op=getchar(); getchar();
  scanf("%s",temp[1]);
  BI a,b,c;
  create(a,temp[0]); create(b,temp[1]);
#ifdef DEBUG
  print(a); printf(" %c ",op); print(b); printf("\n");
#endif
  switch(op){
    case '+': c=add(a,b); break;
    case '-': c=sub(a,b); break;
    case '*': c=mul(a,b); break;
    case '/': c=div(a,b);
  }
  print(c); printf("\n");

  return 0;
}

void create(BI & a, char * str){
  if(str[0]=='-') {a.isMinus=1; str++;}
  int len=strlen(str);
  int i=len; char temp[20];
  while(i>=WIDTH){
    memset(temp,0,sizeof(temp));
    strncpy(temp,str+i-WIDTH,WIDTH);
    a.v.push_back(atoi(temp));
    i-=WIDTH;
  }
  if(i){
    memset(temp,0,sizeof(temp));
    strncpy(temp,str,i);
    a.v.push_back(atoi(temp));
  }
  a.len=a.v.size();
}

BI add(BI a, BI b){
  if(a.isMinus && !b.isMinus){
    a.isMinus=0;
    return sub(b,a);
  }else if(!a.isMinus && b.isMinus){
    b.isMinus=0;
    return sub(a,b);
  }else{
    if(!a.isMinus && compare(a,b)<0) swap(a,b);
    else if(a.isMinus && compare(a,b)>0) swap(a,b);
    int carry=0;
    for(int i=0;i<a.len;i++){
      a.v[i]+=carry;
      if(i<b.len) a.v[i]+=b.v[i];
      carry=a.v[i]/BASE;
      a.v[i]%=BASE;
    }
    if(carry) a.v.push_back(carry);
    a.len=a.v.size();
    return a;
  }
}
BI sub(BI a, BI b){
  if(a.isMinus && !b.isMinus){
    a.isMinus=0;
    BI c=add(a,b); c.isMinus=1;
    return c;
  }else if(!a.isMinus && b.isMinus){
    b.isMinus=0;
    return add(a,b);
  }else{
    int comp=compare(a,b);
    bool isMinus=comp<0;
    //if(a.len<b.len) swap(a,b);
    if(!a.isMinus && comp<0) swap(a,b);
    else if(a.isMinus && comp>0) swap(a,b);
    for(int i=0;i<a.len;i++){
      if(i<b.len){
        if(a.v[i]<b.v[i]){
          a.v[i+1]--;
          a.v[i]=a.v[i]-b.v[i]+BASE;
        }else{
          a.v[i]-=b.v[i];
        }
      }else{
        if(a.v[i]<0) {a.v[i]+=BASE; a.v[i+1]--;}
        }
      }
    vector<int>::iterator it=a.v.end(); it--;
    for(;it!=a.v.begin();it--)
      if((*it)==0) a.v.erase(it);
      else break;
    a.len=a.v.size();
    a.isMinus=isMinus;
    return a;
  }
}
BI mul(BI a, BI b){
  BI c; bool isMinus=0;
  if(a.isMinus ^ b.isMinus) isMinus=1;
  if(a.len<b.len) swap(a,b);
  c=mul(a,b.v[0]);
  for(int i=1;i<b.len;i++){
    BI temp=mul(a,b.v[i]);
    vector<int> tv;
    for(int j=0;j<i;j++) tv.push_back(0);
    for(int j=0;j<temp.len;j++) tv.push_back(temp.v[j]);
    temp.v=tv; temp.len=temp.v.size();
    //for(int j=0;j<i;j++) temp.v.push_back(0);
    //for(int j=temp.len-1;j>=0;j--) temp.v[j+i]=temp.v[j];
    //for(int j=0;j<i;j++) temp.v[j]=0;
    //temp.len+=i;
    c=add(c,temp);
  }
  c.len=c.v.size();
  c.isMinus=isMinus;
  return c;
}
BI mul(BI a, int b){  //mul(BI,BI)的子函数，无需关注正负
  long long carry=0;
  BI c;
  for(int i=0;i<a.len;i++){
    carry+=(long long)a.v[i]*b;
    c.v.push_back(carry%BASE);
    carry/=BASE;
  }
  if(carry) c.v.push_back(carry);
  c.len=c.v.size();
  return c;
  /*
  long long carry=0,temp;
  for(int i=0;i<a.len;i++){
    temp=(long long)a.v[i]*b+carry;
    a.v[i]=temp%BASE;
    carry=temp/BASE;
  }
  if(carry) a.v.push_back(carry);
  a.len=a.v.size();
  return a;
  */
}
BI div(BI a, BI b){ //非向下取整，而是偏向0取整
  BI c,one,zero; bool isMinus=0;
  one.len=1; one.isMinus=0; one.v.push_back(1);
  zero.len=1; zero.isMinus=0; zero.v.push_back(0);
  if(a.isMinus ^ b.isMinus) isMinus=1;
  a.isMinus=0; b.isMinus=0;
  int comp=compare(a,b);
  if(comp<0) return zero;
  else if(comp==0) return one;
  else{
    BI L=one,R=a;
    while(compare(L,R)<0){
#ifdef DEBUG
      printf("  L: "); print(L); printf(",R: "); print(R); printf("\n");
#endif
      BI sum=add(L,R);
      BI M=half(add(sum,one));
      BI temp=mul(b,M);
      int comp_=compare(temp,a);
      if(comp_==0) return M;
      else if(comp_<0) L=M;
      else R=sub(M,one);
    }
    //L.len=L.v.size();
    L.isMinus=isMinus;
    return L;
  }
}
BI half(BI a){
  for(int i=a.len-1;i>=0;i--){
    if(a.v[i]&1 && i) a.v[i-1]+=BASE;
    a.v[i]/=2;
  }
  vector<int>::iterator it=a.v.end(); it--;
  if((*it)==0) a.v.erase(it);
  a.len=a.v.size();
  return a;
}

int compare(const BI & a, const BI & b){
  if(a.isMinus && !b.isMinus) return -1;
  else if(!a.isMinus && b.isMinus) return 1;
  else{
    bool type=1;
    if(a.isMinus) type=-1;
    if(a.len!=b.len) return (a.len-b.len)*type;
    else{
      for(int i=a.len-1;i>=0;i--) if(a.v[i]!=b.v[i])
        return (a.v[i]-b.v[i])*type;
    }
    return 0; //<b>莫忘</b>
  }
}
void print(const BI & a){
  if(!a.len) return;
  if(a.isMinus) putchar('-');
  printf("%d",a.v[a.len-1]);
  for(int i=a.len-2;i>=0;i--) printf("%08d",a.v[i]);
}
