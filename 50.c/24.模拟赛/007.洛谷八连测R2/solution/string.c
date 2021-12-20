#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int T,n,m;
char s[30010],t[30010];
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  int i,j,k,l,u;
  scanf("%d",&T);
  while(T--){
    scanf("%s%s",&s,&t);
    n=strlen(s);
    m=strlen(t);
    for(i=j=0;i<n;i=k,j=l){
      u=0;
      for(k=i;k<n && (s[k]=='*' || s[k]==s[i]);k++)
        if(s[k]=='*') u++;
      for(l=j;l<m && t[l]==t[j];l++);
      if(!(s[i]==t[j] && k-i-u<=l-j && (u || k-i==l-j))) break;
    }
    if(i<n || j<m) printf("No\n");
    else printf("Yes\n");
  }
  return 0;
}
