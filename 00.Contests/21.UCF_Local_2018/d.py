n = int(input())

c2, c5 = 0, 0
p2, p5 = [1], [1]
t2, t5 = 1, 1

while n%2==0:
  c2+=1
  n//=2
  t2*=2
  p2.append(t2)

while n%5==0:
  c5+=1
  n//=5
  t5*=5
  p5.append(t5)

#print(p2)
#print(p5)

l = []
for i in p2:
  for j in p5:
    l.append(i*j)

l = sorted(l)
print(len(l))
for x in l:
  print(x)
