#include<iostream>
#include<cstdio>
#include<cstring>

int main(){
	char a[100];
	char * p;
	int count=0;

	while(fgets(a,sizeof(a),stdin)!=0){
		count=0;
		a[strlen(a)-1]='\0';
		p=strtok(a," ,.-\"\'!");
		while(p!=NULL){
			count++;
			printf("%s\n",p);
			p=strtok(NULL," ,.-\"\'!");
		}
		printf("total words: %d\n",count);
	}
	return 0;
}
