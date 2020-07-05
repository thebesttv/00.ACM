n = int(input())

cnt = 0

while n != 1:
  cnt += 1
  if n&1:
    n += 1
  else:
    n//=2

print(cnt)
