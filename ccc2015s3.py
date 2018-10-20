#Solution by Srihari Vishnu
#CCC 2015 S3 : Gates
gates = [0 for x in range(100001)]
def root(x):
  # If x (Index) not equal to value at xth pos in array, then return its root
  if (x != gates[x]):
    gates[x] = root(gates[x])
  return gates[x]

def merge(x,y):
  gates[root(x)] = root(y)

g = input()
p = input()
answer = 0
for x in range(g+1):
  gates[x] = x

for x in range(p):
  gate = input()
  if (root(gate) == 0):
    break
  else:
    merge(root(gate), root(gate) -1)
    answer += 1

print answer
