#Solution by Srihari Vishnu

for a0 in range(input()):
  s = input()
  v = input()
  o = input()
  subjects = []
  verbs = []
  objects = []

  for x in range(s):
    subjects.append(raw_input())
  for x in range(v):
    verbs.append(raw_input())
  for x in range(o):
    objects.append(raw_input())
  
  for x in range(s):
    for y in range(v):
      for z in range(o):
        print subjects[x]+" "+verbs[y]+" "+objects[z]+"."
