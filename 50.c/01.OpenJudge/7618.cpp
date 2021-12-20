/*
描述
病人登记看病，编写一个程序，将登记的病人按照以下原则排出看病的先后顺序： 
1. 老年人（年龄 >= 60岁）比非老年人优先看病。 
2. 老年人按年龄从大到小的顺序看病，年龄相同的按登记的先后顺序排序。 
3. 非老年人按登记的先后顺序看病。

输入
第1行，输入一个小于100的正整数，表示病人的个数；
后面按照病人登记的先后顺序，每行输入一个病人的信息，包括：一个长度小于10的字符串表示病人的ID（每个病人的ID各不相同且只含数字和字母），一个整数表示病人的年龄，中间用单个空格隔开。

输出
按排好的看病顺序输出病人的ID，每行一个。
*/

#include<iostream>
#include<cstdio>
#include<cstring>

struct Pat{
	int ord;
	char id[14];
	int age;
}a[100],b[100],temp;
int n,lena=0,lenb=0;

void SortAge(struct Pat * p, int left, int right);
void SortOrd(struct Pat * p, int left, int right);

int main(){
	int tage; char tid[14];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %d",tid,&tage);
		if(tage>=60) {a[lena].ord=i;strcpy(a[lena].id,tid);a[lena].age=tage;lena++;}
		else {b[lenb].ord=i;strcpy(b[lenb].id,tid);b[lenb].age=tage;lenb++;}
	}

	SortAge(a,0,lena-1);
	for(int i=0;i<lena-1;i++){
		if(a[i].age==a[i+1].age){
			int tot;
			for(tot=i+1;tot<lena;tot++) if(a[tot].age!=a[i].age) break;
			SortOrd(a,i,tot-1);
			i=tot-1;
		}
	}
	SortOrd(b,0,lenb-1);

	for(int i=0;i<lena;i++) printf("%s\n",a[i].id);
	for(int i=0;i<lenb;i++) printf("%s\n",b[i].id);

	return 0;
}

void SortAge(struct Pat * p, int left, int right){
	if(left>=right) return;
	int i=left, j=right, k=p[left].age;
	while(i!=j){
		while(i<j && p[j].age<=k) j--;
		while(i<j && p[i].age>=k) i++;
		temp=p[i];p[i]=p[j];p[j]=temp;
	}
	temp=p[i];p[i]=p[left];p[left]=temp;
	SortAge(p,left,i-1);
	SortAge(p,i+1,right);
}

void SortOrd(struct Pat * p, int left, int right){
        if(left>=right) return;
        int i=left, j=right, k=p[left].ord;
        while(i!=j){
                while(i<j && p[j].ord>=k) j--;
                while(i<j && p[i].ord<=k) i++;
                temp=p[i];p[i]=p[j];p[j]=temp;
        }
        temp=p[i];p[i]=p[left];p[left]=temp;
        SortOrd(p,left,i-1);
        SortOrd(p,i+1,right);
}
