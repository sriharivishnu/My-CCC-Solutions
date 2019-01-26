#Solution by Srihari Vishnu
n = input()
readings = []
freq = {}
for x in range(n):
  a = input()
  readings.append(a)
  if a in freq:
    freq[a] += 1
  else:
    freq[a] = 1
readings.sort()
i =0
high = -1
second  =-1
placesh = []
placess = []

while i < n:
  if (freq[readings[i]] > high):
    second = high
    placess = placesh
    high = freq[readings[i]]
    placesh = [i]
  elif (freq[readings[i]] == high):
    placesh.append(i)
  elif (freq[readings[i]]<high and freq[readings[i]]>second):
    second = freq[readings[i]]
    placess = [i]
  elif (freq[readings[i]] == second):
    placess.append(i)
  
  i+=freq[readings[i]]
if len(placesh) ==1 and len(placess) == 1:
  print abs(readings[placesh[0]]-readings[placess[0]])
elif len(placesh)>1:
  print abs(readings[placesh[0]]-readings[placesh[-1]])
else:
  ans = abs(readings[placesh[0]]-readings[placess[0]])
  ans2 = abs(readings[placesh[0]]-readings[placess[-1]])
  print max(ans, ans2)
  
