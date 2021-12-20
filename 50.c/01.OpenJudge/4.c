/*
描述
英文字母（除Q和Z外）和电话号码存在着对应关系，如下所示：
A,B,C -> 2
D,E,F -> 3
G,H,I -> 4
J,K,L -> 5
M,N,O -> 6
P,R,S -> 7
T,U,V -> 8
W,X,Y -> 9
标准的电话号码格式是xxx-xxxx，其中x表示0-9中的一个数字。有时为了方便记忆电话号码，我们会将电话号码的数字转变为英文字母，如把263-7422记成America。有时，我们还加上“-”作为分隔符，如把449-6753记成Hi-World。当然，我们未必要将所有的数字都转变为字母，比如474-6635可以记成iPhone-5。
总之，一个方便记忆的电话号码由数字和除Q、Z外的英文字母组成，并且可以在任意位置插入任意多的“-”符号。
现在 ，我们有一个列表，记录着许多方便记忆的电话号码。不同的方便记忆的电话号码可能对应相同的标准号码，你的任务就是找出它们。


输入
第一行是一个正整数n（n <= 100000），表示列表中的电话号码数。
其后n行，每行是一个方便记忆的电话号码，它由数字和除Q、Z外的英文字母、“-”符号组成，其中数字和字母的总数一定为7，字符串总长度不超过200。

输出
输出包括若干行，每行包括一个标准电话号码（xxx-xxxx）以及它重复出现的次数k（k >= 2），中间用空格分隔。输出的标准电话号码需按照升序排序。
如果没有重复出现的标准电话号码，则输出一行“No duplicates.”。
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=100020;
char t1[220];
int a[MAX],n;

int get(char *p){
	int len=strlen(p);
	int ans=0;
  FOR(i,0,len){
		p[i]=tolower(p[i]);
		if(isalpha(p[i])){
			if((p[i]>='a' && p[i]<='c')) ans=ans*10+2;
			if((p[i]>='d' && p[i]<='f')) ans=ans*10+3;
			if((p[i]>='g' && p[i]<='i')) ans=ans*10+4;
			if((p[i]>='j' && p[i]<='l')) ans=ans*10+5;
			if((p[i]>='m' && p[i]<='o')) ans=ans*10+6;
			if((p[i]>='p' && p[i]<='s')) ans=ans*10+7;
			if((p[i]>='t' && p[i]<='v')) ans=ans*10+8;
			if((p[i]>='w' && p[i]<='y')) ans=ans*10+9;
		}else if(isdigit(p[i])){
			ans=ans*10+(p[i]-'0');
		}
	}
	return ans;
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n){
    scanf("%s",t1); a[i]=get(t1);
  }
  sort(a,a+n);
  bool flag=0;
  FOR(i,0,n){
    int cnt=0,t=a[i];
    FOR(j,i,n)
      if(a[j]==t) cnt++;
      else break;
    if(cnt>=2) {flag=1; printf("%03d-%04d %d\n",t/10000,t%10000,cnt);}  //printf中高位补0
    i+=cnt-1; //循环体中还有i++
  }
  if(!flag) printf("No duplicates.\n");

  return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define DEBUG 0

char ori[201];
struct PhonNum{
	long num;
	long rep;
}res[100000];

struct Stack{
	long num[100000];
	long rep[100000];
	int top;
}stack;

long Convert(char p[]);
void QuickSort(int left,int right);
void Msort(int left, int right);

int main(void){
	long n;

	stack.top=0;
	scanf("%ld",&n);
	for(long i=0;i<n;i++){
		scanf("%s",ori);
//		res[i].rep=0;
		res[i].num=Convert(ori);
	}

	QuickSort(0,n-1);
	Msort(0,n-1);

	if(stack.top==0) printf("No duplicates.\n");
	else{
		#if DEBUG
			printf("top: %d\n",stack.top);
		#endif
		for(int i=0;i<stack.top;i++){
			printf("%ld-%ld %ld\n",stack.num[i]/10000,stack.num[i]%10000,stack.rep[i]);
		}
	}

	return 0;
}

void QuickSort(int left,int right){
	if(left>=right) return;
	int i=left,j=right,k=res[left].num;
	struct PhonNum temp;
	while(i!=j){
		while(i<j && res[j].num>=k) j--;
		while(i<j && res[i].num<=k) i++;
		temp=res[i]; res[i]=res[j];res[j]=temp;
	}
	temp=res[left];	res[left]=res[i]; res[i]=temp;
	QuickSort(left,i-1);
	QuickSort(i+1,right);
}

void Msort(int left,int right){
	if(res[0].num==res[1].num){
		stack.num[stack.top]=res[0].num;
		stack.rep[stack.top]=1;
		#if DEBUG
			printf("stack.top: %d, stack.num: %ld, stack.rep: %ld\n",\
				stack.top,stack.num[stack.top],stack.rep[stack.top]);
		#endif
		stack.top++;
	}
	for(int i=1;i<=right;i++){
		if(res[i].num==res[i-1].num){
			if(stack.top!=0){
				if(stack.num[stack.top-1]==res[i].num){
					stack.rep[stack.top-1]++;
				#if DEBUG
					printf("stack.top: %d, stack.num: %ld, stack.rep: %ld\n",\
						stack.top,stack.num[stack.top],stack.rep[stack.top]);
				#endif
				}else{
					stack.num[stack.top]=res[i].num;
					stack.rep[stack.top]=2;
				#if DEBUG
					printf("stack.top: %d, stack.num: %ld, stack.rep: %ld\n",\
						stack.top,stack.num[stack.top],stack.rep[stack.top]);
				#endif
					stack.top++;
				}
			}else{
				stack.num[stack.top]=res[i].num;
				stack.rep[stack.top]=2;
				#if DEBUG
					printf("stack.top: %d, stack.num: %ld, stack.rep: %ld\n",\
						stack.top,stack.num[stack.top],stack.rep[stack.top]);
				#endif
				stack.top++;
			}
//			stack.top++;
		}
	}
}

long Convert(char p[]){
	int len=strlen(p);
	long temp=0;
	for(int i=0;i<len;i++){
		p[i]=tolower(p[i]);
		if(isalpha(p[i])) {
			if((p[i]>='a' && p[i]<='c')) temp=temp*10+2;
			if((p[i]>='d' && p[i]<='f')) temp=temp*10+3;
			if((p[i]>='g' && p[i]<='i')) temp=temp*10+4;
			if((p[i]>='j' && p[i]<='l')) temp=temp*10+5;
			if((p[i]>='m' && p[i]<='o')) temp=temp*10+6;
			if((p[i]>='p' && p[i]<='s')) temp=temp*10+7;
			if((p[i]>='t' && p[i]<='v')) temp=temp*10+8;
			if((p[i]>='w' && p[i]<='y')) temp=temp*10+9;
		}
		else if(isdigit(p[i])){
			temp=temp*10+(p[i]-'0');
		}
	}
	return temp;
}
*/

