def solution(video_len, pos, op_start, op_end, commands):
    minute = int(pos[:2])
    second = int(pos[3:])
    
    v_minute = int(video_len[:2])
    v_second = int(video_len[3:])
    
    ops_minute = int(op_start[:2])
    ops_second = int(op_start[3:])
    
    ope_minute = int(op_end[:2])
    ope_second = int(op_end[3:])
    
    def check(m, s):
        # 초,분 단위 처리
        if s >= 60: # 60초 이상 처리
            m += 1
            s -= 60
        if s < 0: # 초 음수 처리
            if m > 0:
                m -= 1
                s += 60
            else:
                s = 0
                
        # 동영상 건너뛰기
        if ops_minute == ope_minute and ops_minute == m:
            if ops_second <= s and ope_second > s:
                s = ope_second
        else:
            if ops_minute == m and ops_second <= s: # 오프닝 시작 분이 같고 초보다 크거나 같다
                m = ope_minute
                s = ope_second
            elif ops_minute < m and ope_minute > m: # 오프닝 시작 분과 끝 분의 사이
                m = ope_minute
                s = ope_second  
            elif ope_minute == m and ope_second > s: # 오프닝 끝 분과 같고 초보다 작다
                m = ope_minute
                s = ope_second
            
        
        
        # 동영상 최대 길이
        if v_minute == m and v_second < s: # 초가 초과
            s = v_second
        elif v_minute < m: #분이 초과
            s = v_second
            m = v_minute
        return m, s
    # 형식 만들기
    def make(m, s):
        if m < 10:
            minute = '0'+ str(m)
        else:
            minute = str(m)
        if s < 10:
            second = '0' + str(s)
        else:
            second = str(s)
        return minute + ":" + second
    
    # cmd 처리
    for c in commands:
        minute, second = check(minute, second)
        if c == "prev":
            second -= 10
        elif c == "next":
            second += 10
        minute, second = check(minute, second)
        print(minute, second)
    
    
    return make(minute, second)