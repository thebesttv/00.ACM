kase = 0

while True:
  n = int(input())
  if n == 0:
    break

  s = set()
  for i in range(n):
    w = input()
    s.add(w)

  kase += 1
  print("Data set #{}:".format(kase))

  def find(w, s, l):
    if len(w)==0:
      return True

    if w in s:
      l.append(w)
      return True

    for i in range(1,len(w)):
      if w[0:i] in s:
        l.append(w[0:i])
        if find(w[i:], s, l):
          return True
        l.pop()
    return False

  def solve(w, s):
    padding = "     "

    if w in s:
      print("{}{} --- the word is in dictionary".format(padding,w))
      return

    i = 0
    ok = True
    l = []

    if find(w,s,l):
      print("{}{} --- the word is concatenation of".format(padding, w))
      for ww in l:
        print("{}{}{}".format(padding,padding,ww))
    else:
      print("{}{} --- misspelled word".format(padding, w))

    return

  m = int(input())
  for i in range(m):
    solve(input(), s)

  print()
