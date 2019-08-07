#Solution by Srihari Vishnu
#CCC 2011 S1: English or French?
#Simple Implementation
n = input()
scount = 0
tcount = 0
for x in range(n):
  line = raw_input().lower()
  scount += line.count("s")
  tcount += line.count("t")

if scount>=tcount:
  print ("French")
else:
  print ("English")

