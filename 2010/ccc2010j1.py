#Solution by Srihari Vishnu
n = input()
ways = 0
for x in range(min(n,5),n/2,-1):
  ways+=1

if n%2==0:
  ways +=1

print ways
