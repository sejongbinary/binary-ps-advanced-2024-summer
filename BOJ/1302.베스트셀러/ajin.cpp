#include <iostream>
#include <map>
#include <string>

using namespace std;
int n;
map<string, int> book;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	string name;
	while (n--) {
		cin >> name;
		book[name]++;	//등장 횟수 추가
	}

	string most_book;	// 가장 많이 등장한 책 이름
	int max_c = -1;	// 가장 많이 등장한 책의 횟수
	for (auto iter = book.begin(); iter != book.end(); iter++) {
		if (max_c < iter->second) {	// 최댓값(최대 횟수) 갱신
			most_book = iter->first;
			max_c = iter->second;
		}
	}
	cout << most_book;

	return 0;
}