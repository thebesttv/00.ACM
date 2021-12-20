/*
描述
有9个时钟，排成一个3*3的矩阵。

  +-------+    +-------+    +-------+
  |       |    |       |    |   |   |
  |---O   |    |---O   |    |   O   |
  |       |    |       |    |       |
  +-------+    +-------+    +-------+
      A            B            C    

  +-------+    +-------+    +-------+
  |       |    |       |    |       |
  |   O   |    |   O   |    |   O   |
  |   |   |    |   |   |    |   |   |
  +-------+    +-------+    +-------+
      D            E            F    
  
  +-------+    +-------+    +-------+
  |       |    |       |    |       |
  |   O   |    |   O---|    |   O   |
  |   |   |    |       |    |   |   |
  +-------+    +-------+    +-------+
      G            H            I    

现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。共允许有9种不同的移动。如下表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。

移动    影响的时钟
 1         ABDE
 2         ABC
 3         BCEF
 4         ADG
 5         BDEFH
 6         CFI
 7         DEGH
 8         GHI
 9         EFHI    

输入
9个整数，表示各时钟指针的起始位置，相邻两个整数之间用单个空格隔开。其中，0=12点、1=3点、2=6点、3=9点。

输出
输出一个最短的移动序列，使得9个时钟的指针都指向12点。按照移动的序号从小到大输出结果。相邻两个整数之间用单个空格隔开。

样例输入
3 3 0 
2 2 2 
2 1 2 

样例输出
4 5 8 9
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int ori[9],Clock[9],Clock2[9],count[9],save[9],Min=1<<10,tail;

int Solve(int m1, int m2, int m4);
void Move(int n, int time, int * a);

int main(void){
  //freopen("in","r",stdin);
  for(int i=0;i<9;i++) scanf("%d",&ori[i]);
  for(int m1=0;m1<4;m1++) for(int m2=0;m2<4;m2++) for(int m4=0;m4<4;m4++){
    memcpy(Clock,ori,sizeof(ori));
    Move(1,m1,Clock);
    Move(2,m2,Clock);
    Move(4,m4,Clock);
    int temp;
    if(Clock[0]!=0) continue;
    //printf("m1: %d, m2: %d, m4: %d\n",m1,m2,m4);
    if((temp=Solve(m1,m2,m4))<Min){
      Min=temp; memcpy(save,count,sizeof(count));
    }
  }
  bool first=0;
  for(int i=0;i<9;i++) for(int j=0;j<save[i];j++){
    if(first) printf(" ");
    else first=1;
    printf("%d",i+1);
  }
  printf("\n");

  return 0;
}

int Solve(int m1, int m2, int m4){
  int cou=0,m3,m5,m6,m7,m8,m9;
  for(m3=0;m3<4;m3++) for(m5=0;m5<4;m5++){
    memcpy(Clock2,Clock,sizeof(Clock));
    Move(3,m3,Clock2);
    Move(5,m5,Clock2);
    if(Clock2[1]!=0) continue;
    //printf("  m3: %d, m5: %d\n",m3,m5);
    //for(int i=0;i<9;i++) printf("%c: %d, ",'A'+i,Clock2[i]);
    m6=(4-Clock2[2])%4; Move(6,m6,Clock2);
    m7=(4-Clock2[3])%4; Move(7,m7,Clock2);
    m9=(4-Clock2[4])%4; Move(9,m9,Clock2);
    if(Clock2[5]!=0) continue;
    //printf("    m6: %d, m7: %d, m9: %d\n",m6,m7,m9);
    m8=(4-Clock2[6])%4; Move(8,m8,Clock2);
    if(Clock2[7]!=0 || Clock2[8]!=0) continue;
    //printf("      m8: %d\n",m8);
    count[0]=m1; count[1]=m2; count[2]=m3; count[3]=m4; count[4]=m5; count[5]=m6; count[6]=m7; count[7]=m8; count[8]=m9;
    cou=m1+m2+m3+m4+m5+m6+m7+m8+m9;
  }
  return cou;
}

void Move(int n, int time, int * a){
  for(int i=0;i<time;i++)
    switch(n){
      case 1: a[0]=(a[0]+1)%4; a[1]=(a[1]+1)%4; a[3]=(a[3]+1)%4; a[4]=(a[4]+1)%4;
              break;	//0 1 3 4
      case 2: a[0]=(a[0]+1)%4; a[1]=(a[1]+1)%4; a[2]=(a[2]+1)%4;
              break;	//0 1 2
      case 3: a[1]=(a[1]+1)%4; a[2]=(a[2]+1)%4; a[4]=(a[4]+1)%4; a[5]=(a[5]+1)%4;
              break;	//1 2 4 5
      case 4: a[0]=(a[0]+1)%4; a[3]=(a[3]+1)%4; a[6]=(a[6]+1)%4;
              break;	//0 3 6
      case 5: a[1]=(a[1]+1)%4; a[3]=(a[3]+1)%4; a[4]=(a[4]+1)%4; a[5]=(a[5]+1)%4; a[7]=(a[7]+1)%4;
              break;	//1 3 4 5 7
      case 6: a[2]=(a[2]+1)%4; a[5]=(a[5]+1)%4; a[8]=(a[8]+1)%4;
              break;	//2 5 8
      case 7: a[3]=(a[3]+1)%4; a[4]=(a[4]+1)%4; a[6]=(a[6]+1)%4; a[7]=(a[7]+1)%4;
              break;	//3 4 6 7
      case 8: a[6]=(a[6]+1)%4; a[7]=(a[7]+1)%4; a[8]=(a[8]+1)%4;
              break;	//6 7 8
      case 9: a[4]=(a[4]+1)%4; a[5]=(a[5]+1)%4; a[7]=(a[7]+1)%4; a[8]=(a[8]+1)%4;
              break;	//4 5 7 8
    }
}
