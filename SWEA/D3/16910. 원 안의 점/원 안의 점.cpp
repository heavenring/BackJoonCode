#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		// (0, 0) 일때 1개 추가
		long long answer = 1;

		// x = 0일때 y * y <= n * n인 경우의 수
		// y과 음수일 때와 양수 일 떄는 고려하여 2씩 더한다
		for (int y = 1; y <= n; y++) {
			answer += 2;
		}

		// y = 0일때 x * x <= n * n인 경우의 수
		// x과 음수일 때와 양수 일 떄는 고려하여 2씩 더한다
		for (int x = 1; x <= n; x++) {
			answer += 2;
		}

		// x > 0, y > 0 일 때 x * x + y * y <= n * n인 경우의 수
		// x과 음수일 때와 양수 일 떄는 고려하여 4씩 더한다
		for (int x = 1; x * x <= n * n; x++) {
			for (int y = 1; x * x + y * y <= n * n; y++) {
				answer += 4;
			}
		}

		cout << "#" << t << " " << answer << endl;
	}
}