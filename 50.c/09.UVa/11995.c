#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

priority_queue<int> pri;
int st[1000],que[1000];
int head=0,tail=0,top=0;

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif
	int n;
	while(scanf("%d",&n)==1){
		head=0; tail=0; top=0;
		while(!pri.empty()) pri.pop();	//<b>清空优先队列</b>
		int type,x;
		bool isSt=1, isQue=1, isPri=1;
		for(int i=0;i<n;i++){
			scanf("%d%d",&type,&x);
			if(type==1){
				if(isSt) st[top++]=x;
				if(isQue) que[tail++]=x;
				if(isPri) pri.push(x);
			}else{
				if(isSt && st[--top]!=x) isSt=0;
				if(isQue && que[head++]!=x) isQue=0;
				if(isPri){
					if(!pri.empty()){
						if(pri.top()!=x) isPri=0;
						pri.pop();
					}else{
					isPri=0;
					}
				}
			}
		}
		if(!isSt && !isQue && !isPri) printf("impossible\n");
		else if(isSt && !isQue && !isPri) printf("stack\n");
		else if(!isSt && isQue && !isPri) printf("queue\n");
		else if(!isSt && !isQue && isPri) printf("priority queue\n");
		else printf("not sure\n");
	}

	return 0;
}
