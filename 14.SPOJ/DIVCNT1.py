T = int(input())
for k in range(T):
  n = int(input())
  ans = 0
  i = 1
  while i <= n:
    j = n // (n//i)
    ans += (n//i)*(j-i+1)
    i = j+1
  print(ans)
