#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX_TERM=300;
struct Poly{
	int coef;
	int expo;

	bool operator < (const Poly & b) const{
		return expo>b.expo;
	}
}a[MAX_TERM],b[MAX_TERM],c[MAX_TERM*2];
int lena,lenb,lenc;

int read(Poly * a);
void add(Poly * a, Poly * b, Poly * c);
void print(Poly * a);
void printD(Poly * a);

int main(void){
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		memset(a,0,sizeof(a)); memset(b,0,sizeof(b)); memset(c,0,sizeof(c));
		lena=read(a); lenb=read(b);
		add(a,b,c);
		print(c);
	}

	return 0;
}

int read(Poly * a){
	int len=0,coef,expo;
	while(scanf("%d%d",&coef,&expo)==2 && expo>=0){
		if(coef==0) continue;
		int cur=0;
		for(;cur<MAX_TERM;cur++){
			if(a[cur].expo==expo) break;
			if(!a[cur].expo && !a[cur].coef) break;
		}
		if(a[cur].expo==expo){
			a[cur].coef+=coef;
//			if(expo==0) len++;
		}else{
			a[cur].expo=expo; a[cur].coef=coef;
			cur++;
//			len++;
		}
	}
	for(len=0;len<MAX_TERM;len++) if(!a[len].coef && !a[len].expo) break;
	sort(a,a+len);
#ifdef DEBUG
	printf("  read: ");
	printD(a);
#endif
	return len;
}
void add(Poly * a, Poly * b, Poly * c){
	int cura=0,curb=0,curc=0;
	for(;cura<lena && curb<lenb;){
		if(a[cura].expo==b[curb].expo){
			int sum=a[cura].coef+b[curb].coef;
			if(sum){
				c[curc].coef=sum; c[curc].expo=a[cura].expo;
				curc++;
			}
			cura++; curb++;
		}else if(a[cura].expo>b[curb].expo){
			if(a[cura].coef){
				c[curc].coef=a[cura].coef; c[curc].expo=a[cura].expo;
			}
			curc++; cura++;
		}else{
			if(b[curb].coef){
				c[curc].coef=b[curb].coef; c[curc].expo=b[curb].expo;
			}
			curc++; curb++;
		}
	}
	for(;cura<lena;){
		if(a[cura].coef){
			c[curc].coef=a[cura].coef; c[curc].expo=a[cura].expo;
		}
		curc++; cura++;
	}
	for(;curb<lenb;){
		if(b[curb].coef){
			c[curc].coef=b[curb].coef; c[curc].expo=b[curb].expo;
		}
		curc++; curb++;
	}
	for(int i=0;i<curc;i++){
		if(c[i].coef==0) c[i].expo=0;
	}
	sort(c,c+curc);
#ifdef DEBUG
	printf("  curc: %d\n",curc);
	printf("  added: ");
	printD(c);
#endif
}
void print(Poly * a){
	bool first=0;
	for(int i=0;i<MAX_TERM;i++){
		if(!a[i].expo && !a[i].coef) break;
		if(a[i].coef){
			if(!first) first=1;
			else printf(" ");
			printf("[ %d %d ]",a[i].coef,a[i].expo);
		}
	}
//	if(!first) printf("[ 0 0 ]");	//<b>c中全为0时要输出0</b>
	printf("\n");
}
void printD(Poly * a){
	for(int i=0;i<MAX_TERM;i++){
		if(a[i].coef){
			printf("(%d,%d),",a[i].coef,a[i].expo);
		}
	}
	printf("\n");
}
