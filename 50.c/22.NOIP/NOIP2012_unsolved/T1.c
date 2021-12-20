/*
题目描述
16 世纪法国外交家 Blaise de Vigenère 设计了一种多表密码加密算法――Vigenère 密码。Vigenère 密码的加密解密算法简单易用，且破译难度比较高，曾在美国南北战争中为南军所广泛使用。
在密码学中，我们称需要加密的信息为明文，用 M 表示；称加密后的信息为密文，用 C 表示；而密钥是一种参数，是将明文转换为密文或将密文转换为明文的算法中输入的数据，记为 k。 在 Vigenère 密码中，密钥 k 是一个字母串，k=k1k2…kn。当明文 M=m1m2…mn时，得到的密文 C=c1c2…cn，其中 ci=mi®ki，运算®的规则如下表所示：

   A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
  ----------------------------------------------------
A| A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
B| B C D E F G H I J K L M N O P Q R S T U V W X Y Z A
C| C D E F G H I J K L M N O P Q R S T U V W X Y Z A B
D| D E F G H I J K L M N O P Q R S T U V W X Y Z A B C
E| E F G H I J K L M N O P Q R S T U V W X Y Z A B C D
F| F G H I J K L M N O P Q R S T U V W X Y Z A B C D E
G| G H I J K L M N O P Q R S T U V W X Y Z A B C D E F
H| H I J K L M N O P Q R S T U V W X Y Z A B C D E F G
I| I J K L M N O P Q R S T U V W X Y Z A B C D E F G H
J| J K L M N O P Q R S T U V W X Y Z A B C D E F G H I
K| K L M N O P Q R S T U V W X Y Z A B C D E F G H I J
L| L M N O P Q R S T U V W X Y Z A B C D E F G H I J K
M| M N O P Q R S T U V W X Y Z A B C D E F G H I J K L
N| N O P Q R S T U V W X Y Z A B C D E F G H I J K L M
O| O P Q R S T U V W X Y Z A B C D E F G H I J K L M N
P| P Q R S T U V W X Y Z A B C D E F G H I J K L M N O
Q| Q R S T U V W X Y Z A B C D E F G H I J K L M N O P
R| R S T U V W X Y Z A B C D E F G H I J K L M N O P Q
S| S T U V W X Y Z A B C D E F G H I J K L M N O P Q R
T| T U V W X Y Z A B C D E F G H I J K L M N O P Q R S
U| U V W X Y Z A B C D E F G H I J K L M N O P Q R S T
V| V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
W| W X Y Z A B C D E F G H I J K L M N O P Q R S T U V
X| X Y Z A B C D E F G H I J K L M N O P Q R S T U V W
Y| Y Z A B C D E F G H I J K L M N O P Q R S T U V W X
Z| Z A B C D E F G H I J K L M N O P Q R S T U V W X Y

Vigenère 加密在操作时需要注意：
®运算忽略参与运算的字母的大小写，并保持字母在明文 M 中的大小写形式；
当明文 M 的长度大于密钥 k 的长度时，将密钥 k 重复使用。
例如，明文 M=Helloworld，密钥 k=abc 时，密文 C=Hfnlpyosnd。

输入输出格式
输入格式：
输入共 2 行。
第一行为一个字符串，表示密钥 k，长度不超过 100，其中仅包含大小写字母。第二行为一个字符串，表示经加密后的密文，长度不超过 1000，其中仅包含大小写字母。

输出格式：
输出共 1 行，一个字符串，表示输入密钥和密文所对应的明文。

输入输出样例
输入样例#1：
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm 

输出样例#1：
Wherethereisawillthereisaway 

说明
数据范围
对于 100%的数据，输入的密钥的长度不超过 100，输入的密文的长度不超过 1000，且都仅包含英文字母。

来源
NOIP 2012 提高组 第一天 第一题
*/

/*
  得分：100
  解题报告：
    首先要发现规律：ci = (mi-'A'+ki-'A')%26+'A"，然后直接模拟即可。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char ori[2020],equ[2020];
char key[220];

int main(void){
  scanf("%s%s",key,equ); strcpy(ori,equ);
  int elen=strlen(equ),klen=strlen(key);
  for(int i=0;i<elen;i++) equ[i]=toupper(equ[i]);
  for(int i=0;i<klen;i++) key[i]=toupper(key[i]);
  int pos=0;
  for(int i=0;i<elen;i++){
    char ch;
    for(ch='A';ch<='Z';ch++) if((ch-'A'+key[pos]-'A')%26+'A'==equ[i]) break;
    if(islower(ori[i])) ch=tolower(ch);
    printf("%c",ch);
    pos=(pos+1)%klen;
  }
  printf("\n");

  return 0;
}
