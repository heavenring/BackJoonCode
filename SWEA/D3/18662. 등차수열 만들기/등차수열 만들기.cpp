#include <iostream>
#include <algorithm>
#include <cfloat>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		long double a, b, c;
		cin >> a >> b >> c;

		/**
		* 값의 범위는 실수이다
		* b - a = c - b 이기 때문에
		* a = 2 * b - c
		* b = (a + c) / 2
		* c = 2 * b - a
		* 이를 만족시키는 a, b, c를 각각 찾아 min을 사용한다
		* 
		* -- 추가 수정 사항 --
		* 1. fixed << setprecision() 사용법 모름
		* 2. 출력 예제가 0 이었으나, 출력 값은 0.0 이어야 함
		*/

		long double answer = LDBL_MAX;
		answer = min(abs(answer), abs(2 * b - c - a));
		answer = min(abs(answer), abs((a + c) / 2 - b));
		answer = min(abs(answer), abs(2 * b - a - c));

		cout << "#" << t << " ";
		cout << fixed << setprecision(1) << answer;
		cout << "\n";
	}
}