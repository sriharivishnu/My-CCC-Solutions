#Solution by Srihari Vishnu
#CCC 2005 S1 : Snow Calls

digits = "1234567890"
d = {"ABC":2, "DEF":3,"GHI":4,"JKL":5, "MNO":6, "PQRS":7,"TUV":8,"WXYZ":9}
n = input() 
for x in range(n):
  phone = raw_input().replace("-","")
  for char in phone:
    if char not in digits:
      for element in d.keys():
        if char in element:
          phone = phone.replace(char, str(d[element]))
  new = ""
  for x in range(10):
    new += phone[x]
    if x==2 or x == 5:
      new += "-"
  print (new)
