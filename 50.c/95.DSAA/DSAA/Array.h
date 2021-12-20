#ifndef __ARRAY_H__
#define __ARRAY_H__

//*****创建一个len长度的整形数组，返回数组的首地址*****
int * cyf_CreateArray(int len);

//*****为数组赋n个随机数初值，初值范围1~1000*****
void  cyf_InitArray(int * a, int len, int n);

//*****显示数组中有效数字*****
void  cyf_ShowArray(int * a, int len, int n);

//*****样例：对数组n个数进行排序--冒泡升序排序*****
void  cyf_SortArray_Maopao(int * a, int len, int n);

//*****非把本次作业第九章排序算法实现--统一升序排序*********
void  cyf_SortArray_ZhiJieChaRu(int * a, int len, int n);
void  cyf_SortArray_ZheBanChaRu(int * a, int len, int n);
void  cyf_SortArray_XiEr(int * a, int len, int n);
void  cyf_SortArray_KuaiSu(int * a, int len, int n);
void  cyf_SortArray_JianDanXuanZe(int * a, int len, int n);
void  cyf_SortArray_GuiBing(int * a, int len, int n);

//*****样例：计算冒泡排序的时间复杂度*********
int  cyf_SortArray_Maopao_TimeComplex(int * a, int len, int n);

//*****作业1：在一个len长度 n个有效数的有序数组中a[0]~a[n-1]数组中删除指定的元素，要求删除后，数组依然有序*********
//len: 数组长度    n: 有效数字个数   m:要删除的数字
//return: 返回删除后的数组有效数字个数  如1 2 3 4 4 5 6 0 0 0 0  删除4 结果:1 2 3 5 6 0 0 0 0 0 0
int cyf_DeleteElement(int * a, int len, int n, int m);

//*****作业2：将一个元素添加进数组
//len: 数组长度    n: 有效数字个数   m:要添加的数字
//return: 返回添加后的数组有效数字个数  如1 2 3 5 6 0 0 0 0  添加4 结果:1 2 3 4 5 6 0 0 0 0 0 
int cyf_AddElement(int * a, int len, int n, int m);

//*****作业3：将一组元素添加进数组
//len: 数组长度    n: 有效数字个数   m:要添加的数字
//return: 返回添加后的数组首地址  
//如a: 1 2 3 5 6 0 0 0 0  b: 3 7 0 0 0 0  添加后: a: 1 2 3 3 4 5 6 7 0
//如a: 1 2 3 5 6 0 0 0 0  b: 3 7 8 9 9 9 9 0 0 0  添加后: a: 1 2 3 3 4 5 6 7 8 9 9 9 9
void cyf_AddElement(int * & a, int & lena, int & na, int * b, int lenb, int nb);


#endif