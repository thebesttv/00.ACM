/*
描述
You have just been put in charge of developing a new shredder for the Shredding Company Although a "normal" shredder would just shred sheets of paper into little pieces so that the contents would become unreadable, this new shredder needs to have the following unusual basic characteristics.
  1. The shredder takes as input a target number and a sheet of paper with a number written on it.
  2. It shreds (or cuts) the sheet into pieces each of which has one or more digits on it.
  3. The sum of the numbers written on each piece is the closest possible number to the target number, without going over it.
For example, suppose that the target number is 50, and the sheet of paper has the number 12346. The shredder would cut the sheet into four pieces, where one piece has 1, another has 2, the third has 34, and the fourth has 6. This is because their sum 43 (= 1 + 2 + 34 + 6) is closest to the target number 50 of all possible combinations without going over 50. For example, a combination where the pieces are 1, 23, 4, and 6 is not valid, because the sum of this combination 34 (= 1 + 23 + 4 + 6) is less than the above combination's 43. The combination of 12, 34, and 6 is not valid either, because the sum 52 (= 12 + 34 + 6) is greater than the target number of 50.

There are also three special rules :
  1. If the target number is the same as the number on the sheet of paper, then the paper is not cut.
    For example, if the target number is 100 and the number on the sheet of paper is also 100, then the paper is not cut.
  2.If it is not possible to make any combination whose sum is less than or equal to the target number, then error is printed on a display.     For example, if the target number is 1 and the number on the sheet of paper is 123, it is not possible to make any valid combination, as the combination with the smallest possible sum is 1, 2, 3. The sum for this combination is 6, which is greater than the target number, and thus error is printed.
  3.If there is more than one possible combination where the sum is closest to the target number without going over it, then rejected is printed on a display. For example, if the target number is 15, and the number on the sheet of paper is 111, then there are two possible combinations with the highest possible sum of 12: (a) 1 and 11 and (b) 11 and 1; thus rejected is printed.

In order to develop such a shredder, you have decided to first make a simple program that would simulate the above characteristics and rules.
Given two numbers, where the first is the target number and the second is the number on the sheet of paper to be shredded, you need to figure out how the shredder should "cut up" the second number.

输入
The input consists of several test cases, each on one line, as follows:

tl num1
t2 num2
...
tn numn
0 0

Each test case consists of the following two positive integers, which are separated by one space:
  1. the first integer (ti) is the target number
  2. the second integer (numi) is the number that is on the paper to be shredded.
Neither integers may have a 0 as the first digit, e.g., 123 is allowed but 0123 is not. You may assume that both integers are at most 6 digits in length. A line consisting of two zeros signals the end of the input.

输出
For each test case in the input, the corresponding output takes one of the following three types:

sum part1 part2 ...
rejected
error

In the first type, partj and sum have the following meaning:
  1.Each partj is a number on one piece of shredded paper. The order of partj corresponds to the order of the original digits on the sheet of paper.
  2.sum is the sum of the numbers after being shredded, i.e., sum = part1 + part2 +...
Each number should be separated by one space.
The message error is printed if it is not possible to make any combination, and rejected if there is more than one possible combination.
No extra characters including spaces are allowed at the beginning of each line, nor at the end of each line.
*/

//vector版
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

int tar,ansSum;
char temp[40];
vector<int> ans;
vector<int> save,tempSave;
vector<int>::iterator it;

void cut(int len, int way);
inline bool getBit(int a, int n);
inline void setBit(int & a, int n, int i);

int main(void){
	int atoi_of_temp;
	while(scanf("%d%s",&tar,temp)==2){
		atoi_of_temp = atoi(temp);
		if(!tar && !atoi_of_temp) break;
		ansSum=-1; save.clear(); tempSave.clear(); ans.clear();
//		if(tar == atoi(temp)) {printf("%d %d\n",tar,tar); continue;}
		if(tar >= atoi_of_temp) {printf("%d %d\n",atoi_of_temp,atoi_of_temp); continue;}
		int sum=0, len=strlen(temp);
		for(int i=0;i<len;i++) sum += temp[i]-'0';
		if(sum>tar) {printf("error\n"); continue;}

		for(int way=0;way<(1<<(len-1));way++)
			cut(len,way);
		sort(ans.begin(),ans.end());
		if(ans.size()>=2 && ans[ans.size()-1] == ans[ans.size()-2]) printf("rejected\n");
		else{
			printf("%d",ans[ans.size()-1]);
//			for(it=save.begin();it!=save.end();it++) printf(" %d",*it);
			for(int i=0; i<save.size(); i++) printf(" %d",save[i]);
			printf("\n");
		}
	}

	return 0;
}

