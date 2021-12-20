/*
描述
古罗马帝国有一个拥有各种部门的强大政府组织。其中一个部门就是保密服务部门。为了保险起见，在省与省之间传递的重要文件中的大写字母是加密的。当时最流行的加密方法是替换和重新排列。
替换方法是将所有出现的字符替换成其它的字符。有些字符会替换成它自己。例如：替换规则可以是将'A' 到 'Y'替换成它的下一个字符，将'Z'替换成 'A'，如果原词是 "VICTORIOUS" 则它变成 "WJDUPSJPVT"。
排列方法改变原来单词中字母的顺序。例如：将顺序<2,1,5,4,3,7,6,10,9,8>应用到 "VICTORIOUS" 上，则得到"IVOTCIRSUO"。
人们很快意识到单独应用替换方法或排列方法加密，都是很不保险的。但是如果结合这两种方法，在当时就可以得到非常可靠的加密方法。所以，很多重要信息先使用替换方法加密，再将加密的结果用排列的方法加密。用两种方法结合就可以将"VICTORIOUS" 加密成"JWPUDJSTVP"。
考古学家最近在一个石台上发现了一些信息。初看起来它们毫无意义，所以有人设想它们可能是用替换和排列的方法被加密了。人们试着解读了石台上的密码，现在他们想检查解读的是否正确。他们需要一个计算机程序来验证，你的任务就是写这个验证程序。

输入
输入有两行。第一行是石台上的文字。文字中没有空格，并且只有大写英文字母。第二行是被解读出来的加密前的文字。第二行也是由大写英文字母构成的。
两行字符数目的长度都不超过100。

输出
如果第二行经过某种加密方法后可以产生第一行的信息，输出 "YES"，否则输出"NO"。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

//[2] 80%
char ori[110],res[110],len;

void Convert();
int Cou(char a, char b);

int main(void){
	scanf("%s%s",ori,res);
	len=strlen(ori);
	sort(ori,ori+len);
	sort(res,res+len);
	int flag=0;
	for(int i=0;i<len;i++){
		Convert();
		int st=Cou(ori[0],res[0]),tflag=1;
		for(int i=0;i<len;i++)
			if(Cou(ori[i],res[i])!=st){tflag=0; break;}
		if(tflag==1) {flag=1; break;}
	}
	if(flag==0) printf("NO\n");
	else printf("YES\n");
	return 0;
}

void Convert(){
	char t=res[0];
	for(int i=0;i<len-1;i++)
		res[i]=res[i+1];
	res[len-1]=t;
}

int Cou(char a, char b){
	for(int i=0;i<26;i++){
		if((a-'A'+i)%26 == b-'A') return i;
	}
}


/*
[3] 50%
char ori[110],res[110];
char st[26+'A'];	//创建映射表
int len;

void Convert();
int Cou(char a, char b);

int main(void){
	scanf("%s%s",ori,res);
	len=strlen(ori);
	memset(st,0,sizeof(st));
	int flag=0;
	for(int i=0;i<len;i++){
		Convert(); int tflag=1;
		for(int j=0;j<len;j++){
			if(st[ori[j]]==0) st[ori[j]]=Cou(ori[j],res[j]);
			else if(Cou(ori[j],res[j])!=st[ori[j]]) {tflag=0; break;}
		}
		if(tflag==1) {flag=1; break;}
	}
	if(flag==0) printf("NO\n");
	else printf("YES\n");

	return 0;
}
void Convert(){
	char t=res[0];
	for(int i=0;i<len-1;i++)
		res[i]=res[i+1];
	res[len-1]=t;
}
int Cou(char a, char b){
	for(int i=0;i<26;i++){
		if((a-'A'+i)%26 == b-'A') return i;
	}
}
*/

/*
[1] 50%
char ori[110],res[110],temp[110],len;

bool Check(int n);

int main(void){
	scanf("%s%s",ori,res);
	len=strlen(ori);
	sort(ori,ori+len);
	sort(res,res+len);
//printf("%s\n%s\n",ori,res);
	int flag=0;
	for(int i=0;i<len;i++){
//		int st=res[i]-ori[i];
		int st;
		for(st=0;st<26;st++)
			if((ori[0]-'A'+st)%26==res[i]-'A') break;
		for(int j=0;j+i<len;j++) temp[j]=ori[i+j];
		for(int j=i;j<len;j++) temp[j-i]=ori[j];
//printf("%s\n",temp);
		if(Check(st)){flag=1; break;}
	}
	if(flag==0) printf("NO\n");
	else printf("YES\n");

	return 0;
}

bool Check(int n){
	for(int i=0;i<len;i++){
		int t;
		for(t=0;t<26;t++)
			if((ori[i]-'A'+t)%26==temp[i]-'A') break;
		if(t!=n && t!=0) return false;
	}
	return true;
}
*/
