n, k = input().split()
n = int(n)
k = int(k)

s = input()
sub = s[0:k]
# print("get s: " + s + ", sub: " + sub)

for i in range(0,n,k):
  tlen = min(k, n-i)
  ts = s[i : i+tlen]
  # print("ts: {}".format(ts))

  if ts < sub:
    break
  elif ts == sub:
    continue
  else: # ts > sub
    sub = str( int(sub) + 1 )
    break

print(n)
for i in range(0,n,k):
  tlen = min(k, n-i)
  print(sub[0:tlen], end="")

print()
