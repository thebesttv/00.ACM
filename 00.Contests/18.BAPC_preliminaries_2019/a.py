input()
rMax = max( [ int(x) for x in input().split() ] )
cMax = max( [ int(x) for x in input().split() ] )

if rMax == cMax:
  print("possible")
else:
  print("impossible")
