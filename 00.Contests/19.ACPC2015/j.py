n = int(input())
dic = {}
for i in range(n):
  s1,t,s2 = input().split()
  dic[s1]=s2

T = int(input())
for kase in range(T):
  n = int(input())
  l = input().split()
  for i in range(n):
    l[i] = dic[l[i]]
  print(' '.join(l))
