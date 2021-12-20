#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int ori[9],tar[9];
char temp[100];
int main(void){
#ifdef LOCAL
  freopen("out2","r",stdin);
  freopen("out2.judge","w",stdout);
#endif
  bool stop=0;
  while(!stop){
    memset(ori,0,sizeof(ori)); memset(tar,0,sizeof(tar)); memset(temp,0,sizeof(temp));
    int c=0;
    for(int i=0;i<9 && !stop;i++){
      do{
        c=getchar();
        if(c==EOF) {stop=1; break;}
      }while(!isdigit(c) && c!='x');
      if(c=='x') ori[i]=0;
      else ori[i]=c-'0';
    }
    do{
      c=getchar();
      if(c==EOF) {stop=1; break;}
    }while(c!='\n');
    c=getchar();
    if(c==EOF) {stop=1; break;}
    if(!isalpha(c)) continue;
    if(scanf("%s",temp+1)==EOF) {stop=1; break;}
    temp[0]=c;
#ifdef DEBUG
    printf("%d",ori[0]);
    for(int i=1;i<9;i++) printf(" %d",ori[i]); printf("\n");
    printf("%s\n\n",temp);
#endif
    int len=strlen(temp);
    for(int i=0;i<len;i++){
      int pos=0; while(ori[pos]) pos++;
      int x=pos/3,y=pos%3;
      int tx=x,ty=y;
      switch(temp[i]){
        case 'r':
          ty++; break;
        case 'l':
          ty--; break;
        case 'u':
          tx--; break;
        case 'd':
          tx++; break;
      }
      int z=tx*3+ty;
      swap(ori[pos],ori[z]);
    }
    for(int i=0;i<8;i++) tar[i]=i+1;
    tar[8]=0;
    if(memcmp(tar,ori,sizeof(tar))) printf("WA\n");
  }
  return 0;
}
