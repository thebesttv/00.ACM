/*
描述
在计算机上看到文件系统的结构通常很有用。Microsoft Windows上面的"explorer"程序就是这样的一个例子。但是在有图形界面之前，没有图形化的表示方法的，那时候最好的方式是把目录和文件的结构显示成一个"图"的样子，而且使用缩排的形式来表示目录的结构。比如：

ROOT
|     dir1
|     file1
|     file2
|     file3
|     dir2
|     dir3
|     file1
file1
file2
这个图说明：ROOT目录包括三个子目录和两个文件。第一个子目录包含3个文件，第二个子目录是空的，第三个子目录包含一个文件。

输入
你的任务是写一个程序读取一些测试数据。每组测试数据表示一个计算机的文件结构。每组测试数据以'*'结尾，而所有合理的输入数据以'#'结尾。一组测试数据包括一些文件和目录的名字（虽然在输入中我们没有给出，但是我们总假设ROOT目录是最外层的目录）。在输入中,以']'表示一个目录的内容的结束。目录名字的第一个字母是'd'，文件名字的第一个字母是'f'。文件名可能有扩展名也可能没有（比如fmyfile.dat和fmyfile）。文件和目录的名字中都不包括空格,长度都不超过30。一个目录下的子目录个数和文件个数之和不超过30。

输出
在显示一个目录中内容的时候，先显示其中的子目录（如果有的话），然后再显示文件（如果有的话）。文件要求按照名字的字母表的顺序显示（目录不用按照名字的字母表顺序显示，只需要按照目录出现的先后显示）。对每一组测试数据，我们要先输出"DATA SET x:"，这里x是测试数据的编号（从1开始）。在两组测试数据之间要输出一个空行来隔开。
你需要注意的是，我们使用一个'|'和5个空格来表示出缩排的层次。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int kase=0;
bool flag=0;
bool fileStructure(int level, string dir);

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif
	while(true){
		flag=fileStructure(0,"ROOT");
		if(flag) break;
		printf("\n");
	}

	return 0;
}

bool fileStructure(int level, string dir){
	vector<string> v;
	string s;
	for(int i=0;i<level;i++) printf("|     ");
	if(level) cout << dir << endl;
	bool t=0;
	while(true){
		cin >> s;
		if(s[0]=='#') return true;
		if(!level && !t){
			printf("DATA SET %d:\n",++kase);
			cout << dir << endl;
			t=1;
		}
		if(s[0]=='*') break;
		if(s[0]=='f') v.push_back(s);
		if(s[0]=='d') fileStructure(level+1,s);
		if(s[0]==']') break;
	}
	sort(v.begin(),v.end());
	vector<string>::iterator it=v.begin();
	for(;it!=v.end();it++){
		for(int i=0;i<level;i++) printf("|     ");
		cout << *it << endl;
	}
	return false;
}
