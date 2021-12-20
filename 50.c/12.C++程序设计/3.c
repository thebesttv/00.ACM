private:
int a[100][100];
int r,c;
public:
Array2(): r(0), c(0) {}
Array2(int r_, int c_): r(r_), c(c_) {}
int * operator [] (const int i){
  return a[i];
}
int operator () (int i,int j) {return a[i][j];}
Array2 & operator = (Array2 & b){
  for(int i=0;i<b.r;i++) for(int j=0;j<b.c;j++)
    a[i][j] = b.a[i][j];
  return *this;
}
