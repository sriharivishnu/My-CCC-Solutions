#Solution by Srihari Vishnu
#CCC 2018 S3 : RoboThieves
#Graph Theory

conv = "UDLR"
rows,columns = map(int, raw_input().split())
grid = []
numbers = [[999999 for x in range(columns)] for y in range(rows)]
start = []
cameras = []
answers = []
opens = []
for x in range(rows):
  temp = list(raw_input())
  for y in range(len(temp)):
    if temp[y] == "C":
      cameras.append([x,y])
    elif temp[y] == "S":
      start = [x,y]
    elif temp[y] == ".":
      opens.append([x,y])
    elif temp[y] == "W":
      numbers[x][y] = -1
  grid.append(temp)

for camera in cameras:
  #Left
  for x in range(camera[1]-1,-1,-1):
    if grid[camera[0]][x] == "." or grid[camera[0]][x] == "S":
      numbers[camera[0]][x] = -1
    elif (grid[camera[0]][x] == "W"):
      break
  #Up
  for y in range(camera[0]-1,-1,-1):
    if (grid[y][camera[1]]) == "." or grid[y][camera[1]] == "S":
      numbers[y][camera[1]] = -1
    elif (grid[y][camera[1]] == "W"):
      break
  #Right
  for x in range(camera[1]+1,columns):
    if (grid[camera[0]][x]) == "." or grid[camera[0]][x] == "S":
      numbers[camera[0]][x] = -1
    elif (grid[camera[0]][x] == "W"):
      break
  #Down
  for y in range(camera[0]+1,rows):
    if (grid[y][camera[1]]) == "." or grid[y][camera[1]] == "S":
      numbers[y][camera[1]] = -1
    elif (grid[y][camera[1]] == "W"):
      break

queue = [[start[0],start[1],0]]
while queue:
  c = queue.pop()
  character = grid[c[0]][c[1]]
  if numbers[c[0]][c[1]] != -1 and character != "C":
    if character in conv and (numbers[c[0]][c[1]] > c[2]):
      numbers[c[0]][c[1]] = c[2]
      if character == "U":
        queue.append([c[0]-1,c[1],c[2]])
      elif character == "D":
        queue.append([c[0]+1,c[1],c[2]])
      elif character == "L":
        queue.append([c[0],c[1]- 1,c[2]])
      elif character == "R":
        queue.append([c[0],c[1]+1,c[2]])
    elif c[2] < numbers[c[0]][c[1]]:
      numbers[c[0]][c[1]] = c[2]
      queue.append([c[0]- 1,c[1],c[2]+1])
      queue.append([c[0]+1,c[1],c[2]+1])
      queue.append([c[0],c[1]-1,c[2]+1])
      queue.append([c[0],c[1]+1,c[2]+1])

grid[start[0]][start[1]] = "S"
for o in opens:
  if (numbers[o[0]][o[1]] == 999999):
    print -1
  else:
    print numbers[o[0]][o[1]]
