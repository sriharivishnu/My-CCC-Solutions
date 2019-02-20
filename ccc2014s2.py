#Solution by Srihari Vishnu

n = input()
a = raw_input().split()
b = raw_input().split()
d = {}
answer = "good"
for x in range(n):
  if a[x] != b[a.index(b[x])] or a[x] == b[x]:
    answer = "bad"
    break

print answer