void cut(int len, int way){
	tempSave.clear(); char token[10];
	setBit(way,len-1,1);
	int last=-1,sum=0;
	for(int i=0;i<len;i++){
		if(getBit(way,i)){
			memset(token,0,sizeof(token));
			strncpy(token,&temp[last+1],i-last);
			int t=atoi(token);
			tempSave.push_back(t); sum+=t;
			last=i;
		}
	}

	bool debug_flag=0;
	if(sum<=tar){
		ans.push_back(sum);
		if(sum>ansSum){
			ansSum=sum; debug_flag=1;
			save.clear();
			for(int i=0;i<tempSave.size();i++) save.push_back(tempSave[i]);
//			save = tempSave;
		}
	}
	#ifdef DEBUG
	if(debug_flag){
		printf("  in cut(%d,%d), found sum: %d, ansSum: %d, consisting of:",len,way,sum,ansSum);
		for(int i=0;i<tempSave.size();i++) printf(" %d",tempSave[i]);
		printf("\n");
	}
	#endif
}
inline bool getBit(int a, int n){
	return (a>>n)&1;
}
inline void setBit(int & a, int n, int i){
	if(i) a|=(1<<n);
	else a&=~(1<<n);
}

/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int tar,ansSum;
int save[6], tail;
char temp[10];
bool flag,rejected;

inline bool getBit(int a, int n);
inline void setBit(int & a, int n, bool i);
void cut(int len, int way);

int main(void){
	while(scanf("%d%s",&tar,temp)==2 && tar){
		memset(save,0,sizeof(save));
		#ifdef DEBUG
		printf("  get tar: %d, temp: %s\n",tar,temp);
		#endif
		if(atoi(temp)==tar) {printf("%d %d\n",tar,tar); continue;}
		int sum=0, len=strlen(temp);
		for(int i=0;i<len;i++) sum+=temp[i]-'0';
		if(sum>tar) {printf("error\n"); continue;}

		flag=0; rejected=0; ansSum=-1;
		for(int i=0;i<=(1<<(len-1));i++){
			#ifdef DEBUG
			printf("  in cut(%d,%d)\n",len,i);
			#endif
			cut(len,i);
		}
		sum=0;
		if(rejected) printf("rejected\n");
		else{
			printf("%d",ansSum);
			for(int i=0;i<tail;i++) printf(" %d",save[i]);
			printf("\n");
		}
	}

	return 0;
}

void cut(int len, int way){
	int last=-1,sum=0,tempTail=0;
	int tempSave[6]={0};
	char tempGet[7];
	setBit(way,len-1,1);
	for(int i=0;i<len;i++){
		if(sum>tar) break;
		if(getBit(way,i)){
			memset(tempGet,0,sizeof(tempGet));
			strncpy(tempGet,&temp[last+1],i-last);
			sum += (tempSave[tempTail++]=atoi(tempGet));
			#ifdef DEBUG
			printf("  cut: %d to %d, get :%d, sum: %d\n",last+1,i,tempSave[tempTail-1],sum);
			#endif
			last=i;
		}
	}
//	if(!tail && !way) {strcpy(tempSave[tail++],temp); sum=atoi(temp);}

	bool debug_flag=0, debug_rejected=0;
	if(sum>tar) return;
	else if(sum==tar){
		if(sum==ansSum) rejected = debug_rejected = 1;
		else{
			ansSum=sum; rejected=0;
			flag=1; memcpy(save,tempSave,sizeof(save)); tail=tempTail;
			debug_flag=1;
		}
	}else{
		if(sum==ansSum) rejected = debug_rejected = 1;
		else if(sum>ansSum){
			ansSum=sum; rejected=0;
			memcpy(save,tempSave,sizeof(save)); tail=tempTail;
			debug_flag=1;
		}
	}
	#ifdef DEBUG
	printf("    in cut(%d,%d), ",len,way-16);
	if(debug_rejected) printf("rejected with sum: %d\n",sum);
	else if(debug_flag){
		printf("find with sum: %d, save:",sum);
		for(int i=0;i<tail;i++) printf(" %d",save[i]);
		printf("\n");
	}
	#endif
}
inline bool getBit(int a, int n){
	return (a>>n)&1;
}
inline void setBit(int & a, int n, bool i){
	if(i) a|=(1<<n);
}
*/
