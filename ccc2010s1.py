#Solution by Srihari Vishnu

def calc(x,y,z):
  return 2*int(x) + 3*int(y)+int(z)

best = ["",-1]
second = ["",-1]
n = input()
for x in range(n):
  inp = raw_input().split()
  value = calc(inp[1],inp[2],inp[3])
  if value > best[1]:
    if best[1] > second[1] or (best[1]==second[1] and best[0]<second[0]):
        second = best
    best = [inp[0],value]
  elif value == best[1]:
    if inp[0]<best[0]:
      if best[1] > second[1] or (best[1]==second[1] and best[0]<second[0]):
        second = best
      best = [inp[0],value]
    elif value > second[1] or (value==second[1] and inp[0]<second[0]):
      second = [inp[0],value]
  elif (value < best[1] and value > second[1]) or (value == second[1] and inp[0]<second[0]):
    second[0] = inp[0]
    second[1] = value
  #print best,second

print best[0]
if n>1:
  print second[0]
