#Solution by Srihari Vishnu
#Look for cube numbers that are also squares

import math
def square(n):
  c = int(n**(1/2.0))
  return c**2 == n or (c+1)**2 == n
a = input()
b = input()

start = round(a**(1/3.0))
end = round(b**(1/3.0))
count = 0
for x in range(int(start), int(end)+1):
  if square(x**3):
    count += 1

print count
