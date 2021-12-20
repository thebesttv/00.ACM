#include <stdio.h>
#include <string.h>

#define MAXS 10

void Shift( char s[] );

void GetString( char s[] ); /* 实现细节在此不表 */

int main()
{
    char s[MAXS];

    GetString(s);
    Shift(s);
    printf("%s\n", s);
	
    return 0; 
}

void Shift( char s[] ){
  int len=strlen(s);
  char a = s[0], b = s[1], c = s[2];
  for(int i=3;i<len;++i)
    s[i-3]=s[i];
  s[len-3] = a;
  s[len-2] = b;
  s[len-1] = c;
}
