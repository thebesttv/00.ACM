#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

char temp[3][300];

int main(void){
  freopen("out2","r",stdin);
#ifdef LOCAL
  freopen("out22","w",stdout);
#endif
  int tail0=0,tail1=0,tot=0;
  char *p;
  while(fgets(temp[0],sizeof(temp[0]),stdin)){
    fgets(temp[1],sizeof(temp[1]),stdin);
    if(isalpha(temp[1][0])){
      if((p=strstr(temp[0],"tail0:"))==NULL) break;
      while(!isdigit(*p)) p++; p++;
      while(!isdigit(*p)) p++;
      tail0+=atoi(p);
      p=strstr(temp[0],"tail1:");
      while(!isdigit(*p)) p++; p++;
      while(!isdigit(*p)) p++;
      tail1+=atoi(p);
#ifdef DEBUG
      printf("  %5d %5d\n",tail0,tail1);
#endif
      tot++;
    }
    if(fgets(temp[2],sizeof(temp[2]),stdin)==NULL) break;
  }
  printf("total: %d, tail0: %d, tail1: %d\n",tot,tail0,tail1);
  printf("average: tail0: %lf, tail1: %lf\n",(double)tail0/tot,(double)tail1/tot);

  return 0;
}
