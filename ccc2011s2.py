n = input()
array = []
for x in range(n*2):
  array.append(raw_input())
ans = 0
for x in range(n):
  if array[x] == array[x+n]:
    ans+=1

print ans
