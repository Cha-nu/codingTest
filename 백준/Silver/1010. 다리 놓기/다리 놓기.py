# 다리 놓기
import sys

T = int(sys.stdin.readline())

for _ in range(T):
    n, m = map(int, sys.stdin.readline().split())
    memo = [[0 for _ in range(m+1)] for _ in range(n+1)]

    for i in range(n+1):
        memo[i][i] = 1
    
    for j in range(1, m+1):
        memo[1][j] = j
    
    for i in range(2, n+1):
        for j in range(i+1, m+1):
            memo[i][j] = memo[i-1][j-1] + memo[i][j-1]
    
    print(memo[n][m])