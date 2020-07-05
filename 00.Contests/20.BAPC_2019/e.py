"""
d = int(input())
n = d

t = 1
while t <= n:
  m = (n//t)%10
  print('get ', m)
  if m > 5:
    n += (10-m) * t
  t *= 10
print(n,n-d)
s1, s2 = str(n), str(n-d)
ans = 0

for i in s1:
  ans += int(i)
for i in s2:
  ans += int(i)
print(ans)
"""

n = int(input())
ans = 0

while n!=0:
  t = n%10
  if t<5:
    ans += t
    n//=10
  elif t>=6:
    ans += 10-t
    n = n//10 + 1
  else: # t==5
    # print('get 5')
    tt = (n//10)%10
    ans += t
    n//=10
    if tt>=5: # <b> why... </b>
      n+=1
  # print(n, ans)

print(ans)
