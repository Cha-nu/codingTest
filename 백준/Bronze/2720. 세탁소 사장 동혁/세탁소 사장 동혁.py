import sys

T = int(sys.stdin.readline())
coin = [25, 10, 5, 1]
count  = [0, 0, 0, 0]
for _ in range(T):
    c = int(sys.stdin.readline())
    for i in range(len(coin)):
        count[i] = c // coin[i]
        c %= coin[i]
    for j in count:
        print(j, end=' ')
    print()