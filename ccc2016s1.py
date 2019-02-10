#Solution by Srihari Vishnu

one = sorted(list(raw_input()))
two = sorted(list(raw_input()))
asterisks = two.count("*")
aster = asterisks
ans = "A"
if len(one) == len(two):
  x = 0
  y = asterisks
  while x < len(one):
    if (y >= len(one) or one[x] != two[y]):
      aster -= 1
      if aster < 0:
        ans = "N"
        break
    else:
      y += 1
    x+=1
else:
  ans = "N"
print ans
