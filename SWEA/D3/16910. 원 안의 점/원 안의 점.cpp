#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		long long answer = 0;

		// 각 좌표의 제곱의 합이 n의 제곱보다 작거나 같은 경우의 수 탐색
		for (int x = 0; x * x <= n * n; x++) {
			for (int y = 0; x * x + y * y <= n * n; y++) {
				// x or y가 0일 경우 경우의 수는 2가지
				// ex) (0, y), (0, -y)
				if (x == 0 || y == 0) {
					answer += 2;
				} else {
					answer += 4;
				}
			}
		}

		cout << "#" << t << " " << answer - 1 << endl;
	}
}