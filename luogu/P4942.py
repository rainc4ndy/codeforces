n = int(input())
sum = 0

for i in range(n):
    l, r = map(int, input().split())

    s = ""
    for j in range(l, r+1):
        s += str(j)

    print(int(s) % 9)
