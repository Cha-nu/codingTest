import sys


T = int(sys.stdin.readline()) 

# 출발점이나 끝점이 원 내부에 있으면 +1
# 둘이 같이 있으면 생략

def cal(a, b, r, x, y):
    return r >= ((a-x)**2 + (b-y)**2)**(1/2)

for _ in range(T):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    n = int(sys.stdin.readline())
    count = 0
    for _ in range(n):
        cx, cy, r = map(int, sys.stdin.readline().split())
        check1 = cal(cx, cy, r, x1, y1)
        check2 = cal(cx, cy, r, x2, y2)
        if check1 == True and check2 == False:
            count += 1
        elif check2 == True and check1 == False:
            count += 1
    print(count)