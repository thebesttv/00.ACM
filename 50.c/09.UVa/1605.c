#include<iostream>
#include<cstdio>
using namespace std;

char token[50];

int main(void){
  for(int i=0;i<26;i++) token[i]='a'+i;
  for(int i=26;i<50;i++) token[i]='A'+i-26;
  int n; bool flag=0;
  while(scanf("%d",&n)==1){
    if(flag) printf("\n");
    else flag=1;
    printf("2 %d %d\n",n,n);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++) printf("%c",token[i]);
      printf("\n");
    }
    printf("\n");
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++) printf("%c",token[j]);
      printf("\n");
    }
  }

  return 0;
}


/*
//网络
#include<iostream>
#include<cstdio>
using namespace std;

char token[50];

int main(void){
  for(int i=0;i<26;i++) token[i]='a'+i;
  for(int i=26;i<50;i++) token[i]='A'+i-26;
  int n; bool flag=0;
  while(scanf("%d",&n)==1){
    if(flag) printf("\n");
    else flag=1;
    printf("%d %d %d\n",n,n,n);
    for(int i=0;i<n;i++){
      if(i) printf("\n");
      for(int j=0;j<n;j++){
        for(int k=0;k<n;k++)
          if(j==k) printf("%c",token[j]);
          else printf("%c",token[i]);
        printf("\n");
      }
    }
  }

  return 0;
}
*/
