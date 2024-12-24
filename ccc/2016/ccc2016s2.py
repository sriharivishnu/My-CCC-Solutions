q = input()
n = input()
dCitizens = sorted(map(int, raw_input().split()))
pCitizens = sorted(map(int, raw_input().split()))

if q ==1:
  #minimum value
  total = 0
  for x in range(n):
    total += max([dCitizens[x], pCitizens[x]])
if q == 2:
  total = 0
  for x in range(n):
    total += max([dCitizens[n-x-1], pCitizens[x]])

print total

