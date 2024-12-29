def solution(diffs, times, limit):
  n = len(diffs)

  # 이진 탐색의 범위 초기화
  low = 1
  high = max(diffs)
  elapse = sum(times)

  while low <= high:
    level = (low + high) // 2
    elapsed = elapse

    # level 이상에 대해 추가 시간 계산
    for i in range(1, n):
      if diffs[i] > level:
        elapsed += (times[i] + times[i - 1]) * (diffs[i] - level)
      
      # 이미 limit을 초과한 경우 더 계산할 필요 없음
      if elapsed > limit:
        break

    if elapsed <= limit:
      high = level - 1
    else:
      low = level + 1

  return low