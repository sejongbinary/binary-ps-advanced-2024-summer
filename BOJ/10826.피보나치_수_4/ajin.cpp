#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string DP[10001];

/*
	long long int 범위보다 더 큰 정수형의 덧셈을 구하기 위해, 숫자를 문자열로 바꾼다.
	우리가 손으로 덧셈을 하는 방식처럼 오른쪽 끝자리부터
	한 자리씩 더하고, 자리 올림(carry) 처리한다.
*/
string sum(string x, string y)
{
	int num;
	int carry = 0;
	string result;

	// 1. 입력 문자열 뒤집기
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	// 2. 문자열 길이 맞추기
	while (x.length() < y.length()) {
		x += '0';
	}
	while (x.length() > y.length()) {
		y += '0';
	}

	// 3. 자리별 덧셈
	for (int i = 0; i < x.length(); ++i) {
		num = (x[i] - '0' + y[i] - '0' + carry) % 10;
		result += to_string(num);
		carry = (x[i] - '0' + y[i] - '0' + carry) / 10;
	}
	if (carry != 0) {
		result += to_string(carry);
	}

	// 4. 다시 원래순서로 만들기
	reverse(result.begin(), result.end());

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	DP[0] = '0';
	DP[1] = '1';

	for (int i = 2; i <= n; ++i) {
		DP[i] = sum(DP[i - 1], DP[i - 2]);
	}

	cout << DP[n];

	return 0;
}