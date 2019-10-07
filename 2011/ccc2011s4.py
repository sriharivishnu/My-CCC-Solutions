#Solution by Srihari Vishnu
#Type O negative, O positive, A negative, A positive, B negative, B positive, AB negative and AB positive.
def subtract(j,i):
  m = min(available[i],patients[j])
  available[i]-=m
  patients[j] -=m
  return m
def positives():
  pints = 0
  #O Positive
  pints += subtract(1,1)
  pints += subtract (1,0)

  #A positive
  for x in range(3,-1,-1):
    pints += subtract(3,x)

  #B positive
  pints += subtract(5,5)
  pints += subtract(5,4)
  pints += subtract(5,1)
  pints += subtract(5,0)
  #AB Positive
  for x in range(7,-1,-1):
    pints += subtract(7,x)
  return pints

def negatives():
  pints = 0
  #O Negative patients
  pints += subtract(0,0)

  #A Negative
  pints += subtract(2,2)
  pints += subtract(2,0)

  #B Negative
  pints += subtract(4,4)
  pints += subtract(4,0)

  #AB Negative
  for x in range(6,-1,-2):
    pints += subtract(6,x)

  return pints
available1 = map(int,raw_input().split())
patients1 = map(int,raw_input().split())
available = [available1[i] for i in range(len(available1))]
patients = [patients1[i] for i in range(len(patients1))]

s = positives() + negatives()
available = available1
patients = patients1
s1 = negatives() + positives()
print max(s,s1)
