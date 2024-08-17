#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long n, m;
vector<long long> tree;

// 절단기 높이로 충분한 길이의 나무를 얻을 수 있는지 체크
bool isEnoughTree(int h) {
	long long total = 0;
	for (int i = 0; i < n; i++) {
		if (tree[i] >= h)
			total += tree[i] - h;
	}

	return total >= m ? true : false;	// 충분조건 : 잘린 나무의 길이 총합이 m 이상인 경우.
}

// 최대 절단기 높이 찾기
long long settingHeight() {
	long long start = 1;
	long long end = *max_element(tree.begin(), tree.end());
	long long result = 0; // 최대 절단기 높이

	while (start <= end) {
		long long mid = (start + end) / 2; // mid : 절단기 높이
		// 절단기 높이로 나무를 충분히 얻을 수 있는지 체크
		if (isEnoughTree(mid)) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return end;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	long long tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		tree.push_back(tmp);
	}
	cout << settingHeight();

	return 0;
}
