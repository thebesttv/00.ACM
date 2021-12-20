/*
描述
求两个不超过200位的非负整数的积。

输入
有两行，每行是一个不超过200位的非负整数，没有多余的前导0。

输出
一行，即相乘后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。

样例输入
12345678900
98765432100

样例输出
1219326311126352690000
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int BASE=100000000;
const int WIDTH=8;
struct BI{
  vector<int> v;
  int len;
}a,b,c;

void create(BI & a, char * str);
int compare(BI & a, BI & b);
BI add(BI a, BI b);
BI mul(BI a, int b);
BI mul(BI a, BI b);
void print(BI & a);

char temp[300];

int main(void){
  scanf("%s",temp); create(a,temp);
  scanf("%s",temp); create(b,temp);
  c=mul(a,b);
  print(c);

  return 0;
}

void create(BI & a, char * str){
  int len=strlen(str);
  char temp[20];
  int i=len;
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
int compare(BI & a, BI & b){
  if(a.len!=b.len) return a.len-b.len;
  else{
    for(int i=a.len-1;i>=0;i--) if(a.v[i]!=b.v[i])
      return a.v[i]-b.v[i];
  }
  return 0;
}
BI add(BI a, BI b){
  if(compare(a,b)<0) swap(a,b);
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
BI mul(BI a, int b){
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
}
BI mul(BI a, BI b){
  if(compare(a,b)<0) swap(a,b);
  BI c,temp; c=mul(a,b.v[0]);
  for(int i=1;i<b.len;i++){
    temp=mul(a,b.v[i]);
    for(int j=0;j<i;j++) temp.v.push_back(0);
    for(int j=temp.len-1;j>=0;j--) temp.v[j+i]=temp.v[j];
    for(int j=0;j<i;j++) temp.v[j]=0;
    //    for(int j=0;j<i;j++) temp.v.insert(temp.v.begin(),0);
    temp.len+=i;
    c=add(c,temp);
  }
  return c;
}
void print(BI & a){
  printf("%d",a.v[a.len-1]);
  for(int i=a.len-2;i>=0;i--) printf("%08d",a.v[i]);
  printf("\n");
}
