#Solution by Srihari Vishnu
#Storing primes found before for optimization

import math
def isPrime(n):
  for x in range(2,int(math.sqrt(n))+1):
    if n%x == 0:
      return False
  return True

primes = [False for x in range(2000001)]
primes[1] = True
primes[2] = True
a = int(input())
for a0 in range(a):
  n = int(input())
  x = n
  y = n
  while not primes[x] or not primes[y]:
    if isPrime(x):
      primes[x] = True
    if isPrime(y):
      primes[y] = True
    if primes[x] and primes[y]:
      break
    x-=1
    y+=1
  print (x,y)
