#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char s[100],p[100];

void show(int i, int j){
  system("clear");
  fputs(s,stdout);
  for(int k=0;k<(i-j);k++) printf(" "); fputs(p,stdout);
  for(int k=0;k<i;k++) printf(" "); printf("^\n");
}
int ViolentMatch(char * s, char * p);
int KMP(char * s, char * p);
void GetN(char * p, int * next);

int main(void){
  system("clear");
  printf("input target S: "); fgets(s,sizeof(s),stdin);
  printf("input pattern T: "); fgets(p,sizeof(p),stdin);

//  int res=ViolentMatch(s,p);
  int res=KMP(s,p);

  if(res!=-1){
    system("clear");
    fputs(s,stdout);
    for(int k=0;k<res;k++) printf(" "); fputs(p,stdout);
  }
  if(res==-1) printf("no match pattern\n");
  else printf("in %d pattern matched\n",res);

  return 0;
}

int ViolentMatch(char * s, char * p){
  int sLen=strlen(s)-1, pLen=strlen(p)-1;
  int i=0,j=0;
  while(i<sLen && j<pLen){
    show(i,j);
    if(s[i]==p[j]){
      i++; j++;
    }else{
      i=i-j+1; j=0;
    }
    getchar();
  }
  if(j==pLen) return i-j;
  else return -1;
}
int KMP(char * s, char * p){
  int sLen=strlen(s)-1, pLen=strlen(p)-1;
  int *next=(int *)calloc(pLen,sizeof(int));
  GetN(p,next);
  printf("next: "); for(int i=0;i<pLen;i++) printf("%d,",next[i]); printf("\n");
  getchar();
  int i=0,j=0;
  while(i<sLen && j<pLen){
    show(i,j);
    if(j==-1 || s[i]==p[j]){
      i++; j++;
    }else{
      j=next[j];
    }
    getchar();
  }
  if(j==pLen) return i-j;
  else return -1;
}

void GetN(char * p, int * next){
  int pLen=strlen(p)-1;
  next[0]=-1;
  int k=-1, j=0;
  while(j<pLen-1){
    if(k==-1 || p[j]==p[k]){
      k++; j++;
      //next[j]=k;
      next[j] = (p[j]==p[k] ? next[k] : k);
    }else{
      k=next[k];
    }
  }
}
