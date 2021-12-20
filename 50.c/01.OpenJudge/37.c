/*
描述
现在有一些英语单词需要做拼写检查，你的工具是一本词典。需要检查的单词，有的是词典中的单词，有的与词典中的单词相似，你的任务是发现这两种情况。单词A与单词B相似的情况有三种：
1、删除单词A的一个字母后得到单词B；
2、用任意一个字母替换单词A的一个字母后得到单词B；
3、在单词A的任意位置增加一个字母后得到单词B。
你的任务是发现词典中与给定单词相同或相似的单词。


输入
第一部分是词典中的单词，从第一行开始每行一个单词，以"#"结束。词典中的单词保证不重复，最多有10000个。
第二部分是需要查询的单词，每行一个，以"#"结束。最多有50个需要查询的单词。
词典中的单词和需要查询的单词均由小写字母组成，最多包含15个字符。

输出
按照输入的顺序，为每个需要检查的单词输出一行。如果需要检查的单词出现在词典中，输出“?x is correct"，?x代表需要检查的单词。如果需要检查的单词没有出现在词典中，则输出"?x: ?x1 ?x2 ...?xn"，其中?x代表需要检查的单词，?x1...?xn代表词典中与需要检查的单词相似的单词，这些单词中间以空格隔开。如果没有相似的单词，输出"?x:"即可。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

struct Word{
	char str[20];
	int ord;

	bool operator < (const Word & b) const {
		return strcmp(str,b.str)<0;
	}
}dic[10000];
struct Word2{
	char str[20];
	int ord;

	bool operator < (const Word2 & b) const {
		return ord<b.ord;
	}
};
int tot;
char a[20];

void Search(char * a);

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif
	while(scanf("%s",dic[tot].str)==1){
		if(dic[tot].str[0]=='#'){
			dic[tot].str[0]=0;
			break;
		}else{
			dic[tot].ord=tot;
			tot++;
		}
	}
	sort(dic,dic+tot);
	#ifdef DEBUG
	for(int i=0;i<tot;i++) printf("%s\n",dic[i].str);
	#endif
	while(scanf("%s",a)==1){
		if(a[0]=='#') break;
		Search(a);
	}

	return 0;
}

void Search(char * a){
	Word temp,ori; memset(&temp,0,sizeof(temp)); memset(&ori,0,sizeof(ori));
	for(int i=0;i<20;i++) ori.str[i]=a[i];
	set<Word> save;
	int len=strlen(ori.str),tail=0;
	for(int k=0;k<len;k++){
		tail=0; memset(&temp,0,sizeof(temp));
		for(int i=0;i<len;i++)
			if(i!=k) temp.str[tail++]=a[i];
		Word *p=lower_bound(dic,dic+tot,temp);
		#ifdef DEBUG
		printf("  %s\n",temp.str);
		#endif
		if(strcmp(temp.str,p->str)==0) save.insert(*p);
	}
	for(int k=0;k<len;k++){
		for(char w='a';w<='z';w++){
			tail=0; memset(&temp,0,sizeof(temp));
			for(int i=0;i<len;i++){
				if(i!=k) temp.str[tail++]=a[i];
				else temp.str[tail++]=w;
			}
			Word *p=lower_bound(dic,dic+tot,temp);
			#ifdef DEBUG
			printf("  %s\n",temp.str);
			#endif
			if(strcmp(temp.str,p->str)==0) save.insert(*p);
		}
	}
	for(int k=0;k<=len;k++){
		for(char w='a';w<='z';w++){
			tail=0; memset(&temp,0,sizeof(temp));
			for(int i=0;i<len;i++){
				if(i!=k) temp.str[tail++]=a[i];
				else {temp.str[tail++]=w; temp.str[tail++]=a[i];}
			}
			if(k==len) temp.str[tail++]=w;
			Word *p=lower_bound(dic,dic+tot,temp);
			#ifdef DEBUG
			printf("  %s\n",temp.str);
			#endif
			if(strcmp(temp.str,p->str)==0) save.insert(*p);
		}
	}
	set<Word>::iterator it=save.begin();
	if(save.find(ori)!=save.end()) printf("%s is correct\n",a);
	else{
		set<Word2> out; Word2 t;
		for(;it!=save.end();it++){
			for(int i=0;i<20;i++) t.str[i]=(*it).str[i];
			t.ord=(*it).ord;
			out.insert(t);
		}
		set<Word2>::iterator it_=out.begin();
		printf("%s:",a);
		for(;it_!=out.end();it_++) cout << " " << (*it_).str;
		printf("\n");
	}
}
