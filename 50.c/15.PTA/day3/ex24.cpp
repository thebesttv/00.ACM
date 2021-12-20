#include <stdio.h>

int getTreasure(int *pBucket, int x, int y){
  if(x&1 && y&1){
    *pBucket += (*pBucket)/3;
  }else if((x&1)==0 && (y&1)==0){
    *pBucket +=5;
  }else{
    return 0;
  }
  return 1;
}

int main(){
  int bucket,total;
  bucket = total = 0;
  scanf("%d",&total);
  for (int i=0; i<total; i++) {
    int x,y;
    x = y = 0;
    scanf("%d%d", &x, &y);
    int flag = getTreasure(&bucket, x, y);
    printf("[%d]:%d\n", flag, bucket);
  }
}
