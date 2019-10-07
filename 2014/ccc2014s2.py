#Solution by Srihari Vishnu
#CCC 2014 S2 : Assigning Partners

n = input()
a = raw_input().split()
b = raw_input().split()
d = {}
answer = "good"
for x in range(n):
  if a[x] == b[x]:
    answer = "bad"
    break
  else:
    if a[x] not in d:
      d[b[x]] = a[x]
    else:
      if d[a[x]] != b[x]:
        answer = "bad"
        break

print answer
