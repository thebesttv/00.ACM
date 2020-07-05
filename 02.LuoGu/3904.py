n, m = input().split()
n = int(n)
m = int(m)

rec = [0 for i in range(51)]

C = [ [ 0 for j in range(51) ] for i in range(51)]
A = [ 0 for i in range(51) ]

C[0][0] = C[1][0] = C[1][1] = 1
A[0] = A[1] = 1

for i in range(2,51):
  C[i][0] = 1
  for j in range(1,i):
    C[i][j] = C[i-1][j-1] + C[i-1][j]
  C[i][i] = 1

  A[i] = A[i-1] * i

def cal():
  t = n
  cnt = 0
  last = 0
  tans = 1

  for i in range(0,m):

    tans = tans * C[t][rec[i]]
    t = t - rec[i]

    if rec[i] == last:
      cnt = cnt + 1
    else:
      last = rec[i]
      tans = tans // A[cnt]
      cnt = 1

  tans = tans // A[cnt]
  return tans

def dfs(cur, st, tsum):
  if cur == m:
    if tsum == n:
      return cal()
    else:
      return 0

  r = (n-tsum) // (m-cur)
  tans = 0
  for i in range(st,r+1):
    rec[cur] = i
    tans = tans + dfs(cur+1, i, tsum + i)
  return tans


ans = dfs(0,1,0)

print(ans)
