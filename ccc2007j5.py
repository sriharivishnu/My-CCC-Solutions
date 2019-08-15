#Solution by Srihari Vishnu
mindist = input()
maxdist = input()
N = input()
#0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000
count = 0
def between(curr, y):
  if y - curr >= mindist and y - curr <= maxdist:
    return True
def findNext(current):
  global count
  if current == 7000:
    count += 1
  else:
    for x in range(current, len(motels)):
      if motels[x]:
        if between(current, x):
          findNext(x)
      
motels = [False for x in range(7001)]
motels[0] = True
motels[990] = True
motels[1010] = True
motels[1970] = True
motels[2030] = True
motels[2940] = True
motels[3060] = True
motels[3930] = True
motels[4060] = True
motels[4970] = True
motels[5030] = True
motels[5990] = True
motels[6010] = True
motels[7000] = True

for x in range(N):
  motels[input()] = True
  
findNext(0)
print count


