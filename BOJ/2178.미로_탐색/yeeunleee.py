from collections import deque

n, m = map(int, input().split())
graph = [list(map(int, input())) for _ in range(n)]
dx, dy = [0, 0, -1, 1], [-1, 1, 0, 0]

def bfs(i, j):
    queue = deque()
    queue.append((i, j))
    
    while queue:
        x, y = queue.popleft()
        
        for k in range(4):
            nx, ny = x + dx[k], y + dy[k]    # (x, y)에서 상하좌우로 이동시킨 값
            if 0 <= nx < n and 0 <= ny < m:  # 범위 확인
                if graph[nx][ny] == 1:       # 이동할 수 있는 칸인지 확인
                    queue.append((nx, ny))   # 큐에 해당 좌표 추가
                    graph[nx][ny] = graph[x][y] + 1
                    # graph의 각 원소는 (시작점 ~ 해당 좌표)까지 갈 때 지나야 하는 최소 칸의 수가 됨.
                
bfs(0, 0)
print(graph[n-1][m-1]) # 도착 위치의 원소를 출력