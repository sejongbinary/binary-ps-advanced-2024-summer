import sys
input=sys.stdin.readline


# 블루레이 사이즈로 가능한지 여부를 반환
def is_possible_bluray_size(size) -> bool:
    global times, M

    cnt = 1
    sum_temp = 0

    for time in times:
        if size < sum_temp + time:
            cnt += 1
            sum_temp = 0
        sum_temp += time

    return cnt <= M


# 매개변수 탐색
def parametric_search(N: int, M: int, times: list):
    start, end = max(times), 10000 * int(N / M + 0.5)

    while start <= end:
        mid = (start + end) // 2

        if is_possible_bluray_size(mid):
            end = mid - 1
        else:
            start = mid + 1

    return end + 1


N, M = map(int, input().split())
times = list(map(int, input().split()))
print(parametric_search(N, M, times))
