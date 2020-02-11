#Solution by Srihari Vishnu
# CCC 2003 S2 : Poetry
def find_last(a):
    i =len(a)
    while (i > 0):
        i -= 1
        if (a[i] in vowels):
            return i
    return 0
vowels = "aeiou"
a = input()
for x in range(a):
    last_syllables = []
    for l in range(4):
        line = raw_input().lower()
        last_word = line.split()[-1]
        last_syllables.append(last_word[find_last(last_word):])
        
    if (last_syllables[0] == last_syllables[1] and last_syllables[1] == last_syllables[2] and last_syllables[2] == last_syllables[3]):
        print ("perfect")
    elif (last_syllables[0] == last_syllables[1] and last_syllables[2] == last_syllables[3]):
        print ("even")
    elif (last_syllables[0] == last_syllables[2] and last_syllables[1] == last_syllables[3]):
        print("cross")
    elif (last_syllables[0] == last_syllables[3] and last_syllables[1] == last_syllables[2]):
        print ("shell")
    else:
        print ("free")
