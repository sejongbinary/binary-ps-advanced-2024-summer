#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[1001];
bool visited[1001];
int t, n, m, a, b;
int airplane;

void bfs(int x) {
	visited[x] = true;	// 노드 x 방문
	queue<int> q;
	q.push(x);
	while (!q.empty()) {	// 그래프 탐색 실행
		int node = q.front();
		q.pop();
		for (int i = 0; i < v[node].size(); i++) {	// node의 인접노드들 전부 방문
			int adj = v[node][i];
			if (!visited[adj]) {	// 아직 방문하지 않은 인접노드라면
				visited[adj] = true;	// 방문
				q.push(adj);
				airplane++;	// 결과 1 추가
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			v[a].push_back(b);	// 인접 노드 추가(양방향)
			v[b].push_back(a);
		}
		bfs(1);
		cout << airplane << "\n";
		// 값 초기화
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			visited[i] = false;
		}
		airplane = 0;
	}

	return 0;
}