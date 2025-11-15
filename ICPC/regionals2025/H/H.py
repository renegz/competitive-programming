N = int(input())

max = 0
tot = 0

for x in input().split():
    num = int(x)
    if num > max:
        max = num
        tot += 1

print(tot)
