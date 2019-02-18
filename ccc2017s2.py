//CCC 2017 S2 : High Tide, Low Tide
// Solution by Srihari Vishnu

n = input()
t = sorted(map(int,raw_input().split()))

if n%2 ==0:
  x = len(t)/2-1
  y = len(t)/2
else:
  x = len(t)/2
  y = len(t)/2+1
new = []
for z in range(len(t)/2):
  new.append(t[x])
  new.append(t[y])
  x-=1
  if y <len(t)-1:
    y+=1
  else:
    break
if n%2 ==1:
  new.append(t[0])
print " ".join(map(str,new))

