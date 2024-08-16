'''
(y+num)*100//(x+num) = z+1
위 식을 num에 대하여 정리
num = ((z+1)*x-100y)/(99-z)
num은 자연수이므로 올림 처리
'''

import math
x, y = map(int, input().split())
z = (y*100)//x

if z >= 99: # 99 이상이면 승률은 변하지 않음
    print("-1")
else:
    n = (z+1)*x-100*y
    d = 99-z
    print(math.ceil(n/d)) # 올림