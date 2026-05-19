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
		*/

		long double answer = LDBL_MAX;
		long double x = 2 * b - c - a;
		long double y = (a + c) / 2 - b;
		long double z = 2 * b - a - c;

		answer = min(abs(answer), abs(x));
		answer = min(abs(answer), abs(y));
		answer = min(abs(answer), abs(z));

		cout << "#" << t << " ";
		cout << fixed << setprecision(1) << answer;
		cout << "\n";
	}
}