#Solution by Srihari Vishnu

w = input()
n = input()

stack = []
ans = 0
s = 0
b= True
for x in range(n):
  a = input()
  if b:
    stack.append(a)
    s += a
    if len(stack) >4:
      s-=stack.pop(0)
    if s > w:
      b = False
    else:
      ans += 1

print ans


  
