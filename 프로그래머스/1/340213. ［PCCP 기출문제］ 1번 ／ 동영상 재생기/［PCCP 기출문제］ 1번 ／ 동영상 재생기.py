def solution(video_len, pos, op_start, op_end, commands):
    def time_to_second(time):
        minute, second = map(int, time.split(':'))
        return (minute * 60) + second
    
    video_len = time_to_second(video_len)
    op_start = time_to_second(op_start)
    op_end = time_to_second(op_end)
    pos = time_to_second(pos)
   
    for i in commands:
        if op_start <= pos <= op_end:
            pos = op_end

        if i == "prev":
            pos = max(0, pos - 10)
        else:
            pos = min(video_len, pos + 10)

    if op_start <= pos <= op_end:
        pos = op_end
    
    return f"{pos//60:02d}:{pos%60:02d}"