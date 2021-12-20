/*
描述
求两个大的正整数相除的商。

输入
第1行是被除数，第2行是除数。每个数均不超过100位。

输出
一行，相应的商的整数部分

样例输入
2376
24

样例输出
99
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
  bool isMinus;
}a,b,c;
vector<int>::iterator it;

void create(BI & a, char * str);
int compare(BI & a, BI & b);
BI add(BI a, BI b);
BI sub(BI a, BI b);
BI mul(BI a, int b);
BI mul(BI a, BI b);
BI half(BI a);
BI div(BI a, BI b);
void print(BI & a);

char temp[300];

int main(void){
  scanf("%s",temp); create(a,temp);
  scanf("%s",temp); create(b,temp);
  c=div(a,b);
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
BI half(BI a){
  for(int i=a.len-1;i>=0;i--){
    if(a.v[i]&1 && i>0) a.v[i-1]+=BASE;
    a.v[i]/=2;
  }
  if(a.v[a.len-1]==0) a.len--;
  return a;
}
BI div(BI a, BI b){
  BI c;
  if(compare(a,b)<0){
    c.v.push_back(0); c.len=1;
    return c;
  }else if(compare(a,b)==0){
    c.v.push_back(1); c.len=1;
    return c;
  }else{
    BI one; one.len=1; one.v.push_back(1);
    BI L=one,R=a;
    while(compare(L,R)<0){
      BI temp=add(L,R);
      BI M=half(add(temp,one));
      BI ans=mul(b,M);
      if(compare(ans,a)==0) return M;
      else if(compare(ans,a)<0) L=M;
      else R=sub(M,one);
    }
    return L;
  }
}
void print(BI & a){
  printf("%d",a.v[a.len-1]);
  for(int i=a.len-2;i>=0;i--) printf("%08d",a.v[i]);
  printf("\n");
}
