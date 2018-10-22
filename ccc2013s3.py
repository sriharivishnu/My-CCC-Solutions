import time
array = []
#Initializes a 2D array
for x in range(4):
  array.append([None for x in range(4)])

array[0][0] = 99
array[1][1] = 99
array[2][2] = 99
array[3][3] = 99

count = 0
#sums up the points of a team
def points(n):
  sum = 0
  for element in array[n]:
    if element != None:
      sum += element
  return sum - 99
#Checks if the favourite team has the most points
def isBiggest():
  maxi = True
  for x in range(4):
    if x != favourite:
      if points(x) >= points(favourite):
        maxi = False
  return maxi
def possible(array_team, array_result, opensi):
  global count
  #If the current open position is the end of the list
  if opensi == len(opens)-1:
    array[array_team][array_result] = 3
    array[array_result][array_team] = 0
    if isBiggest():
      count += 1
    array[array_team][array_result] = 1
    array[array_result][array_team] = 1
    if isBiggest():
      count += 1
    array[array_team][array_result] = 0
    array[array_result][array_team] = 3
    if isBiggest():
      count += 1
  else:
    #Attempts the first team wins, and then recurse
    array[array_team][array_result] = 3
    array[array_result][array_team] = 0
    #goes to next open
    possible(opens[opensi+1][0],opens[opensi+1][1], opensi+1)
    
    #Teams tie
    array[array_team][array_result] = 1
    array[array_result][array_team] = 1
    possible(opens[opensi+1][0],opens[opensi+1][1], opensi+1)
    
    #Teams A loses
    array[array_team][array_result] = 0
    array[array_result][array_team] = 3
    possible(opens[opensi+1][0],opens[opensi+1][1], opensi+1)
    
  
favourite = input() - 1
#Inputs the scores into a table
for x in range(input()):
  #getting the scores
  a = raw_input().split()
  #making input all integers
  for e in a:
    a[a.index(e)] = int(e)
  #first team wins
  if a[2] > a[3]:
    array[a[0]-1][a[1]-1] = 3
    array[a[1]-1][a[0]-1] = 0
    
  #tie game
  elif a[2] == a[3]:
    array[a[0]-1][a[1]-1] = 1
    array[a[1]-1][a[0]-1] = 1
  
  #Second team wins
  else:
    array[a[0]-1][a[1]-1] = 0
    array[a[1]-1][a[0]-1] = 3

#(W,L) (T,T) (L,W)
opens = []

for team in range(len(array)):
  for result in range(len(array[team])):
    if array[team][result] == None:
      if [result,team] not in opens:
        opens.append([team,result])

possible(opens[0][0], opens[0][1], 0)
print count
