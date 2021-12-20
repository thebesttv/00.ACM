#include <stdio.h>
#define MAXN 10

void f( long int x, char *p ){
  const char *to = "0123456789ABCDEF";
  if(x==0){
    *(p++) = '0'; *p=0;
    return;
  }
  char res[MAXN]; int tail=0;
  if(x<0){
    *(p++) = '-'; x=-x;
  }
  while(x){
    int r = x%16;
    res[tail++]=to[r];
    x/=16;
  }
  for(int i=tail-1;i>=0;--i)
    *(p++)=res[i];
  *p=0;
}

int main()
{
    long int x;
    char s[MAXN] = "";

    scanf("%ld", &x);
    f(x, s);
    printf("%s\n", s);

    return 0;
}
