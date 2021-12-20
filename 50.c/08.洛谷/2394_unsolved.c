/*
故事背景
从前,有个人叫yyy,他特别喜欢化学,尤其是一些很危(zuo)险(si)的实验.

题目背景
这一天,他开始研究起了一个神奇又有趣的方程式
2Na + 2H2O ==== 2NaOH + H2↑

题目描述
现在yyy将一块质量为xg的钠投入很多的水中,然后开始收集氢气.
最终,我们知道,后来,这块钠在水中游动着消失了.而yyy很厉害,把氢气全收集起来了.
已知每投入了23克的钠,就会生成1克的氢气.
那么现在yyy收集了多少克氢气呢?

输入输出格式

输入格式：
一行,一个实数x,代表yyy将多少克钠投入了水中
输入文件行末一定[color=red][b]不会[/b][/color]有一只回车啦~

数据规模
对于100%的数据,0<x<=1

提示
你想知道x有几位小数吗?才不给你呢>_<
我只知道空间限制是4M,时间限制是0.1s,而且如果你把数字全读下来的话可能就MLE咯~
kkksc:没有数据范围怎么行!输入文件不超过5M!
出题人:怎么能这样!差评!我不好挖坑了!

输出格式：
一行,一个实数(四舍五入精确到8位小数),代表生成了多少克氢气
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(void){
	long double n;
	char a[100];
	fgets(a,sizeof(a),stdin);
	n=strtold(a,NULL);
	n=floor((n*1e8)/23+0.5);
	printf("%.8Lf\n",n/1e8);

	return 0;
}
