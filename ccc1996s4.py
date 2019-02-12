#Solution by Srihari Vishnu
#Converts both numbers to decimal, adds them, and then converts back to roman
#Looks ugly but works
def toDecimal(roman, values):
  x = 0
  total = 0
  while x < len(roman):
    if x < len(roman)-1 and values[roman[x]]<values[roman[x+1]]:
      total += values[roman[x+1]]-values[roman[x]]
      x+=2
    else:
      total += values[roman[x]]
      x+=1

  return total
def toRoman(answer):
  string = ""
  counter = 0
  last = ""
  while answer>0:
    x = 0
    while x < len(keys) and values[keys[x]]<=answer:
      x+=1
    x-=1
    if last == keys[x]:
      counter += 1
    else:
      counter = 0
      last = keys[x]
    
    if counter ==3:
      temp = keys[x]
      if len(string) >= 4:
        new = keys[keys.index(string[-4])+1]
      else:
        new = keys[x+1]
      string = string[:-4]
      string += temp + new
      counter = 0
    else:
      string += keys[x]
    answer-=values[keys[x]]
  return string

values = {"I":1, "V":5, "X":10, "L":50, "C":100,"D":500,"M":1000}
keys = ["I","V","X","L","C","D","M"]
for x in range(input()):
  inp = raw_input().split("+")
  a = toDecimal(inp[0], values)
  b = toDecimal(inp[1][:-1], values)

  answer = a+b
  if a+b>1000:
    print "CONCORDIA CUM VERITATE"
  else:
    print inp[0]+"+"+inp[1]+toRoman(answer)
