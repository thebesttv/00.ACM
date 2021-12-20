/*
描述
求两个不超过200位的非负整数的和。

输入
有两行，每行是一个不超过200位的非负整数，可能有多余的前导0。

输出
一行，即相加后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。

样例输入
22222222222222222222
33333333333333333333

样例输出
55555555555555555555
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

const int BASE=100000000;
const int WIDTH=8;
struct BI{
  vector<int> v;
  int len;
  int isMinus;
}a,b,c;

char temp[300];

void create(BI & a, char * str);
int compare(BI & a, BI & b);
BI add(BI a, BI b);
void print(BI & a);

int main(void){
  int i=0;
  scanf("%s",temp); while(temp[i]=='0' && temp[i+1]!=0) i++;
  create(a,temp+i);
  i=0;
  scanf("%s",temp); while(temp[i]=='0' && temp[i+1]!=0) i++;
  create(b,temp+i);
  c=add(a,b);
  print(c);

  return 0;
}

void create(BI & a, char * str){
  int len=strlen(str);
  int i=len;
  char temp[20];
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
  a.isMinus=0;
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
  if(carry){
    a.v.push_back(carry);
  }
  a.len=a.v.size();
  return a;
}
void print(BI & a){
  printf("%d",a.v[a.len-1]);
  for(int i=a.len-2;i>=0;i--)
    printf("%08d",a.v[i]);
  printf("\n");
}
