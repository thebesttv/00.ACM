#include <stdio.h>

#define MAXS 20

char *match( char *s, char ch1, char ch2 );

int main()
{
  char str[MAXS], ch_start, ch_end, *p;

  scanf("%s\n", str);
  scanf("%c %c", &ch_start, &ch_end);
  p = match(str, ch_start, ch_end);
  printf("%s\n", p);

  return 0;
}

#include <string.h>
char *match( char *s, char ch1, char ch2 ){
  int l=0, r=0, len=strlen(s);
  while(s[l]){
    if(s[l]==ch1){
      putchar(s[l]);
      r = l+1;
      while(s[r]){
        putchar(s[r]);
        if(s[r]==ch2) break;
        r++;
      }
      putchar('\n');
      return s + l;
    }
    l++;
  }
  putchar('\n');
  return s+l;
}
