#Solution by Srihari Vishnu
n = input()
ar = []
neighbour = [0.0 for x in range(n)]
neighbour[0] = 10**10
neighbour[n-1] = 10**10
for x in range(n):
  ar.append(input())

ar.sort()
for x in range(1,n-1):
  neighbour[x] = float(ar[x]-ar[x-1])/2.0 + float(ar[x+1]-ar[x])/2.0
print min(neighbour)
