# d a l d i dal g o -> 8
# daldida n -> 2

N = int(input())
time = 9 # 시간 (초기값: daldidalgo + n 을 입력하는 최소 시간)
cnt = 1 # daldaialgo를 추가할 수 있는 최대 개수

while 0 < N:
    N -= cnt
    time += 1
    cnt *= 2
 
print(time)  
