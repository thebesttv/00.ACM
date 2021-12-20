/*
描述
Flip game is played on a rectangular 4x4 field with two-sided pieces placed on each of its 16 squares. One side of each piece is white and the other one is black and each piece is lying either it's black or white side up. Each round you flip 3 to 5 pieces, thus changing the color of their upper side from black to white and vice versa. The pieces to be flipped are chosen every round according to the following rules:
Choose any one of the 16 pieces.
Flip the chosen piece and also all adjacent pieces to the left, to the right, to the top, and to the bottom of the chosen piece (if there are any).
Consider the following position as an example:
  bwbw
  wwww
  bbwb
  bwwb
Here "b" denotes pieces lying their black side up and "w" denotes pieces lying their white side up. If we choose to flip the 1st piece from the 3rd row (this choice is shown at the picture), then the field will become:
  bwbw
  bwww
  wwwb
  wwwb
The goal of the game is to flip either all pieces white side up or all pieces black side up. You are to write a program that will search for the minimum number of rounds needed to achieve this goal.

输入
The input consists of 4 lines with 4 characters "w" or "b" each that denote game field position.

输出
Write to the output file a single integer number - the minimum number of rounds needed to achieve the goal of the game from the given position. If the goal is initially achieved, then write 0. If it's impossible to achieve the goal, then write the word "Impossible" (without quotes).

样例输入
bwwb
bbwb
bwwb
bwww

样例输出
4
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[4],ori[4],ansMin=(1<<30);

void search(int s, int tar);
inline int getBit(int a, int n);
inline void flipBit(int & a, int n);
inline void setBit(int & a, int n, bool i);

int main(void){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      int c=getchar();
      setBit(ori[i],j,(c=='b' ? 1 : 0));
    }
    getchar();
  }
#ifdef DEBUG
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++) printf("%d",getBit(ori[i],j));
    printf("\n");
  }
#endif
  for(int i=0;i<(1<<4);i++){
    search(i,0);
    search(i,1);
  }
  if(ansMin==(1<<30)) printf("Impossible\n");
  else printf("%d\n",ansMin);

  return 0;
}

void search(int s, int tar){
  int tot=0;
  memcpy(a,ori,sizeof(ori));
  for(int i=0;i<4;i++){
    if(getBit(s,i)){
      flipBit(a[0],i); tot++;
      if(i>0) flipBit(a[0],i-1);
      if(i<3) flipBit(a[0],i+1);
      flipBit(a[1],i);  //<b>莫忘（然而还是忘了）</b>
    }
  }
  for(int i=1;i<4;i++){
    for(int j=0;j<4;j++){
      if(getBit(a[i-1],j)!=tar){
        flipBit(a[i],j); tot++;
        flipBit(a[i-1],j);
        if(j>0) flipBit(a[i],j-1);
        if(j<3) flipBit(a[i],j+1);
        if(i<3) flipBit(a[i+1],j);
      }
    }
  }
  for(int i=0;i<4;i++) if(getBit(a[3],i)!=tar) {tot=1<<30; break;}
#ifdef DEBUG
  printf("  s: %d, tot: %d\n",s,tot);
  if(tot!=(1<<30)){
    for(int i=0;i<4;i++){
      printf("  ");
      for(int j=0;j<4;j++) printf("%d",getBit(a[i],j));
      printf("\n");
    }
    printf("\n");
  }
#endif
  ansMin=min(ansMin,tot);
}
inline int getBit(int a, int n){
  return (a>>n)&1;
}
inline void flipBit(int & a, int n){
  a^=(1<<n);
}
inline void setBit(int & a, int n, bool i){
  if(i) a|=(1<<n);
  else a&=~(1<<n);
}
