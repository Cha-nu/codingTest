def solution(n, l, r):
    answer = 0
    for i in range(l-1,r):
        while i > 0:
            mod = i % 5
            i //= 5
            if mod == 2:
                break
        else:
            answer += 1
    return answer