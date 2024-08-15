#큐 구현을 위한 deque 라이브러리, 리스트를 기본 값으로 제공하는 딕셔너리 defaultdict 라이브러리
from collections import deque, defaultdict 

def dfs(graph, start, visited): #그래프, 탐색을 시작할 정점 번호, 방문한 노드 저장
    visited.append(start) # 현재 방문한 노드
    for neighbor in sorted(graph[start]): # 현재 노드에 연결된 모든 이웃 노드를 작은 순서대로 방문을 위해 정렬 순회
        if neighbor not in visited: # 인접 노드에 아직 방문하지 않았을 때
            dfs(graph, neighbor, visited) # DFS 재귀 호출

def bfs(graph, start): # 그래프, 탐색을 시작할 정점 번호
    visited = [] # 방문한 노드를 초기화
    queue = deque([start]) # 시작 노드를 큐에 추가
    while queue: # 큐가 모두 빌 때까지
        node = queue.popleft() # 큐의 맨 앞 노드를 node에 저장
        if node not in visited: # 아직 방문하지 않은 노드라면
            visited.append(node) # 방문 목록에 노드를 추가
            queue.extend(sorted(graph[node])) # 현재 노드에 연결된 모든 이웃 노드를 정렬하고, 큐에 추가
    return visited # 리스트 반환

n, m, v = map(int, input().split()) # 입력 정점 수, 간선 수, 정점 번호
graph = defaultdict(list) # 인접 리스트를 위해 그래프 초기화

for _ in range(m): # 간선의 수만큼 반복
    a, b = map(int, input().split()) # 두 정점 입력
    graph[a].append(b) # 정점 a에서 정점 b로의 간선 추가
    graph[b].append(a) # 정점 b에서 정점 a로의 간선 추가

visited_dfs = [] 
dfs(graph, v, visited_dfs) # DFS 탐색
print(" ".join(map(str, visited_dfs))) # DFS 결과 출력

visited_bfs = bfs(graph, v) # BFS 탐색
print(" ".join(map(str, visited_bfs))) # BFS 결과 출력
