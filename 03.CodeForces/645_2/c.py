def s(n):
  return n*(n+1)//2;

def s3(n, d):
  return n * (n * n - 1 - 3 * d * (d-1)) // 6;

def s2(d, n):
  n = n + d - 1;
  return s3(n, d) - s3(d-1, d);

def f( x, y, dx):
  a = s(x+y-2) + x;
  ans = a * dx + s2(x+y-1, dx);
  return ans;

def g(x, y, dx):
  a = s(x+y-2) + x;
  ans = a * dx + s2(x+y, dx);
  return ans;

def h(x,y):
  return s(x+y-2) + x;

T = int(input())
for kase in range(T):
  X1, Y1, X2, Y2 = input().split()
  X1 = int(X1)
  Y1 = int(Y1)
  X2 = int(X2)
  Y2 = int(Y2)
  dx = X2 - X1 + 1
  dy = Y2 - Y1 + 1
  ans1 = f(X1, Y1, dy) + g(X1, Y2, dx) - h(X1,Y2)
  ans2 = f(X2, Y1, dy) + g(X1, Y1, dx) - h(X2,Y1)
  print(ans2 - ans1 + 1)
