def isPrime(n):
  if n==1:
    return False
  if n==2:
    return True
  for i in range(2,n):
    if n%i==0:
      return False
  return True


n = 100000
for i in range(1,n+1):
  if isPrime(i):
    print(i)



