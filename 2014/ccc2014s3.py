#Solution by Srihari Vishnu

for a0 in range(int(input())):
  cars = []
  branch = []
  total = int(input())
  for x in range(total):
    cars.append(int(input()))
  
  state = "Y"
  n = 1
  i = len(cars)-1
  while state == "Y" and n<= total:
    #print cars,branch,n
    if branch and branch[-1] == n:
      n += 1
      branch.pop()
    elif i >=0:
      if cars[i] == n:
        n += 1
        i-=1
      else:
        branch.append(cars[i])
        i-=1
    else:
      state = "N"
      break
  print(state)
