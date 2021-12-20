#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Ants{
	int pos;
	int d;
	int ord;
}a[10000+5],b[10000+5],temp;
int ord[10000+5];
char out[3][10]={"L","Turning","R"};

void Sort(struct Ants * p, int left, int right);

int main(void){
	int kase;
	scanf("%d",&kase);
	for(int k=1;k<=kase;k++){
		int n,l,t; char c;
		scanf("%d %d %d",&l,&t,&n);
		for(int i=0;i<n;i++){
			scanf("%d %c",&a[i].pos,&c); a[i].d=(c=='L' ? -1 : 1); a[i].ord=i;
			b[i].pos=a[i].pos+t*a[i].d; b[i].d=a[i].d;
		}
		Sort(a,0,n-1);
		Sort(b,0,n-1);
		for(int i=0;i<n;i++) {b[i].ord=a[i].ord; ord[b[i].ord]=i;}
		for(int i=0;i<n-1;i++){
			if(b[i].pos==b[i+1].pos) {b[i].d=0;b[i+1].d=0;}
		}

		printf("Case #%d:\n",k);
		for(int i=0;i<n;i++){
			int t=ord[i];
			if(b[t].pos>l || b[t].pos<0) printf("Fell off\n");	//Fell off有两种情况
			else printf("%d %s\n",b[t].pos,out[b[t].d+1]);
		}
		printf("\n");
	}
	return 0;
}

void Sort(struct Ants *p, int left, int right){
	if(left>=right) return;
	int i=left, j=right, k=p[left].pos;
	while(i!=j){
		while(i<j && p[j].pos>=k) j--;
		while(i<j && p[i].pos<=k) i++;
		temp=p[i];p[i]=p[j];p[j]=temp;
	}
	temp=p[left];p[left]=p[i];p[i]=temp;
	Sort(p,left,i-1);
	Sort(p,i+1,right);
}
