word_list = []
with open("vocabulary.txt") as f:
  for l in f:
    if len(l.strip()):
      word_list.append(l.strip())

with open("vocab",'w') as f:
  f.write("\n".join(word_list))
