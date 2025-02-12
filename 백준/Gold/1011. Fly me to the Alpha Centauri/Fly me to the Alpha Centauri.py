import sys

T = int(sys.stdin.readline())

def caculate(d):
    c = 0
    count = 0
    while count < d:
        c += 1
        count += (c+1)//2
    print(c)

for _ in range(T):
    x, y = map(int, sys.stdin.readline().split())
    caculate(y-x)