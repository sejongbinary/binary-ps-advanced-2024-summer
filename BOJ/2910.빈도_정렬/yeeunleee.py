n, c = map(int, input().split())
temp = list(map(int, input().split()))
x = {}

# 딕셔너리 x에 리스트의 원소를 key로, 그 원소의 개수를 value로 저장
for i in temp:
    if i not in x:
        x[i] = 1
    else:
        x[i] += 1

# 개수를 기준으로 내림차순 정렬
x = sorted(x.items(), key=lambda x:x[1], reverse=True)

# 순서대로 개수만큼 빈 리스트 result에 append
result = []
for key, value in x:
    for _ in range(value):
        result.append(key)
        
print(*result)