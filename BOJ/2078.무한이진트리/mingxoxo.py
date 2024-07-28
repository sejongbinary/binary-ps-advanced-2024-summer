import sys
input = sys.stdin.readline

def find_move_count(L, R):
    left_cnt = right_cnt = 0

    # 루트가 되기 전까지 계속 부모 노드를 찾아 올라가는 방식
    while L != 1 or R != 1:
        if L > R:
            left_cnt += L // R
            L %= R
            if L == 0:
                left_cnt -= 1
                break
        else:
            right_cnt += R // L
            R %= L
            if R == 0:
                right_cnt -= 1
                break

    print(left_cnt, right_cnt)


L, R = map(int, input().split())
find_move_count(L, R)
