# Tag: 正难则反 循环节 排列 LCM ii
n = int(input())
l = [ int(x)-1 for x in input().split() ]
vis = [ 0 for i in range(n) ]
q = [ 0 for i in range(n+1) ]

def gcd(a, b):
  if not b:
    return a
  return gcd(b,a%b)

def lcm(a, b):
  return a // gcd(a,b) * b

def bfs(u):
  global q, l
  q[0] = u
  vis[u] = 1
  cnt = 0

  head, tail = 0, 1
  while head < tail:
    u = q[head]
    head += 1
    cnt += 1

    if vis[l[u]]:
      break

    q[tail] = l[u]
    tail += 1
    vis[l[u]] = 1

  return cnt

ans = 1
for i in range(n):
  if vis[i] == 0:
    ans = lcm(ans, bfs(i))

# print("ans: {}".format(ans))

def power(a, x):
  ans = 1
  while x:
    if x&1:
      ans *= a
    a *= a
    x >>= 1
  return ans

print(ans % power(10,n))
