#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;

class BigInteger;
typedef BigInteger BI;
class BigInteger{
  private:
    vector<int> v;
    int len;        //vector中元素个数
    bool isMinus;
  public:
    static const int BASE=100000000;
    static const int WIDTH=8;
    BigInteger(): isMinus(0), len(0) {}
    BigInteger(char * str);
    BigInteger(BI & b);
    ~BigInteger() {}
    void clear() {v.clear(); isMinus=0; len=0;}
    void create(char * str);
    bool isZero(BI & a);

    friend ostream & operator << (ostream & os, const BI & a);
    friend istream & operator >> (istream & is, BI & a);
};

BI operator + (BI & a, BI & b);
BI operator - (BI & a, BI & b);
BI operator * (BI & a, BI & b);
BI operator / (BI & a, BI & b);
BI operator ^ (BI & a, int e);
BI & operator = (BI & a, BI & b);
BI & operator += (BI & a, BI & b);
BI & operator -= (BI & a, BI & b);
BI & operator *= (BI & a, BI & b);
BI & operator /= (BI & a, BI & b);
BI & operator ^= (BI & a, int e);
bool operator < (BI & a, BI & b){
  if(isMinus && !b.isMinus) return true;
  else if(!isMinus && b.isMinus) return false;
  if(isMinus && b.isMinus){
    if(len<b.len) return false;
    else if(len>b.len) return true;
    else{
      for(int i=len-1;i>=0;i--) if(v[i]!=b.v[i])
        return v[i]>b.v[i];
    }
  }
}
bool operator <= (BI & a, BI & b){return !(b < *this);}
bool operator > (BI & a, BI & b){return b < *this;}
bool operator >= (BI & a, BI & b){return !(*this < b);}
bool operator != (BI & a, BI & b){return *this < b || b < *this;}
bool operator == (BI & a, BI & b){return !(*this < b) && !(b < *this);}

int main(void){
  BI a,b,c;
  char temp1[300],temp2[300];
  while(scanf("%s%s",temp1,temp2)==2){
    a.create(temp1); b.create(temp2);
    cout << a+b << endl;
  }

  return 0;
}

BI operator + (BI & a, BI & b){ //无法处理正、负数之间相加
  BI c,d;
  if(len>b.len) {c=(a); d=b;}
  else {c=b; d=(a);}
  int i=0,carry=0;
  while(i<c.len){
    c.v[i]+=carry;
    if(i<d.len) c.v[i]+=d.v[i];
    carry=c.v[i]/BASE;
    c.v[i]%=BASE;
    i++;
  }
  if(carry) c.v.push_back(carry);
  return c;
}
BI BI::operator - (BI & a, BI & b){
  if(a < b){
    BI c = b-(a);
    c.isMinus=1;
    return c;
  }else{
    BI c(a);
    for(int i=0;i<b.len;i++){
      if(c.v[i]<b.v[i]){
        c.v[i+1]--;
        c.v[i] = c.v[i]-b.v[i]+BASE;
      }else{
        c.v[i] = c.v[i]-b.v[i];
      }
    }
    return c;
  }
}
BI & BI::operator = (BI & a, BI & b){
  isMinus=b.isMinus;
  len=b.len;
  v=b.v;
  return a;
}



















BI::BigInteger(char *str){  //checked
  this->create(str);
}
void BI::create(char * str){  //checked
  if(len) clear();
  if(str[0]=='-') {isMinus=true; str++;}
  int slen=strlen(str);
  int i=slen;
  char temp[WIDTH+10];
  while(i>=WIDTH){
    memset(temp,0,sizeof(temp));
    strncpy(temp,str+i-WIDTH,WIDTH);
    v.push_back(atoi(temp));
    i-=WIDTH;
  }
  if(i){
    memset(temp,0,sizeof(temp));
    strncpy(temp,str,i);
    v.push_back(atoi(temp));
  }
  len=v.size();
#ifdef DEBUG
  printf("  create BI from original len: %d, now with len: %d, isMinus: %d\n",slen,len,isMinus);
#endif
}

ostream & operator << (ostream & os, const BI & a){ //not good
  if(a.isMinus) putchar('-');
  for(int i=a.len-1;i>=0;i--){
    //os << a.v[i];
    if(i==a.len-1) printf("%d",a.v[i]);
    else printf("%08d",a.v[i]);
  }
  return os;
}
/*
   istream & operator >> (istream & is, BI & a){ //checked
   a.clear();
   string s;
   is >> s;
   char *str = new char[s.length()+10];
   for(int i=0;i<s.length();i++) str[i]=s[i];
   a.create(str);
   delete [] str;
   return is;
   }
 */
