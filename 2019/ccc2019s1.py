#Solution by Srihari Vishnu

s = raw_input()

grid = [[1,2],[3,4]]

if s.count("H")%2 ==1:
  grid.reverse()

if s.count("V")%2 == 1:
  temp = grid[0][0]
  grid[0][0] = grid[0][1]
  grid[0][1] = temp
  temp = grid[1][0]
  grid[1][0] = grid[1][1]
  grid[1][1] = temp
for x in grid:
  print " ".join(map(str,x))
