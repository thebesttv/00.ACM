#include <stdio.h>

void pyramid( int n ){
  for(int i=1;i<=n;i++){
    for(int j=0;j<n-i;j++) putchar(' ');
    int first=1;
    for(int j=0;j<i;j++){
      printf("%d ",i);
    }
    putchar('\n');
  }
}

int main()
{    
    int n;

    scanf("%d", &n);
    pyramid(n);

    return 0;
}
