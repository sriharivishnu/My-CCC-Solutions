// Solution by Srihari Vishnu
// CCC 2012 S5 : Mouse Journey
// Dynamic Programming
r,c = map(int, raw_input().split())

grid = [[-1 for x in range(c)] for y in range(r)]
for x in range(input()):
  l,m = map(int, raw_input().split())
  grid[l-1][m-1] = 0
for x in range(r):
  if grid[x][0] == 0:
    break
  else:
    grid[x][0] = 1
for x in range(c):
  if grid[0][x] == 0:
    break
  else:
    grid[0][x] = 1

for x in range(1, r):
  for y in range(1, c):
    if grid[x][y] != 0:
      if grid[x-1][y] == -1:
        grid[x][y] = grid[x][y-1]
      elif grid[x][y-1] == -1:
        grid[x][y] = grid[x-1][y]
      else:
        grid[x][y] = grid[x-1][y] + grid[x][y-1]
print grid[r-1][c-1]
