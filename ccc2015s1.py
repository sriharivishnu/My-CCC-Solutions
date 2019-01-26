//Solution by Srihari Vishnu
//Straightforward stack approach
arr = []
for x in range(input()):
  y = input()
  if y == 0:
    arr.pop()
  else:
    arr.append(y)

print sum(arr)
