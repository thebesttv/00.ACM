#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define DEBUG 0
#define DEBUG_REAL 0

const int MAX_LEN=1000;

struct BigInteger{
	signed char s[MAX_LEN];	//char默认为unsigned
	int base;
	int len;
	bool minus;
};

BigInteger Create(char * str, int base, int len, bool minus);
BigInteger Add(BigInteger a, BigInteger b);
BigInteger Sub(BigInteger a, BigInteger b);
BigInteger Mul(BigInteger a, BigInteger b);
BigInteger Div(BigInteger a, BigInteger b);
BigInteger Mod(BigInteger a, BigInteger b);
BigInteger Half(BigInteger a);
BigInteger Pow(BigInteger a, int n);
BigInteger MovLt(BigInteger a, int n);
BigInteger MovRt(BigInteger a, int n);
BigInteger Pow(BigInteger a, int n);

int Compare(BigInteger a, BigInteger b);
bool isZero(BigInteger a);

void Print(BigInteger a);
void Reverse(char * dest, char * ori, int size);

int main(void){
	char temp[300];
	BigInteger a,b,c;
	scanf("%s",temp); a=Create(temp,0,strlen(temp),0);
	scanf("%s",temp); b=Create(temp,0,strlen(temp),0);
	c=Mul(a,b);
	Print(c);

	return 0;
}

//函数体

BigInteger Create(char * str, int base, int len, bool minus){
	BigInteger temp; memset(&temp,0,sizeof(temp));
	for(int i=len-1;i>=0;i--) temp.s[i]=str[len-i-1]-'0';
	temp.base=base; temp.len=len; temp.minus=minus;
	return temp;
}

BigInteger Add(BigInteger a, BigInteger b){
	BigInteger temp; memset(&temp,0,sizeof(temp));
/*
//小数处理
	if(a.base<0 || b.base<0){
		if(-a.base>=-b.base)
			b=MovRt(b,b.base-a.base);
		else
			a=MovRt(a,a.base-b.base);

//[2]
		BigInteger ta,tb; memset(&ta,0,sizeof(ta)); memset(&tb,0,sizeof(tb));
		int base=-a.base;
		for(int i=0;i<base;i++) ta.s[i]=a.s[base-i-1];
		base=-b.base;
		for(int i=0;i<base;i++) tb.s[i]=b.s[base-i-1];
		ta.len=-a.base; tb.len=-b.base;
		ta.base=0; tb.base=0;
		ta.minus=0; tb.minus=0;
		dec=Add(ta,tb);
		dec.base=dec.len;
	}
*/
/*
//负数处理
	if(a.minus==1 && b.minus==0){
		a.minus=0;
		temp=Sub(b,a);
		return temp;
	}else if(a.minus==0 && b.minus==1){
		b.minus=0;
		temp=Sub(a,b);
		return temp;		
	}else if(a.minus==1 && b.minus==1){
		a.minus=0; b.minus=0;
		temp=Add(a,b); temp.minus=1;
		return temp;
	}
*/
//整数加法，a,b全为正整数
	int len=max(a.len,b.len);
	int t=0;
	for(int i=0;i<len;i++){
		temp.s[i]=(a.s[i]+b.s[i]+t)%10;
		t=(a.s[i]+b.s[i]+t)/10;
	}
	if(t) temp.s[len++]=t;
	temp.len=len; temp.base=0; temp.minus=0;
	return temp;
}

BigInteger Sub(BigInteger a, BigInteger b){
	BigInteger temp; memset(&temp,0,sizeof(temp));
	int Comp=Compare(a,b);
	if(Comp==0){
		temp.len=1; temp.minus=0; temp.s[0]=0;
		return temp;
	}else if(Comp==1){
		temp.minus=0;
	}else if(Comp==-1){
		temp.minus=1;
		swap(a,b);
	}
	int len=a.len, t=0;
	for(int i=0;i<len;i++){
		if(a.s[i]<b.s[i]){
			a.s[i+1]--;
			temp.s[i]=a.s[i]-b.s[i]+10;
		}else{
			temp.s[i]=a.s[i]-b.s[i];
		}
	}
	while(temp.s[len-1]==0 && len>1) len--;
	temp.len=len; temp.base=0;
	return temp;
}

