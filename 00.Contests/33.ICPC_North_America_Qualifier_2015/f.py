T = int(input())
for kase in range(T):
  s = input().lower()
  l = []
  for ch in range(26):
    if chr(ch + ord('a')) not in s:
      l.append(chr(ch + ord('a')))
  if len(l)>0:
    print("missing {}".format(''.join(l)))
  else:
    print("pangram")
