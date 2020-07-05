s = input()

if '-' not in s:
  print("NO")
  exit()

l = s.find('-')
if l > 8 or l == len(s) or len(s) - l - 1> 24:
  print("NO")
else:
  print("YES")
