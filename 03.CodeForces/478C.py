r, g, b = input().split()
r, g, b = reversed(sorted([int(r), int(g), int(b)]))

print(min((r+g+b)//3, g+b))
"""
if r >= 2 * (g+b):
  print(g+b)
else:
  print((r+g+b)//3)
"""
