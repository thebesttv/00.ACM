/*
描述
在这个问题中，将用英语给你一个或多个整数。你的任务是将这些数字转换成整型表示。数字范围从-999,999,999到999,999,999.下面是你的程序必须考虑的详尽的英语单词表：
negative, zero, one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen, twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety, hundred, thousand, million

输入
输入包括多个样例，注意：
1.负数前面有词negative
2.当能用thousand的时候，将不用hundred。例如1500将写为"one thousand five hundred",而不是"fifteen hundred".
输入将以一个空行结束

输出
输出将是每一个单独一行，每一个后面一个换行符
*/

//网络答案
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

char buf[20][10];

char number[32][10] = {
	"negative", "zero", "one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine", "ten", "eleven", "twelve",
	"thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
	"eighteen", "nineteen", "twenty", "thirty", "forty", "fifty",
	"sixty", "seventy", "eighty", "ninety", "hundred",
	"thousand", "million"
};

int value[32] = {-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,1000000};

int find(char *str) {
	for (int i = 1 ; i < 29 ; ++ i)
		if (!strcmp(str, number[i]))
			return value[i];
	return -1;
}

int dfs(int a, int b) {
	if (a > b) return 0;
	if (a == b) return find(buf[a]);
	else {
		int million = 0,thousand = 0,hundred = 0,sum = 0;
		for (int i = a ; i <= b ; ++ i) {
			if (!strcmp(buf[i], "million")) million = i;
			if (!strcmp(buf[i], "thousand")) thousand = i;
			if (!strcmp(buf[i], "hundred")) hundred = i;
			sum += find(buf[i]);
		}
		if (million) return dfs(a, million-1)*1000000+dfs(million+1, b);
		if (thousand) return dfs(a, thousand-1)*1000+dfs(thousand+1, b);
		if (hundred) return dfs(a, hundred-1)*100+dfs(hundred+1, b);
		return sum;
	}
}

int main() {
	int count = 0;
	while (scanf("%s",buf[count ++]) != EOF) {
		while (getchar() != '\n')
			scanf("%s",buf[count ++]);

		if (!strcmp(buf[0], "negative")) printf("-%d\n",dfs(1, count-1));
		else printf("%d\n",dfs(0, count-1));
		count = 0;
	}
	return 0;
}

/*
//仿写网络答案
//unsolved
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

char str[100][20];

struct Check{
	char str[20];
	int n;
}check[40]={
{"negative", -1}, {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90}, {"hundred", 100}, {"thousand", 1000}, {"million", 1000000}
};

int dfs(int L, int R);
int token(int n);

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif
	char t[100]; memset(t,0,sizeof(t));
	while(fgets(t,sizeof(t),stdin)!=NULL){
		int tail=0;
		if(!isalpha(t[0])) break;
		char *p=strtok(t," \n\r");
		while(p!=NULL){
			for(int i=0;p[i];i++) str[tail][i]=p[i];
			tail++;
			p=strtok(NULL," \n\r");
		}
		#ifdef DEBUG
		printf("str: ");
		for(int i=0;i<tail;i++) printf("%s ",str[i]); printf("\n");
		#endif
		int ans=dfs(0,tail);
		if(!strcmp(str[0],check[0].str)) ans*=-1;
		printf("%d\n",ans);
		memset(t,0,sizeof(t)); memset(str,0,sizeof(str));
	}

	return 0;
}

int dfs(int L, int R){
	#ifdef DEBUG
	printf("  in dfs(%d, %d)\n",L,R);
	#endif
	if(L==0 && !strcmp(str[0],check[0].str)) return dfs(L+1,R);
	if(L==R-1) return token(L);
	if(L==R) return 0;

	int isMillion=-1, isThousand=-1, isHundred=-1;
	int sum=0;
	for(int i=L;i<R;i++){
		int t=token(i);
		#ifdef DEBUG
		printf("    %s: %d\n",str[i],t);
		#endif
		if(t==1000000) isMillion=i;
		else if(t==1000) isThousand=i;
		else if(t==100) isHundred=i;
		sum+=t;
	}
	if(isMillion!=-1) return dfs(L,isMillion)*1000000 + dfs(isMillion+1,R);
	if(isThousand!=-1) return dfs(L,isThousand)*1000 + dfs(isThousand+1,R);
	if(isHundred!=-1) return dfs(L,isHundred)*100 + dfs(isHundred+1,R);
	return sum;
}
int token(int n){
	for(int i=0;i<40;i++){
		if(!strcmp(str[n],check[i].str)) return check[i].n;
	}
	return -1;
}
*/

