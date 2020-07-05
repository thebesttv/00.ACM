T = int(input())

def allOne(s):
  for ch in s:
    if ch != '1':
      return False
  return True

def isOk(a,b,c,op):
  r = 2**32 - 1
  if a < 1 or a > r or b < 1 or b > r or c < 1 or c > r:
    return False

  if op == '+':
    return a + b == c
  elif op == '-':
    return a - b == c
  elif op == '*':
    return a * b == c
  else:
    return a == b * c

def toBase(b):
  if b <= 9:
    return str(b)

  if b != 36:
    return chr(ord('a') + b-10)

  return '0'

for kase in range(T):
  s1, op, s2, op2, s3 = input().split()
  ans = ""

  if allOne(s1+s2+s3):
    if isOk(len(s1), len(s2), len(s3), op):
      ans += "1"

  for b in range(2, 37):
    try:
      if isOk(int(s1,b),int(s2,b),int(s3,b),op):
        ans += toBase(b)
    except ValueError:
      continue

  if len(ans) == 0:
    print("invalid")
  else:
    print(ans)
