# 진법 변환 2
import sys

match = {0:0, 1:1, 2:2, 3:3, 4:4, 5:5, 6:6, 7:7, 8:8, 9:9, 10:"A", 11:"B", 12:"C", 13:"D", 14:"E", 15:"F", 16:"G", 17:"H", 18:"I", 19:"J", 20:"K", 21:"L", 22:"M", 23:"N", 24:"O", 25:"P", 26:"Q", 27:"R", 28:"S", 29:"T", 30:"U", 31:"V", 32:"W", 33:"X", 34:"Y", 35:"Z"}
result = []

# 10진수, B진법법
n, b = map(int, sys.stdin.readline().split())

# 진법 계산산
while n > 1:
    result.append(n % b)
    n //= b

# n이 남으면 result에 넣기기
if n != 0:
    result.append(n)

# 진법 표시로 변환환
for i in result[::-1]:
    print(match[i], end='')