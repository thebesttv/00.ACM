#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000
#define DEBUG 0

char str[MAX];
long len,i=0;
long *pi =&i;
long count=0;

int Match(char str[],long * pi);	//返回值

int main(void){
	fgets(str,sizeof(str),stdin);
	len=strlen(str)-1;
	while(str[i]!='(' && i<len) i++;
	if(i==len) printf("(1)match error\n");
	else{
		if(Match(str,pi)==1)
			printf("successfully matched\n");
		else
			printf("(2)match error\n");
	}
	return 0;
}

int Match(char str[],long * pi){
	while(*pi<len){
		if(str[*pi]=='('){
			(*pi)++;	//间接访问(*)优先级与自增、自减相同
			if(Match(str,pi)==1){
				return 1;
			}else{
				return 0;
			}
		}else if(str[*pi]==')'){
			(*pi)++;
			return 1;
		}
		(*pi)++;
	}
	return 0;
}

/*
int main(void){
	fgets(str,sizeof(str),stdin);
	len=strlen(str)-1;
	#if DEBUG
		fputs(str,stdout);
		printf("strlen: %ld\n",len);
	#endif
	while(str[i]!='(' && i<len) i++;
	if(i==len) printf("(1)match error\n");
	else{
		#if DEBUG
			printf("i: %ld\n",i);
		#endif
		if(Match(str,pi)==1)
			printf("successfully matched\n");
		else
			printf("(2)match error\n");
	}
	return 0;
}

int Match(char str[],long * pi){
	#if DEBUG
		count++;
		printf("Match count: %ld, i: %ld\n",count,*pi);
	#endif
	while(*pi<len){
		#if DEBUG
			printf("enter loop of Match: %ld\n",count);
			printf("str[%ld]: %c\n",*pi,str[*pi]);
		#endif
		if(str[*pi]=='('){
		#if DEBUG
			printf("find str[%ld]: %c\n",*pi,str[*pi]);
		#endif
			(*pi)++;	//间接访问(*)优先级与自增、自减相同
		#if DEBUG
			printf("i: %ld\n",*pi);
		#endif
			if(Match(str,pi)==1){
				return 1;
			}else{
				return 0;
			}
		}else if(str[*pi]==')'){
		#if DEBUG
			printf("find str[%ld]: %c\n",*pi,str[*pi]);
		#endif
			(*pi)++;
			return 1;
		}
		(*pi)++;
	}
	return 0;
}
*/
