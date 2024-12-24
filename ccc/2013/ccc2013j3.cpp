//Solution by Srihari Vishnu
//CCC 2013 J3
def check(string):
  digits = [False for x in range(10)]
  for x in string:
    if digits[eval(x)]:
      return False
    else:
      digits[eval(x)] = True
  return True

a = str(input()+1)
while (not check(a)):
  a = str(eval(a)+1)

print a
