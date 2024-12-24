n = input()
measurements = []
for x in range(n):
    measurements.append(map(int, raw_input().split()))

measurements.sort()

ans = -10000000000000.0

for x in range(len(measurements)-1):
    speed = float(measurements[x+1][1]-measurements[x][1])/float(measurements[x+1][0]-measurements[x][0])
    if (abs(speed) > ans):
        ans = abs(speed)

print (ans)