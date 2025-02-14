import sys
from collections import deque

T = int(sys.stdin.readline())  # 테스트 케이스 수

for _ in range(T):
    n, k = map(int, sys.stdin.readline().split())  # 건물 개수, 규칙 개수
    construct_time = list(map(int, sys.stdin.readline().split()))  # 건물 건설 시간
    graph = [[] for _ in range(n+1)]
    in_degree = [0 for _ in range(n+1)]

    # 그래프 구성 (건설 규칙 입력)
    for _ in range(k):
        x, y = map(int, sys.stdin.readline().split())
        graph[x].append(y)
        in_degree[y] += 1

    w = int(sys.stdin.readline())  # 목표 건물 번호

    # 위상 정렬을 이용한 건설 순서 결정
    q = deque()
    dp = [0 for _ in range(n+1)]  # 각 건물까지 걸리는 최소 시간 저장

    # 진입 차수가 0인 건물(즉, 건설 가능한 건물) 찾기
    for i in range(1, n+1):
        if in_degree[i] == 0:
            q.append(i)
            dp[i] = construct_time[i-1]  # 시작 건물의 초기 건설 시간 설정

    # 위상 정렬 수행
    while q:
        building = q.popleft()

        for next_building in graph[building]:
            in_degree[next_building] -= 1
            dp[next_building] = max(dp[next_building], dp[building] + construct_time[next_building-1])

            if in_degree[next_building] == 0:
                q.append(next_building)

    # 목표 건물까지의 최소 건설 시간 출력
    print(dp[w])