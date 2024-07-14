#include <iostream>
#include <vector>

using namespace std;
int M, N, J;
int result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> J;
	vector<int> loc;
	int tmp;
	for (int i = 0; i < J; i++) {
		cin >> tmp;
		loc.push_back(tmp);
	}

	int l = 1;	int r = M;	// 바구니의 시작 칸(l)과 끝 칸(r) 위치
	for (int i = 0; i < loc.size(); i++) {
		int x = loc[i];	// 가야하는 위치
		if (l <= x && x <= r) {
			continue;
		}
		do {
			if (r < x) {	// 가야하는 위치가 더 오른쪽에 있는 경우, 오른쪽으로 이동
				l++; r++;
			}
			if (x < l) {	// 가야하는 위치가 더 왼쪽에 있는 경우, 왼쪽으로 이동
				l--; r--;
			}
			result++;	// 1칸 이동
		} while (l > x || x > r);	// l <= x <= r 를 만족하는 순간, 이동 종료

	}

	cout << result;

	return 0;
}