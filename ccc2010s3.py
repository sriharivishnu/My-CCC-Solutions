#Based off of algorithm by Sumudu Fernando
#Solution to CCC 2010 S3 : Firehose
def returnNumberNeeded(hose, houses):
  diameter = hose * 2
  i = 0
  best = len(houses)
  while i < len(houses) and houses[i] <= houses[0] + diameter:
    count = 1
    curEnd = houses[i]
    j = i + 1
    while j < len(houses) and (houses[j] + diameter - 1000000) < houses[i]:
      if houses[j] > curEnd:
        count += 1
        curEnd = houses[j] + diameter
      j += 1
    best = min(count, best)
    i += 1
  return best

houses = []

n = input()
for x in range(n):
  houses.append(input())

houses.sort()
k = input()

hi = 1000000
lo = -1

while hi > lo+1:
  mid = (hi+lo)//2
  if (returnNumberNeeded(mid, houses) > k):
    lo = mid
  else:
    hi = mid

print hi
