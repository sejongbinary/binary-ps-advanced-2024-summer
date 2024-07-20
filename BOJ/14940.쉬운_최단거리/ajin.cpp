#include <iostream>
#include <vector>
#include <queue>
/*
	<bfs> 풀이
	- 시간초과 방지위해, 목표지점 -> 모든다른좌표 방향으로 count 진행.
	- 목표지점의 인근 지점에서 목표지점으로 되돌아가는 것을 막기 위해, if문 추가작성
*/

using namespace std;
int n, m;
int map[1000][1000];
int visited[1000][1000];	// 목표지점까지의 거리 저장
int dx[4] = { -1,1,0,0 };	// 상하좌우 순
int dy[4] = { 0,0,-1,1 };
int x2, y2;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y }); // make_pair(x,y) 대신 중괄호 {} 사용
	visited[x][y] = 1;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int a = 0; a < 4; a++) {
			int nx = p.first + dx[a];
			int ny = p.second + dy[a];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (nx == x2 && ny == y2)	// 목표지점으로 되돌아가는것 방지
				continue;
			if (!visited[nx][ny] && map[nx][ny] != 0) {
				visited[nx][ny] = visited[p.first][p.second] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {	// 목표 지점 저장
				x2 = i;
				y2 = j;
			}
		}
	}
	bfs(x2, y2); // 목표지점으로부터 다른 모든 좌표까지의 거리 카운트

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				cout << "0" << " ";
			else
				cout << visited[i][j] - 1 << " "; // 방문하지 않은(visited == 0) 곳은 -1 출력
		}
		cout << "\n";
	}

	return 0;
}