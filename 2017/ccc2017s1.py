// CCC 2017 S1 : Sum Game
// Solution by Srihari Vishnu

n = input()
a = map(int,raw_input().split())
b = map(int,raw_input().split())
c = 0
d = 0
k = 0
for x in range(n):
  c += a[x]
  d += b[x]
  if c == d:
    k=x+1

print k
