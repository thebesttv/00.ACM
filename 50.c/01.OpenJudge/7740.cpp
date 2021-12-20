/*
描述
某医院想统计一下某项疾病的获得与否与年龄是否有关，需要对以前的诊断记录进行整理，按照0-18、19-35、36-60、61以上（含61）四个年龄段统计的患病人数占总患病人数的比例。

输入
共2行，第一行为过往病人的数目n（0 < n <= 100)，第二行为每个病人患病时的年龄。

输出
按照0-18、19-35、36-60、61以上（含61）四个年龄段输出该段患病人数占总患病人数的比例，以百分比的形式输出，精确到小数点后两位。每个年龄段占一行，共四行。
*/

#include<iostream>
#include<cstdio>

int main(){
	int n;
	int age;
	int s_a=0,s_b=0,s_c=0,s_d=0;

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&age);
		if(age<=18) s_a++;
		else if(age<=35) s_b++;
		else if(age<=60) s_c++;
		else s_d++;
	}
	printf("%.2lf%%\n",double(s_a)/n*100);
	printf("%.2lf%%\n",double(s_b)/n*100);
	printf("%.2lf%%\n",double(s_c)/n*100);
	printf("%.2lf%%\n",double(s_d)/n*100);

	return 0;
}
