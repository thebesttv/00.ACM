def ok(n, s1):
  s2 = str(n)
  for i in range(0,3):
    if s1[i]!='-' and s1[i] != s2[i]:
      return False
  return True

T = int(input())
for kase in range(T):
  s1, s2, s3 = input().split()

  done = False
  for i in range(200, 501):
    if not ok(i, s1):
      continue
    for j in range(i+1, 501):
      if not ok(j, s2):
        continue
      for k in range(j+1, 501):
        if not ok(k, s3):
          continue
        print("Gas Station #{}:".format(kase+1))
        print("   Input:  {} {} {}".format(s1,s2,s3))
        print("   Output: {} {} {}".format(i,j,k))
        done = True
        break

      if done:
        break
    if done:
      break