/*
//unsolved
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;

struct Check{
	char str[20];
	int n;
}check[40]={
{"negative", -1}, {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90}, {"hundred", 100}, {"thousand", 1000}, {"million", 1000000}
};
bool isNegative=0;
char a[100];
char *p,*q;

int Get();
int token(char *p, char * q);

int main(void){
	while(fgets(a,sizeof(a),stdin)!=NULL){
		if(!(isalpha(a[0]) && isalpha(a[1]))) break;	//结束条件
		char *Thousand=strstr(a,"thousand");
		char *Million=strstr(a,"million");
		int num[3]; memset(num,0,sizeof(num)); isNegative=0;
		p=strtok(a," \n\r");
		q=strtok(NULL," \n\r");
		if(Million && Thousand){
			num[0]=Get();
			num[1]=Get();
			num[2]=Get();
		}else if(Million){
			num[0]=Get();
			num[2]=Get();
		}else if(Thousand){
			num[1]=Get();
			num[2]=Get();
		}else{
			num[2]=Get();
		}
		#ifdef DEBUG
		printf("isMillion: %d, isThousand: %d\n",Million!=NULL,Thousand!=NULL);
		printf("  %d\n  %d\n  %d\n",num[0],num[1],num[2]);
		#endif
		int ans=num[0]*1000000+num[1]*1000+num[2];
		if(isNegative) ans*=-1;
		printf("%d\n",ans);
		memset(a,0,sizeof(a));
	}
	return 0;
}

int Get(){
//printf("  in Get()\n");
	int sum=0;
	while(p!=NULL && strcmp(p,"thousand")!=0 && strcmp(p,"million")!=0){
		int t=token(p,q);
		if(t==-1) isNegative=1;
		else sum+=t;
		p=q; q=strtok(NULL," \n\r");
	}
//printf("  out of while\n");
	if(p!=NULL && (strcmp(p,"thousand")==0 || strcmp(p,"million")==0)){
		p=q; q=strtok(NULL," \n\r");
	}
//printf("  out of Get()\n");
	return sum;
}

int token(char *p, char *q){
//printf("    in token(%s, %s)\n",p,q);
	int p_,q_; int ans;
	if(p) for(p_=0;p_<40;p_++){
		if(strcmp(p,check[p_].str)==0) break;
	}
	if(q)for(q_=0;q_<40;q_++){
		if(strcmp(q,check[q_].str)==0) break;
	}
	int L=p ? check[p_].n : 0;
	int R=q ? check[q_].n : 0;
	if(R>100) R=0;
	if(L==-1){
		ans=L;
	}else if(L<10){
		if(R==0) ans=L;
		else if(R==100) ans=L*R;
		else ans=0;
	}else if(L<20 && L!=10){
		if(R==0) ans=L;
		else ans=0;
	}else if(L%10==0 && L<100){
		ans=L;
	}else{
		ans=0;
	}
	#ifdef DEBUG
	printf("  p: %s, q: %s, token: %d\n",p,q,ans);
	#endif
//printf("    out of token()\n");
	return ans;
}
*/

