MAX = 40
for a in range(1,MAX):
  for b in range(a,MAX):
    for c in range(b,MAX):
      for d in range(c,MAX):
        for e in range(d,MAX):
          for f in range(e,MAX):
            for g in range(f,MAX):
              if a+b+c+d+e+f+g == a*b*c*d*e*f*g:
                print(a,b,c,d,e,f,g)
