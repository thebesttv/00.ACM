n = int(input())
l = [int(x) for x in input().split()]

curMax = 0
res = 0
left = 0

for i in range(1,n+1):
  curMax += l[i-1]
  if curMax < 0:
    curMax = 0
    left = i
  res = max(res, (i-left)*curMax)

print(res)
print(sum(l)*len(l) - res)