/*
//unsolved
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char a[200];
const char check[][20]={"negative", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million"};
char rec[3][4];

int token(char a[], char b[]);
int inerToken(int ta, int tb);

int main(void){
	while(fgets(a,sizeof(a),stdin)!=NULL){
		int temp=0; bool neg=0;
		memset(rec,0,sizeof(rec)); int tail=0;
		char *p=strtok(a," \n\r");
		char *q=strtok(NULL," \n\r");
		while(p!=NULL){
			int t=token(p,q);
			if(t==1000 || t==1000000 || q==NULL){
				if(!q) temp+=t;
				rec[tail][0]=temp/100+'0';
				rec[tail][1]=(temp/10)%10+'0';
				rec[tail][2]=temp%10+'0';
				temp=-t;
				tail++;
			}
			if(t!=-1){
				temp+=t;
			}else{
				neg=1;
			}

//[1]		if(t==-1){
//			neg=1;
//		}else if(t>100){
//			int e=0,T=t,ten=1;
//			while(T>=10){T/=10; e++;}
//			for(int i=0;i<=e;i++) ten*=10;
//			temp=temp*ten+t;
//		}else{
//			temp+=t;
//		}
//
//[2]		if(t==-1){
//			neg=-1;
//		}else if(temp<t && temp!=0){
//			if(t<1000){
//				temp=temp*100 + t;
//			}else if(t<1000000){
//				temp=temp*1000 + t;
//			}else{
//				temp=temp*1000000 + t;
//			}
//		}else{
//			temp+=t;
//		}

			#ifdef DEBUG
			printf(" p: %s, q: %s, t: %d, temp: %d\n",p,q,t,temp);
			#endif
			p=q; q=strtok(NULL," \n\r");
		}
		if(neg) putchar('-');
		bool first=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(!first){
					if(rec[i][j]!='0'){
						putchar(rec[i][j]); first=1;
					}
				}else{
					putchar(rec[i][j]);
				}
			}
		}
		putchar('\n');
		memset(a,0,sizeof(a));
	}

	return 0;
}

int inerToken(int ta, int tb){
	if(ta<100){
		if(tb>=100) return ta*tb;
		else if(tb<100) return ta;
	}else if(ta>=100){
		return 0;
	}else if(ta==-1){
		return ta;
	}
}

int token(char a[], char b[]){
	int tot=(b==NULL ? 1 : 2);
	int ta=0,tb=0;
	for(int i=0;i<tot;i++){
		int t;
		char *p=(i==0 ? a : b);
		if(!strcmp(p,check[0])){
			t=-1;
		}else if(!strcmp(p,check[1])){
			t=0;
		}else if(!strcmp(p,check[2])){
			t=1;
		}else if(!strcmp(p,check[3])){
			t=2;
		}else if(!strcmp(p,check[4])){
			t=3;
		}else if(!strcmp(p,check[5])){
			t=4;
		}else if(!strcmp(p,check[6])){
			t=5;
		}else if(!strcmp(p,check[7])){
			t=6;
		}else if(!strcmp(p,check[8])){
			t=7;
		}else if(!strcmp(p,check[9])){
			t=8;
		}else if(!strcmp(p,check[10])){
			t=9;
		}else if(!strcmp(p,check[11])){
			t=10;
		}else if(!strcmp(p,check[12])){
			t=11;
		}else if(!strcmp(p,check[13])){
			t=12;
		}else if(!strcmp(p,check[14])){
			t=13;
		}else if(!strcmp(p,check[15])){
			t=14;
		}else if(!strcmp(p,check[16])){
			t=15;
		}else if(!strcmp(p,check[17])){
			t=16;
		}else if(!strcmp(p,check[18])){
			t=17;
		}else if(!strcmp(p,check[19])){
			t=18;
		}else if(!strcmp(p,check[20])){
			t=19;
		}else if(!strcmp(p,check[21])){
			t=20;
		}else if(!strcmp(p,check[22])){
			t=30;
		}else if(!strcmp(p,check[23])){
			t=40;
		}else if(!strcmp(p,check[24])){
			t=50;
		}else if(!strcmp(p,check[25])){
			t=60;
		}else if(!strcmp(p,check[26])){
			t=70;
		}else if(!strcmp(p,check[27])){
			t=80;
		}else if(!strcmp(p,check[28])){
			t=90;
		}else if(!strcmp(p,check[29])){
			t=100;
		}else if(!strcmp(p,check[30])){
			t=1000;
		}else{
			t=1000000;
		}
		if(i==0) ta=t;
		else tb=t;
	}

	return inerToken(ta,tb);
}
*/
