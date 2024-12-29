def solution(points, routes):
    answer = 0
    n = len(routes) # 로봇의 개수
    m = len(routes[0]) # 이동경로 개수
    moves = {} # key: 시간, value: 시간별 로봇의 위치
    
    for i in range(n):
        time = 0
        r, c = points[routes[i][0] - 1][0], points[routes[i][0] - 1][1]
  
        # 시작 위치 설정
        if time not in moves:
            moves[time] = []
        moves[time].append((r, c))

        for j in range(1, m):
            arrive_r, arrive_c = points[routes[i][j] - 1][0], points[routes[i][j] - 1][1]

            while r != arrive_r:
              if r > arrive_r:
                r -= 1
              elif r < arrive_r:
                r += 1
              time += 1
              if time not in moves: # 예외처리
                moves[time] = []
              moves[time].append((r, c))

            while c != arrive_c:
              if c > arrive_c:
                c -= 1
              elif c < arrive_c:
                c += 1
              time += 1
              if time not in moves:
                moves[time] = []
              moves[time].append((r, c))

    
    for key in moves:
        visited = set()
        duplicates = set()
  
        for coord in moves[key]:
            if coord in visited:
                duplicates.add(coord)  # 중복된 좌표를 저장
            else:
                visited.add(coord)
      
        answer += len(duplicates)  # 중복된 좌표 개수 추가
                
    return answer