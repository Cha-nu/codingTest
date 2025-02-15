import sys
from collections import deque

dx = (1, 0, -1, 0)
dy = (0, 1, 0, -1)

def bfs(field, x, y, m, n):
    queue = deque([(x, y)])
    field[y][x] = 2  # 방문 표시

    while queue:
        cx, cy = queue.popleft()
        for i in range(4):
            nx, ny = cx + dx[i], cy + dy[i]
            if 0 <= nx < m and 0 <= ny < n and field[ny][nx] == 1:
                field[ny][nx] = 2
                queue.append((nx, ny))

T = int(sys.stdin.readline())

for _ in range(T):
    m, n, k = map(int, sys.stdin.readline().split())  # 가로, 세로, 배추 개수
    field = [[0] * m for _ in range(n)]

    for _ in range(k):
        x, y = map(int, sys.stdin.readline().split())
        field[y][x] = 1

    result = 0

    for i in range(n):
        for j in range(m):
            if field[i][j] == 1:  # 배추가 있고, 아직 방문하지 않았다면
                bfs(field, j, i, m, n)
                result += 1

    print(result)