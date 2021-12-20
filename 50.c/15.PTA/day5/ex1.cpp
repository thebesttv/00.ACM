#include <stdio.h>

char *getmonth( int n );

int main()
{
    int n;
    char *s;

    scanf("%d", &n);
    s = getmonth(n);
    if ( s==NULL ) printf("wrong input!\n");
    else printf("%s\n", s);

    return 0;
}

#include <stdlib.h>
#include <string.h>
char *getmonth( int n ){
  char *p = (char*)malloc(20);
  switch(n){
    case 1:  strcpy(p,"January"); break;
    case 2:  strcpy(p,"February"); break;
    case 3:  strcpy(p,"March"); break;
    case 4:  strcpy(p,"April"); break;
    case 5:  strcpy(p,"May"); break;
    case 6:  strcpy(p,"June"); break;
    case 7:  strcpy(p,"July"); break;
    case 8:  strcpy(p,"August"); break;
    case 9:  strcpy(p,"September"); break;
    case 10: strcpy(p,"October"); break;
    case 11: strcpy(p,"November"); break;
    case 12: strcpy(p,"December"); break;
    default: p = NULL; break;
  }
  return p;
}
