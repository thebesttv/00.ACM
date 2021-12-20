#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

struct Node{
	char n;
	Node * left;
	Node * right;
}ind[100];
char temp[100];

void Pre(Node * a);
void Mid(Node * a);
void Fin(Node * a);
void Broad(Node * a);
void print(Node * a);

int main(void){
	ind[0].n='A'; ind[0].left=&ind[1]; ind[0].right=&ind[2];
	ind[1].n='B'; ind[1].left=&ind[3]; ind[1].right=&ind[4];
	ind[2].n='C'; ind[2].right=&ind[5];
	ind[3].n='D';
	ind[4].n='E'; ind[4].left=&ind[6];
	ind[5].n='F'; ind[5].left=&ind[7]; ind[5].right=&ind[8];
	ind[6].n='G';
	ind[7].n='H';
	ind[8].n='I';

	printf("Pre: "); Pre(&ind[0]); printf("\n");
	printf("Mdd: "); Mid(&ind[0]); printf("\n");
	printf("Fin: "); Fin(&ind[0]); printf("\n");
	printf("Broad: "); Broad(&ind[0]);

	printf("("); print(&ind[0]); printf(")\n");

	return 0;
}

void Pre(Node * a){
	if(!a) return;
	printf("%c ",a->n);
	Pre(a->left);
	Pre(a->right);
}
void Mid(Node * a){
	if(!a) return;
	Mid(a->left);
	printf("%c ",a->n);
	Mid(a->right);
}
void Fin(Node * a){
	if(!a) return;
	Fin(a->left);
	Fin(a->right);
	printf("%c ",a->n);
}
void Broad(Node * a){
	Node * str[100];
	int head=0, tail=0;
	str[tail++]=a;
	while(head<tail){
		printf("%c ",str[head]->n);
		if(str[head]->left) str[tail++]=str[head]->left;
		if(str[head]->right) str[tail++]=str[head]->right;
		head++;
	}
	printf("\n");
}

void print(Node * a){
	printf("%c",a->n);
	if(a->left || a->right) printf("(");
	if(a->left && a->right){
		print(a->left);
		printf(",");
		print(a->right);
	}else if(a->left){
		print(a->left);
	}else if(a->right){
		print(a->right);
	}
	if(a->left || a->right) printf(")");
}
