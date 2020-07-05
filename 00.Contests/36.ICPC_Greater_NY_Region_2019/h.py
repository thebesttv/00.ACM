from math import sqrt

n = int(input())

s = set()

def div(x, s):
  r = int(sqrt(x+0.5) + 1)
  for i in range(2,r):
    if x%i==0:
      s.add(i)
      s.add(x//i)
      break

for i in range(n):
  div(int(input()), s)

cnt = 0
for k in sorted(s):
  cnt += 1
  if cnt == 5:
    print(" " + str(k))
    cnt = 0
  elif cnt != 1:
    print(" " + str(k), end="")
  else:
    print(k, end="")
