n, m = input().split()
n = int(n)
m = int(m)

f = [ [ 0 for i in range(60) ] for j in range(60) ]

for i in range(1,n+1):
  f[i][1] = 1
  r = min(i,m) + 1
  for j in range(2,r):
    f[i][j] = f[i-1][j-1] + j * f[i-1][j]

print(f[n][m])
