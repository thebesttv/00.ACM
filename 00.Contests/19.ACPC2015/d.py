def gcd(a, b):
  if b==0:
    return a
  return gcd(b,a%b)

T = int(input())
for kase in range(T):
  a,b,c,d = input().split()
  a,b,c,d = int(a), int(b), int (c), int(d)
  t1, t2 = a*d, c*b
  g = gcd(t1,t2)
  n, m = t1//g, t2//g
  g1, g2 = a, b*n
  l1, l2 = a*m, b

  g = gcd(g1,g2)
  g1, g2 = g1//g, g2//g

  g = gcd(l1,l2)
  l1, l2 = l1//g, l2//g
  print("{}/{} {}/{}".format(g1,g2,l1,l2))