/*
//Time Limit Exceeded.
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int i,j,k=0,ti,state;
	int a[100000]={0},b[100000]={0},c[100000]={0},out[7]={0};
	long n;
	char t[200];

	scanf("%ld",&n);
	for(i=0;i<n;i++) {
		scanf("%s",t);
		for(j=0;j<200;j++) {
			if((t[j]>=65 && t[j]<=90) || (t[j]>=97 && t[j]<=122)) {
				if((t[j]>=65 && t[j]<=67) || (t[j]>=97 && t[j]<=99)) {out[k]=2; k++;}
				if((t[j]>=68 && t[j]<=70) || (t[j]>=100 && t[j]<=102)) {out[k]=3; k++;}
				if((t[j]>=71 && t[j]<=73) || (t[j]>=103 && t[j]<=105)) {out[k]=4; k++;}
				if((t[j]>=74 && t[j]<=76) || (t[j]>=106 && t[j]<=108)) {out[k]=5; k++;}
				if((t[j]>=77 && t[j]<=79) || (t[j]>=109 && t[j]<=111)) {out[k]=6; k++;}
				if((t[j]>=80 && t[j]<=83) || (t[j]>=112 && t[j]<=115)) {out[k]=7; k++;}
				if((t[j]>=84 && t[j]<=86) || (t[j]>=116 && t[j]<=118)) {out[k]=8; k++;}
				if((t[j]>=87 && t[j]<=89) || (t[j]>=119 && t[j]<=121)) {out[k]=9; k++;}
				}
			else if(t[j]>=48 && t[j]<=57) {
				out[k]=t[j]-48;
				k++;
			}
			else if(t[j]=='\0') break;
		}
		ti=out[0]*1000000+out[1]*100000+out[2]*10000+out[3]*1000+out[4]*100+out[5]*10+out[6];
		a[i]=ti;
		k=0;
	}
//排序

	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(a[j]>a[j+1]) {ti=a[j];a[j]=a[j+1];a[j+1]=ti;};
		}
	}

//删除重复并打印
	k=0;
	for(i=0;i<n;i++){
		if(a[i]==0) break;
		else if(a[i]==a[i+1]){
			b[k]=a[i]; c[k]++;
			//for(j=i;j<n-1;j++){ti=a[j];a[j]=a[j+1];a[j+1]=t;}
		}else{
			b[k]=a[i]; c[k]++;
			k++;
		}
	}

	state=2;
	for(j=0;j<i;j++){
		if(c[j]!=1 && c[j]!=0) state=1;
	}

	if(state==1){
		for(j=0;j<i;j++){
			if(b[j]!=0 && c[j]!=1) printf("%d-%d %d\n",b[j]/10000,b[j]%10000,c[j]);
			else if(b[j]==0) break;
		}
	} else if(state==2) printf("No duplicates.\n");


	return 0;
}
*/
