#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
  int N;

  scanf("%d", &N);
  Print_Factorial(N);
  return 0;
}



#define DEBUG 0
#define DEBUG_REAL 0

#include<stdlib.h>
#include<string.h>
#define max(a,b) ( a > b ? a : b )
#define MAX_LEN 100000

typedef struct{
  signed char s[MAX_LEN]; //char默认为unsigned
  int base;
  int len;
  int minus;
} BigInteger;

BigInteger Create(char * str, int base, int len, int minus);
BigInteger Add(BigInteger a, BigInteger b);
BigInteger Sub(BigInteger a, BigInteger b);
BigInteger Mul(BigInteger a, BigInteger b);
BigInteger Div(BigInteger a, BigInteger b);
BigInteger Mod(BigInteger a, BigInteger b);
BigInteger Half(BigInteger a);
BigInteger Pow(BigInteger a, int n);
BigInteger MovLt(BigInteger a, int n);
BigInteger MovRt(BigInteger a, int n);
BigInteger Pow(BigInteger a, int n);

int Compare(BigInteger a, BigInteger b);
int isZero(BigInteger a);

void Print(BigInteger a);
void Reverse(char * dest, char * ori, int size);

//函数体

BigInteger Create(char * str, int base, int len, int minus){
  BigInteger temp; memset(&temp,0,sizeof(temp));
  for(int i=len-1;i>=0;i--) temp.s[i]=str[len-i-1]-'0';
  temp.base=base; temp.len=len; temp.minus=minus;
  return temp;
}

BigInteger Add(BigInteger a, BigInteger b){
  BigInteger temp; memset(&temp,0,sizeof(temp));
  //整数加法，a,b全为正整数
  int len=max(a.len,b.len);
  int t=0;
  for(int i=0;i<len;i++){
    temp.s[i]=(a.s[i]+b.s[i]+t)%10;
    t=(a.s[i]+b.s[i]+t)/10;
  }
  if(t) temp.s[len++]=t;
  temp.len=len; temp.base=0; temp.minus=0;
  return temp;
}

BigInteger Sub(BigInteger a, BigInteger b){
  BigInteger temp; memset(&temp,0,sizeof(temp));
  int Comp=Compare(a,b);
  if(Comp==0){
    temp.len=1; temp.minus=0; temp.s[0]=0;
    return temp;
  }else if(Comp==1){
    temp.minus=0;
  }else if(Comp==-1){
    temp.minus=1;
    //swap(a,b);
    BigInteger t = a;
    a = b;
    b = t;
  }
  int len=a.len, t=0;
  for(int i=0;i<len;i++){
    if(a.s[i]<b.s[i]){
      a.s[i+1]--;
      temp.s[i]=a.s[i]-b.s[i]+10;
    }else{
      temp.s[i]=a.s[i]-b.s[i];
    }
  }
  while(temp.s[len-1]==0 && len>1) len--;
  temp.len=len; temp.base=0;
  return temp;
}

BigInteger Mul(BigInteger a, BigInteger b){
  if(isZero(a)) return a;
  if(isZero(b)) return b;
  BigInteger temp; memset(&temp,0,sizeof(temp));
  for(int i=0;i<a.len;i++){
    for(int j=0;j<b.len;j++){
      temp.s[i+j]+=a.s[i]*b.s[j];
      temp.s[i+j+1]+=temp.s[i+j]/10;
      temp.s[i+j]%=10;
    }
  }
  temp.len=a.len+b.len-1;
  if(temp.s[temp.len]!=0) temp.len++;
  return temp;
}

BigInteger Div(BigInteger a, BigInteger b){
  BigInteger temp; memset(&temp,0,sizeof(temp));
  if(isZero(b)){
    printf("illegal input\n"); return temp;
  }
  if(isZero(a)){
    temp.len=1; return temp;
  }

  int Comp=Compare(a,b);
  if(Comp<0){
    temp.s[0]=0; temp.len=1; return temp;
  }else if(Comp==0){
    temp.s[0]=1; temp.len=1; return temp;
  }
  //temp.base=a.base-b.base;
  BigInteger L,R,M,one;
  memset(&one,0,sizeof(one)); one.len=1; one.s[0]=1;
  memset(&L,0,sizeof(L)); L.len=1;
  R=a;
  while(Compare(L,R)<0){  //30/20可用来检验二分法
    M=Half(Add(L,R));
    temp=Mul(b,M);
    int Comp=Compare(a,temp);
    if(Comp==0){
      L=M; break;
    }else if(Comp<0){
      R=Sub(M,one);
    }else{
      L=Add(M,one);
    }
  }
  temp=Mul(b,L);
  if(Compare(a,temp)<0) L=Sub(L,one);

  return L;
}
BigInteger Mod(BigInteger a, BigInteger b){

}
BigInteger Half(BigInteger a){
  for(int i=a.len-1;i>=0;i--){
    if(a.s[i]&1)
      a.s[i-1]+=10;
    a.s[i]/=2;
  }
  if(a.s[a.len-1]==0 && a.len>1) a.len--;
  return a;
}
BigInteger Pow(BigInteger a, int n){

}
BigInteger MovLt(BigInteger a, int n){
  BigInteger temp; memset(&temp,0,sizeof(temp));
  for(int i=0;i<a.len-n;i++){
    temp.s[i]=a.s[i+n];
  }
  temp.len=a.len-n; temp.minus=a.minus; temp.base=a.base-n;
}
BigInteger MovRt(BigInteger a, int n);
BigInteger Pow(BigInteger a, int n);

void Print(BigInteger a){
  if(a.minus) putchar('-');
  for(int i=a.len-1;i>=0;i--)
    putchar(a.s[i]+'0');
  putchar('\n');
}

int Compare(BigInteger a, BigInteger b){
  if(a.minus==1 && b.minus==0) return -1;
  else if(a.minus==0 && b.minus==1) return 1;
  else if(a.minus==0 && b.minus==0){
    if(a.len>b.len) return 1;
    else if(a.len<b.len) return -1;
    else{
      for(int i=a.len-1;i>=0;i--){
        if(a.s[i]>b.s[i]) return 1;
        else if(a.s[i]<b.s[i]) return -1;
      }
      return 0;
    }
  }else{
    if(a.len>b.len) return -1;
    else if(a.len<b.len) return 1;
    else{
      for(int i=a.len-1;i>=0;i--){
        if(a.s[i]>b.s[i]) return -1;
        else if(a.s[i]<b.s[i]) return 1;
      }
      return 0;
    }
  }
}

int isZero(BigInteger a){
  if(a.len==1 && a.s[0]==0) return 1;
  else return 0;
}

void Print_Factorial ( const int N ){
  int base=100000;
  if(N<0) { printf("Invalid input\n"); return; }
  char s[2]; s[0]='1'; s[1]=0;
  BigInteger ans = Create(s,base,1,0);
  for(int i=1;i<=N;i++){
    char s1[20],s2[20]; int tmp=i,tail=0;
    while(tmp){
      s1[tail++]=tmp%10+'0';
      tmp/=10;
    }
    for(int j=0;j<tail;j++) s2[j]=s1[tail-j-1];
    s2[tail]=0;
    BigInteger t = Create(s2,base,tail,0);
    ans = Mul(ans, t);
  }
  Print(ans);
}
