//Solution by Srihari Vishnu
// Passes all test cases
// Matrix rotation
def printOut(matrix):
  for row in matrix:
    print " ".join(map(str,row))
def check(matrix, size):
  for x in range(size):
    for y in range(size-1):
      if matrix[x][y] > matrix[x][y+1]:
        return False
  for j in range(size-1):
    if matrix[j][size-1] > matrix[j+1][size-1]:
      return False
  return True
def rotate(matrix,size, rotation):
  new = []
  if rotation == 1:
    for x in range(size):
      temp = []
      for y in range(size-1,-1,-1):
        temp.append(matrix[y][x])
      new.append(temp)
  elif rotation == 2:
    for x in range(size-1,-1,-1):
      temp = []
      for y in range(size-1,-1,-1):
        temp.append(matrix[x][y])
      new.append(temp)
  elif rotation ==3:
    for x in range(size-1,-1,-1):
      temp = []
      for y in range(size):
        temp.append(matrix[y][x])
      new.append(temp)
  else:
    return matrix
  return new
      
size = input()
matrix = []
for x in range(size):
  matrix.append(map(int,raw_input().split()))

for x in range(4):
  answer = rotate(matrix,size,x)
  if check(answer, size):
    printOut(answer)
