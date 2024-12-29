from collections import Counter

def solution(points, routes):
    answer = 0
    n = len(routes) # 로봇의 개수
    m = len(routes[0]) # 이동경로 개수
    robot = {}
    
    for r in range(n):
        time = 0
        x, y = points[routes[r][0] - 1][0], points[routes[r][0] - 1][1]
  
        # 시작 위치 설정
        if time not in robot:
            robot[time] = []
        robot[time].append((x, y))

        for i in range(1, m):
            arrive_x, arrive_y = points[routes[r][i] - 1][0], points[routes[r][i] - 1][1]

            while x != arrive_x:
              if x > arrive_x:
                x -= 1
              elif x < arrive_x:
                x += 1
              time += 1
              if time not in robot:
                robot[time] = []
              robot[time].append((x, y))

            while y != arrive_y:
              if y > arrive_y:
                y -= 1
              elif y < arrive_y:
                y += 1
              time += 1
              if time not in robot:
                robot[time] = []
              robot[time].append((x, y))

    
    for key in robot:
        c = Counter(robot[key])
        for key in c:
            if c[key] > 1:
                answer += 1
                
    return answer