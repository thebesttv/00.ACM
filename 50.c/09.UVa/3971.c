#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define SWAP(x,y) temp=(x);(x)=(y);(y)=temp

struct Ind{
	int price;
	int quality;
}a[1000][1000];
struct Rule{
	bool operator()(const Ind & a, const Ind & b){
		return (a.quality)<(b.quality);
	}
};

char type[1000][24];
int lent[1000];
int n,b,tail=0,tprice,tquality,maxq;
char ttype[24],tname[24];

void Get();
bool Check(int n);
void Sort(Ind a[], int left, int right);
Ind * Search(Ind a[], int n, int x);	//顺序查找 O(n)

int main(){
	int T;
	scanf("%d",&T);
for(int kase=0;kase<T;kase++){
	memset(a,0,sizeof(a));
	memset(type,0,sizeof(type));
	memset(lent,0,sizeof(lent));
	tail=0; maxq=0;
	scanf("%d%d",&n,&b);
	for(int i=0;i<n;i++) Get();
	for(int i=0;i<tail;i++)
		Sort(a[i],0,lent[i]-1);
/*
for(int i=0;i<tail;i++){
	for(int j=0;j<lent[i];j++)
		printf("a[%d][%d]: %d %d\n",i,j,a[i][j].price,a[i][j].quality);
	printf("\n");
}
*/
	int L=0,R=maxq;
	while(L<R){
		int M=L+(R-L+1)/2;
		if(Check(M)){
			L=M;
//			printf("%d: 1\n",M);
		}
		else{
			R=M-1;
//			printf("%d: 0\n",M);
		}
	}
	printf("%d\n",L);
}
	return 0;
}

void Get(){
	scanf("%s%s%d%d",ttype,tname,&tprice,&tquality);
	int j; maxq=max(maxq,tquality);
	for(j=0;j<tail;j++)
		if(strcmp(ttype,type[j])==0){
			a[j][lent[j]].price=tprice;
			a[j][lent[j]].quality=tquality;
			lent[j]++; break;
		}
	if(j==tail){
		strcpy(type[tail],ttype);
		a[tail][lent[tail]].price=tprice;
		a[tail][lent[tail]].quality=tquality;
		lent[tail]++; tail++;
	}
}

bool Check(int n){
	int tot=0;
	Ind * p;
	for(int i=0;i<tail;i++){
		p=Search(a[i],lent[i],n);
		if(p==a[i]+lent[i]) return false;
		else tot+=p->price;
	}
	return tot<=b;
}

void Sort(Ind a[], int left, int right){
	if(left>=right) return;
	int i=left, j=right, k=a[left].quality;
	while(i!=j){
		while(i<j && a[j].quality>=k) j--;
		while(i<j && a[i].quality<=k) i++;
		Ind SWAP(a[i],a[j]);
	}
	Ind SWAP(a[left],a[i]);
	Sort(a,left,i-1);
	Sort(a,i+1,right);
}

Ind * Search(Ind a[], int n, int x){
	for(int i=0;i<n;i++)
		if(a[i].quality>=x) return a+i;
	return a+n;
}
