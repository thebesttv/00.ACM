#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define DEBUG 0

struct Ind{
  int n;
  double fit;
}ind[5],tempInd;
long long Generation=0;

int FitNess(int a);
int GetBit(int a, int n);
void SetBit(int a, int n, int p);
void Sort(struct Ind * p, int left, int right);

int main(void){
  srand(time(NULL));
  int k;
  int totN=0;
  while(totN<=20){
    int count=0;
    k=0;
    while(k<1000){
      Generation=0;
      int matPool[4];
      int best=0;
      double maxfit=0;
      while(Generation++<=1<<totN){
#if DEBUG
        printf("enter Generation: %lld\n",Generation);
#endif
        int tot=0;
        for(int i=0;i<4;i++)  ind[i].n=abs(rand()%32);
        for(int i=0;i<4;i++) {ind[i].fit=(double)FitNess(ind[i].n); tot+=(int)ind[i].fit;}
        for(int i=0;i<4;i++) ind[i].fit=(double)ind[i].fit/tot;
        Sort(ind,0,3);
        for(int i=0;i<4;i++){
          double ran=fabs((double)(rand()%100)/100);
          int u=3;
          for(int j=1;j<4;j++){
            if(ind[j-1].fit<=ran && ind[j].fit>=ran) u=j;
            if(ind[j].fit>maxfit) {maxfit=ind[j].fit;best=ind[j].n;}
          }
          matPool[0]=ind[3].n;matPool[1]=ind[2].n;matPool[2]=ind[1].n;matPool[3]=ind[3].n;
        }
        for(int i=0;i<2;i++){
          int fat,mat;
          do{fat=rand()%4;mat=rand()%4;}while(fat==mat);
          int ran=rand()%8;
          int Fbit=GetBit(matPool[fat],ran);
          int Mbit=GetBit(matPool[mat],ran);
          SetBit(matPool[fat],ran,Mbit);
          SetBit(matPool[mat],ran,Fbit);
        }
        for(int i=0;i<4;i++) ind[i].n=matPool[i];
      }
      //printf("best fitness:%lf, best number:%d\n",maxfit,best);
      if(best==10) ++count;
      ++k;
    }
    printf("total:%ld ,count: %d\n",(long)(1<<totN),count);
    ++totN;
  }
  return 0;
}

int FitNess(int a){
  int temp=1000-abs((a-10)*(a-10));
  if(temp<=0) return 0;
  else return temp;
}

int GetBit(int a, int n){
  return a|(1<<n);
}

void SetBit(int a, int n, int p){
  if(p==1) a|=(1<<n);
  else a&=~(1<<n);
}

void Sort(struct Ind * p, int left, int right){
  if(left>=right) return;
  int i=left, j=right;
  double k=p[left].fit*10;
  while(i!=j){
    while(i<j && p[j].fit*10>=k) j--;
    while(i<j && p[i].fit*10<=k) i++;
    tempInd=p[i];p[i]=p[j];p[j]=tempInd;
  }
  tempInd=p[i];p[i]=p[left];p[left]=tempInd;
  Sort(p,left,i-1);
  Sort(p,i+1,right);
}
