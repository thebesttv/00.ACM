#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

struct Node{
	int data;
	Node * next;
};
int n,m;

Node * create(){
	Node * temp=(Node *) calloc(1,sizeof(Node));
	temp->data=0; temp->next=NULL;
#ifdef DEBUG
	printf("    successfully created head\n");
#endif
	return temp;
}
Node * insert(int n, Node * head){
	Node * p=head;
	while(p->next) p=p->next;
	Node * temp=(Node *) calloc(1,sizeof(Node));
	p->next=temp; temp->data=n; temp->next=NULL;
	return temp;
}

int main(void){
//freopen("in","r",stdin);
	while(scanf("%d%d",&n,&m) && n){
#ifdef DEBUG
	printf("  loop of %d %d begin\n",n,m);
#endif
		Node * head=create(), *p, *q;
		for(int i=1;i<=n;i++) p=insert(i,head);
#ifdef DEBUG
	printf("    successfully inserted all %d elements\n",n);
#endif
		p->next=head->next; p=head->next;
		int last;
		for(int cou=0;cou<n;cou++){
			for(int i=1;i<m;i++){	//i初始为1，共循环m-1次
				q=p;
				p=p->next;
			}
			last=p->data;
			q->next=p->next;
			free(p);
			p=q->next;
		}
		printf("%d\n",last);
		free(head);
#ifdef DEBUG
	printf("  loop of %d %d ended\n",n,m);
#endif
	}

	return 0;
}

/*
在OpenJudge上AC，但本地对拍时出错
出现问题的测试数据：
13 9
121 89
75 5
141 114
51 47
226 70
285 231
156 126
129 9
137 11
268 193
243 214
255 88
208 26
260 118
92 47
250 73
208 141
157 96
209 138
146 28
91 46
104 47
176 77
116 40
82 2
244 211
82 81
91 90
78 37
172 140
28 24
76 68
150 53
270 94
134 14
183 16
250 149
166 65
206 188
144 78
62 26
8 8
282 65
112 36
144 48
216 62
101 92
101 49
211 192
6 5
190 27
256 66
170 131
270 238
100 40
59 46
189 177
274 151
157 108
227 107
73 54
166 132
130 9
118 53
41 16
82 59
7 1
67 1
164 127
238 1
139 37
112 66
57 40
203 52
183 97
209 198
260 60
123 105
46 40
127 70
60 17
4 3
248 207
220 101
94 4
73 25
151 39
254 66
265 77
124 4
274 180
100 82
113 10
38 19
166 21
230 220
67 11
277 181
289 237
0 0

输出到68行时正常，直到第69个数据，显示错误信息：
*** Error in `./a.out': double free or corruption (fasttop): 0x01ceaec0 ***
Aborted (core dumped)
怀疑多次free相同空间，暂未解决
*/
