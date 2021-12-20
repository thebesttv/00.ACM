  冒泡排序
    共n-1次遍历，每次将序列“左边”偏大的数放到尽量右边。
    FOR(i,1,n) FOR(j,0,n-i)
      if(a[j]>a[j+1])
        swap(a[j],a[j+1]);
  选择排序
    共n-1次遍历，每次从序列“左边”选择最大的数，将其与右边的数对调。
    FOR(i,1,n){
      int u=0,tMax=a[0];
      FORR(j,1,n-i) if(a[j]>tMax) //<b> 1<=j<=n-i </b>
        tMax=a[u=j];
      swap(a[u],a[n-i]);
    }
<b>插入排序</b>
    将序列分成已排序和待排序两段。共n-1次遍历，每次在已排序序列中逆序遍历并依次右移，将待排序序列中的第一个放入合适位置。
    FOR(i,1,n){
      int t=a[i],j=i;
      while(j && a[j-1]>t) {a[j]=a[j-1]; j--;}
      a[j]=t;
    }
  桶排（基数排序）
    构建一个计数序列cnt[max{ai}+1]，每次将cnt[ai]++，最后按顺序输出cnt即可。
  快排 O(nlogn)
    普通的快排
      对于已经有序，或两两元素完全相同的序列，时间复杂度将退化到O(n^2)
      void quick_sort(int l, int r){  //[l,r]
        if(l>=r) return;
        if(l+1==r){
          if(a[l]>a[r]) swap(a[l],a[r]);
          return;
        }
        int k=a[l],i=l,j=r; //<b></b>
        while(i<j){
          while(i<j && a[j]>=k) j--;
          while(i<j && a[i]<=k) i++;
          swap(a[i],a[j]);
        }
        swap(a[l],a[i]);
        quick_sort(l,i-1);
        quick_sort(i+1,r);
      }
    优化的快排
      每次随机选择哨兵位置，区间长度较小时改为直接判断或冒泡排序。
      缺点：若区间中的数全部相同，将会退化到O(n^2)
      void quick_sort(int l, int r){  //[l,r]
        int i=l,j=r; //<b> i从l开始 </b>
        int p=l+rand()%(r-l);
        int k=a[p]; swap(a[l],a[p]);
        while(i<j){
          while(i<j && a[j]>=k) j--;
          while(i<j && a[i]<=k) i++;
          swap(a[i],a[j]);
        }
        swap(a[l],a[i]);
  
        int l1=i-l,l2=r-i;  //左边和右边的长度
        if(l1==2){
          if(a[l]>a[i-1]) swap(a[l],a[i-1]);
        }else if(l1<=4){
          bubble_sort(l,i-1);
        }else if(l1>0) quick_sort(l,i-1);
  
        if(l2==2){
          if(a[i+1]>a[r]) swap(a[i+1],a[r]);
        }else if(l2<=4){
          bubble_sort(i+1,r);
        }else if(l2>0) quick_sort(i+1,r);
      }
    第n小的元素 O(n)
      基于快排的思想，分治查找。
      int quick_sort(int l, int r, int n){
        if(l>=r) return a[l];
        int k=a[l],i=l,j=r;
        while(i<j){
          while(i<j && a[j]>=k) j--;
          while(i<j && a[i]<=k) i++;
          swap(a[i],a[j]);
        }
        swap(a[l],a[i]);
        if(n==i) return a[i];
        if(n<i) return quick_sort(l,i-1,n);
        else return quick_sort(i+1,r,n);
      }
  并排 O(nlogn)
    不同于块排，虽然需要额外的t数组，但时间复杂度稳定。
    void merge_sort(int l, int r){  //[l,r)
      if(l+1>=r) return;
      int m=(l+r)>>1;
      merge_sort(l,m);
      merge_sort(m,r);
      int p=l,q=m,tail=l;
      while(p<m || q<r){  //<b>
        if(q>=r || (p<m && a[p]<=a[q]) t[tail++]=a[p++]; //a[p] < a[q]
        else t[tail++]=a[q++];  //a[q] < a[p]
      }                   //</b>
      FOR(i,l,r) a[i]=t[i];
    }
 <b>逆序对</b>
      对于i<j，若ai>aj，则<ai,aj>为一个逆序对。
      朴素判断 O(n^2)
        FOR(i,0,n) FOR(j,i+1,n)
          if(a[i]>a[j]) cnt++;
      插入排序 O(n^2)
        对于aj，[0:j-1]的所有数中，小于它的就是逆序对。
        在插入排序中，每次将未排序序列中的第一个元素aj插入到已排序部分，而对于aj，在插入中右移的每个有序元素都为关于aj的逆序对，那么右移的元素数目即为关于aj的逆序对个数。因为有序序列都是[0:j-1]的元素，只要有序序列中ai>aj,0<=i<j，那么在原序列中也成立。
      优化 O(nlogn)
        在归并排序中，同样是将一个数组分为两部分处理，在a[q]<a[p]时，将a[q]放入t数组的动作与插入排序相似。而对于a[p]>a[q]，a[p:m-1]即为插入排序中右移的元素，每个<a[p:m-1],a[j]>都为一个逆序对，那么只要累加m-p即可（因为区间为[p,m)）。
     <b>并且一定不能说：a[p]>a[q]，那么a[p]>a[m:q]，那么就cnt+=q-m+1。因为原理是插入排序，只关注a[p:m)，而与a[m:q)无关。</b>
      void merge_sort(int l, int r){
        if(l+1>=r) return;
        int m=(l+r)>>1;
        merge_sort(l,m);
        merge_sort(m,r);
        int p=l,q=m,tail=l;
        while(p<m || q<r){
          if(q>=r || (p<m && a[p]<=a[q])) t[tail++]=a[p++];  //a[p] <= a[q]
          else {t[tail++]=a[q++]; cnt+=m-p;}  //a[p] > a[q]
        }
        FOR(i,l,r) a[i]=t[i];
      }

字符串
  KMP

动规
  最大连续子段和
    令 f[i] 为以a[i]结尾的最大连续子段和，那么对于每个f[i]，共有两种决策：选a[i]和不选a[i]，则
      f[i] = max{ f[i-1] + a[i], a[i] }
    可以使用滚动数组优化，且可以边读边算。
    时间O(n)，空间最优可达O(1)。
  最大子矩阵
    类似于“最大连续子段和”的DP方法。
    令 f[l][r][i] 表示占据[l:r]列、最下方在行i上的最大子矩阵权值，那么对于每个状态亦有两种决策，则
      f[l][r][i] = max{ f[l][r][i-1] + sum{a[i][l:r]}, sum{a[i][l:r]} }
    可以使用一维前缀和、滚动数组优化，以达到O(n^3)的时间复杂度与在排除前缀和的情况下O(1)的空间复杂度。
  最大上升子序列
  最大回文子序列

RMQ
  ST
    主要适用于静态求区间最值。
    倍增，令 f[i][j] 表示sum{ a[ i : i+(2^j)-1 ] }。
      ROR(i,n,1) for(RE int j=1;i+(1<<j)-1<=n;j++)
        f[i][j] = max(f[i][j-1],f[ i+(1<<(j-1)) ][j-1]);
    求最值时，将区间分成两块，直接O(1)求解。
      int s_max(int l, int r){
        int k = log(r-l+1)/log(2);
        return max( f[l][k], f[r+1-(1<<k)][k] );
      }
  线段树

logn优化算法
  树状数组
    inline int lowbit(int x) { return x&-x; }
    int sum(int x){
      int ans=0;
      while(x){
        ans+=C[x]; x-=lowbit(x);
      }
      return ans;
    }
    void add(int x, int d){
      while(x<=n){
        C[x]+=d; x+=lowbit(x);
      }
    }
  线段树
  倍增
  树上倍增
  堆
  ST

数据结构
  并查集 近似O(1)
    int find(int x){
      return p[x]<0 ? x : p[x]=find(p[x]);
    }
    void merge(int x, int y){
      int px=find(x),py=find(y);
      if(px==py) return;
      if(p[px]<p[py]){  //|p[px]|>|p[py]|
        p[px]+=p[py];
        p[py]=px;
      }else{
        p[py]+=p[px];
        p[px]=py;
      }
    }
  树状数组 O(logn)
  inline int lowbit(int x) { return x&-x; } //<b> </b>
  int sum(int x){ //sum{a[1:x]}
    int ans=0;
    while(x){
      ans+=C[x]; x-=lowbit(x);
    }
    return ans;
  }
  void add(int x, int d){ //a[x]+=d
    while(x<=n){
      C[x]+=d; x+=lowbit(x);
    }
  }
  线段树 O(logn)
  堆 O(logn)

树
  三种遍历
    仅适用于二叉树，根据对root的访问次序命名。
    void pre(int u){
      visit(u);
      pre(node[u].leftChild);
      pre(node[u].rightChild);
    }
    void mid(int u){
      pre(node[u].leftChild);
      visit(u);
      pre(node[u].rightChild);
    }
    void post(int u){
      pre(node[u].leftChild);
      pre(node[u].rightChild);
      visit(u);
    }
  LCA
    //洛谷 P3379
    树上倍增
      需要先初始化dep[]和f[][]。
      const int MAX=500020;
      int n,m,s;
      int f[MAX][20],dep[MAX],lg[MAX];
      struct Edge{
        int v,next;
      }edge[MAX<<1];
      int se[MAX],tailE=1;
      bool vis[MAX];
      int q[MAX],head,tail;
      
      inline void addEdge(int u, int v){
        int t=tailE++;
        edge[t] = (Edge){v,se[u]}; se[u]=t;
      }
      int lca(int x, int y){
        if(dep[x]<dep[y]) swap(x,y);
        while(dep[x]>dep[y])
          x=f[x][lg[dep[x]-dep[y]]];
        //for(int t=dep[x]-dep[y],cnt=0;t;t>>=1,cnt++) if(t&1)  //好像要快一点点  //11月10日： 太慢
        //  x=f[x][cnt];
        if(x==y) return x;
        ROR(k,lg[dep[x]],0)
          if(f[x][k]!=f[y][k])
            x=f[x][k],y=f[y][k];
        return f[x][0];
      }

      int main(void){
        n=read(); m=read(); s=read();
        //init lg
        for(int i=2;i<=n;i<<=1) lg[i]=1;  //<b> log2(1)=0，i从2开始 </b>
        int *p=lg+1;
        FORR(i,1,n) {*p += *(p-1); p++;}

        //read edge
        int u,v;
        FOR(i,1,n){
          u=read(); v=read();
          addEdge(u,v); addEdge(v,u);
        }
        //bfs
        RE int d;
        q[tail++]=s; vis[s]=1;
        while(head<tail){
          u=q[head++]; d=dep[u];
          for(RE int k=1;(1<<k)<=d;k++)
            f[u][k] = f[f[u][k-1]][k-1];
          for(RE int i=se[u];i;i=edge[i].next) if(!vis[v=edge[i].v]){
            dep[v]=d+1; f[v][0]=u;
            vis[v]=1; q[tail++]=v;
          }
        }

        FOR(i,0,m){
          u=read(); v=read();
          printf("%d\n",lca(u,v));
        }

        return 0;
      }

    Tarjan
      int n,m,s;
      int p[MAX],ans[MAX];
      struct Edge{
        int v,next;
      }edge[MAX<<1];  //<b>要开两倍</b>
      int se[MAX],tailE=1;
      bool vis[MAX];
      struct Query{
        int v,n,next;
      }query[MAX<<1]; //<b>开两倍</b>
      int sq[MAX],tailQ=1;

      inline void addEdge(int u, int v){
        int t=tailE++;
        edge[t] = (Edge){v,se[u]}; se[u]=t;
      }
      inline void addQuery(int u, int v, int n){
        int t=tailQ++;
        query[t] = (Query){v,n,sq[u]}; sq[u]=t;
      }
      inline int find(int x){
        return p[x]<0 ? x : p[x]=find(p[x]);
      }
      void dfs(int u){
        int v; vis[u]=1;  //先设置vis并无大碍，即使一开始ans中存放了错误答案，最后还是会被正确答案覆盖
        for(int i=se[u];i;i=edge[i].next) if(!vis[v=edge[i].v]){
          dfs(v); p[v]=u;
        }
        for(int i=sq[u];i;i=query[i].next) if(vis[v=query[i].v]){
          ans[query[i].n]=find(v);
        }
      }

      int main(void){
        MST(p,-1);
        n=read(); m=read(); s=read();
        int u,v;
        FOR(i,1,n){
          u=read(); v=read();
          addEdge(u,v); addEdge(v,u);
        }
        FOR(i,0,m){
          u=read(); v=read();
          addQuery(u,v,i); addQuery(v,u,i);
        }
        dfs(s);
        FOR(i,0,m) printf("%d\n",ans[i]);

        return 0;
      }

    RMQ //to be solved

图论
  拓扑排序
    dfs
      topo[1:n]为最后的拓扑序列
      bool dfs(int u){
        c[u]=-1;  //表示正在访问
        for(int i=se[u],v;i;i=edge[i].next){
          if(c[v=edge[i].v]<0) return false;
          else if(!c[v] && !dfs(v)) return false;
        }
        c[u]=1; topo[t--]=u;
        return true;
      }
      bool topo_sort(int n){
        t=n;
        FORR(i,1,n) if(!c[i])
          if(!dfs(i)) return false;
        return true;
      }
    bfs //to be solved
      记录每个点的入度，bfs，每次寻找入度为0的节点u，将u指向的每一个节点的入度减1，直到队空。
  欧拉回路  //to be solved
    对于无向图，若要存在欧拉回路需满足以下条件之一：
      1.任何点的度数都为偶数。
      2.有且仅有两个点的度数为奇数，其余都为偶数。
    对于有向图，有类似的结论：
      1.任何点的入度都等于出度。
      2.有且仅有两个点的入度与出度不等，且这两个点中，一个入度比出度大一，另一个入度比出度小一。
    void euler(int u){  //对于有向图
      FORR(v,1,n) if(G[u][v] && !vis[u][v]){
        vis[u][v]=1; euler(v);
        st.push((Edge){u,v}); //需要使用栈输出
      }
    }
  最小生成树
    1.Kruskal
    2.Prim
  最短路
    1.Floyd
    2.Dijkstra
      边权必须都为正
      更适用于稠密图
      [1]朴素的Dij O(n^2)
        void Dij(int s){
          MST(d,0x3f); d[s]=0;
          FOR(i,0,n){
            int tMin=INF,u=-1;
            FORR(j,1,n) if(d[j]<tMin && !vis[j]) tMin=d[u=j];
            vis[u]=1;
            for(int i=se[u];i;i=edge[i].next){
              Edge & e=edge[i];
              if(d[e.v]>d[u]+e.w) d[e.v]=d[u]+e.w;
            }
          }
        }
      [2]采用堆优化的Dij O(mlogn)，在过于稠密的图中效果会稍有不好，但总体还是很快。
        struct Node{
          int u,d;
          bool operator < (const Node & b) const {return d>b.d;}
        };
        void Dij(int s){
          MST(d,0x3f); d[s]=0;
          PQ<Node> q;
          q.push((Node){s,0});
          while(!q.empty()){
            Node t=q.top(); q.pop();
            int u=t.u;
            if(d[u]!=t.d) continue;
            for(int i=se[u];i;i=edge[i].next){
              Edge & e=edge[i];
              if(d[e.v]>t.d+e.w){
                d[e.v]=t.d+e.w;
                q.push((Node){e.v,d[e.v]});
              }
            }
          }
        }
    3.Bellman_Ford, SPFA
      可以用在有负边的图中，可以检查是否有负环。
      在稠密图中会被卡，如渔网状的图。

        *---->*---->*
        |     |     |
        V     V     V
        *---->*---->*
        |     |     |
        V     V     V
        *---->*---->*

      [1]一般的BF O(nm)
     <b>无向边一定要存两条</b>，即 addEdge(u,v,w), addEdge(v,u,w)。
        较慢，尽量不要用。
        void Bellman_Ford(int s){ //O(nm)
          MST(d,0x3f); d[s]=0;
          FOR(i,1,n)  //迭代 n-1 次
            FOR(j,0,m){
              Edge & e=edge[j];
              if(d[e.v]>d[e.u]+e.w) d[e.v]=d[e.u]+e.w;
            }
        }
      [2]队列优化的BF，即SPFA O(km)，大多数情况下k等于2
        bool SPFA(int s){
          MST(d,0x3f); MST(inq,0); MST(cnt,0);
          queue<int> q; q.push(s);
          inq[s]=1; d[s]=0; cnt[s]=1;
          while(!q.empty()){
            int u=q.front(),v; q.pop();
            inq[u]=0;
            for(int i=se[u];i;i=edge[i].next){
              v=edge[i].v;
              if(d[v]>d[u]+edge[i].w){
                d[v]=d[u]+edge[i].w;
                if(!inq[v]){
                  if(++cnt[v]>=n) return false;
                  q.push(v); inq[v]=1;
                }
              }
            }
          }
          return true;
        }

  二分图
    1.判断二分图
      染色法
    2.二分图的最大匹配
  网络流

数论初步
  1.欧几里得算法（辗转相除法） O(logn)
    原理：gcd(a,b) = gcd(b,a%b)
    边界条件：gcd(a,0) = a
    int gcd(int a, int b){
      return b==0 ? a : gcd(b,a%b);
    }
    求lcm：
      a*b = gcd(a,b)*lcm(a,b)
      原理：唯一分解定理
      lcm(a,b) = a/gcd(a,b)*b;  //<b>注意溢出</b>
    判断分式是否为整数：
      对于分式 a1*a2*a3*...*an / b ，进行
        For(i 1:n) b/=gcd(ai,b)
      当且仅当最后 b==1 时，分式为整数。
      原理：唯一分解定理，任何一个数 ai 最多只能将 b 约掉 gcd(ai,b)。
  2.埃氏筛法 O(nlogn)
    对于每个p，筛去 2p, 3p, 4p, ..., kp，剩下的即为素数。
    int sq=sqrt(n+0.5);
    FORR(i,2,sq) if(!vis[i])  //
      for(int j=i*i;j<=n;j+=i) vis[j]=1;  //j不必从2*i开始，因为当i>2时，2*i已经被之前的 i'=2 筛过了，即 2*i = i'*i = k*i'
                                          //                    而i=2时，2*i = i*i = 4
  3.扩展欧几里得算法
    对于 ax+by=gcd(a,b)，求出x,y使其成立，且x+y最小（x,y可正可负可为零）。
    void gcd(int a, int b, int & d, int & x, int & y){
      if(!b) {d=a; x=1; y=0;}
      else {gcd(b,a%b,d,y,x); y-=x*(a/b);}
    }
    求不定方程根/直线方程整数点：
      若方程形如 ax+by=gcd(a,b)：
        先利用 ex_gcd 求出一对 (x1,y1)，使得 ax1+by1=gcd(a,b)。
        则所有的解都可以写成 (x1+kb',y1-ka') 的形式，其中 a'=a/gcd(a,b),b'=b/gcd(a,b)。
        证明：
          若 (x2,y2) 为方程的另一组解
          则 a*x1+b*y1 = a*x2+b*y2
          即 a*(x1-x2) = b*(y2-y1)
          两边同除 gcd(a,b)，令 a'=a/gcd(a,b),b'=b/gcd(a,b)，则
            a'*(x1-x2) = b'*(y2-y1)
          因为 a',b' 互质，即不存在任何整数k，使得 a'=kb' 或 b'=ka'
          那么 x1-x2 必为 b' 倍数，y2-y1 必为 a' 倍数，即
            x1-x2=kb', y1-y2=ka'
          那么可得 x2=x1+kb', y2=y1-ka'，成立。
      扩展，对于方程 ax+by=c：
        设 ax+by=g 的一组解为 (x1,y1)。
        若c为g的倍数， 即c=kg, ax+by=kg
          则两边同除k，得
            a*(x/k) + b*(y/k) = g
          就得到了最初的式子。
          而最初的式子满足 a*x1 + b*y1 = g，那么
            x1=x/k, y1=y/k
          也就是
            x = kx1 = x1*(c/g)
            y = ky1 = y1*(c/g)
        若c不是g的倍数，则无整数解。 
  4.同余与模算数
    (a-b)%MOD = (a%MOD - b%MOD + MOD)%MOD
    大整数取模（高精模低精）： O(n)
      原理：秦九韶算法，即 1234 = ((1*10+2)*10+3)*10+4
      对于大整数 s[0:len) 与模数m（int范围内）
        FOR(i,0,len) ans = ((LL)ans*10+s[i])%MOD
    快速幂（分治）： O(loge),e为指数
      int pow_mod(int n, int a, int m){ //求 (n^a)%m
        if(a==0) return 1;
        if(a==1) return n%m;
        LL ans=pow_mod(n,a>>1,m);
        ans=ans*ans%m;
        if(a&1) ans=ans*n%m;
        return (int)ans;
      }
    模线性方程组：
      求整数x，使得 ax≡ b mod n
      则 ax % n = b % n
      即 (ax-b)%n=0
      也就是 ax-b=ny，移项得 ax-ny=b ，使用 ex_gcd 求解即可。
    模的逆：
      当 b=1 ，即 ax≡ 1 mod n 时，x称为a关于模n的逆
      那么 ax-1=ny，即 ax-ny=1
      由“求不定方程组”的结论可得，gcd(a,n)=1，即a与n互质。
    结论：1. a≡ b mod n <==> (a-b)%n=0
          2.对于 ax≡ 1 mod n（x为a关于模n的逆），当且仅当 a与n互质时有解。
          3. ax≡ b mod n 的解不是一个数，而是一个同余等价类。
  99.唯一分解定理
    对于任意整数n>=2，一定能将其分解为 n = p1^e1 * p2^e2 * ... * pk^ek 的形式。
    代码实现：
      将指数存于数组e中，ei与pi一一对应。
      FOR(i,0,prime.size()){
        int p=prime[i],cnt=0;
        while(n%p==0) {n/=p; cnt++;}
        e[i]=cnt;
        if(n==1) break; //优化
      }

计算与概率基础
  容斥原理
  二项式定理：
    (a+b)^n = sum{ C(n,k) * a^(n-k) * b^k | 0<=k<=n}

数论中的计数问题
  约数的个数：
    给定 n 的唯一分解式 n = p1^e1 * p2^e2 * ... * pk^ek，求 n 的约数个数。
    对于每个n的约数，当它的唯一分解式与n的一一对应时，其任意 e'i<=ei。
    乘法原理，ans = (e1+1)*(e2+1)*...*(ek+1)
  欧拉函数：
    phi(n): 小于n且与n互质的数的个数。<b>（与 n-(n的约数个数)不同）</b>
    设 Ai 为 [1:n] 中是 pi 倍数的数的集合。
    则 ans = | union{ Ai } |
    根据容斥原理，则 ans = n - sum{|Ai|} + sum{|Ai cross Ai+1|} - ... ...
    又因为 |Ai| = floor(n/pi), |Ai cross Ai+1| = floor(n/(pi*pi+1)) ...
    那么
      phi(n) = sum{ (-1)^(|S|) * ( n/mul{pi|pi属于S} ) | S为{p[1:k]}的子集 }, O(2^k)
    等效于
      phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
             = n * mul{ 1 - 1/pi }, O(k)
    那么就可以通过代码来实现。
    int phi(int n){ //O(logn)
      int ans=n,sq=sqrt(n+0.5);
      FORR(i,2,sq) if(n%i==0){  //之后的while循环保证了每个满足 n%i==0 的i都为n的质因数
        ans = ans/i*(i-1);  // ans*(i-1)/i <== ans*(1-1/pi)
        while(n%i==0) n/=i; //原理：唯一分解定理，将 pi 的指数减到0
      }
      if(n>1) ans = ans/n*(n-1);  //特判：n中含有大于sqrt(n)的大素数，将 O(n) 优化为 O(logn)
      return ans;                 //      此时n一定为素数，证明：判素数时，试除[2:sqrt(n)]
    }
    void phi_table(int n){  //O(nlogn)
      phi[1]=1;
      FORR(i,2,n) if(!phi[i])   //每次用一个素数i更新phi[1:n]，因为素数i的phi(i)是不会被小于i的数更新的，<b> i一定要取满[2:n] </b>
        for(int j=i;j<=n;j+=i){   //从i开始，<b> i也要更新 </b>
          if(!phi[j]) phi[j]=j;   // <==> ans=n
          phi[j]=phi[j]/i*(i-1);  // <==> ans = ans/i*(i-1)
        }
    }
    比较：筛法：                    //每次vis[i]==0时，i都为素数，原理：每个素数不可能被小于i的数筛到
      For(i 2:sqrt(n)) if(!vis[i])  //只需到sqrt(n)，因为当筛到 2*47 时，已经在之前i=2时筛过 47*2 了，即筛的时候都满足 j=k*i,k>=i
        For(j 2*i:n step=i) vis[j]=1

高精

