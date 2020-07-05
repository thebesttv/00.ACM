from math import sqrt

MOD = int(1e9 + 7)

def isPrime(n):
  if n==1:
    return False
  if n%2==0:
    return n==2
  r = int(sqrt(n+0.5))
  for i in range(3,r+1,2):
    if n%i==0:
      return False
  return True

def powmod(x,y):
  if y==0:
    return 1
  if y==1:
    return x
  t = powmod(x,y//2)
  t = t * t % MOD
  if y%2==1:
    t = t * x % MOD
  return t

x, n = input().split()
x = int(x)
n = int(n)

prime = []
r = int(sqrt(x+0.5))
for i in range(1,r+1):
  if x%i==0:
    if isPrime(i):
      prime.append(i)
    if i*i!=x and isPrime(x//i):
      prime.append(x//i)

#print(prime)

ans = 1
for p in prime:
  pk = p
  while pk <= n:
    m = n//pk - n//(pk*p)
    ans = ans * powmod(pk%MOD,m) % MOD
    pk = pk * p

print(ans)
