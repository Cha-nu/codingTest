def solution(mats, park):
  def check(m, i, j):
    # 매트를 놓을 수 있는지 검사
    if i + m > len(park) or j + m > len(park[0]):
      return False  # 범위를 초과하면 실패
    for k in range(m):
      for l in range(m):
        if park[i + k][j + l] != "-1":  # 매트를 놓을 수 없으면 실패
          return False
    return True

  answer = -1
  placed = False  # 매트 배치 여부 플래그
  mats.sort(reverse=True)  # 큰 매트부터 확인

  for m in mats:
    for i in range(len(park)):
      if placed:
        break
      for j in range(len(park[i])):
        if park[i][j] == "-1":  # 빈 공간일 경우 매트 배치 시도
          if check(m, i, j):
            answer = max(answer, m)
            placed = True  # 매트를 배치했으면 중단
            break
    if placed:  # 매트를 배치했으면 더 작은 매트를 확인할 필요 없음
      break

  return answer
