#include <iostream>

using namespace std;

int n;
int paper[130][130];
int white, blue;

void countPaper(int x, int y, int side) {	// (시작지점 i, 시작지점 j, 한 변의 길이)
	bool isAllSame = true;	// "전부 같은 색깔인지" 상태 변수
	int color = paper[x][y];	// 영역의 첫번째칸 색깔, 초기 color
	for (int i = x; i < x + side; i++) {	// 영역의 색종이 색깔이 모두같은지 체크
		for (int j = y; j < y + side; j++) {
			if (color != paper[i][j]) {	// 하나라도 초기 color와 다른 색깔이 있다면
				isAllSame = false;	// "전부 같지 않음"으로 상태 업데이트
				break;
			}
		}
	}
	if (isAllSame) {
		color == 0 ? white++ : blue++;
		return;
	}
	else {	// 4등분하여 다시 확인
		countPaper(x, y, side / 2);	// Ⅰ구역
		countPaper(x, y + side / 2, side / 2);	//	Ⅱ구역
		countPaper(x + side / 2, y, side / 2);	// Ⅲ구역
		countPaper(x + side / 2, y + side / 2, side / 2);	// Ⅳ구역
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	countPaper(0,0,n);

	cout << white << "\n" << blue;

	return 0;
}
