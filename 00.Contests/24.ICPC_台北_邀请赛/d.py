s = input().split()
ans = []

done = 0
for i in s:
  if i != 'tapioka' and i != 'bubble':
    ans.append(i)
if len(ans)==0:
  ans.append('nothing')

print(' '.join(ans))
