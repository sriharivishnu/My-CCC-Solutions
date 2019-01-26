# Solution by Srihari Vishnu
#Try every jersey
j = input() #Jerseys
a = input() #Athletes

jerseys = []
requests = []
taken = [False for x in xrange(j)]
for x in range(j):
  jerseys.append(raw_input())

for y in range(a):
  requests.append(raw_input().split())
  requests[y][1] = int(requests[y][1])

count = 0
for r in requests:
  number = r[1]
  sizewanted = r[0]
  if sizewanted>=jerseys[number-1] and not taken[number-1]:
    count += 1
    taken[number-1] = True
print count
