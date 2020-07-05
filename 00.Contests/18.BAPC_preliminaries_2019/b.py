MOD = int(1e9+7)
n = int(input())
l = input().split()

s = ""
i = 0

def dfs(lev):
  first = 1
  global s, i
  while i < n:
    if l[i] == '(':
      if first:
        first = 0
      else:
        if (lev&1)==0:
          s += '+'
        else:
          s += '*'
      s += '('
      i += 1
      dfs(lev+1)
    elif l[i] == ')':
      s += ')'
      i += 1
      return
    else:
      if first:
        first = 0
      else:
        if (lev&1)==0:
          s += '+'
        else:
          s += '*'
      s += l[i]
      i += 1

dfs(0)
print("get: ",s)
print(eval(s)%MOD)
