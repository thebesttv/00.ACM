T = int(input())
for kase in range(1,T+1):
  s = input()
  d = {}
  for c in s:
    d[c] = d.get(c,0) + 1
  mx = max(d.values())
  print("UCF Hold-em #{}: {}\nBest possible hand: "
        .format(kase,s),end="")
  if mx==1:
    print("BUST")
  elif mx==2:
    print("TWO OF A KIND")
  elif mx==3 and 2 in d.values():
    print("FULL HOUSE")
  elif mx==3:
    print("THREE OF A KIND")
  else:
    print("FOUR OF A KIND")
  print()
