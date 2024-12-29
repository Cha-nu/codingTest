def solution(cards):
    answer = 0
    n = len(cards)
    for i in range(n):
        one = 0
        cal = 0
        state = [0 for _ in range(n)]
        k = cards[i]
        while(1):
            if state[k-1] == 1:
                break
            else:
                state[k-1] = 1
                k = cards[k-1]
                one += 1
        for j in range(n):
            if i == j:
                continue
            two = 0
            statetwo = state[:]
            k = cards[j]
            while(1):
                if statetwo[k-1] == 1:
                    break
                else:
                    statetwo[k-1] = 1
                    k = cards[k-1]
                    two += 1
            cal = one * two
            answer = max(answer, cal)
            
    return answer