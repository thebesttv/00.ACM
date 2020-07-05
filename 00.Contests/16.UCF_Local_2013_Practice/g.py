T = int(input())
for kase in range(1,T+1):
  n = int(input())
  cities = [ input() for i in range(n) ]
  shown = ""
  m = int(input())
  print("Brett Log #{}:".format(kase))
  for i in range(m):
    s = input()
    flag = 0
    for city in cities:
      if city in s and city != shown:
        flag = 1
        shown = city
        break
    if flag:
      print('   ' + s)
  print()
