/*
描述
在情报传递过程中,为了防止情报被截获,往往需要对情报用一定的方式加密,简单的加密算法虽然不足以完全避免情报被破译,但仍然能防止情报被轻易的识别.我们给出一种最简的的加密方法,对给定的一个字符串,把其中从a-y,A-Y的字母用其后继字母替代,把z和Z用a和A替代,则可得到一个简单的加密字符串.

输入
第一行是字符串的数目n, (也要使用get(s)读取字符串,再用n=atoi(s)获得整数数值).
其余n行每行一个字符串,用gets(s)方式读取这一行字符串.每个字符串长度小于80个字符.

输出
输出每行字符串的加密字符串.

样例输入
1
Hello! How are you!

样例输出
Ifmmp! Ipx bsf zpv!
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
using namespace std;

char a[100];

void Convert(char a[]);

int main(void){
  char temp[10]; fgets(temp,sizeof(temp),stdin);
  int n=atoi(temp);
  for(int i=0;i<n;i++){
    fgets(a,sizeof(a),stdin);
    Convert(a);
    printf("%s",a);
  }

  return 0;
}

void Convert(char a[]){
  int len=strlen(a);
  for(int i=0;i<len;i++){
    if(isupper(a[i])){
      a[i]=(a[i]-'A'+1)%26+'A';
    }else if(islower(a[i])){
      a[i]=(a[i]-'a'+1)%26+'a';
    }
  }
}
