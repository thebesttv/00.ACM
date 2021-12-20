/*
  多重背包：
    在求解多重背包时，要使用拆分法，将一种物品拆分为多个物品，由此将问题转化为01背包。
    使用拆分法的前提是：若当前物品i共有ni个，拆分后的物品个数为 a1,a2,...,ak ，那么任意[1:ni]中的数都要能使用 {ai} 表示，否则拆分不成立。
    [1]朴素的拆分法
      将物品i直接拆分为c=costi,w=weighti的ni个物品，正确性显然。
      但朴素的拆分法对时间或空间没有任何优化。
    [2]“二进制”思想的拆分法
      注意这个拆分法并非完全的“二进制”，而是在证明时使用了二进制的思想。
      将物品i拆分为 2^0, 2^1, 2^2, ..., 2^k, n-sum{2^i} 的k+2（ni>1）或k+1个（ni=1）物品，那么每一个[1:ni]的数都可以使用一个或多个 2^i 表示。因为每个<=ni的数都需要小于等于k+2的 2^i 之和表示，而任意 2^i 都在拆分的结果中，那么也就可以了。或者说，[1,2^(k+1))一定能表示，而想要表示[2^(k+1),n]，只需在之前的基础上加上最后一个 n-sum{2^i} 即可。
      但千万注意，一定不能只根据ni的二进制表示来拆分，否则只能保证一定能表示ni，而不一定能表示其他小于ni的数。
      举例来说，当ni=13时，应拆分为 1,2,4,6，可以表示[1:13]的任何数；但如果只根据二进制拆，拆成 1,4,8，则连2都不能表示。

  化归思想
    任何01背包或完全背包都可以转化成amount为1或正无穷的多重背包。
*/

const int MAX=10000;
int n,V,c[MAX],w[MAX];

inline void ZeroOnePack(int cost, int weight){
  ROR(i,V,cost) f[i]=max(f[i],f[i-cost]+weight);
}
inline void CompletePack(int cost, int weight){
  FORR(i,cost,V) f[i]=max(f[i],f[i-cost]+weight);
}
inline void MultiPack(int cost, int weight, int amount){
  if(cost*amount>=V) {CompletePack(cost,weight); return;}
  int k=1;
  while(k<amount){  //<b>使用小于号，防止出现amount被减成0的情况（若改为小于等于，对于正确性证明没有影响）</b>
    ZeroOnePack(cost*k,weight*k);
    amount-=k; k<<=1;
  }
  ZeroOnePack(cost*amount,weight*amount);
}
