a = map(int, raw_input().split())
while a[0] != 0:
  length = a[0]
  differences = []
  for x in range(2,length+1):
    differences.append(a[x]-a[x-1])
  period = 1
  found = False
  while not found:
    c = period
    cycle = 1
    while c < len(differences) and differences[c] == differences[c-cycle*period]:
      c += 1
      cycle = c // period
    if c == len(differences):
      found = True

    if not found:
      if period >= len(differences):
        found = True
      period += 1
    else:
      break
  if len(differences) == 0:
    print 0
  else:
    print period
  a = map(int, raw_input().split())
