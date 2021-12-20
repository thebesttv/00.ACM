f = open('list')
for i in f:
  i = i[:-1]
  if '.c' in i or '.h' in i:
    print('iconv -f gbk -t utf8 {} -o {}'.format(i,i))
