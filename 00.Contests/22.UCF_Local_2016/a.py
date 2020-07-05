n = int(input())

for kase in range(n):
  s = input()
  v = [int(x) for x in s.split()]
  cnt = 0
  for i in v:
    if i>=10:
      cnt += 1
  print(s)
  if cnt==0:
    print('zilch')
  elif cnt==1:
    print('double')
  elif cnt==2:
    print('double-double')
  elif cnt==3:
    print('triple-double')
  print()