BigInteger Mul(BigInteger a, BigInteger b){
	if(isZero(a)) return a;
	if(isZero(b)) return b;
	BigInteger temp; memset(&temp,0,sizeof(temp));
	for(int i=0;i<a.len;i++){
		for(int j=0;j<b.len;j++){
			temp.s[i+j]+=a.s[i]*b.s[j];
			temp.s[i+j+1]+=temp.s[i+j]/10;
			temp.s[i+j]%=10;
		}
	}
	temp.len=a.len+b.len-1;
	if(temp.s[temp.len]!=0) temp.len++;
	return temp;
}

BigInteger Div(BigInteger a, BigInteger b){
	BigInteger temp; memset(&temp,0,sizeof(temp));
	if(isZero(b)){
		printf("illegal input\n"); return temp;
	}
	if(isZero(a)){
		temp.len=1; return temp;
	}

	int Comp=Compare(a,b);
	if(Comp<0){
		temp.s[0]=0; temp.len=1; return temp;
	}else if(Comp==0){
		temp.s[0]=1; temp.len=1; return temp;
	}
	//temp.base=a.base-b.base;
	BigInteger L,R,M,one;
	memset(&one,0,sizeof(one)); one.len=1; one.s[0]=1;
	memset(&L,0,sizeof(L)); L.len=1;
	R=a;
	while(Compare(L,R)<0){	//30/20可用来检验二分法
		M=Half(Add(L,R));
//putchar('L'); Print(L); putchar('R'); Print(R); putchar('M'); Print(M);
		temp=Mul(b,M);
		int Comp=Compare(a,temp);
		if(Comp==0){
			L=M; break;
		}else if(Comp<0){
			R=Sub(M,one);
		}else{
			L=Add(M,one);
		}
/*		if(Compare(a,temp)>=0){
			L=M;
			if(Compare(a,Add(temp,b))<0) break;
		}else{
			R=Sub(M,one);
		}
*/	}
	temp=Mul(b,L);
	if(Compare(a,temp)<0) L=Sub(L,one);

	return L;
}
BigInteger Mod(BigInteger a, BigInteger b){

}
BigInteger Half(BigInteger a){
	for(int i=a.len-1;i>=0;i--){
		if(a.s[i]&1)
			a.s[i-1]+=10;
		a.s[i]/=2;
	}
	if(a.s[a.len-1]==0 && a.len>1) a.len--;
	return a;
}
BigInteger Pow(BigInteger a, int n){

}
BigInteger MovLt(BigInteger a, int n){
	BigInteger temp; memset(&temp,0,sizeof(temp));
	for(int i=0;i<a.len-n;i++){
		temp.s[i]=a.s[i+n];
	}
	temp.len=a.len-n; temp.minus=a.minus; temp.base=a.base-n;
}
BigInteger MovRt(BigInteger a, int n);
BigInteger Pow(BigInteger a, int n);

void Print(BigInteger a){
#if DEBUG
	printf("***len: %d, base: %d, minus: %d\n",a.len,a.base,(int)a.minus);
	#if DEBUG_REAL
		printf("***real: "); for(int i=a.len-1;i>=0;i--) printf("%d ",a.s[i]); putchar('\n');
	#endif
#endif
	if(a.minus) putchar('-');
	for(int i=a.len-1;i>=0;i--)
		putchar(a.s[i]+'0');
	putchar('\n');
}

int Compare(BigInteger a, BigInteger b){
	if(a.minus==1 && b.minus==0) return -1;
	else if(a.minus==0 && b.minus==1) return 1;
	else if(a.minus==0 && b.minus==0){
		if(a.len>b.len) return 1;
		else if(a.len<b.len) return -1;
		else{
			for(int i=a.len-1;i>=0;i--){
				if(a.s[i]>b.s[i]) return 1;
				else if(a.s[i]<b.s[i]) return -1;
			}
			return 0;
		}
	}else{
		if(a.len>b.len) return -1;
		else if(a.len<b.len) return 1;
		else{
			for(int i=a.len-1;i>=0;i--){
				if(a.s[i]>b.s[i]) return -1;
				else if(a.s[i]<b.s[i]) return 1;
			}
			return 0;
		}
	}
}

bool isZero(BigInteger a){
	if(a.len==1 && a.s[0]==0) return 1;
	else return 0;
}
