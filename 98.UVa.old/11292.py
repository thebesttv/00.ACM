while True:
  a = input().split()
  n = int(a[0])
  m = int(a[1])
  if n==0 and m==0:
    break
  r = []
  h = []
  for i in range(n):
    r.append(int(input()))
  for i in range(m):
    h.append(int(input()))
  r.sort()
  h.sort()

  i = j = ans = 0
  while i<n and j<m:
    if r[i]<=h[j]:
      ans += h[j]
      i+=1
    j+=1

  if i<n:
    print("Loowater is doomed!")
  else:
    print(ans)
