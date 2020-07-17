n, m = input().split()
n, m = int(n), int(m)

a = [ int(x) for x in input().split() ]

MOD = int(1e9+7)

for kase in range(m):
  l, r = input().split()
  l, r = int(l), int(r)
  l -= 1

  ansMax = 0
  for x in range(l,r):
    for y in range(x,r):
      t = 1
      for k in range(x,y+1):
        t *= a[k]
      ansMax = max(ansMax, t)
  print(ansMax % MOD)
