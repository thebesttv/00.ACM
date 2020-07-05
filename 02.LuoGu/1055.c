#include<cstdio>
using namespace std;

int main(void){
  char s[20]; scanf("%s",s);
  int sum=0, ch;
  for(int i=0,cnt=1;cnt<=9;i++)
    if(s[i]!='-') sum += cnt*(s[i]-'0'), cnt++;
  sum %= 11;
  ch = sum==10 ? 'X' : sum+'0';
  if(s[12]==ch) printf("Right\n");
  else{
    s[12]=ch; printf("%s\n",s);
  }


  return 0;
}

/*
const int MAX=20;
char s[MAX];
int pos[]={0,0,2,3,4,6,7,8,9,10};

bool right(int sum){
  if(sum==10) return s[12]=='X';
  else return s[12] == sum+'0';
}

int main(void){
  scanf("%s",s);
  int sum=0;
  FORR(i,1,9) sum += i * (s[pos[i]]-'0');
  sum %= 11;

  if(right(sum)) printf("Right\n");
  else{
    s[12] = sum==10 ? 'X' : (sum+'0');
    printf("%s\n",s);
  }

  return 0;
}
*/
