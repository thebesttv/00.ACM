/*
描述
求两个大的正整数相减的差。

输入
共2行，第1行是被减数a，第2行是减数b(a > b)。每个大整数不超过200位，不会有多余的前导零。

输出
一行，即所求的差。

样例输入
9999999999999999999999999999999999999
9999999999999

样例输出
9999999999999999999999990000000000000
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
  bool isMinus;
}a,b,c;
vector<int>::iterator it;

void create(BI & a, char * str);
int compare(BI & a, BI & b);
BI sub(BI a, BI b);
void print(BI & a);

char temp[300];

int main(void){
  scanf("%s",temp); create(a,temp);
  scanf("%s",temp); create(b,temp);
  c=sub(a,b);
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
  a.isMinus=0;
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
BI sub(BI a, BI b){
  if(compare(a,b)<0){
    swap(a,b);
    BI t=sub(a,b);
    t.isMinus=1;
    return t;
  }else if(compare(a,b)==0){
    BI t; t.len=1; t.isMinus=0; t.v.push_back(0);
    return t;
  }else{
    for(int i=0;i<b.len;i++){
      if(a.v[i]<b.v[i]){
        a.v[i+1]--;
        a.v[i] = a.v[i]-b.v[i]+BASE;
      }else{
        a.v[i]-=b.v[i];
      }
    }
    it=a.v.end(); it--;
    while(it!=a.v.begin()){
      if(!(*it)) a.v.erase(it);
      else break;
      it--;
    }
    a.len=a.v.size();
    return a;
  }
}
void print(BI & a){
  printf("%d",a.v[a.len-1]);
  for(int i=a.len-2;i>=0;i--) printf("%08d",a.v[i]);
  printf("\n");
}
