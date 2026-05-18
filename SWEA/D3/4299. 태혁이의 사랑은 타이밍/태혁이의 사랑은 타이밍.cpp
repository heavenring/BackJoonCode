#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int d, h, m;
		cin >> d >> h >> m;

		// 일, 시, 분 계산
		long long answer = 0;
		answer += (d - 11) * 60 * 24;
		answer += (h - 11) * 60;
		answer += (m - 11);

		// 약속 전 깨달았을 시
		if (answer < 0) {
			answer = -1;
		}

		cout << "#" << t << " " << answer << "\n";
	}

}