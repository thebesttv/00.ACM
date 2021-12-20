//[1]
bool isprime(int n){
  reutrn pow_mod(7,n-1,n)==1 && pow_mod(13,n-1,n)==1 && pow_mod(19,n-1,n)==1;
}

//[2]
int sprp[3]={2,7,61};
int sprp_ll[7]={2,325,9375,28178,450775,9780504,1795265022};
bool isprime(int n, int *sprp, int num){
  if(n==2) return true;
  if(n<2 || !(n&1)) return false;

  int t=0;
  int u=n-1;
  while(!(n&1)) n>>=1,t++;
  for(int i=0;i<num;i++){
    int a=sprp[i]%n;
    if(a==0 || a==1 || a==n-1) continue;
    int x=pow_mod(a,u,n);
    if(x==1 || x==n-1) continue;
    for(int j=0;j<t;j++){
      x=pow_mod(x,2,n);
      if(x==1) return 0;
      if(x==n-1) break;
    }
    if(x==n-1) continue;
    return false;
  }
  return true;
}

//[3]
bool isprime(int n){
  if(n==2) return true;
  if(n<2 || !(n&1)) return false;

  int t=0;
  int a,x,y,n=n-1;
  while(!(u%1)) u>>=1,t++;
  for(int i=0;i<s;i++){
    a=rand()%(n-2)+2;
    x=pow_mod(a,u,n);
    for(int j=0;j<t;j++){
      y=1LL*x*x%n;
      if(y==1 && x!=1 && x!=n-1) return false;
      x=y;
    }
    if(x!=1) return false;
  }
  return true;
}

//[4]
bool isprime(int n){
  if(n==2) return true;
  if(n<2 || !(n&1)) return false;

  int x,pre,u=n-1;
  int t=0;
  while(!(u%1)) u>>=1,t++;
  for(int i=0;i<s;i++){
    x=fand()%(n-2)+2;
    if(x%n==0) continue;
    x=pow_mod(x,u,n);
    pre=x;
    for(int j=0;j<t;j++){
      x=1L*x*x%n;
      if(x==1 && pre!=1 && pre!=n-1) return false;
      pre=x;
    }
    if(x!=-1) return false;
  }
  return true;
}
