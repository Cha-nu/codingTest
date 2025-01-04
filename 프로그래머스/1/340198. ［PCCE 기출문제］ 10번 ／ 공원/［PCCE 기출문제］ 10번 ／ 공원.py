def solution(mats, park):
    a = len(park)
    b = len(park[0])
    def spread(m, i, j):
        for k in range(m):
            for l in range(m):
                try:
                    if park[i+k][j+l] != "-1":
                        return -1
                except:
                    return -1
        return m
    
    answer = -1
    mats.sort()
    
    for m in mats:
        for i in range(len(park)):
            for j in range(len(park[i])):
                if park[i][j] == "-1":
                    answer = max(answer, spread(m, i, j))
                else:
                    continue
                if answer >= m:
                    break
            if answer >= m:
                break
    
    return answer