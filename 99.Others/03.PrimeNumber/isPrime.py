from math import sqrt

def isPrime(n):
  if n==1:
    return False
  if n==2:
    return True
  r = int(sqrt(n)) + 2
  for i in range(2,r):
    if n%i==0:
      return False
  return True

n = eval(input())
if isPrime(n):
  print("Yes")
else:
  print("No")
