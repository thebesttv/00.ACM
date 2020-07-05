T = int(input())
std = "Simon says "

for kase in range(T):
  s = input()
  if s[0:len(std)] == std:
    print(s[len(std)-1:])

